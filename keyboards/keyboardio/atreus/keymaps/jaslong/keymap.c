#include QMK_KEYBOARD_H

#define _____NO_____ KC_NO
#define ____TRNS____ KC_TRNS

#define K(ch) ( \
(ch) == '`' ? KC_GRAVE : \
(ch) == '~' ? KC_TILDE : \
(ch) == '!' ? KC_EXCLAIM : \
(ch) == '@' ? KC_AT : \
(ch) == '#' ? KC_HASH : \
(ch) == '$' ? KC_DOLLAR : \
(ch) == '%' ? KC_PERCENT : \
(ch) == '^' ? KC_CIRCUMFLEX : \
(ch) == '&' ? KC_AMPERSAND : \
(ch) == '*' ? KC_ASTERISK : \
(ch) == '(' ? KC_LEFT_PAREN : \
(ch) == ')' ? KC_RIGHT_PAREN : \
(ch) == '-' ? KC_MINUS : \
(ch) == '_' ? KC_UNDERSCORE : \
(ch) == '=' ? KC_EQUAL : \
(ch) == '+' ? KC_PLUS : \
(ch) == '[' ? KC_LEFT_BRACKET : \
(ch) == '{' ? KC_LEFT_CURLY_BRACE : \
(ch) == ']' ? KC_RIGHT_BRACKET : \
(ch) == '}' ? KC_RIGHT_CURLY_BRACE : \
(ch) == '\\' ? KC_BACKSLASH : \
(ch) == '|' ? KC_PIPE : \
(ch) == ';' ? KC_SEMICOLON : \
(ch) == ':' ? KC_COLON : \
(ch) == '\'' ? KC_QUOTE : \
(ch) == '"' ? KC_DOUBLE_QUOTE : \
(ch) == ',' ? KC_COMMA : \
(ch) == '<' ? KC_LEFT_ANGLE_BRACKET : \
(ch) == '.' ? KC_DOT : \
(ch) == '>' ? KC_RIGHT_ANGLE_BRACKET : \
(ch) == '/' ? KC_SLASH : \
(ch) == '?' ? KC_QUESTION : \
KC_NO)

enum custom_keycodes {
    // For window tabbing, equivalent to KC_LGUI + MO(5).
    GUITAB = SAFE_RANGE,
    // Sends "=>"
    ARROW,
};

bool handle_guitab(bool down) {
  if (down) {
    register_code(KC_LGUI);
    layer_on(5);
  } else {
    layer_off(5);
    unregister_code(KC_LGUI);
  }
  return true;
}

bool handle_arrow(bool down) {
  if (down) {
    SEND_STRING("=>");
  }
  return true;
}

// Up/down/left/right + number repeats the last direction number times within 2000ms.
// Number 0 repeats 10 times.

uint16_t last_dir_kc = 0;
uint16_t last_dir_kc_time = 0;

bool handle_dir(bool down, uint16_t keycode) {
  if (down) {
  } else {
    last_dir_kc = keycode;
    last_dir_kc_time = timer_read();
  }
  return true;
}

bool handle_num(bool down, uint16_t keycode) {
  if (down) {
    if (timer_read() - last_dir_kc_time > 2000) {
      return true;
    } else {
      // KC_1 is the lowest and KC_0 is the highest, so KC_0 naturally becomes 10.
      int times = keycode - KC_1 + 1;
      for (int i = 0; i < times; ++i) {
        tap_code(last_dir_kc);
      }
      last_dir_kc_time = timer_read();
      return false;
    }
  } else {
    return true;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool down = record->event.pressed;
  switch (keycode) {
    case KC_UP:
    case KC_DOWN:
    case KC_LEFT:
    case KC_RGHT:
      return handle_dir(down, keycode);
    case KC_1:
    case KC_2:
    case KC_3:
    case KC_4:
    case KC_5:
    case KC_6:
    case KC_7:
    case KC_8:
    case KC_9:
    case KC_0:
      return handle_num(down, keycode);
    case GUITAB:
      return handle_guitab(down);
    case ARROW:
      return handle_arrow(down);
    default:
      return true;
  }
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Colemak
  [0] = LAYOUT(
    KC_Q         , KC_W         , KC_F         , KC_P         , KC_B         ,                               KC_J         , KC_L         , KC_U         , KC_Y         , LT(4,K('\'')),
    KC_A         , KC_R         , KC_S         , KC_T         , KC_G         ,                               KC_M         , KC_N         , KC_E         , KC_I         , KC_O         ,
    LT(3,KC_Z)   , KC_X         , KC_C         , KC_D         , KC_V         , KC_ESC       , KC_TAB       , KC_K         , KC_H         , K(',')       , K('.')       , LT(4,K('/')) ,
    GUITAB       , ____TRNS____ , KC_LGUI      , KC_LSFT      , KC_LCTL      , KC_BSPC      , KC_ENT       , KC_SPC       , MO(2)        , KC_LALT      , ____TRNS____ , ____TRNS____
  ),
  // QWERTY
  [1] = LAYOUT(
    KC_Q         , KC_W         , KC_E         , KC_R         , KC_T         ,                               KC_Y         , KC_U         , KC_I         , KC_O         , KC_P         ,
    KC_A         , KC_S         , KC_D         , KC_F         , KC_G         ,                               KC_H         , KC_J         , KC_K         , KC_L         , K(';')       ,
    KC_Z         , KC_X         , KC_C         , KC_V         , KC_B         , ____TRNS____ , ____TRNS____ , KC_N         , KC_M         , K(',')       , K('.')       , K('/')       ,
    ____TRNS____ , ____TRNS____ , ____TRNS____ , ____TRNS____ , ____TRNS____ , ____TRNS____ , ____TRNS____ , ____TRNS____ , ____TRNS____ , ____TRNS____ , ____TRNS____ , ____TRNS____
  ),
  // Symbol
  [2] = LAYOUT(
    _____NO_____ , _____NO_____ , _____NO_____ , _____NO_____ , _____NO_____ ,                               _____NO_____ , K('[')       , K(']')       , ARROW        , K('`')       ,
    K('~')       , K('_')       , K('-')       , K('=')       , K('+')       ,                               K('|')       , K('(')       , K(')')       , K(':')       , K(';')       ,
    K('!')       , K('@')       , K('#')       , K('$')       , K('%')       , K('^')       , K('&')       , K('*')       , K('{')       , K('}')       , _____NO_____ , K('\\')      ,
    ____TRNS____ , ____TRNS____ , ____TRNS____ , ____TRNS____ , ____TRNS____ , A(KC_BSPC)   , ____TRNS____ , ____TRNS____ , ____TRNS____ , ____TRNS____ , ____TRNS____ , ____TRNS____
  ),
  // NavNum
  [3] = LAYOUT(
    KC_HOME      , A(KC_LEFT)   , KC_UP        , A(KC_RGHT)   , KC_PGUP      ,                               _____NO_____ , KC_7         , KC_8         , KC_9         , K('/')       ,
    KC_END       , KC_LEFT      , KC_DOWN      , KC_RGHT      , KC_PGDN      ,                               _____NO_____ , KC_4         , KC_5         , KC_6         , K('*')       ,
    _____NO_____ , C(KC_A)      , _____NO_____ , C(KC_E)      , _____NO_____ , ____TRNS____ , ____TRNS____ , _____NO_____ , KC_1         , KC_2         , KC_3         , K('-')       ,
    ____TRNS____ , ____TRNS____ , ____TRNS____ , ____TRNS____ , ____TRNS____ , ____TRNS____ , ____TRNS____ , ____TRNS____ , KC_0         , K('.')       , K(',')       , K('+')
  ),
  // OS
  [4] = LAYOUT(
    _____NO_____ , _____NO_____ , _____NO_____ , _____NO_____ , _____NO_____ ,                               _____NO_____ , KC_MPRV      , KC_MPLY      , KC_MNXT      , _____NO_____ ,
    _____NO_____ , _____NO_____ , _____NO_____ , _____NO_____ , _____NO_____ ,                               _____NO_____ , G(K('$'))    , C(G(KC_SPC)) , KC_MUTE      , _____NO_____ ,
    _____NO_____ , _____NO_____ , _____NO_____ , _____NO_____ , _____NO_____ , ____TRNS____ , ____TRNS____ , _____NO_____ , G(K('%'))    , KC_BRMU      , KC_VOLU      , _____NO_____ ,
    QK_BOOT      , ____TRNS____ , ____TRNS____ , ____TRNS____ , ____TRNS____ , ____TRNS____ , ____TRNS____ , ____TRNS____ , ____TRNS____ , KC_BRMD      , KC_VOLD      , ____TRNS____
  ),
  // GUITAB
  [5] = LAYOUT(
    _____NO_____ , _____NO_____ , _____NO_____ , _____NO_____ , _____NO_____ ,                               _____NO_____ , _____NO_____ , _____NO_____ , _____NO_____ , _____NO_____ ,
    _____NO_____ , _____NO_____ , _____NO_____ , _____NO_____ , _____NO_____ ,                               _____NO_____ , _____NO_____ , _____NO_____ , _____NO_____ , _____NO_____ ,
    _____NO_____ , _____NO_____ , _____NO_____ , _____NO_____ , _____NO_____ , ____TRNS____ , ____TRNS____ , _____NO_____ , _____NO_____ , _____NO_____ , _____NO_____ , _____NO_____ ,
    ____TRNS____ , K('`')       , KC_TAB       , ____TRNS____ , ____TRNS____ , ____TRNS____ , ____TRNS____ , ____TRNS____ , ____TRNS____ , ____TRNS____ , ____TRNS____ , ____TRNS____
  )
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

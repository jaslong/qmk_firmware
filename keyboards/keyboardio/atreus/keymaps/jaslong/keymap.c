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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Colemak
  [0] = LAYOUT(
    LT(4,KC_Q)   , KC_W         , KC_F         , KC_P         , KC_B         ,                               KC_J         , KC_L         , KC_U         , KC_Y         , LT(4,K('\'')),
    KC_A         , KC_R         , KC_S         , KC_T         , KC_G         ,                               KC_M         , KC_N         , KC_E         , KC_I         , KC_O         ,
    LT(3,KC_Z)   , KC_X         , KC_C         , KC_D         , KC_V         , KC_ESC       , KC_TAB       , KC_K         , KC_H         , K(',')       , K('.')       , LT(4,K('/')) ,
    ____TRNS____ , ____TRNS____ , KC_LGUI      , KC_LSFT      , KC_LCTL      , KC_BSPC      , KC_ENT       , KC_SPC       , MO(2)        , KC_LALT      , ____TRNS____ , ____TRNS____
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
    _____NO_____ , _____NO_____ , _____NO_____ , _____NO_____ , _____NO_____ ,                               _____NO_____ , K('[')       , K(']')       , _____NO_____ , K('`')       ,
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
    _____NO_____ , KC_LGUI      , KC_TAB       , KC_LSFT      , K('`')       ,                               _____NO_____ , KC_MPRV      , KC_MPLY      , KC_MNXT      , _____NO_____ ,
    _____NO_____ , _____NO_____ , _____NO_____ , _____NO_____ , _____NO_____ ,                               _____NO_____ , G(K('$'))    , C(G(KC_SPC)) , KC_MUTE      , _____NO_____ ,
    _____NO_____ , _____NO_____ , _____NO_____ , _____NO_____ , _____NO_____ , ____TRNS____ , ____TRNS____ , _____NO_____ , G(K('%'))    , KC_BRMU      , KC_VOLU      , _____NO_____ ,
    QK_BOOT      , ____TRNS____ , ____TRNS____ , ____TRNS____ , ____TRNS____ , ____TRNS____ , ____TRNS____ , ____TRNS____ , ____TRNS____ , KC_BRMD      , KC_VOLD      , ____TRNS____
  )
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

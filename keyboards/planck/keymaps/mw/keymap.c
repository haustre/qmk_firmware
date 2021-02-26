#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "sendstring_german.h"
#include "rgblight_list.h"
#include "keymap_steno.h"

enum planck_layers {
  _NEO,
  _NEO_3,
  _NEO_4,
  _NEO_EXTRA,
  _QWERTZ,
  _PLOVER,
  _ADJUST,
  _LED,
};

enum custom_keycodes {
  ADJUST,
};

#define M3 MO(_NEO_3)
#define M4 MO(_NEO_4)
#define NEO_EXTRA MO(_NEO_EXTRA)
#define ADJUST MO(_ADJUST)
#define MW_TILD SEND_STRING("abc")

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/*
,-----------------------------------------------------------------------------------.
| Esc  |   X  |   V  |   L  |   C  |   W  |   K  |   H  |   G  |   F  |   Q  | Bksp |
|------+------+------+------+------+-------------+------+------+------+------+------|
| Ent  |   U  |   I  |   A  |   E  |   O  |   S  |   N  |   R  |   T  |   D  |  Y   |
|------+------+------+------+------+------|------+------+------+------+------+------|
| Shift|   Ü  |   Ö  |   Ä  |   P  |   Z  |   B  |   M  |   ,  |   .  |   J  |Shift |
|------+------+------+------+------+------+------+------+------+------+------+------|
| Ctrl | GUI  | Alt  |  M2  |  M1  |    Space    |  M1  |  M2  | Alt  |MRight| Ctrl |
`-----------------------------------------------------------------------------------'
*/

[_NEO] = LAYOUT_planck_grid(
     KC_TAB,        DE_X,    DE_V,       DE_L,  DE_C,  DE_W,   DE_K,   DE_H,  DE_G,    DE_F,     DE_Q,     KC_BSPC      ,
     M3,            DE_U,    DE_I,       DE_A,  DE_E,  DE_O,   DE_S,   DE_N,  DE_R,    DE_T,     DE_D,     DE_Y         ,
     OSM(MOD_LSFT), DE_UE,   DE_OE,      DE_AE, DE_P,  DE_Z,   DE_B,   DE_M,  DE_COMM, DE_DOT,   DE_J,     OSM(MOD_LSFT),
     KC_LCTL ,      KC_LALT, TT(ADJUST), M4,    M3,    KC_SPC, KC_SPC, M3,    TT(M4),  KC_LGUI,  KC_BTN2,  KC_ENT
),

/* M1
 ,-----------------------------------------------------------------------------------.
 |  Esc |      |   _  |   [  |   ]  |   ^  |   !  |   <  |   >  |   =  |   &  |  ß   |
 |------+------+------+------+------+-------------+------+------+------+------+------|
 |  Tab |   \  |   /  |   {  |   }  |   *  |   ?  |   (  |   )  |   -  |   :  |  @   |
 |------+------+------+------+------+------|------+------+------+------+------+------|
 | Shift|   #  |   $  |   |  |   ~  |   `  |   +  |   %  |   "  |   '  |   ;  |Shift |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | Ctrl | GUI  | Alt  |  M2  |  M1  |    Space    |  M1  |  M2  | Alt  | Esc  | Ctrl |
 `-----------------------------------------------------------------------------------'
*/
[_NEO_3] = LAYOUT_planck_grid(
     _______, _______, DE_UNDS, DE_LBRC,   DE_RBRC, DE_CIRC, DE_EXLM, DE_LESS, DE_MORE,   DE_EQL,  DE_AMPR, KC_BSPC ,
     _______, DE_BSLS, DE_SLSH, DE_LCBR,   DE_RCBR, DE_ASTR, DE_QST,  DE_LPRN, DE_RPRN,   DE_MINS, DE_COLN, DE_AT   ,
     _______, DE_HASH, DE_DLR,  DE_PIPE,   DE_TILD, DE_ACUT, DE_PLUS, DE_PERC, DE_DQOT,   DE_QUOT, DE_SCLN, _______ ,
     _______, _______, _______, NEO_EXTRA, _______, _______, _______, _______, NEO_EXTRA, _______, _______, _______
),

/* M2 Navigation & Number Blocks
*  very easy to get used to & intuituve placement
* ,-----------------------------------------------------------------------------------.
* |      | PgUp | Bksp |  Up  |  DEL | PgDn |      |   7  |   8  |   9  |      | Ins  |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* |  Tab | Home |  Lft | Down | Right| End  |      |   4  |   5  |   6  |   .  | Enter|
* |------+------+------+------+------+------|------+------+------+------+------+------|
* | Shift|      |  Tab |      | Enter|      |   0  |   1  |   2  |   3  |   ,  |Shift |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* | Ctrl | GUI  | Alt  |  M2  |  M1  |    Space    |  M1  |  M2  | Alt  | Esc  | Ctrl |
* `-----------------------------------------------------------------------------------'
*/
[_NEO_4] = LAYOUT_planck_grid(
     _______, KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,    KC_PGDN, XXXXXXX,    DE_7,      DE_8,   DE_9,    XXXXXXX, KC_INS  ,
     _______,  KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,   KC_END,  KC_LGUI,    DE_4,      DE_5,   DE_6,    DE_DOT,  KC_ENT  ,
     _______, KC_ESC,  KC_TAB,  XXXXXXX, KC_ENT,    XXXXXXX, LCTL(DE_B), DE_1,      DE_2,   DE_3,    DE_COMM, _______ ,
     _______, _______, _______, _______, NEO_EXTRA, DE_0,    DE_0,       NEO_EXTRA, TG(M4), _______, _______, _______
),

/* M3 Function & Media Keys
* ,-----------------------------------------------------------------------------------.
* |      |      | Print|Scroll|Pause |      |      |  F7  |  F8  |  F9  |  F12 |      |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* | Tab  |      | Mute | Vol- | Vol+ |      |   ³  |  F4  |  F5  |  F6  |  F11 | Enter|
* |------+------+------+------+------+------|------+------+------+------+------+------|
* | Shift|      | Prev | Play | Next |      |   ²  |  F1  |  F2  |  F3  |  F10 |Shift |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* | Ctrl | GUI  | Alt  |  M2  |  M1  |    Space    |  M1  |  M2  | Alt  | Esc  | Ctrl |
* `-----------------------------------------------------------------------------------'
*/
[_NEO_EXTRA] = LAYOUT_planck_grid(
     XXXXXXX, XXXXXXX, KC_PSCR, KC_SLCK, KC_PAUS, XXXXXXX, XXXXXXX, KC_F7, KC_F8,    KC_F9,   KC_F12,  XXXXXXX ,
     KC_TAB,  XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, KC_F4, KC_F5,    KC_F6,   KC_F11,  KC_ENT  ,
     _______, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, KC_F1, KC_F2,    KC_F3,   KC_F10,  _______ ,
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_QWERTZ] = LAYOUT_planck_grid(
    KC_TAB,      KC_Q,    KC_W,        KC_E,    KC_R,        KC_T,    KC_Z,    KC_U,        KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_CAPSLOCK, KC_A,    KC_S,        KC_D,    KC_F,        KC_G,    KC_H,    KC_J,        KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,     KC_Y,    KC_X,        KC_C,    KC_V,        KC_B,    KC_N,    KC_M,        KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_LCTL,     KC_LALT, TG(_QWERTZ), KC_ALGR, KC_CAPSLOCK, KC_SPC,  KC_SPC,  KC_CAPSLOCK, KC_ALGR, KC_LGUI, KC_UP,   KC_DOWN
),

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  FN  |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |  PWR | RES1 | RES2 |
 * `-----------------------------------------------------------------------------------'
 */

[_PLOVER] = LAYOUT_planck_grid(
  STN_N1,      STN_N2,  STN_N3,  STN_N4,  STN_N5,  STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,  STN_NC ,
  STN_FN,      STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR ,
  XXXXXXX,     STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR ,
  TG(_PLOVER), XXXXXXX, XXXXXXX, STN_A,   STN_O,   XXXXXXX, XXXXXXX, STN_E,   STN_U,   STN_PWR, STN_RE1, STN_RE2
),

[_ADJUST] = LAYOUT_planck_grid(
    _______,    _______,    _______,     _______,       _______,     _______, _______, _______, _______,  _______, TG(_QWERTZ), _______,
    KC_MS_BTN1, KC_MS_UP,   KC_MS_BTN2,  KC_MS_WH_UP,   AU_OFF,      AG_NORM, AG_SWAP, _______, _______,  _______, _______,     _______,
    KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_WH_DOWN, TG(_PLOVER), MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______,     _______,
    _______,    _______,    TG(_ADJUST), _______,       _______,     _______, _______, _______, _______,    RESET,   DEBUG,     TG(_LED)
),

[_LED] = LAYOUT_planck_grid(
    RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(_LED)
)

};

#define COL_0 HSV_OFF
#define COL_1 HSV_RED
#define COL_2 HSV_GREEN
#define COL_3 HSV_BLUE


const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
   [_NEO_4] =  {{COL_0},{COL_0},{COL_1},{COL_2},{COL_0},{COL_0},{COL_0},{COL_2},{COL_2},{COL_2},{COL_0},{COL_0},
                {COL_0},{COL_0},{COL_2},{COL_2},{COL_2},{COL_0},{COL_0},{COL_2},{COL_2},{COL_2},{COL_0},{COL_0},
                {COL_0},{COL_0},{COL_0},{COL_0},{COL_3},{COL_0},{COL_0},{COL_2},{COL_2},{COL_2},{COL_0},{COL_0},
                {COL_0},{COL_0},{COL_0},{COL_0},{COL_0},{COL_0},        {COL_0},{COL_1},{COL_0},{COL_0},{COL_0}},
   [_ADJUST] = {{COL_0},{COL_0},{COL_0},{COL_0},{COL_0},{COL_0},{COL_0},{COL_0},{COL_0},{COL_0},{COL_0},{COL_0},
                {COL_0},{COL_2},{COL_0},{COL_0},{COL_0},{COL_0},{COL_0},{COL_0},{COL_0},{COL_0},{COL_0},{COL_0},
                {COL_2},{COL_2},{COL_2},{COL_0},{COL_0},{COL_0},{COL_0},{COL_0},{COL_0},{COL_0},{COL_0},{COL_0},
                {COL_0},{COL_0},{COL_1},{COL_0},{COL_0},{COL_0},        {COL_0},{COL_0},{COL_0},{COL_0},{COL_0}}

};

void set_led_colors( void ) {
  uint8_t layer = biton32(layer_state);
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
	    .h = pgm_read_byte(&ledmap[layer][i][0]),
	    .s = pgm_read_byte(&ledmap[layer][i][1]),
	    .v = pgm_read_byte(&ledmap[layer][i][2])};
    if (hsv.v > 0) {
      RGB rgb = hsv_to_rgb( hsv );
      rgb_matrix_set_color( i, rgb.r, rgb.g, rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  switch (biton32(layer_state)) {
    case _NEO_4:
    case _ADJUST:
      set_led_colors();
      break;
  }
}

void matrix_init_user() {
  steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
}

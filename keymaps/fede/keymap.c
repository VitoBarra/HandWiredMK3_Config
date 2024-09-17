#include QMK_KEYBOARD_H
#include <stdio.h>

#define KC_COPY LCTL(KC_C) // copy
#define KC_CUT LCTL(KC_X)  // cut
#define KC_PSTE LCTL(KC_V) // paste
#define KC_UNDO LCTL(KC_Z) // undo
#define KC_AGIN LCTL(KC_Y) // redo
#define KC_SCRE LSG(KC_S)  // screenshot  WIN+SHIFT+S
#define KC_RENA KC_F2      //

// clang-format off

enum layer_names {
  base,
  numbers,
  navigation,
  symbols,
  function,
  media,
  games
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [base] = LAYOUT_ortho_10x4(
		KC_Q,                    KC_W,                    KC_E,                    KC_R,                    KC_T,                    KC_Y,                    KC_U,                    KC_I,                    KC_O,                    KC_BSPC,
		LGUI_T(KC_A),            LALT_T(KC_S),            LSFT_T(KC_D),            LCTL_T(KC_F),            KC_G,                    KC_H,                    RCTL_T(KC_J),            RSFT_T(KC_K),            RALT_T(KC_L),            RGUI_T(KC_P),
		KC_Z,                    KC_X,                    KC_C,                    KC_V,                    KC_B,                    KC_N,                    KC_M,                    KC_COMM,                 KC_DOT,                  KC_SLSH,
		                         KC_CAPS,                 KC_ESC,                  LT(navigation, KC_TAB),  LT(numbers, KC_SPC),     LT(symbols, KC_ENT),     LT(media, KC_GRV),       LT(function, KC_QUOT),    KC_DEL
  ),
  [numbers] = LAYOUT_ortho_10x4(
		KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_EQL,   KC_7,     KC_8,     KC_9,     KC_TRNS,  KC_TRNS,
		          KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PLUS,  KC_4,     KC_5,     KC_6,     KC_ASTR,
		KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MINS,  KC_1,     KC_2,     KC_3,     KC_SLSH,
		          KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_COMM,  KC_DOT,   KC_0
  ),
  [navigation] = LAYOUT_ortho_10x4(
		KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
		          KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,
		KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,
		          KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  ),
  [symbols] = LAYOUT_ortho_10x4(
		KC_AT,    KC_CIRC,  KC_MINS,  KC_PLUS,  KC_ASTR,  KC_SLSH,  KC_BSLS,  KC_HASH,  KC_PERC,  KC_TRNS,  KC_COLN,
		          KC_UNDS,  KC_LABK,  KC_RABK,  KC_PIPE,  KC_AMPR,  KC_EXLM,  KC_EQL,   KC_DLR,   KC_SCLN,
		KC_TILD,  KC_TRNS,  KC_LCBR,  KC_LBRC,  KC_LPRN,  KC_RPRN,  KC_RBRC,  KC_RCBR,  KC_TRNS,  KC_QUES,
		          KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  ),
  [function] = LAYOUT_ortho_10x4(
		QK_BOOT,  CG_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_F9,    KC_F10,   KC_F11,   KC_F12,   TO(games),
		QK_RBT,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_TRNS,
		KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_TRNS,
		          KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  ),
  [media] = LAYOUT_ortho_10x4(
		KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_VOLD,     KC_KB_MUTE,  KC_VOLU,     KC_TRNS,     KC_TRNS,
		             KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_MPRV,     KC_MPLY,     KC_MNXT,     KC_TRNS,
		KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_BRID,     KC_TRNS,     KC_BRIU,     KC_TRNS,
		             KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS
  ),
  [games] = LAYOUT_ortho_10x4(
		KC_G,      KC_Q,      KC_W,      KC_E,      KC_R,      KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   TO(base),  KC_LCTL,
		           KC_A,      KC_S,      KC_D,      KC_F,      KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
		KC_LSFT,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
		           KC_1,      KC_2,      KC_3,      KC_SPC,    KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS
  )
};

// clang-format on

#ifdef OLED_ENABLE

// /* 32 * 14 os logos */
// static const char PROGMEM windows_logo[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbc, 0xbc, 0xbe, 0xbe, 0x00, 0xbe, 0xbe, 0xbf, 0xbf, 0xbf, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x0f, 0x0f, 0x00, 0x0f, 0x0f, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

// static const char PROGMEM mac_logo[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xf8, 0xf8, 0xf0, 0xf6, 0xfb, 0xfb, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0f, 0x1f, 0x1f, 0x0f, 0x0f, 0x1f, 0x1f, 0x0f, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

static void print_screen(void) {
    /* Print current mode */
    oled_set_cursor(9, 3);
    if (keymap_config.swap_lctl_lgui) {
        oled_write("mac", false);
    } else {
        oled_write("win", false);
    }

    oled_set_cursor(0, 1);

    /* Print current layer */
    oled_write("LAYER", false);

    oled_set_cursor(6, 1);

    switch (get_highest_layer(layer_state)) {
        case base:
            oled_write("Base", false);
            break;
        case numbers:
            oled_write("Nums", false);
            break;
        case navigation:
            oled_write("Navs", false);
            break;
        case symbols:
            oled_write("Symb", false);
            break;
        case function:
            oled_write("Func", false);
            break;
        case media:
            oled_write("Medi", false);
            break;
        case games:
            oled_write("Game", false);
            break;
        default:
            oled_write("Undef", false);
    }

    /* caps lock */
    oled_set_cursor(0, 3);
    oled_write("CPSLK", host_keyboard_led_state().caps_lock);

    oled_set_cursor(17, 2);
    oled_write(" wpm", false);
    uint8_t n = get_current_wpm();
    char    wpm_str[4];
    oled_set_cursor(18, 3);
    wpm_str[3] = '\0';
    wpm_str[2] = '0' + n % 10;
    wpm_str[1] = '0' + (n /= 10) % 10;
    wpm_str[0] = '0' + n / 10;
    oled_write(wpm_str, false);

}

bool oled_task_user(void) {
    print_screen();
    return false;
}

#endif

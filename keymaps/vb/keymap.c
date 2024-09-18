#include QMK_KEYBOARD_H
#include <stdio.h>

#define KC_COPY LCTL(KC_C) //copy
#define KC_CUT LCTL(KC_X) //cut
#define KC_PSTE LCTL(KC_V)  //paste
#define KC_UNDO LCTL(KC_Z) //undo
#define KC_REDO LCTL(S(KC_Z)) //redo
#define KC_SCRE LSG(KC_S) //screenshot WIN+SHIFT+S
#define KC_CLIPHI LGUI(KC_V) // WIN+V clipboard history

// clang-format off

enum layer_names {
  Base,
  Num,
  Nav,
  Symbols,
  Comm,
  Games,
  GamesExtra,
};


//Tap Dance Declarations
enum {
  TD_GAMES = 0,
  TD_BASE  = 1 
};
//Tap Dance Definitions
tap_dance_action_t  tap_dance_actions[] = {
  [TD_GAMES] = ACTION_TAP_DANCE_LAYER_MOVE(KC_SCLN, Games),
  [TD_BASE]  = ACTION_TAP_DANCE_LAYER_MOVE(KC_SCLN, Base),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [Base] = LAYOUT_ortho_10x4(
		KC_Q,         KC_W,         KC_E,           KC_R,             KC_T,       /**/    KC_Y,                 KC_U,              KC_I,            KC_O,                  KC_BSLS,
		LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D),   LSFT_T(KC_F),     KC_G,       /**/    KC_H,                 LSFT_T(KC_J),      RCTL_T(KC_K),    RALT_T(KC_L),          RGUI_T(KC_SLSH),
		KC_Z,         KC_X,         KC_C,           KC_V,             KC_B,       /**/    KC_N,                 KC_M,              KC_P,            KC_COMM,               KC_DOT,
		              KC_ESC,       LT(Num,KC_GRV), LT(Comm, KC_TAB), KC_SPC,     /**/    LT(Symbols, KC_BSPC), LT(Nav,KC_DEL),    KC_ENT,          TD(TD_GAMES)),
  [Num] = LAYOUT_ortho_10x4(
		XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, /**/  KC_EQL,   KC_7,     KC_8,     KC_9,     KC_TRNS,  
		KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  XXXXXXX, /**/  KC_PLUS,  KC_4,     KC_5,     KC_6,     KC_ASTR,
		XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, /**/  KC_MINS,  KC_1,     KC_2,     KC_3,     KC_SLSH,
		          KC_TRNS,  XXXXXXX,  KC_TRNS,  KC_TRNS, /**/  KC_TRNS,  KC_COMM,  KC_0,     KC_DOT),
  [Nav] = LAYOUT_ortho_10x4(
		XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, /**/ XXXXXXX,  XXXXXXX,  KC_UP  ,  XXXXXXX,  XXXXXXX,
		KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  XXXXXXX, /**/ XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RGHT,  XXXXXXX,
		XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, /**/ XXXXXXX,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END ,
		          KC_TRNS,  XXXXXXX,  KC_TRNS,  KC_TRNS, /**/ KC_TRNS,  KC_TRNS,  KC_TRNS,  XXXXXXX),
  [Symbols] = LAYOUT_ortho_10x4(
		KC_AT,    KC_CIRC,  KC_MINS,  KC_PLUS,  KC_ASTR, /**/ KC_SLSH,  KC_BSLS,  KC_HASH,  KC_PERC,  KC_COLN,
		XXXXXXX,  KC_LABK,  KC_RABK,  KC_PIPE,  KC_AMPR, /**/ KC_EXLM,  KC_EQL,   KC_DLR,   KC_SCLN,  KC_UNDS,
		KC_TILD,  XXXXXXX,  KC_LCBR,  KC_LBRC,  KC_LPRN, /**/ KC_RPRN,  KC_RBRC,  KC_RCBR,  KC_DQUO,  KC_QUOT,
		          KC_TRNS,  XXXXXXX,  KC_TRNS,  KC_TRNS, /**/ KC_TRNS,  KC_TRNS,  KC_TRNS,  XXXXXXX),
  [Comm] = LAYOUT_ortho_10x4(
		QK_BOOT,  KC_CUT ,  KC_COPY,  KC_PSTE,  XXXXXXX,   /**/ XXXXXXX,  KC_F9,    KC_F10,   KC_F11,   KC_F12,
		KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_SCRE,   /**/ XXXXXXX,  KC_F5,    KC_F6,    KC_F7,    KC_F8, 
		XXXXXXX,  KC_UNDO,  XXXXXXX,  KC_REDO,  KC_CLIPHI, /**/ XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    
		          KC_TRNS,  XXXXXXX,  KC_TRNS,  KC_TRNS,   /**/ KC_TRNS,  KC_TRNS,  KC_TRNS,  XXXXXXX
  ),
  [Games] = LAYOUT_ortho_10x4(
		KC_LALT,   KC_Q,      KC_W,            KC_E,      KC_R,    /**/  KC_T,    KC_Y,    KC_U,   KC_I,   KC_O,  
        KC_LCTL,   KC_A,      KC_S,            KC_D,      KC_F,    /**/  KC_G,    KC_H,    KC_J,   KC_K,   KC_L,
		KC_LSFT,   KC_Z,      KC_X,            KC_C,      KC_V,    /**/  KC_B,    KC_N,    KC_M,   KC_P,   XXXXXXX,
		           KC_ESC,    MO(GamesExtra),  KC_TAB,   KC_SPC,   /**/  KC_BSPC, KC_DEL, KC_ENT, TD(TD_BASE)),
  [GamesExtra] = LAYOUT_ortho_10x4(
		KC_1,      KC_2,      KC_3,       KC_4,     KC_5,    /**/  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  
        KC_6,      KC_7,      KC_8,       KC_9,     KC_0,    /**/  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
		KC_LEFT,   KC_DOWN,   KC_UP,   KC_RGHT,  XXXXXXX,    /**/  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
		           XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,    /**/  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX)
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
        case Base:
            oled_write("Base", false);
            break;
        case Num:
            oled_write("Nums", false);
            break;
        case Nav:
            oled_write("Navs", false);
            break;
        case Symbols:
            oled_write("Symb", false);
            break;
        case Comm:
            oled_write("Comm", false);
            break;
        case Games:
            oled_write("Games", false);
            break;
        case GamesExtra:
            oled_write("GamesExtra", false);
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


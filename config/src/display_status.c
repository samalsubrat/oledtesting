```c
/*
 * Minimal OLED display_status.c for ZMK on RP2040-Zero
 * Using SSD1306 128x64 I²C display
 */

#include <zmk/display/status_screen.h>
#include <zmk/display/widgets/battery_status.h>
#include <zmk/display/widgets/layer_status.h>
#include <zmk/display/widgets/output_status.h>
#include <lvgl.h>

static struct zmk_widget_battery_status battery_widget;
static struct zmk_widget_layer_status layer_widget;
static struct zmk_widget_output_status output_widget;

lv_obj_t *zmk_display_status_screen() {
    lv_obj_t *screen = lv_obj_create(NULL);

    /* Battery widget (top-left) */
    lv_obj_t *bat = zmk_widget_battery_status_create(screen, &battery_widget);
    lv_obj_align(bat, LV_ALIGN_TOP_LEFT, 0, 0);

    /* Layer widget (top-center) */
    lv_obj_t *layer = zmk_widget_layer_status_create(screen, &layer_widget);
    lv_obj_align(layer, LV_ALIGN_TOP_MID, 0, 0);

    /* Output widget (top-right, USB/BLE) */
    lv_obj_t *output = zmk_widget_output_status_create(screen, &output_widget);
    lv_obj_align(output, LV_ALIGN_TOP_RIGHT, 0, 0);

    /* Example text label (centered) */
    lv_obj_t *label = lv_label_create(screen);
    lv_label_set_text(label, "RP2040-OLED Test");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

    return screen;
}
```

#ifndef QM_UI_ENTRY_H
#define QM_UI_ENTRY_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>

#include "lvgl/lvgl.h"
#include "qmsd_lang.h"
#include "qmsd_gui.h"
LV_FONT_DECLARE(ali_font_16);

LV_IMG_DECLARE(imgimg_cir_bottom_png);
LV_IMG_DECLARE(imginstructions_png);
LV_IMG_DECLARE(imgbbb_png);
LV_IMG_DECLARE(imgerror_png);
LV_IMG_DECLARE(imgimg_left_light_png);
LV_IMG_DECLARE(imgimg_light_left_png);
LV_IMG_DECLARE(imgimg_light_png);
LV_IMG_DECLARE(imgimg_load_png);
LV_IMG_DECLARE(imgimg_up_line_png);
LV_IMG_DECLARE(imgaaa_png);
LV_IMG_DECLARE(imglight_round_png);

/*
* declear screen_main
*/
extern lv_obj_t * screen_main;
extern lv_obj_t * gauge_4y50;
extern lv_obj_t * image_lKms;
extern lv_obj_t * image_CP93;
extern lv_obj_t * image_nVuv;
extern lv_obj_t * image_kUYv;
void screen_main_build(void);
void screen_main_show(void);
void screen_main_delete(void);

extern lv_obj_t * g_kb;

void qmsd_ui_entry(void);
void qmsd_ui_loop(void);
lv_img_src_t *qmsd_get_img(const char *w_name);
lv_font_t *qmsd_get_font(const char *w_name);

void g_create_kb_ifneeded(void);
void g_show_kb(void);
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*QM_UI_ENTRY_H*/
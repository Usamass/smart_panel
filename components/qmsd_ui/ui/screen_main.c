#include "qmsd_ui_entry.h"
#include "qmsd_internal_ui_cb.h"

lv_obj_t* screen_main;
lv_obj_t* gauge_4y50;
lv_obj_t* image_lKms;
lv_obj_t* image_CP93;
lv_obj_t* image_nVuv;
lv_obj_t* image_kUYv;


    void qmsd_gauge_4y50_create()
{
    gauge_4y50 = lv_gauge_create(screen_main, NULL);
    lv_obj_set_size(gauge_4y50, 304, 304);
    lv_obj_set_pos(gauge_4y50, 11, 2);
    static lv_color_t gauge_4y50_needle_colors[] = {LV_COLOR_MAKE(0x00, 0x00, 0x00)};
    lv_gauge_set_needle_count(gauge_4y50, 1, gauge_4y50_needle_colors);
    
    //set main part style
	lv_obj_set_style_local_scale_end_color(gauge_4y50,LV_GAUGE_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xFF, 0x00, 0x00));
    lv_obj_set_style_local_text_color(gauge_4y50,LV_GAUGE_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x00, 0x00, 0xFF));
    lv_obj_set_style_local_line_color(gauge_4y50,LV_GAUGE_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x00, 0x00, 0xFF));
    lv_obj_set_style_local_bg_color(gauge_4y50,LV_GAUGE_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xFF, 0xFF, 0xFF));
    lv_obj_set_style_local_bg_opa(gauge_4y50,LV_GAUGE_PART_MAIN,LV_STATE_DEFAULT,255);
    lv_obj_set_style_local_line_width(gauge_4y50,LV_GAUGE_PART_MAIN,LV_STATE_DEFAULT,3);
    lv_obj_set_style_local_pad_left(gauge_4y50,LV_GAUGE_PART_MAIN,LV_STATE_DEFAULT,10);
    lv_obj_set_style_local_pad_inner(gauge_4y50,LV_GAUGE_PART_MAIN,LV_STATE_DEFAULT,8);
    //set major part style
    lv_obj_set_style_local_scale_end_color(gauge_4y50,LV_GAUGE_PART_MAJOR,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xFF, 0x00, 0x00));
    lv_obj_set_style_local_text_color(gauge_4y50,LV_GAUGE_PART_MAJOR,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x00, 0x00, 0xFF));
    lv_obj_set_style_local_line_color(gauge_4y50,LV_GAUGE_PART_MAJOR,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x00, 0x00, 0xFF));
    lv_obj_set_style_local_bg_color(gauge_4y50,LV_GAUGE_PART_MAJOR,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xFF, 0xFF, 0xFF));
    lv_obj_set_style_local_bg_opa(gauge_4y50,LV_GAUGE_PART_MAJOR,LV_STATE_DEFAULT,255);
    lv_obj_set_style_local_line_width(gauge_4y50,LV_GAUGE_PART_MAJOR,LV_STATE_DEFAULT,3);
    lv_obj_set_style_local_pad_left(gauge_4y50,LV_GAUGE_PART_MAJOR,LV_STATE_DEFAULT,10);
    lv_obj_set_style_local_pad_inner(gauge_4y50,LV_GAUGE_PART_MAJOR,LV_STATE_DEFAULT,8);
    //set needle style
    lv_obj_set_style_local_bg_color(gauge_4y50,LV_GAUGE_PART_NEEDLE,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x00, 0x00, 0x00));

    lv_gauge_set_range(gauge_4y50, 0, 100);
    lv_gauge_set_critical_value(gauge_4y50, 80);
    lv_gauge_set_value(gauge_4y50, 0, 0);
    qmsd_obj_set_id(gauge_4y50,"gauge_4y50");
}
    
void qmsd_image_lKms_create()
{
    image_lKms = lv_img_create(screen_main, NULL);
    lv_img_set_src(image_lKms, &imgimg_load_png);
#ifdef BLOCKLY_image_lKms_EVENT_HANDLER
    lv_obj_set_event_cb(image_lKms, __qmsd_image_lKms_cb);
#endif
    lv_obj_set_pos(image_lKms, -37, 147);
    qmsd_obj_set_id(image_lKms,"image_lKms");
}
    
void qmsd_image_CP93_create()
{
    image_CP93 = lv_img_create(screen_main, NULL);
    lv_img_set_src(image_CP93, &imginstructions_png);
#ifdef BLOCKLY_image_CP93_EVENT_HANDLER
    lv_obj_set_event_cb(image_CP93, __qmsd_image_CP93_cb);
#endif
    lv_obj_set_pos(image_CP93, 125, 267);
    qmsd_obj_set_id(image_CP93,"image_CP93");
}
    
void qmsd_image_nVuv_create()
{
    image_nVuv = lv_img_create(screen_main, NULL);
    lv_img_set_src(image_nVuv, &imgimg_light_png);
#ifdef BLOCKLY_image_nVuv_EVENT_HANDLER
    lv_obj_set_event_cb(image_nVuv, __qmsd_image_nVuv_cb);
#endif
    lv_obj_set_pos(image_nVuv, 261, 274);
    qmsd_obj_set_id(image_nVuv,"image_nVuv");
}
    
void qmsd_image_kUYv_create()
{
    image_kUYv = lv_img_create(screen_main, NULL);
    lv_img_set_src(image_kUYv, &imgimg_left_light_png);
#ifdef BLOCKLY_image_kUYv_EVENT_HANDLER
    lv_obj_set_event_cb(image_kUYv, __qmsd_image_kUYv_cb);
#endif
    lv_obj_set_pos(image_kUYv, 11, 274);
    qmsd_obj_set_id(image_kUYv,"image_kUYv");
}

static void screen_main_qmsd_cb(lv_obj_t * obj, lv_event_t event, void *data)
{/*
    char *trans;
*/
#ifdef BLOCKLY_screen_main_SCREEN_INIT
    __qmsd_screen_main_init();
#endif
}

static void screen_main_del_cb(lv_obj_t* obj,lv_event_t event)
{
    if(event == LV_EVENT_DELETE)
    {
        screen_main=NULL;
        qmsd_screen_remove("screen_main");
    }
}

void screen_main_build(void)
{
    if(screen_main) return;
    screen_main = lv_obj_create(NULL, NULL);
    lv_obj_qmsd_set_cb(screen_main, screen_main_qmsd_cb);
    lv_obj_set_style_local_bg_color(screen_main,LV_OBJ_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x00, 0x00, 0x00));

    qmsd_gauge_4y50_create();
    qmsd_image_lKms_create();
    qmsd_image_CP93_create();
    qmsd_image_nVuv_create();
    qmsd_image_kUYv_create();
    lv_obj_set_event_cb(screen_main,screen_main_del_cb);
    qmsd_screen_register(screen_main,"screen_main");
}

void screen_main_show(void)
{
    if(!screen_main)
    {
        screen_main_build();
    }
    lv_scr_load(screen_main);
}

void screen_main_delete(void)
{
    if(screen_main)
    {
        lv_obj_del(screen_main);
        screen_main = NULL;
    }
}

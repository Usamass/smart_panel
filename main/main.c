/* LVGL Example project
 * 
 * Basic project to test LVGL on ESP32 based projects.
 *
 * This example code is in the Public Domain (or CC0 licensed, at your option.)
 *
 * Unless required by applicable law or agreed to in writing, this
 * software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
 * CONDITIONS OF ANY KIND, either express or implied.
 */
#include "sdkconfig.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "nvs_flash.h"
#include"qmsd_gui_init.h"
#include "qmsd_control.h"
#include "qmsd_ui_entry.h"
#include "qmsd_ui_cb.h"
#include "qmsd_storage.h"
#include "qmsd_ui_storage.h"
#include "qmsd_msgque.h"
#include "qmsd_screen_config.h"
#include "qmsd_version.h"
#include "qmsd_mod.h"
#include "qmsd_api.h"
#include "qmsd_wifi.h"
#include "qmsd_notifier.h"
#include "net_auth.h"
#include <esp_log.h>


#define TAG "MAIN"
#define NON_BLOCKING_SCAN 1
#define LOCAL_HTTP_SERVER 1

void qmsd_ui_init_cb(void)
{
    /*
     * add some init, lang or other logic init
     */

    qmsd_ui_storage_init("qmsd_ui_data", true);
    qmsd_set_ui_event_cb(qmsd_ui_cb);
    qmsd_ui_entry();
}


static int __qmsd_nb_func(struct qmsd_notifier_block *nb, unsigned int action, void *data)
{
    struct qmsd_wifi_scan_res* scan_res;
    if (action == QMSD_WIFI_STA_GOT_IP) {
        ESP_LOGI(TAG , "GOT_IP_CALLBACK\n");
    }else if (action == QMSD_WIFI_SCAN_DONE) {
        scan_res = (struct qmsd_wifi_scan_res*)data;
        for (int i = 0 ; i < scan_res->number ; i++) {
            ESP_LOGI(TAG , "AP_SSID:%s\n" , scan_res->ap_info[i].ssid);
        }

    }

    return QMSD_NOTIFY_OK;
}

static struct qmsd_notifier_block g_nb = {
    .notifier_call = __qmsd_nb_func,
};

void app_main(void)
{
   
    printf("version: %s\n", QMSD_VERSION);
    qmsd_storage_init();

    qmsd_main_msgque_init(16);
    qmsd_mod_init();
    qmsd_notifier_register(&g_nb);

    // qmsd_server_init(LOCAL_HTTP_SERVER);


    qmsd_set_init_cb(qmsd_ui_init_cb);

    qmsd_gui_init(0, DIR_INPUT);
    qmsd_control_init();
}





    // char* res = NULL;
    // initialize_auth_storage();

    // save_auth_token("AESD1234564");
    // get_auth_token(res);

    // free(res);


    // smart_wifi_init();
    // qmsd_wifi_set_mode(WIFI_MODE_AP);
    // qmsd_wifi_ap_config("esp32" , "esp32#1212");
    // qmsd_server_init(LOCAL_HTTP_SERVER);


    // qmsd_wifi_scan(NULL, NON_BLOCKING_SCAN);
    //qmsd_wifi_sta_config("test-ssid", "test-pwd111", NULL);


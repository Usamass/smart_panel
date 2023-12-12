#include "net_auth.h"
#define TAG "AUTH"

void initialize_auth_storage() {
    qmsd_nvs_init();
}

esp_err_t save_auth_token(char* input)
{
    return qmsd_nvs_set_str(AUTH_NAMESPACE, TOKEN_KEY,input);

}

esp_err_t get_auth_token(char *output)
{
    size_t size = 0;
   if (qmsd_nvs_get_str_size(AUTH_NAMESPACE , TOKEN_KEY , &size) != ESP_OK){
        ESP_LOGI(TAG , "error in setting variable!\n");
        return ESP_FAIL;

    }
    ESP_LOGI(TAG , "size of str: %d" , size);
    output = (char*)malloc(sizeof(char) * size);

    if (qmsd_nvs_get_str(AUTH_NAMESPACE , TOKEN_KEY , output , &size) != ESP_OK){
        ESP_LOGI(TAG , "error in setting variable!\n");
        return ESP_FAIL;
    }
    ESP_LOGI(TAG , "value of str: %s" , output);

    return ESP_OK;

}

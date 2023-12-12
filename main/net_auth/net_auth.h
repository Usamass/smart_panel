
#include <stdio.h>
#include <string.h>
#include <sys/unistd.h>
#include <sys/stat.h>
#include "esp_err.h"
#include "esp_log.h"
#include "qmsd_api.h"

#define AUTH_TOKEN CONFIG_AUTH_TOKEN
#define AUTH_NAMESPACE "token"
#define TOKEN_KEY "key"


void initialize_auth_storage();
esp_err_t save_auth_token(char* input);
esp_err_t get_auth_token(char *output);





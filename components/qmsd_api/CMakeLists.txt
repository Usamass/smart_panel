file(GLOB SOURCES *.c src/*.c src/blufi/*.c)
idf_component_register(SRCS ${SOURCES}
                       INCLUDE_DIRS "include"
                       REQUIRES qmsd_mod nvs_flash esp-tls mqtt esp_http_client esp_http_server esp_https_ota app_update bt)

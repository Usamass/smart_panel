#file(GLOB SOURCES *.c)
file(GLOB_RECURSE SOURCES ./*.c ./custom/*.c ./control/*.c test/*.c net_auth/net_auth.c)
idf_component_register(SRCS ${SOURCES}
                       INCLUDE_DIRS . ./custom ./control ./net_auth
                    #    REQUIRES freertos log spiffs nvs_flash
                       )
# target_compile_definitions(${COMPONENT_LIB} PRIVATE LV_CONF_INCLUDE_SIMPLE=1)

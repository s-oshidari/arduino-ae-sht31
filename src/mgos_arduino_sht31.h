/*
 * Copyright (c) 2014-2017 Cesanta Software Limited
 * All rights reserved
 *
 * Arduino Adafruit DHT library API wrapper
 */

#include "AE_SHT31.h"

#ifdef __cplusplus
extern "C"
{
#endif

AE_SHT31 *mgos_sht31_create(int addr);
void mgos_sht31_close(AE_SHT31 *sht);
void mgos_sht31_begin(AE_SHT31 *sht);
int mgos_sht31_read_temperature(AE_SHT31 *sht);
int mgos_sht31_read_humidity(AE_SHT31 *sht);

#ifdef __cplusplus
}
#endif  /* __cplusplus */

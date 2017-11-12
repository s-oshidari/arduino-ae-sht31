/*
 * Copyright (c) 2014-2017 Cesanta Software Limited
 * All rights reserved
 *
 * Arduino Adafruit DHT library API wrapper
 */

#include <math.h>
#include "mgos_arduino_sht31.h"

#define MGOS_SHT31_RES_FAIL -12700

AE_SHT31 *mgos_sht31_create(int addr) {
  return new AE_SHT31(addr);
}

void mgos_sht31_close(AE_SHT31 *sht31) {
  if (sht31 != nullptr) {
    delete sht31;
    sht31 = nullptr;
  }
}

void mgos_sht31_begin(AE_SHT31 *sht31) {
  if (sht31 == nullptr) return;
  sht31->SoftReset();
  sht31->Heater(0);
}

//int mgos_sht31_read_status(AE_SHT31 *sht31) {
//  if (sht31 == nullptr) return;
//  uint16_t res = sht31->ReadStatus();
//  return isnan(res) ? MGOS_SHT31_RES_FAIL : res;
//}

int mgos_sht31_read_temperature(AE_SHT31 *sht31) {
  if (sht31 == nullptr) return MGOS_SHT31_RES_FAIL;
  sht31->GetTempHum();
  float res = sht31->Temperature();
  return isnan(res) ? MGOS_SHT31_RES_FAIL : round(res * 100.0);
}

int mgos_sht31_read_humidity(AE_SHT31 *sht31) {
  if (sht31 == nullptr) return MGOS_SHT31_RES_FAIL;
  sht31->GetTempHum();
  float res = sht31->Humidity();
  return isnan(res) ? MGOS_SHT31_RES_FAIL : round(res * 100.0);
}

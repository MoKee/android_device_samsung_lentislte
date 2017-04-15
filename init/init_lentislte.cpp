/*
   Copyright (c) 2017, The LineageOS Project. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <stdio.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#include "init_apq8084.h"

void init_target_properties()
{
    std::string platform = property_get("ro.board.platform");
    if (platform != ANDROID_TARGET)
        return;

    std::string bootloader = property_get("ro.bootloader");

    if (bootloader.find("G906S") == 0) {
        /* SKT */
        property_set("ro.build.fingerprint", "samsung/lentislteskt/lentislteskt:6.0.1/MMB29M/G906SKSU1CPL1:user/release-keys");
        property_set("ro.build.description", "lentislteskt-user 6.0.1 MMB29M G906SKSU1CPL1 release-keys");
        property_set("ro.product.model", "SM-G906S");
        property_set("ro.product.device", "lentislteskt");
    } else if (bootloader.find("G906K") == 0) {
        /* KTT */
        property_set("ro.build.fingerprint", "samsung/lentisltektt/lentisltektt:6.0.1/MMB29M/G906KKTU1CPL1:user/release-keys");
        property_set("ro.build.description", "lentisltektt-user 6.0.1 MMB29M G906KKTU1CPL1 release-keys");
        property_set("ro.product.model", "SM-G906K");
        property_set("ro.product.device", "lentisltektt");
    } else if (bootloader.find("G906L") == 0) {
        /* LGT */
        property_set("ro.build.fingerprint", "samsung/lentisltelgt/lentisltelgt:6.0.1/MMB29M/G906LKLU1CPL2:user/release-keys");
        property_set("ro.build.description", "lentisltelgt-user 6.0.1 MMB29M G906LKLU1CPL2 release-keys");
        property_set("ro.product.model", "SM-G906L");
        property_set("ro.product.device", "lentisltelgt");
    } else {
      ERROR("Setting product info FAILED\n");
    }

    std::string device = property_get("ro.product.device");
    INFO("Found bootloader id %s setting build properties for %s device\n", bootloader.c_str(), device.c_str());
}

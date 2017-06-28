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

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#include "init_apq8084.h"

const char *fingerprint[3] = {
  "samsung/lentislteskt/lentislteskt:6.0.1/MMB29M/G906SKSU1CPL1:user/release-keys",
  "samsung/lentisltektt/lentisltektt:6.0.1/MMB29M/G906KKTU1CPL1:user/release-keys",
  "samsung/lentisltelgt/lentisltelgt:6.0.1/MMB29M/G906LKLU1CPL2:user/release-keys"
};

const char *description[3] = {
  "lentislteskt-user 6.0.1 MMB29M G906SKSU1CPL1 release-keys",
  "lentisltektt-user 6.0.1 MMB29M G906KKTU1CPL1 release-keys",
  "lentisltelgt-user 6.0.1 MMB29M G906LKLU1CPL2 release-keys"
};

const char *model[3] = {
  "SM-G906S",
  "SM-G906K",
  "SM-G906L"
};

const char *device[3] =  {
  "lentislteskt",
  "lentisltektt",
  "lentisltelgt"
};

void init_target_properties()
{
    std::string platform = property_get("ro.board.platform");
    if (platform != ANDROID_TARGET)
        return;

    std::string bootloader = property_get("ro.bootloader");

    int idx = 0;

    if (bootloader.find("G906S") == 0)		/* SKT */
	idx = 0;
    else if (bootloader.find("G906K") == 0)	/* KTT */
	idx = 1;
    else if (bootloader.find("G906L") == 0)	/* LGT */
	idx = 2;
    else
	ERROR("Setting product info FAILED\n");

    property_set("ro.build.fingerprint", fingerprint[idx]);
    property_set("ro.build.description", description[idx]);
    property_set("ro.product.model", model[idx]);
    property_set("ro.product.device", device[idx]);

    std::string device = property_get("ro.product.device");
    INFO("Found bootloader id %s setting build properties for %s device\n",
	 bootloader.c_str(), device.c_str());
}

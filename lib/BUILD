config_setting(
    name = "avr-config",
    values = {
        "cpu": "avr",
    },
)

cc_library(
    name = "UnityOutput",
    srcs = glob(["src/*.c"]) +
           select({
               ":avr-config": glob(["src/platform/$(MCU)/*.c"]),
               "//conditions:default": glob(["src/platform/dummy/*.c"]),
           }),
    hdrs = glob(["include/**/*.h"]),
    copts = select({
        ":avr-config": ["-mmcu=$(MCU)"],
        "//conditions:default": [],
    }) + ["-O3"],
    visibility = [
        "//visibility:public",
    ],
)

#include "hidapi/hidapi.h"
#include <stdbool.h>
#include <stdint.h>
#include <wchar.h>

struct vector_t {
  struct hid_device_info device;
};

struct vector_key_t {
};

int vector_usb_devices_qty(void);
void vector_enumerate_devs(void);

int vector_main(const int argc, const char **argv);

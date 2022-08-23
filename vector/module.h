#pragma once
#include "module/def.h"
#include "module/module.h"
#include "module/require.h"
#include "vector/def.h"

module(vector_module) {
  define(vector_module, CLIB_MODULE);
  void  (*list_usb_devices)(void);
  int   (*get_usb_devices_qty)(void);
  pid_t pid;
};

int  vector_module_init(module(vector_module) * exports);
void vector_module_deinit(module(vector_module) * exports);

#include "vector/exports.h"

exports(vector_module) {
  .init                = vector_module_init,
  .deinit              = vector_module_deinit,
  .list_usb_devices    = vector_enumerate_devs,
  .get_usb_devices_qty = vector_usb_devices_qty,
  .pid                 = 0,
};

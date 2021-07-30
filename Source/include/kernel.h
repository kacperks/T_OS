#pragma once

#include <stdint.h>
#include <stddef.h>

#include "print.h"

extern void kernel_init();
extern void boot_code();
extern void kernel_panic();

#define TERMS 7
#define ERR -1
#define SUCCESS 0
#define NULL 0
#define BIT(x) 1<<x
#pragma once

#include <stdint.h>
#include <stddef.h>

#include "print.h"

void kernel_init();

int infolog(char message);
int errorlog(char message);
int warnlog(char message);


#define TERMS 7
#define ERR -1
#define SUCCESS 0
#define NULL 0
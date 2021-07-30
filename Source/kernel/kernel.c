#include "kernel.h"

void kernel_init(){
    infolog("Kernel Init!");
}

void kernel_panic(){
    errorlog("Kernel panic!");
    __asm__("hlt");
}

void boot_code(){
    print_clear();
    print_str("[INFO] Welcome to Tiny OS");
}
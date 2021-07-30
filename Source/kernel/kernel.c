#include "kernel.h"

int infolog(char message){
    print_set_color(PRINT_COLOR_CYAN, PRINT_COLOR_BLACK);
    print_str("[OK]" );
    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
    print_str(message);
    print_str("\n");
    return SUCCESS;
}
int errorlog(char message){
    print_set_color(PRINT_COLOR_RED, PRINT_COLOR_BLACK);
    print_str("[ERR]" );
    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
    print_str(message);
    print_str("\n");
    return SUCCESS;
}
int warnlog(char message){
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    print_str("[WARN]" );
    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
    print_str(message);
    print_str("\n");
    return SUCCESS;
}
void afterboot_init(){
    infolog("Boot completed!");
}
void kernel_init(){
    infolog("Kernel Init completed!");
}
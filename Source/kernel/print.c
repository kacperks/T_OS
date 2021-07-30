#include "print.h"

const static size_t NUM_COLS = 80;
const static size_t NUM_ROWS = 25;

struct Char {
    uint8_t character;
    uint8_t color;
};

struct Char* buffer = (struct Char*) 0xb8000;
size_t col = 0;
size_t row = 0;
uint8_t color = PRINT_COLOR_WHITE | PRINT_COLOR_BLACK << 4;

void clear_row(size_t row) {
    struct Char empty = (struct Char) {
        character: ' ',
        color: color,
    };

    for (size_t col = 0; col < NUM_COLS; col++) {
        buffer[col + NUM_COLS * row] = empty;
    }
}

void print_clear() {
    for (size_t i = 0; i < NUM_ROWS; i++) {
        clear_row(i);
    }
}

void print_newline() {
    col = 0;

    if (row < NUM_ROWS - 1) {
        row++;
        return;
    }

    for (size_t row = 1; row < NUM_ROWS; row++) {
        for (size_t col = 0; col < NUM_COLS; col++) {
            struct Char character = buffer[col + NUM_COLS * row];
            buffer[col + NUM_COLS * (row - 1)] = character;
        }
    }

    clear_row(NUM_COLS - 1);
}

void print_char(char character) {
    if (character == '\n') {
        print_newline();
        return;
    }

    if (col > NUM_COLS) {
        print_newline();
    }

    buffer[col + NUM_COLS * row] = (struct Char) {
        character: (uint8_t) character,
        color: color,
    };

    col++;
}

void print_str(char* str) {
    for (size_t i = 0; 1; i++) {
        char character = (uint8_t) str[i];

        if (character == '\0') {
            return;
        }
        print_char(character);
    }
}

void print_set_color(uint8_t foreground, uint8_t background) {
    color = foreground + (background << 4);
}

void print_set_position(size_t newrow, size_t newcol) {
    if (newrow > NUM_ROWS) { return; }
    if (newcol > NUM_COLS) { return; }
    col = newcol;
    row = newrow;
}

size_t print_get_row() {
    return row;
}
size_t print_get_col() {
    return col;
}

void print_int(int input_int) {
    print_str(convert_int_to_str(input_int));
}
void print_set_color(uint8_t foreground, uint8_t background) {
    color = foreground + (background << 4);
}

int infolog(char message){
    if (print_get_col() != 0) { print_str("\n"); }
    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK); 
    print_str("[  "); print_set_color(PRINT_COLOR_GREEN, PRINT_COLOR_BLACK); print_str("OK"); print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK); print_str("  ] ");
    print_str(message);
    print_str("\n");
    return SUCCESS;
}
int errorlog(char message){
    if (print_get_col() != 0) { print_str("\n"); }
    
    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
    print_str("[");
    print_set_color(PRINT_COLOR_RED, PRINT_COLOR_BLACK);
    print_str("ERR");
    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
    print_str("] ");
    print_str(str);
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
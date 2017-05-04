#include <stdlib.h>
#include <stdio.h>
#include "game.h"

int main(int argc, char* argv[]) {
    int is[10][10];
    int_grid(10, 10, is);
    place_cell(10, 10, is, 0, 0);
    print_grid(10, 10, is);
    return 0;
}

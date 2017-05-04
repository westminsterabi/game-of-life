#include <stdlib.h>
#include <stdio.h>
#include "game.h"

int main(int argc, char* argv[]) {
    int is[10][10];
    int_grid(10, 10, is);
    place_cell(10, 10, is, 0, 0);
    place_cell(10, 10, is, 1, 0);
    place_cell(10, 10, is, 0, 1);
    place_cell(10, 10, is, 0, 9);
    print_grid(10, 10, is);
    printf("%d", check_surroundings(10, 10, is, 0, 0));
    return 0;
}

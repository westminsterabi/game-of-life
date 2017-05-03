#include <stdlib.h>
#include <stdio.h>
#include "game.h"

int main(int argc, char* argv[]) {
    int is[10][10];
    int sidex = atoi(argv[1]);
    int sidey = atoi(argv[2]);
    int i;
    for(i = 3; i < argc; i += 2) {
        place_cell(sidex, sidey, is,
                   atoi(argv[i]), atoi(argv[i + 1]));
    }

    return 0;
}

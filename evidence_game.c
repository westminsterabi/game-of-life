#include <stdlib.h>
#include <stdio.h>
#include "game.h"

int main(int argc, char* argv[]) {
    int sidex = atoi(argv[0]);
    int sidey = atoi(argv[1]);
    int** is = make_grid(sidex, sidey);
    int i;
    for(i = 0; i < argc; i += 2) {
        place_cell(is, sidex, sidey,
                   atoi(argv[i]), atoi(argv[i + 1]));
    }
    play(is, sidex, sidey);
    return 0;
}

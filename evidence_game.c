#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "game.h"

int main(int argc, char* argv[]) {
    int h = 24;
    int w = 80;
    int i, points[argc / 2], j = 0;
    if (argc > 1){
        for(i = 1; i < argc; i++) {
            if(i + 1 > argc) {
                break;
            }
            if(!strcmp("-w", argv[i])) {
                w = atoi(argv[i + 1]);
                i++;
            } else if (!strcmp("-h", argv[i])) {
                h = atoi(argv[i + 1]);
                i++;
            } else {
                points[j] = atoi(argv[i + 1]);
                j++;
                points[j] = atoi(argv[i]);
                j++;
                i++;
            }
        }
    }
    int is[h][w];
    int_grid(w, h, is);
    int k;
    for(k = 0; k < j ; k += 2) {
        place_cell(w, h, is, points[k], points[k + 1]);
    }
    play(w, h, is);
    return 0;
}

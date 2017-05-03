/* the game of life
 * coded with love by abi hunter
 */

#include <stdio.h>
#include <stdlib.h>

int** make_grid(int x, int y) {
    int** is = (int**)malloc(sizeof(int*) * y);
    int j;
    for(j = 0; j < y; j++) {
        is[j] = (int*)malloc(sizeof(int) * x);
    }
    return is;
}

/* takes two integers and places a cell at those coords */
void place_cell(int** is, int sidex, int sidey, int x, int y) {
    if(x >= sidex || y >= sidey) {
        fprintf(stderr, "place_cell: out of grid range");
        exit(1);
    }
    is[y][x] = 1;
}

int check_surroundings(int** is, int sidex,
                       int sidey, int x, int y) {
    int y_less = y - 1;
    if(y == 0) {
        y_less = sidey - 1;
    }
    int y_more = y + 1;
    if(y == sidey - 1) {
        y_more = 0;
    }
    int x_less = x - 1;
    if(x == 0) {
        x_less = sidex - 1;
    }
    int x_more = x + 1;
    if(x == sidex - 1) {
        x_more = 0;
    }
    int p = is[y_less][x_less] +
        is[y_less][x] +
        is[y_less][x_more] +
        is[y][x_less] +
        is[y][x_more] +
        is[y_more][x_less] +
        is[y_more][x_less] +
        is[y_more][x_more];
    return p;
}

void change_condition(int** is,
                      int sidex, int sidey, int x, int y) {
    int* state = &is[y][x];
    int surr = check_surroundings(is, sidex, sidey, x, y);
    if(surr > 3) {
        *state = 0;
    } else if(surr == 3 || surr == 2) {
        *state = 1;
    } else {
        *state = 0;
    }
}

void print_grid(int** is, int sidex, int sidey) {
    int i, j;
    for(i = 0; i < sidey; i++) {
        for(j = 0; j < sidex; j++) {
            if(is[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void new_generation(int** is, int sidex, int sidey) {
    int i, j;
    for(i = 0; i < sidey; i++) {
        for(j = 0; j < sidex; j++) {
            change_condition(is, sidex, sidey, j, i);
        }
    }
}

void play(int** is, int sidex, int sidey) {
    int i = 0;
    while(i < 100) {
        new_generation(is, sidex, sidey);
        print_grid(is, sidex, sidey);
        i++;
    }
}

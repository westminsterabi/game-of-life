#include <stdio.h>
#include <stdlib.h>

/* takes two integers and places a cell at those coords */
void place_cell(int sidex, int sidey, int is[][sidex], int r, int c) {
    if(r >= sidex || c >= sidey) {
        fprintf(stderr, "place_cell: out of grid range\n");
        exit(1);
    }
    is[r][c] = 1;
}

int check_surroundings(int sidex,
                       int sidey, int is[][sidex], int x, int y) {
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

void change_condition(int sidex, int sidey, int is[][sidex], int x, int y) {
    int* state = &is[y][x];
    int surr = check_surroundings(sidex, sidey, is, x, y);
    if(surr > 3) {
        *state = 0;
    } else if(surr == 3 || surr == 2) {
        *state = 1;
    } else {
        *state = 0;
    }
}

void print_grid(int sidex, int sidey, int is[][sidex]) {
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

void new_generation(int sidex, int sidey, int is[][sidex]) {
    int i, j;
    for(i = 0; i < sidey; i++) {
        for(j = 0; j < sidex; j++) {
            change_condition(sidex, sidey, is, j, i);
        }
    }
}

void play(int sidex, int sidey, int is[][sidex]) {
    int i = 0;
    while(i < 100) {
        new_generation(sidex, sidey, is);
        print_grid(sidex, sidey, is);
        i++;
    }
}

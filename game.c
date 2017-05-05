#include <stdio.h>
#include <stdlib.h>

void int_grid (int sidex, int sidey, int is[][sidex]) {
    int j, i;
    for(i = 0; i < sidey; i++) {
        for(j = 0; j < sidex; j++) {
            is[i][j] = 0;
        }
    }
}

/* takes two integers and places a cell at those coords */
void place_cell(int sidex, int sidey, int is[][sidex], int r, int c) {
    if(c >= sidex || r >= sidey) {
        fprintf(stderr, "place_cell: out of grid range\n");
        exit(1);
    }
    is[r][c] = 1;
}

/* check around the cell and return the number of populated cells
around it */
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
        is[y_more][x] +
        is[y_more][x_less] +
        is[y_more][x_more];
    return p;
}

void change_condition(int sidex, int sidey, int is[][sidex],
                      int par[][sidex], int r, int c) {
    int surr = check_surroundings(sidex, sidey, is, r, c);
    if(surr > 3) {
        par[r][c] = 0;
    } else if(surr == 3) {
        par[r][c] = 1;
    } else if (surr == 2 && is[r][c] == 1) {
        par[r][c] = 1;
    } else {
        par[r][c] = 0;
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
    for(i = 0; i < sidex; i++) {
        printf("-");
    }
    printf("\n");
}

void new_generation(int sidex, int sidey, int is[][sidex],
                    int parallel[][sidex]) {
    int i, j;
    for(i = 0; i < sidey; i++) {
        for(j = 0; j < sidex; j++) {
            change_condition(sidex, sidey, is, parallel, j, i);
        }
    }
}

void copy_array(int sidex, int sidey, int src[][sidex], int new[][sidex]) {
    int i, k;
    for(i = 0; i < sidey; i++) {
        for(k = 0; k < sidex; k++) {
            new[i][k] = src[i][k];
        }
    }
}

void play(int sidex, int sidey, int is[][sidex]) {
    int i = 0;
    int is_odd[sidey][sidex];
    copy_array(sidex, sidey, is, is_odd);
    while(i < 10) {
        new_generation(sidex, sidey, is, is_odd);
        print_grid(sidex, sidey, is);
        new_generation(sidex, sidey, is_odd, is);
        print_grid(sidex, sidey, is_odd);
        i++;
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

void int_grid (int w, int h, int is[h][w]) {
    int j, i;
    for(i = 0; i < h; i++) {
        for(j = 0; j < w; j++) {
            is[i][j] = 0;
        }
    }
}

/* takes two integers and places a cell at those coords */
void place_cell(int w, int h, int is[][w], int r, int c) {
    if(c >= w || r >= h) {
        fprintf(stderr, "place_cell: out of grid range\n");
        exit(1);
    }
    is[r][c] = 1;
}

/* check around the cell and return the number of populated cells
around it */
int check_surroundings(int w,
                       int h, int is[][w], int x, int y) {
    int y_less = y - 1;
    if(y == 0) {
        y_less = h - 1;
    }
    int y_more = y + 1;
    if(y == h - 1) {
        y_more = 0;
    }
    int x_less = x - 1;
    if(x == 0) {
        x_less = w - 1;
    }
    int x_more = x + 1;
    if(x == w - 1) {
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

void change_condition(int w, int h, int is[][w],
                      int par[][w], int c, int r) {
    int surr = check_surroundings(w, h, is, c, r);
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

void print_grid(int w, int h, int is[][w]) {
    int i, j;
    for(i = 0; i < h; i++) {
        for(j = 0; j < w; j++) {
            if(is[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    for(i = 0; i < w; i++) {
        printf("-");
    }
    printf("\n");
}

void new_generation(int w, int h, int is[][w],
                    int parallel[][w]) {
    int r, c;
    for(r = 0; r < h; r++) {
        for(c = 0; c < w; c++) {
            change_condition(w, h, is, parallel, c, r);
        }
    }
}

void copy_array(int w, int h, int src[][w], int new[][w]) {
    int i, k;
    for(i = 0; i < h; i++) {
        for(k = 0; k < w; k++) {
            new[i][k] = src[i][k];
        }
    }
}

void play(int w, int h, int is[][w]) {
    int i = 0;
    int is_odd[h][w];
    copy_array(w, h, is, is_odd);
    while(i < 10) {
        new_generation(w, h, is, is_odd);
        print_grid(w, h, is);
        new_generation(w, h, is_odd, is);
        print_grid(w, h, is_odd);
        i++;
    }
}

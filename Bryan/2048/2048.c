#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROW 5
#define MAX_COL 5
void print_map(int map[MAX_ROW][MAX_COL]);
void edit_map(int map[MAX_ROW][MAX_COL], char command);
void do_move_a(int map[MAX_ROW][MAX_COL], int row, int col, int number);
void do_move_w(int map[MAX_ROW][MAX_COL], int row, int col, int number);
void do_move_d(int map[MAX_ROW][MAX_COL], int row, int col, int number);
void do_move_s(int map[MAX_ROW][MAX_COL], int row, int col, int number);

void combine_numbers(int map[MAX_ROW][MAX_COL], char command);
void combine_numbers_a(int map[MAX_ROW][MAX_COL]);
void combine_numbers_w(int map[MAX_ROW][MAX_COL]);
void combine_numbers_s(int map[MAX_ROW][MAX_COL]);
void combine_numbers_d(int map[MAX_ROW][MAX_COL]);


int main (void) {
    int map[MAX_ROW][MAX_COL] = {0};
    map[1][1] = 1;
    map[1][3] = 3;
    map[1][4] = 3;
    map[3][4] = 2;
    map[2][2] = 4;
    map[4][1] = 1;
    map[4][4] = 1;
    map[0][2] = 2;
    map[4][0] = 2;

    print_map(map);
    char command;
    
    while (1) {
        printf("Enter your command: ");
        scanf(" %c", &command);
        int *changed = 0;
        edit_map(map, command);
        //print_map(map);

        combine_numbers(map, command);

        //grow_new_numbers();
        edit_map(map, command);

        
        print_map(map);
    }
    return 0;
}



void print_map(int map[MAX_ROW][MAX_COL]) {
    for (int i = 0; i < MAX_ROW; i++) {
        for (int j = 0; j < MAX_COL; j++) {
            printf(" %d", map[i][j]);
        }
        printf("\n");
    }
}


void edit_map(int map[MAX_ROW][MAX_COL], char command) {
    if (command == 'a') {
        for (int i = 0; i < MAX_ROW; i++) {
            for (int j = 0; j < MAX_COL; j++) {
                do_move_a(map, i, j, 0);
                

            }
        }
    } else if (command == 'w') {
        for (int i = 0; i < MAX_ROW; i++) {
            for (int j = 0; j < MAX_COL; j++) {
                do_move_w(map, i, j, 0);
            }
        }
    } else if (command == 'd') {
       for (int i = 0; i < MAX_ROW; i++) {
            for (int j = MAX_COL - 1; j >= 0; j--) {
                do_move_d(map, i, j, MAX_COL - 1);
            }
        }
    } else if (command == 's') {
        for (int i = MAX_ROW - 1; i >= 0; i--) {
            for (int j = 0; j < MAX_COL; j++) {
                do_move_s(map, i, j, MAX_ROW - 1);
            }
        }
    }
}

void do_move_a(int map[MAX_ROW][MAX_COL], int row, int col, int number) {
    if (number < col) {
        if (map[row][number] == 0) {
            map[row][number] = map[row][col];
            map[row][col] = 0;

            return;
        } else {
            do_move_a(map, row, col, number + 1);
        }
    } else {
        return;
    }
}

 
void do_move_w(int map[MAX_ROW][MAX_COL], int row, int col, int number) {
    if (number < row) {
        if (map[number][col] == 0) {
            map[number][col] = map[row][col];
            map[row][col] = 0;
            return;
        } else {
            do_move_w(map, row, col, number + 1);
        }
    } else {
        return;
    }
}


void do_move_d(int map[MAX_ROW][MAX_COL], int row, int col, int number) {
    if (number > col) {
        if (map[row][number] == 0) {
            map[row][number] = map[row][col];
            map[row][col] = 0;
            return;
        } else {
            do_move_d(map, row, col, number - 1);
        }
    } else {
        return;
    }
}


void do_move_s(int map[MAX_ROW][MAX_COL], int row, int col, int number) {
    if (number > row) {
        if (map[number][col] == 0) {
            map[number][col] = map[row][col];
            map[row][col] = 0;
            return;
        } else {
            do_move_s(map, row, col, number - 1);
        }
    } else {
        return;
    }
}

void combine_numbers(int map[MAX_ROW][MAX_COL], char command) {
    if (command == 'a') {
        combine_numbers_a(map);
    } else if (command == 'w') {
        combine_numbers_w(map);
    } else if (command == 's') {
        combine_numbers_s(map);
    } else {
        combine_numbers_d(map);
    }
}
void combine_numbers_a(int map[MAX_ROW][MAX_COL]) {
    for (int i = 0; i < MAX_ROW; i++) {
        for (int j = 1; j < MAX_COL; j++) {
            if ((map[i][j] == map[i][j - 1]) && (map[i][j] != 0) && (map[i][j - 1] != 0)) {
                map[i][j - 1]++;
                map[i][j] = 0;
            }
        }
    }
}


void combine_numbers_w(int map[MAX_ROW][MAX_COL]) {
    for (int i = 1; i < MAX_ROW; i++) {
        for (int j = 0; j < MAX_COL; j++) {
            if ((map[i][j] == map[i - 1][j]) && (map[i][j] != 0) && (map[i - 1][j] != 0)) {
                map[i - 1][j]++;
                map[i][j]  = 0;
            }
        }
    }
}

void combine_numbers_s(int map[MAX_ROW][MAX_COL]) {
    for (int i = MAX_ROW - 2; i >= 0; i--) {
        for (int j = 0; j < MAX_COL; j++) {
            if ((map[i][j] == map[i + 1][j]) && (map[i][j] != 0) && (map[i + 1][j] != 0)) {
                map[i + 1][j]++;
                map[i][j] = 0;
            }
        }
    }
}

void combine_numbers_d(int map[MAX_ROW][MAX_COL]) {
    for (int i = 0; i < MAX_ROW; i++) {
        for (int j = MAX_COL - 2; j >= 0; j--) {
            if ((map[i][j] == map[i][j + 1]) && (map[i][j] != 0) && (map[i][j + 1] != 0)) {
                map[i][j + 1]++;
                map[i][j] = 0;
            }
        }
    }
}
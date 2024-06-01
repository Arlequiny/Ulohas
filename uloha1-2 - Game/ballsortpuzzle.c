#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ballsortpuzzle.h"

void generator(const int rows, const int columns, char field[rows][columns])
{
    int col1, col2;
    col1 = rand() % columns;
    col2 = rand() % columns;

    while(col1 == col2){
        col2 = rand() % columns;
    }

    for(int i = 0; i < rows; i++){
        field[i][col1]=' ';
        field[i][col2]=' ';
    }

    char symbols[10]={'*','+','&','^','$','#','%','-','=','@'};
    int countArr[10]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for(int i = 0; i < rows; i++){
        for(int j = 0; j<columns; j++){
            if (j == col1 || j == col2) { continue; }
            
            int index = rand() % (columns-2);

            if(countArr[index] < rows){
                field[i][j] = symbols[index];
                countArr[index]++;
            } else {
                while(countArr[index] >= rows){
                    index = rand() % (columns-2);
                }

                field[i][j] = symbols[index];
                countArr[index]++;
            }
        }
    }
}

void down_possible(const int rows, const int columns, char field[rows][columns], int x, int y)
{
    // 1) Пустая колонка
    // 2) Есть ли место в колонке
    // 3) совпадают ли символы
    // 4) чтобы символы не зависали в воздухе
    // 5) x и y одинаковые - !complete!
    // 6) есть ли такие координаты - !complete!
    if (x == y || x > columns || y > columns || x < 1 || y < 1) {
        printf("\n < ERROR: Invalid coordinates! >\n\n");
    } else {
        // get symbol
        char tmp = '\0';
        int getIndex = -1;
        for (int i = 0; i < rows; i++){
            if (field[i][x - 1] != ' ') {
                tmp = field[i][x - 1];
                field[i][x - 1] = ' ';
                getIndex = i;
                break;
            }
        }
        if (tmp == '\0') {
            printf("\n < ERROR: Column for get is empty! >\n\n");
        } else {
            if (field[rows-1][y-1] == ' ') {
                // full column is empty
                field[rows-1][y-1] = tmp;
            } else if (field[0][y-1] != ' ') {
                printf("\n < ERROR: Column for set is full! >\n\n");
                field[getIndex][x - 1] = tmp;
            } else {
                for (int i = 1; i < rows; i++) {
                    if (field[i][y-1] != ' ' && field[i][y-1] == tmp) {
                        field[i-1][y-1] = tmp;
                        break;
                    } else if (field[i][y-1] != ' ' && field[i][y-1] != tmp) {
                        field[getIndex][x - 1] = tmp;
                        break;
                    }
                }
            }
        }
    }
}

void game_field(const int rows, const int columns, char field[rows][columns]){

    printf("  ");

    for(int j = 0; j < columns; j++){
        printf("\\   /  ");
    }

    printf("\n");

    for (int i = 0; i < rows; i++){
        printf("%d ", i+1);

        for (int j = 0; j < columns; j++){
            printf("| %c |  ",field[i][j]);
        }

        printf("\n");

    }

    printf("  ");

    for(int j = 0; j < columns; j++){
        printf("\\___/  ");
    }

    printf("\n ");

    for(int j = 0; j < columns; j++){
        printf("   %d   ", j+1);
    }

    printf("\n");
}

bool check(const int rows, const int columns, char field[rows][columns]){
    for(int i = 0; i < columns; i++){
        for(int j = 1; j < rows; j++){
            if(field[0][i] != field[j][i]){
                return 0;
            }
        }
    }
    return 1;
}

void ball_sort_puzzle(){

    int rows, cols;

    srand(time(NULL));
    printf("Enter rows: ");
    scanf("%d", &rows);
 
    printf("Enter cols: ");
    scanf("%d", &cols);

    printf("\n");
 
    char field[rows][cols];
 
    generator(rows, cols, field);
    game_field(rows, cols, field);

    int x, y;
    while (1)
    {
        printf("\nEnter cho: ");
        scanf("%d", &x);
        printf("Enter kuda: ");
        scanf("%d", &y);

        printf("\n");

        down_possible(rows, cols, field, x, y);
        game_field(rows, cols, field);
        if(check(rows, cols, field)){ printf("YOU WON!  :D\n"); break; }
        printf("\n-----------------------------------------------------------------");
    }
}
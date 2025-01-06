#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void generate_list(char list[][11], int n) {
    srand(time(NULL)); // seed the random number generator
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            list[i][j] = (rand() % 2) ? '1' : '0';
        }
        list[i][n] = '\0'; 
    }
}

void diagonalize(char list[][11], char diagonal[], int n) {
    for (int i = 0; i < n; i++) {
        diagonal[i] = (list[i][i] == '0') ? '1' : '0'; // flip the bit
    }
    diagonal[n] = '\0';
}

int is_in_list(char list[][11], char diagonal[], int n) {
    for (int i = 0; i < n; i++) {
        if (strcmp(list[i], diagonal) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int n = 10; // size of the list and number of binary digits
    char list[10][11]; // list of binary strings (10 strings of 10 digits each)
    char diagonal[11]; // diagonal number

    generate_list(list, n);
    printf("generated binary list:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: %s\n", i + 1, list[i]);
    }

    diagonalize(list, diagonal, n);
    printf("\ndiagonal number (not in the list):\n%s\n", diagonal);

    if (is_in_list(list, diagonal, n)) {
        printf("diagonal number is in the list. whoops hehe\n");
    } else {
        printf("diagonal number is NOT in the list. Cantor wins!\n");
    }

    return 0;
}
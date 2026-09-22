# Diagonal Difference

Direct HackerRank access link:
https://www.hackerrank.com/challenges/diagonal-difference/problem

## Solution in C

This program reads the square matrix, sums the values on both diagonals, and prints the absolute difference.

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    scanf("%d", &n);

    int matrix[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    long long primary_diagonal = 0;
    long long secondary_diagonal = 0;

    for (int i = 0; i < n; i++) {
        primary_diagonal += matrix[i][i];
        secondary_diagonal += matrix[i][n - 1 - i];
    }

    printf("%lld\n", llabs(primary_diagonal - secondary_diagonal));
    return 0;
}
```

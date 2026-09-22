# Sparse Arrays

Direct HackerRank access link:
https://www.hackerrank.com/challenges/sparse-arrays/problem

## Solution in C

This version stores the input strings, checks each query against all strings, and prints the count for each query.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int n;
    scanf("%d", &n);

    char **strings = malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        strings[i] = malloc(1001 * sizeof(char));
        scanf("%1000s", strings[i]);
    }

    int q;
    scanf("%d", &q);

    char **queries = malloc(q * sizeof(char *));
    for (int i = 0; i < q; i++) {
        queries[i] = malloc(1001 * sizeof(char));
        scanf("%1000s", queries[i]);
    }

    for (int i = 0; i < q; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (strcmp(strings[j], queries[i]) == 0) {
                count++;
            }
        }
        printf("%d\n", count);
    }

    for (int i = 0; i < n; i++) {
        free(strings[i]);
    }
    free(strings);

    for (int i = 0; i < q; i++) {
        free(queries[i]);
    }
    free(queries);

    return 0;
}
```

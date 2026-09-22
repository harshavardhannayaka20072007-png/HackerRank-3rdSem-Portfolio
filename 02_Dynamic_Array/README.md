# Dynamic Array

Direct HackerRank access link:
https://www.hackerrank.com/challenges/dynamic-array/problem

## Solution in C

This implementation uses a dynamic vector for each sequence and applies the required XOR-based indexing logic.

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} Vector;

void init_vector(Vector *v) {
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

void push_back(Vector *v, int value) {
    if (v->size == v->capacity) {
        int new_capacity = (v->capacity == 0) ? 1 : v->capacity * 2;
        int *new_data = realloc(v->data, new_capacity * sizeof(int));
        if (new_data == NULL) {
            exit(1);
        }
        v->data = new_data;
        v->capacity = new_capacity;
    }
    v->data[v->size++] = value;
}

int main(void) {
    int n, q;
    scanf("%d %d", &n, &q);

    Vector *sequences = malloc(n * sizeof(Vector));
    for (int i = 0; i < n; i++) {
        init_vector(&sequences[i]);
    }

    int last_answer = 0;
    for (int i = 0; i < q; i++) {
        int type, x, y;
        scanf("%d %d %d", &type, &x, &y);

        int index = (x ^ last_answer) % n;

        if (type == 1) {
            push_back(&sequences[index], y);
        } else {
            last_answer = sequences[index].data[y % sequences[index].size];
            printf("%d\n", last_answer);
        }
    }

    for (int i = 0; i < n; i++) {
        free(sequences[i].data);
    }
    free(sequences);
    return 0;
}
```

#include <stdio.h>
#include <stdlib.h>

// Structure to represent each sequence in the 2D array
typedef struct {
    int *data;
    int size;
    int capacity;
} Sequence;

int* dynamicArray(int n, int queries_rows, int queries_columns, int** queries, int* result_count) {
    Sequence *arr = malloc(n * sizeof(Sequence));
    for (int i = 0; i < n; i++) {
        arr[i].data = NULL;
        arr[i].size = 0;
        arr[i].capacity = 0;
    }

    int *answers = NULL;
    int ans_size = 0;
    int ans_capacity = 0;
    int lastAns = 0;

    for (int i = 0; i < queries_rows; i++) {
        int type = queries[i][0];
        int x = queries[i][1];
        int y = queries[i][2];

        int idx = (x ^ lastAns) % n;

        if (type == 1) {
            if (arr[idx].size >= arr[idx].capacity) {
                arr[idx].capacity = arr[idx].capacity == 0 ? 1 : arr[idx].capacity * 2;
                arr[idx].data = realloc(arr[idx].data, arr[idx].capacity * sizeof(int));
            }
            arr[idx].data[arr[idx].size++] = y;
        } else if (type == 2) {
            int element_idx = y % arr[idx].size;
            lastAns = arr[idx].data[element_idx];

            if (ans_size >= ans_capacity) {
                ans_capacity = ans_capacity == 0 ? 1 : ans_capacity * 2;
                answers = realloc(answers, ans_capacity * sizeof(int));
            }
            answers[ans_size++] = lastAns;
        }
    }

    for (int i = 0; i < n; i++) {
        free(arr[i].data);
    }
    free(arr);

    *result_count = ans_size;
    return answers;
}

// HackerRank's main function to handle input/output
int main() {
    int n, q;
    if (scanf("%d %d", &n, &q) != 2) return 0;

    int **queries = malloc(q * sizeof(int*));
    for (int i = 0; i < q; i++) {
        queries[i] = malloc(3 * sizeof(int));
        scanf("%d %d %d", &queries[i][0], &queries[i][1], &queries[i][2]);
    }

    int result_count = 0;
    int *result = dynamicArray(n, q, 3, queries, &result_count);

    for (int i = 0; i < result_count; i++) {
        printf("%d\n", result[i]);
    }

    // Clean up
    for (int i = 0; i < q; i++) {
        free(queries[i]);
    }
    free(queries);
    free(result);

    return 0;
}
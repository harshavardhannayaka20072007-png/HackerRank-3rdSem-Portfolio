#include <stdio.h>
#include <stdlib.h>

int *create_array(int n, int initial_value) {
    int *array = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        array[i] = initial_value;
    }
    return array;
}

int get_element(int *array, int index) {
    return array[index];
}

void set_element(int *array, int index, int value) {
    array[index] = value;
}

void free_array(int *array) {
    free(array);
}

int main(void) {
    int n, initial_value;
    scanf("%d %d", &n, &initial_value);

    int *array = create_array(n, initial_value);

    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    int index, value;
    scanf("%d %d", &index, &value);
    set_element(array, index, value);

    printf("%d\n", get_element(array, index));

    free_array(array);
    return 0;
}

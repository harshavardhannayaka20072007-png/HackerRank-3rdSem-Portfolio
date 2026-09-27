#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int n, q;
    scanf("%d", &n);

    char **strings = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        strings[i] = (char *)malloc(1001 * sizeof(char));
        scanf("%s", strings[i]);
    }

    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        char query[1001];
        scanf("%s", query);

        int count = 0;
        for (int j = 0; j < n; j++) {
            if (strcmp(strings[j], query) == 0) {
                count++;
            }
        }

        printf("%d\n", count);
    }

    for (int i = 0; i < n; i++) {
        free(strings[i]);
    }
    free(strings);
    return 0;
}

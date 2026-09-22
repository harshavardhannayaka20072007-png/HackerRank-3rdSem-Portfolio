#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* matchingStrings(int stringList_count, char** stringList, int queries_count, char** queries, int* result_count) {
    int* results = malloc(queries_count * sizeof(int));
    
    for (int i = 0; i < queries_count; i++) {
        int count = 0;
        for (int j = 0; j < stringList_count; j++) {
            if (strcmp(queries[i], stringList[j]) == 0) {
                count++;
            }
        }
        results[i] = count;
    }
    
    *result_count = queries_count;
    return results;
}

int main() {
    int stringList_count;
    scanf("%d", &stringList_count);
    
    char** stringList = malloc(stringList_count * sizeof(char*));
    for (int i = 0; i < stringList_count; i++) {
        stringList[i] = malloc(100 * sizeof(char));
        scanf("%s", stringList[i]);
    }
    
    int queries_count;
    scanf("%d", &queries_count);
    
    char** queries = malloc(queries_count * sizeof(char*));
    for (int i = 0; i < queries_count; i++) {
        queries[i] = malloc(100 * sizeof(char));
        scanf("%s", queries[i]);
    }
    
    int result_count = 0;
    int* res = matchingStrings(stringList_count, stringList, queries_count, queries, &result_count);
    
    for (int i = 0; i < result_count; i++) {
        printf("%d\n", res[i]);
    }
    
    // Free memory
    for (int i = 0; i < stringList_count; i++) free(stringList[i]);
    free(stringList);
    for (int i = 0; i < queries_count; i++) free(queries[i]);
    free(queries);
    free(res);
    
    return 0;
}
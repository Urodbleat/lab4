#include <stdlib.h>
#include "my_string.h"
#define DELIM " "

#include <stdio.h>

void quicksort(char *token, int left, int right) {
    if (left < right) {
        int i = left, j = right;
        char pivot = token[(left + right) / 2];
        while (i <= j) {
            while (token[i] < pivot) i++;
            while (token[j] > pivot) j--;

            if (i <= j) {
                char tmp = token[i];
                token[i] = token[j];
                token[j] = tmp;
                i++;
                j--;
            }
        }

        quicksort(token, left, j);
        quicksort(token, i, right);
    }
}

char *sorting(char *token) {
    int len = lens(token);
    char *result = (char *)malloc((len + 1) * sizeof(char));

    if (result == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    quicksort(token, 0, len - 1);

    int resultIndex = 0;
    for (int j = 0; j < len; ++j) {
        if (j == 0 || token[j] != token[j - 1]) {
            result[resultIndex++] = token[j];
        }
    }

    result[resultIndex] = '\0';
    return result;
}

char **comparison(char *s, int *numLines) {
    char *token = custom_strtok(s, DELIM);
    int size = 1;
    char **result = (char **)malloc(size * sizeof(char *));

    if (result == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    int resultIndex = 0;

    while (token != NULL) {
        int wordLength = lens(token);

        result = (char **)realloc(result, (resultIndex + 1) * sizeof(char *));

        if (result == NULL) {
            perror("Memory allocation error");
            exit(EXIT_FAILURE);
        }

        result[resultIndex] = sorting(token);
        token = custom_strtok(NULL, DELIM);
        resultIndex++;
    }

    *numLines = resultIndex;
    return result;
}

void final(char **resultArray, int lines, int *result, char *str2) {
    int resultindex = 0;
    int reallocSize = 10;

    for (int i = 0; i < lines; ++i) {
        int count = 0;
        for (int j = 0; j < lines; ++j) {
            if (i != j && my_strcmp(resultArray[i], resultArray[j]) == 0) {
                count += 1;
            }
        }
        if (count > 0) {
            if (resultindex % reallocSize == 0) {
                result = realloc(result, (resultindex + reallocSize) * sizeof(int));
                if (result == NULL) {
                    perror("Memory allocation error");
                    exit(EXIT_FAILURE);
                }
            }
            result[resultindex] = i;
            resultindex++;
        }
    }

    char *token = custom_strtok(str2, DELIM);
    int count = 0;
    char **result2 = NULL;
    int size = 0;

    while (token != NULL) {
        int count2 = 0;
        for (int i = 0; i < resultindex; ++i) {
            if (count == result[i]) {
                count2 += 1;
                break;
            }
        }
        if (!count2) {
            result2 = realloc(result2, (size + 1) * sizeof(char *));
            if (result2 == NULL) {
                perror("Memory allocation error");
                exit(EXIT_FAILURE);
            }
            result2[size] = custom_strdup(token);
            size += 1;
        }
        token = custom_strtok(NULL, DELIM);
        count += 1;
    }

    int start = (size > 4) ? size - 4 : 0;
    for (int i = start; i < size; ++i) {
        printf("%s ", result2[i]);
    }
    printf("\n");

    for (int i = 0; i < lines; ++i) {
        free(resultArray[i]);
    }
    free(resultArray);
    free(result);

    for (int i = 0; i < size; ++i) {
        free(result2[i]);
    }
    free(result2);
}












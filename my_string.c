#include <stdlib.h>
#include <stdio.h>
char *custom_strdup(const char *str) {
    if (str == NULL) {
        return NULL;
    }
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    char *duplicate = (char *)malloc((length + 1) * sizeof(char));

    if (duplicate == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i <= length; i++) {
        duplicate[i] = str[i];
    }

    return duplicate;
}

char *custom_strtok(char *str, const char *delim) {
    static char *lastToken = NULL;

    if (str != NULL) {
        lastToken = str;
    } else if (lastToken == NULL || *lastToken == '\0') {
        return NULL;
    }
    while (*lastToken != '\0') {
        int isDelimiter = 0;
        const char *d = delim;
        while (*d != '\0') {
            if (*lastToken == *d) {
                isDelimiter = 1;
                break;
            }
            d++;
        }

        if (!isDelimiter) {
            break;
        }

        lastToken++;
    }

    if (*lastToken == '\0') {
        lastToken = NULL;
        return NULL;
    }
    char *tokenStart = lastToken;
    while (*lastToken != '\0') {
        int isDelimiter = 0;
        const char *d = delim;
        while (*d != '\0') {
            if (*lastToken == *d) {
                isDelimiter = 1;
                break;
            }
            d++;
        }

        if (isDelimiter) {
            break;
        }

        lastToken++;
    }
    if (*lastToken != '\0') {
        *lastToken = '\0';
        lastToken++;
    }
    return tokenStart;
}

int my_strcmp(const char *str1, const char *str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return (*str1 - *str2);
        }
        str1++;
        str2++;
    }

    return (*str1 - *str2);
}

int lens(const char *s){
    int count = 0;
    while(s[count] != '\0'){
        count += 1;
    }
    return count;
}
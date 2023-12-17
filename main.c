#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include "sorting.h"

#define DELIM " "
#define ADD "> "

char* getstr(char* PROMT) {
    printf("%s", PROMT);
    char* ptr = malloc(1);
    char buf[81];
    int len = 0;
    int n = 0;
    *ptr = '\0';
    do{
        n = scanf("%80[^\n]", buf);
        if (n < 0) {
            free(ptr);
            ptr = NULL;
            continue;
        }
        if(n == 0)
            scanf("%*c");
        else {
            len += strlen(buf);
            ptr = (char*) realloc (ptr, len + 1);
            strcat(ptr, buf);
        }
    } while (n > 0);
    return ptr;
}

int* readliner(const char *add){
    char *str = readline(add);
    return (int *) str;
}

int main() {
    char *str;
    char *str2;
    int numLines;
    int *result = NULL;
    char **resultArray;
    int number;
    while (1) {
        printf("Выберите номер дейтсвия\n");
        printf("1 - readline\n");
        printf("2 - scanf\n");
        printf("Ввод:");
        while (scanf("%d", &number) != 1) {
            printf("Введите номер позиции:");
            while (getchar() != '\n');
        }
        switch (number) {
            case 1:
                while(1) {
                    str = getstr(ADD);
                    if (str == NULL) {
                        free(str);
                        free(str2);
                        exit(EXIT_FAILURE);
                    }
                    str2 = strdup(str);
                    resultArray = comparison(str, &numLines);
                    final(resultArray, numLines, result, str2);
                }
            case 2:
                while(1) {
                    str = (char *) readliner(ADD);
                    if (str == NULL) {
                        free(str);
                        free(str2);
                        return 0;
                    }
                    str2 = strdup(str);
                    resultArray = comparison(str, &numLines);
                    final(resultArray, numLines, result, str2);
                }
        }
    }
}
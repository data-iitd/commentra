#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>
#include <limits.h>
#include <time.h>
#include <float.h>
#include <assert.h>

#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)
#define EPS 1e-9
#define INF 1e9
#define PI acos(-1.0)
#define MAX_SIZE 1000000
#define MAX_CHAR 1000000

#define LIST(type) struct {\
    int size;\
    int capacity;\
    type *arr;\
}

#define LIST_INIT(list, type) {\
    list.size = 0;\
    list.capacity = 1;\
    list.arr = (type *)malloc(list.capacity * sizeof(type));\
}

#define LIST_PUSH(list, item) {\
    if (list.size == list.capacity) {\
        list.capacity *= 2;\
        list.arr = (type *)realloc(list.arr, list.capacity * sizeof(type));\
    }\
    list.arr[list.size++] = item;\
}

#define LIST_POP(list) (list.arr[--list.size])

#define LIST_GET(list, index) (list.arr[index])

#define LIST_SET(list, index, item) (list.arr[index] = item)

#define LIST_INSERT(list, index, item) {\
    if (list.size == list.capacity) {\
        list.capacity *= 2;\
        list.arr = (type *)realloc(list.arr, list.capacity * sizeof(type));\
    }\
    for (int i = list.size; i > index; i--) {\
        list.arr[i] = list.arr[i - 1];\
    }\
    list.arr[index] = item;\
    list.size++;\
}

#define LIST_REMOVE(list, index) {\
    for (int i = index; i < list.size - 1; i++) {\
        list.arr[i] = list.arr[i + 1];\
    }\
    list.size--;\
}

#define LIST_REVERSE(list) {\
    for (int i = 0; i < list.size / 2; i++) {\
        int temp = list.arr[i];\
        list.arr[i] = list.arr[list.size - i - 1];\
        list.arr[list.size - i - 1] = temp;\
    }\
}

#define LIST_SORT(list) qsort(list.arr, list.size, sizeof(type), compare)

#define LIST_PRINT(list) {\
    for (int i = 0; i < list.size; i++) {\
        printf("%d ", list.arr[i]);\
    }\
    printf("\n");\
}

#define LIST_FREE(list) free(list.arr)

#define STRING_INIT(str) {\
    str.size = 0;\
    str.capacity = 1;\
    str.arr = (char *)malloc(str.capacity * sizeof(char));\
}

#define STRING_PUSH(str, item) {\
    if (str.size == str.capacity) {\
        str.capacity *= 2;\
        str.arr = (char *)realloc(str.arr, str.capacity * sizeof(char));\
    }\
    str.arr[str.size++] = item;\
}

#define STRING_POP(str) (str.arr[--str.size])

#define STRING_GET(str, index) (str.arr[index])

#define STRING_SET(str, index, item) (str.arr[index] = item)

#define STRING_INSERT(str, index, item) {\
    if (str.size == str.capacity) {\
        str.capacity *= 2;\
        str.arr = (char *)realloc(str.arr, str.capacity * sizeof(char));\
    }\
    for (int i = str.size; i > index; i--) {\
        str.arr[i] = str.arr[i - 1];\
    }\
    str.arr[index] = item;\
    str.size++;\
}

#define STRING_REMOVE(str, index) {\
    for (int i = index; i < str.size - 1; i++) {\
        str.arr[i] = str.arr[i + 1];\
    }\
    str.size--;\
}

#define STRING_REVERSE(str) {\
    for (int i = 0; i < str.size / 2; i++) {\
        char temp = str.arr[i];\
        str.arr[i] = str.arr[str.size - i - 1];\
        str.arr[str.size - i - 1] = temp;\
    }\
}

#define STRING_SORT(str) qsort(str.arr, str.size, sizeof(char), compare_string)

#define STRING_PRINT(str) {\
    for (int i = 0; i < str.size; i++) {\
        printf("%c", str.arr[i]);\
    }\
    printf("\n");\
}

#define STRING_FREE(str) free(str.arr)

#define STRING_TO_INT(str) atoi(str.arr)

#define STRING_TO_FLOAT(str) atof(str.arr)

#define STRING_TO_CHAR(str) str.arr[0]

#define STRING_EQUALS(str1, str2) (strcmp(str1.arr, str2.arr) == 0)

#define STRING_CONTAINS(str1, str2) (strstr(str1.arr, str2.arr) != NULL)

#define STRING_STARTS_WITH(str1, str2) (strncmp(str1.arr, str2.arr, str2.size) == 0)

#define STRING_ENDS_WITH(str1, str2) (strcmp(str1.arr + str1.size - str2.size, str2.arr) == 0)

#define STRING_INDEX_OF(str1, str2) (strstr(str1.arr, str2.arr) - str1.arr)

#define STRING_LAST_INDEX_OF(str1, str2) (strstr(str1.arr, str2.arr) - str1.arr + str2.size - 1)

#define STRING_SUBSTRING(str, start, end) {\
    STRING_INIT(result);\
    for (int i = start; i <= end; i++) {\
        STRING_PUSH(result, str.arr[i]);\
    }\
    return result;\
}

#define STRING_TRIM(str) {\
    int start = 0, end = str.size - 1;\
    while (isspace(str.arr[start])) start++;\
    while (isspace(str.arr[end])) end--;\
    return STRING_SUBSTRING(str, start, end);\
}

#define STRING_SPLIT(str, delim) {\
    LIST_INIT(result, STRING);\
    char *token = strtok(str.arr, delim);\
    while (token != NULL) {\
        STRING_INIT(temp);\
        STRING_PUSH(temp, token);\
        LIST_PUSH(result, temp);\
        token = strtok(NULL, delim);\
    }\
    return result;\
}

#define STRING_JOIN(list, delim) {\
    STRING_INIT(result);\
    for (int i = 0; i < list.size; i++) {\
        STRING_PUSH(result, list.arr[i].arr[0]);\
        if (i != list.size - 1) {\
            STRING_PUSH(result, delim);\
        }\
    }\
    return result;\
}

#define STRING_REPLACE(str, search, replace) {\
    STRING_INIT(result);\
    char *token = strtok(str.arr, search.arr);\
    while (token != NULL) {\
        STRING_PUSH(result, token);\
        STRING_PUSH(result, replace.arr[0]);\
        token = strtok(NULL, search.arr);\
    }\
    return result;\
}

#define STRING_REPEAT(str, count) {\
    STRING_INIT(result);\
    for (int i = 0; i < count; i++) {\
        STRING_PUSH(result, str.arr[0]);\
    }\
    return result;\
}

#define STRING_REPEAT_SEPARATOR(str, count, sep) {\
    STRING_INIT(result);\
    for (int i = 0; i < count; i++) {\
        STRING_PUSH(result, str.arr[0]);\
        if (i != count - 1) {\
            STRING_PUSH(result, sep.arr[0]);\
        }\
    }\
    return result;\
}

#define STRING_SLICE(str, start, end) {\
    STRING_INIT(result);\
    for (int i = start; i <= end; i++) {\
        STRING_PUSH(result, str.arr[i]);\
    }\
    return result;\
}

#define STRING_COUNT(str, substr) (strstr(str.arr, substr.arr) != NULL)

#define STRING_CASE_CONTAINS(str1, str2) (strcasestr(str1.arr, str2.arr) != NULL)

#define STRING_CASE_STARTS_WITH(str1, str2) (strncasecmp(str1.arr, str2.arr, str2.size) == 0)

#define STRING_CASE_ENDS_WITH(str1, str2) (strcasecmp(str1.arr + str1.size - str2.size, str2.arr) == 0)

#define STRING_CASE_INDEX_OF(str1, str2) (strcasestr(str1.arr, str2.arr) - str1.arr)

#define STRING_CASE_LAST_INDEX_OF(str1, str2) (strcasestr(str1.arr, str2.arr) - str1.arr + str2.size - 1)

#define STRING_CASE_REPLACE(str, search, replace) {\
    STRING_INIT(result);\
    char *token = strtok(str.arr, search.arr);\
    while (token != NULL) {\
        STRING_PUSH(result, token);\
        STRING_PUSH(result, replace.arr[0]);\
        token = strtok(NULL, search.arr);\
    }\
    return result;\
}

#define STRING_CASE_REPEAT(str, count) {\
    STRING_INIT(result);\
    for (int i = 0; i < count; i++) {\
        STRING_PUSH(result, str.arr[0]);\
    }\
    return result;\
}

#define STRING_CASE_REPEAT_SEPARATOR(str, count, sep) {\
    STRING_INIT(result);\
    for (int i = 0; i < count; i++) {\
        STRING_PUSH(result, str.arr[0]);\
        if (i != count - 1) {\
            STRING_PUSH(result, sep.arr[0]);\
        }\
    }\
    return result;\
}

#define STRING_CASE_SLICE(str, start, end) {\
    STRING_INIT(result);\
    for (int i = start; i <= end; i++) {\
        STRING_PUSH(result, str.arr[i]);\
    }\
    return result;\
}

#define STRING_CASE_COUNT(str, substr) (strcasestr(str.arr, substr.arr) != NULL)

#define STRING_CASE_REVERSE(str) {\
    for (int i = 0; i < str.size / 2; i++) {\
        char temp = str.arr[i];\
        str.arr[i] = str.arr[str.size - i - 1];\
        str.arr[str.size - i - 1] = temp;\
    }\
}

#define STRING_CASE_TRIM(str) {\
    int start = 0, end = str.size - 1;\
    while (isspace(str.arr[start])) start++;\
    while (isspace(str.arr[end])) end--;\
    return STRING_CASE_SUBSTRING(str, start, end);\
}

#define STRING_CASE_SPLIT(str, delim) {\
    LIST_INIT(result, STRING);\
    char *token = strtok(str.arr, delim);\
    while (token != NULL) {\
        STRING_INIT(temp);\
        STRING_PUSH(temp, token);\
        LIST_PUSH(result, temp);\
        token = strtok(NULL, delim);\
    }\
    return result;\
}

#define STRING_CASE_JOIN(list, delim) {\
    STRING_INIT(result);\
    for (int i = 0; i < list.size; i++) {\
        STRING_PUSH(result, list.arr[i].arr[0]);\
        if (i != list.size - 1) {\
            STRING_PUSH(result, delim);\
        }\
    }\
    return result;\
}

#define STRING_CASE_SUBSTRING(str, start, end) {\
    STRING_INIT(result);\
    for (int i = start; i <= end; i++) {\
        STRING_PUSH(result, str.arr[i]);\
    }\
    return result;\
}

#define STRING_CASE_TO_INT(str) atoi(str.arr)

#define STRING_CASE_TO_FLOAT(str) atof(str.arr)

#define STRING_CASE_TO_CHAR(str) str.arr[0]

#define STRING_CASE_EQUALS(str1, str2) (strcasecmp(str1.arr, str2.arr) == 0)

#define STRING_CASE_CONTAINS(str1, str2) (strcasestr(str1.arr, str2.arr) != NULL)

#define STRING_CASE_STARTS_WITH(str1, str2) (strncasecmp(str1.arr, str2.arr, str2.size) == 0)

#define STRING_CASE_ENDS_WITH(str1, str2) (strcasecmp(str1.arr + str1.size - str2.size, str2.arr) == 0)

#define STRING_CASE_INDEX_OF(str1, str2) (strcasestr(str1.arr, str2.arr) - str1.arr)

#define STRING_CASE_LAST_INDEX_OF(str1, str2) (strcasestr(str1.arr, str2.arr) - str1.arr + str2.size - 1)

#define STRING_CASE_REPLACE(str, search, replace) {\
    STRING_INIT(result);\
    char *token = strtok(str.arr, search.arr);\
    while (token != NULL) {\
        STRING_PUSH(result, token);\
        STRING_PUSH(result, replace.arr[0]);\
        token = strtok(NULL, search.arr);\
    }\
    return result;\
}

#define STRING_CASE_REPEAT(str, count) {\
    STRING_INIT(result);\
    for (int i = 0; i < count; i++) {\
        STRING_PUSH(result, str.arr[0]);\
    }\
    return result;\
}

#define STRING_CASE_REPEAT_SEPARATOR(str, count, sep) {\
    STRING_INIT(result
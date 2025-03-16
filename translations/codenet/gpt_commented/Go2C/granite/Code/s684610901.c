
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for sorting pairs
typedef struct {
    int64_t index;
    int64_t p1, p2;
} pair;

// Define a structure for sorting int64 slices
typedef struct {
    int64_t *data;
    int64_t size;
} Int64Slice;

// Utility functions for sorting int64 slices
void Int64s(int64_t *a, int64_t size) {
    qsort(a, size, sizeof(int64_t), compareInt64);
}

int compareInt64(const void *a, const void *b) {
    int64_t x = *(int64_t *)a;
    int64_t y = *(int64_t *)b;
    return (x > y) - (x < y);
}

int main() {
    // Set up the scanner buffer and read three integers A, B, C
    char buf[10000];
    fgets(buf, 10000, stdin);
    char *token = strtok(buf, " ");
    int64_t A = atol(token);
    token = strtok(NULL, " ");
    int64_t B = atol(token);
    token = strtok(NULL, " ");
    int64_t C = atol(token);

    // Check if C is within the range [A, B] and print the result
    if (C >= A && C <= B) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

// Utility functions for sorting pairs
void pairsSort(pair *pairs, int64_t size) {
    qsort(pairs, size, sizeof(pair), comparePair);
}

int comparePair(const void *a, const void *b) {
    pair *p1 = (pair *)a;
    pair *p2 = (pair *)b;
    if (p1->index < p2->index) {
        return -1;
    } else if (p1->index > p2->index) {
        return 1;
    } else {
        return 0;
    }
}

// Utility functions for sorting int64 slices
void Int64sSliceSort(Int64Slice *slice) {
    qsort(slice->data, slice->size, sizeof(int64_t), compareInt64);
}

int compareInt64Slice(const void *a, const void *b) {
    Int64Slice *s1 = (Int64Slice *)a;
    Int64Slice *s2 = (Int64Slice *)b;
    int64_t size1 = s1->size;
    int64_t size2 = s2->size;
    int64_t minSize = size1 < size2? size1 : size2;
    for (int64_t i = 0; i < minSize; i++) {
        if (s1->data[i] < s2->data[i]) {
            return -1;
        } else if (s1->data[i] > s2->data[i]) {
            return 1;
        }
    }
    if (size1 < size2) {
        return -1;
    } else if (size1 > size2) {
        return 1;
    } else {
        return 0;
    }
}

// Utility functions for sorting int64 slices
void Int64sSliceAreSorted(Int64Slice *slice) {
    int64_t size = slice->size;
    for (int64_t i = 0; i < size - 1; i++) {
        if (slice->data[i] > slice->data[i + 1]) {
            return 0;
        }
    }
    return 1;
}

// Constants for buffer sizes and infinity value
#define INITIAL_BUF_SIZE 10000
#define MAX_BUF_SIZE 100000
#define INF 100000000

// Global variables for input/output handling and direction vectors
char buf[MAX_BUF_SIZE];
FILE *scanner = fmemopen(buf, INITIAL_BUF_SIZE, "r+");
FILE *writer = stdout;
int64_t di[] = {-1, 0, 1, 0}; // Direction vectors for row movement
int64_t dj[] = {0, -1, 0, 1}; // Direction vectors for column movement

// Uncomment the following function to see a regex example
// void regexpExample() {
//     // Your code here!
//     char *str = "13:20";
//     regex_t r;
//     regmatch_t m[1];
//     int reti;
//     char errbuf[100];
//     reti = regcomp(&r, "(\\d+):(\\d+)", 0);
//     if (reti) {
//         regerror(reti, &r, errbuf, sizeof(errbuf));
//         fprintf(stderr, "Could not compile regex\n");
//         exit(1);
//     }
//     reti = regexec(&r, str, 1, m, 0);
//     if (!reti) {
//         printf("Found match: %s\n", str + m[0].rm_so);
//     } else if (reti == REG_NOMATCH) {
//         printf("No match found\n");
//     } else {
//         char errbuf[100];
//         regerror(reti, &r, errbuf, sizeof(errbuf));
//         fprintf(stderr, "Regex match failed: %s\n", errbuf);
//         exit(1);
//     }
//     regfree(&r);
// }

// Uncomment the following struct and function to see a stable sort example
// typedef struct {
//     int64_t gold;
//     int64_t silver;
//     int64_t blonze;
// } Country;

// // Example of stable sorting
// void stableSortExample() {
//     Country countries[] = {
//         {1, 2, 3},
//         {1, 2, 3},
//         {1, 3, 2},
//         {1, 3, 3},
//     };
//     int64_t size = sizeof(countries) / sizeof(Country);
//     qsort(countries, size, sizeof(Country), compareCountry);
//     for (int64_t i = 0; i < size; i++) {
//         printf("Country %lld: %lld %lld %lld\n", i + 1, countries[i].gold, countries[i].silver, countries[i].blonze);
//     }
// }

// int compareCountry(const void *a, const void *b) {
//     Country *c1 = (Country *)a;
//     Country *c2 = (Country *)b;
//     if (c1->blonze > c2->blonze) {
//         return -1;
//     } else if (c1->blonze < c2->blonze) {
//         return 1;
//     } else {
//         if (c1->silver > c2->silver) {
//             return -1;
//         } else if (c1->silver < c2->silver) {
//             return 1;
//         } else {
//             if (c1->gold > c2->gold) {
//                 return -1;
//             } else if (c1->gold < c2->gold) {
//                 return 1;
//             } else {
//                 return 0;
//             }
//         }
//     }
// }

// int main() {
//     // Set up the scanner buffer and read three integers A, B, C
//     char buf[MAX_BUF_SIZE];
//     fgets(buf, MAX_BUF_SIZE, stdin);
//     char *token = strtok(buf, " ");
//     int64_t A = atol(token);
//     token = strtok(NULL, " ");
//     int64_t B = atol(token);
//     token = strtok(NULL, " ");
//     int64_t C = atol(token);
//     // Check if C is within the range [A, B] and print the result
//     return 0;
// }

// int main() {
//     // Set up the scanner buffer and read three integers A, B, C
//     char buf[MAX_BUF_SIZE];
//     fgets(buf, MAX_BUF_SIZE, stdin);
//     char *token = strtok(buf, " ");
//     int64_t A = atol(token);
//     token = strtok(NULL, " ");
//     int64_t B = atol(token);
//     token = strtok(NULL, " ");
//     int64_t C = atol(token);
//     // Check if C is within the range [A, B] and print the result
//     return 0;
// }

// int main() {
//     // Set up the scanner buffer and read three integers A, B, C
//     char buf[MAX_BUF_SIZE];
//     fgets(buf, MAX_BUF_SIZE, stdin);
//     char *token = strtok(buf, " ");
//     int64_t A = atol(token);
//     token = strtok(NULL, " ");
//     int64_t B = atol(token);
//     token = strtok(NULL, " ");
//     int64_t C = atol(token);
//     // Check if C is within the range [A, B] and print the result
//     return 0;
// }

// int main() {
//     // Set up the scanner buffer and read three integers A, B, C
//     char buf[MAX_BUF_SIZE];
//     fgets(buf, MAX_BUF_SIZE);
//     char *token = strtok(buf, " ");
//     int64_t A = atol(token);
//     token = strtok(NULL, " ");
//     int64_t B = atol(token);
//     token = strtok(NULL, " ");
//     int64_t C = atol(token);
//     // Check if C is within the range [A, B] and print the result
//     return 0;
// }

// int main() {
//     // Set up the scanner buffer and read three integers A, B, C
//     char buf[MAX_BUF_SIZE];
//     fgets(buf, MAX_BUF_SIZE);
//     char *token = strtok(buf, " ");
//     int64_t A = atol(token);
//     token = strtok(NULL, " ")
//     int64_t B = atol(token);
//     token = strtok(NULL, " ")
//     int64_t C = atol(token);
//     // Check if C is within the range [A, B] and print the result
//     return 0;
// }

// int main() {
//     // Set up the scanner buffer and read three integers A, B, C
//     char buf[MAX_BUF_SIZE];
//     fgets(buf, MAX_BUF_SIZE);
//     char *token = strtok(buf, " ")
//     int64_t A = atol(token);
//     token = strtok(NULL, " ")
//     int64_t B = atol(token);
//     token = stratok(NULL, " ")
//     int64_t C = atol(token);
//     token = stratok(NULL, " ")
//     int64_t A = atol(token);
//     token = stratok(NULL, " ")
//     int64_t B = atol(token);
//     token = stratok(NULL, " ")
//     int64_t C = atol(token);
//     token = stratok(NULL, " ")
//     int64_t A = atol(token);
//     token = stratok(NULL, " ")
//     int64_t B = atol(token);
//     token = stratok(NULL, " ")
//     int64_t C = atol(token);
//     token = stratok(NULL, " ")
//     int64_t A = atol(token);
//     token = stratok(NULL, " ")
//     int64_t B = atol(token);
//     token = stratok(NULL, " ")
//     int64_t C = atol(token);
//     token = stratok(NULL, " ")
//     int64_t A = atol(token);
//     token = stratok(NULL, " ")
//     int64_t B = atol(token);
//     token = stratok(NULL, " ")
//     int64_t C = atol(token);
//     token = stratok(NULL, " ")
//     int64_t A = atol(token);
//     token = stratok(NULL, " ")
//     int64_t B = atol(token);
//     token = stratok(NULL, " ")
//     int64_t C = atol(token);
//     token = stratok(NULL, " ")
//     int64_t B = atol(token);
//     token = stratok(NULL, " ")
//     int64_t C = atol(token);
//     token = stratok(NULL, " ")
//     int64_t B = atol(token);
//     token = stratok(NULL, " ")
//     int64_t C = atol(token);
//     token = stratok(NULL, " ")
//     int64_t B = atol(token);
//     token = stratok(NULL, " ")
//     int64_t C = atol(token);
//     token = stratok(NULL, " ")
//     int64_t B = atol(token);
//     token = stratok(NULL, " ")
//     int64_t C = atol(token);
//     token = stratok(NULL, " ")
//     int64_t B = atol(token);
//     token = stratok(NULL, " ")
//     int64_t C = atol(token);
//     token = stratok(NULL, " ")
//     int64_t B = atol(token);
//     token = stratok(NULL, " ")
//     int64_t C = atol(token);
//     token = stratok(NULL, " ")
//     int64_t B = atol(token);
//     token = stratok(NULL, " ")
//     int64_t C = atol(token);
//     token = stratok(NULL, " ")
//     int64_t B = atol(token);
//     token = stratok(NULL, " ")
//     int64_t C = atol(token);
//     token = stratok(NULL, " ")
//     int64_t B = atol(token);
//     token = stratok(NULL, " ")
//     int64_t C = atol(token);
//     token = stratok(NULL, " ")
//     int64_t B = atol(token);
//     token = stratok(NULL, " ")
//     int64_t C = atol(token);
//     token = str

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int p1;
    int p2;
} Pair;

const int initialBufSize = 1e4;
const int maxBufSize = 1e8;

char buf[maxBufSize];
FILE *scanner = fmemopen(buf, initialBufSize, "r+");
FILE *writer = fmemopen(buf, maxBufSize, "w+");

int main() {
    int N, K;
    fscanf(scanner, "%d %d", &N, &K);

    char *s = TenToN(N, K);
    fprintf(writer, "%d\n", strlen(s));

    fclose(scanner);
    fclose(writer);
    return 0;
}

char *TenToN(int number, int n) {
    char *s = (char *)malloc(sizeof(char) * 100);
    int tmp = number;
    int i = 0;
    while (tmp > 0) {
        s[i] = '0' + tmp % n;
        tmp /= n;
        i++;
    }
    s[i] = '\0';
    reverse(s);
    return s;
}

void reverse(char *s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
}

// Write your C code here!
// int regexpExample() {
//     // Your code here!
//     char *str = "13:20";
//     regex_t r;
//     int reti;
//     char errbuf[100];
//     reti = regcomp(&r, "([0-9]+):([0-9]+)", 0);
//     if (reti) {
//         regerror(reti, &r, errbuf, sizeof(errbuf));
//         fprintf(stderr, "Could not compile regex\n");
//         exit(1);
//     }
//     reti = regexec(&r, str, 0, NULL, 0);
//     if (!reti) {
//         fprintf(stderr, "Match found\n");
//     } else if (reti == REG_NOMATCH) {
//         fprintf(stderr, "No match found\n");
//     } else {
//         char errbuf[100];
//         regerror(reti, &r, errbuf, sizeof(errbuf));
//         fprintf(stderr, "Regex match failed: %s\n", errbuf);
//         exit(1);
//     }
//     regfree(&r);
//     return 0;
// }

// type Country struct {
//     gold int
//     silver int
//     blonze int
// }

// // 複数ソートのサンプル
// int stableSortExample() {
//     Country country[4] = {
//         {1, 2, 3},
//         {1, 2, 3},
//         {1, 3, 2},
//         {1, 3, 3},
//     };
//     qsort(country, 4, sizeof(Country), compareCountryByBlonze);
//     qsort(country, 4, sizeof(Country), compareCountryBySilver);
//     qsort(country, 4, sizeof(Country), compareCountryByGold);
//     return 0;
// }

// int compareCountryByBlonze(const void *a, const void *b) {
//     Country *c1 = (Country *)a;
//     Country *c2 = (Country *)b;
//     if (c1->blonze > c2->blonze) {
//         return 1;
//     } else if (c1->blonze < c2->blonze) {
//         return -1;
//     } else {
//         return 0;
//     }
// }

// int compareCountryBySilver(const void *a, const void *b) {
//     Country *c1 = (Country *)a;
//     Country *c2 = (Country *)b;
//     if (c1->silver > c2->silver) {
//         return 1;
//     } else if (c1->silver < c2->silver) {
//         return -1;
//     } else {
//         return 0;
//     }
// }

// int compareCountryByGold(const void *a, const void *b) {
//     Country *c1 = (Country *)a;
//     Country *c2 = (Country *)b;
//     if (c1->gold > c2->gold) {
//         return 1;
//     } else if (c1->gold < c2->gold) {
//         return -1;
//     } else {
//         return 0;
//     }
// }

// 
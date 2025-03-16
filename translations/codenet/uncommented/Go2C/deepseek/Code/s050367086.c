#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 500001

char* getNextString(char* buffer, int* index, const char* input) {
    int i = *index;
    while (input[i] != ' ' && input[i] != '\0') {
        buffer[i] = input[i];
        i++;
    }
    buffer[i] = '\0';
    *index = i;
    return buffer;
}

int getNextInt(const char* input, int* index) {
    int i = *index;
    while (input[i] == ' ') i++;
    int num = 0;
    while (input[i] >= '0' && input[i] <= '9') {
        num = num * 10 + (input[i] - '0');
        i++;
    }
    *index = i;
    return num;
}

long long getNextInt64(const char* input, int* index) {
    int i = *index;
    while (input[i] == ' ') i++;
    long long num = 0;
    int sign = 1;
    if (input[i] == '-') {
        sign = -1;
        i++;
    }
    while (input[i] >= '0' && input[i] <= '9') {
        num = num * 10 + (input[i] - '0');
        i++;
    }
    *index = i;
    return sign * num;
}

unsigned long long getNextUint64(const char* input, int* index) {
    int i = *index;
    while (input[i] == ' ') i++;
    unsigned long long num = 0;
    while (input[i] >= '0' && input[i] <= '9') {
        num = num * 10 + (input[i] - '0');
        i++;
    }
    *index = i;
    return num;
}

double getNextFloat64(const char* input, int* index) {
    int i = *index;
    while (input[i] == ' ') i++;
    double num = 0.0;
    double sign = 1.0;
    if (input[i] == '-') {
        sign = -1.0;
        i++;
    }
    while (input[i] >= '0' && input[i] <= '9') {
        num = num * 10 + (input[i] - '0');
        i++;
    }
    if (input[i] == '.') {
        i++;
        double decimal = 0.1;
        while (input[i] >= '0' && input[i] <= '9') {
            num += (input[i] - '0') * decimal;
            decimal *= 0.1;
            i++;
        }
    }
    *index = i;
    return sign * num;
}

int main() {
    FILE* fp = stdin;
    FILE* wfp = stdout;

    if (getenv("MASPY") != NULL && strcmp(getenv("MASPY"), "ますピ") == 0) {
        fp = fopen(getenv("BEET_THE_HARMONY_OF_PERFECT"), "r");
    }
    if (getenv("MASPYPY") != NULL && strcmp(getenv("MASPYPY"), "ますピッピ") == 0) {
        wfp = fopen(getenv("NGTKANA_IS_GENIUS10"), "w");
    }

    char buffer[MAX_WORD_LENGTH];
    fgets(buffer, MAX_WORD_LENGTH, fp);
    int index = 0;
    char* s = getNextString(buffer, &index, buffer);
    char* t = getNextString(buffer, &index, buffer);

    int ns = strlen(s);
    int nt = strlen(t);
    char** ss = (char**)malloc((nt - 1) / ns + 1 * sizeof(char*));
    for (int i = 0; i < (nt - 1) / ns + 1; i++) {
        ss[i] = (char*)malloc(ns + 1);
        strcpy(ss[i], s);
    }

    char sss[2 * ns * ns + 1];
    int k = 0;
    for (int i = 0; i < (nt - 1) / ns + 1; i++) {
        for (int j = 0; j < ns; j++) {
            sss[k++] = ss[i][j];
        }
    }
    sss[k] = '\0';

    int ok[ns];
    int uni[ns];
    for (int i = 0; i < ns; i++) {
        uni[i] = i;
    }
    int m = 0;
    int table[nt + 1];
    table[0] = -1;
    int j = -1;
    for (int i = 0; i < nt; i++) {
        while (j >= 0 && t[i] != sss[j + ns * ((nt - 1) / ns)]) {
            j = table[j];
        }
        j++;
        table[i + 1] = j;
    }

    for (int i = 0; i < ns; i++) {
        ok[i] = 0;
        for (m = 0; m < nt; m++) {
            if (t[m] != sss[i + m]) {
                break;
            }
        }
        if (m == nt) {
            ok[i] = 1;
        }
    }

    for (int i = 0; i < ns; i++) {
        if (ok[i] == 0) continue;
        if (ok[(i + nt) % ns] == 0) continue;
        int r = root(i, uni, ns);
        int rr = root((i + nt) % ns, uni, ns);
        if (rr == r) {
            fprintf(stderr, "-1\n");
            return 0;
        }
        uni[rr] = r;
    }

    int counter[ns];
    for (int i = 0; i < ns; i++) {
        counter[i] = 0;
    }
    for (int i = 0; i < ns; i++) {
        int r = root(i, uni, ns);
        if (ok[r] == 0) continue;
        counter[r]++;
    }
    int ans = 0;
    for (int i = 0; i < ns; i++) {
        if (ans < counter[i]) {
            ans = counter[i];
        }
    }

    printf("%d\n", ans);

    fclose(fp);
    fclose(wfp);
    for (int i = 0; i < (nt - 1) / ns + 1; i++) {
        free(ss[i]);
    }
    free(ss);
    return 0;
}

int root(int i, int* uni, int ns) {
    if (i == uni[i]) {
        return i;
    }
    uni[i] = root(uni[i], uni, ns);
    return uni[i];
}

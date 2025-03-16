
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
FILE *writer = stdout;

int TenToN(int number, int n) {
    int s = 0;
    int tmp = number;
    while (tmp > 0) {
        s = (tmp % n) + (s * 10);
        tmp /= n;
    }
    return s;
}

void write(char *s) {
    fprintf(writer, "%s", s);
}

void print() {
    fflush(writer);
}

char *readLine() {
    fgets(buf, maxBufSize, scanner);
    char *s = malloc(strlen(buf));
    strcpy(s, buf);
    return s;
}

int readInt() {
    int read;
    fscanf(scanner, "%d", &read);
    return read;
}

float readFloat() {
    float read;
    fscanf(scanner, "%f", &read);
    return read;
}

void readRunes() {
    char *runes = readLine();
    int len = strlen(runes);
    for (int i = 0; i < len; i++) {
        putc(runes[i], writer);
    }
}

char *readString() {
    char *read = readLine();
    return read;
}

char **readStrings() {
    char *strings = readLine();
    int len = strlen(strings);
    char **read = malloc(len * sizeof(char *));
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (strings[i] =='') {
            read[count] = malloc(i - count + 1);
            strncpy(read[count], strings + count, i - count + 1);
            count++;
        }
    }
    return read;
}

int s2i(char *s) {
    int intVal;
    sscanf(s, "%d", &intVal);
    return intVal;
}

char *i2s(int i) {
    char *strVal = malloc(11 * sizeof(char)); // Assuming int can be up to 10 digits
    sprintf(strVal, "%d", i);
    return strVal;
}

float s2f(char *s) {
    float floatVal;
    sscanf(s, "%f", &floatVal);
    return floatVal;
}

int sum(int *i, int len) {
    int sum = 0;
    for (int j = 0; j < len; j++) {
        sum += i[j];
    }
    return sum;
}

char **split(char *s) {
    char **strs = malloc(100 * sizeof(char *)); // Assuming maximum number of words is 100
    int count = 0;
    char *token = strtok(s, " ");
    while (token!= NULL) {
        strs[count] = malloc(strlen(token) + 1);
        strcpy(strs[count], token);
        count++;
        token = strtok(NULL, " ");
    }
    return strs;
}

int *strAry2intAry(char **strs, int len) {
    int *nums = malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        nums[i] = s2i(strs[i]);
    }
    return nums;
}

char **intAry2strAry(int *nums, int len) {
    char **strs = malloc(len * sizeof(char *));
    for (int i = 0; i < len; i++) {
        strs[i] = i2s(nums[i]);
    }
    return strs;
}

char *ary2str(char **strs, int len) {
    char *res = malloc(1000 * sizeof(char)); // Assuming maximum length of string is 1000
    int count = 0;
    for (int i = 0; i < len; i++) {
        strcat(res, strs[i]);
        strcat(res, " ");
        count += strlen(strs[i]) + 1;
    }
    return res;
}

int *reverse(int *res, int len) {
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        int temp = res[i];
        res[i] = res[j];
        res[j] = temp;
    }
    return res;
}

void initalize(int *res, int len, int init) {
    if (len == 0) {
        return;
    }
    res[0] = init;
    for (int i = 0; i < len; i++) {
        memmove(res + i, res, i * sizeof(int));
    }
}

int main() {
    int N = readInt();
    int K = readInt();
    int s = TenToN(N, K);
    write(i2s(strlen(i2s(s))));
    print();
    return 0;
}
// END-OF-CODE
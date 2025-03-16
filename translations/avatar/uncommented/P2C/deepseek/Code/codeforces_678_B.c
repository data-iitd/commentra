#include <stdio.h>

int leapyear(int n) {
    if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
        return 1; // "y"
    } else {
        return 0; // "n"
    }
}

int main() {
    int n;
    scanf("%d", &n);
    char *ans;
    if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
        ans = "ly";
    } else {
        ans = "nly";
    }
    char d = 'f';
    while (1) {
        if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
            if (d == 'm') {
                d = 'w';
                n++;
            } else if (d == 't') {
                d = 'th';
                n++;
            } else if (d == 'w') {
                d = 'f';
                n++;
            } else if (d == 'th') {
                d = 'sa';
                n++;
            } else if (d == 'f') {
                d = 's';
                n++;
            } else if (d == 'sa') {
                d = 'm';
                n++;
            } else if (d == 's') {
                d = 't';
                n++;
            }
        } else {
            if (d == 'm') {
                d = 't';
                n++;
            } else if (d == 't') {
                d = 'w';
                n++;
            } else if (d == 'w') {
                d = 'th';
                n++;
            } else if (d == 'th') {
                d = 'f';
                n++;
            } else if (d == 'f') {
                d = 'sa';
                n++;
            } else if (d == 'sa') {
                d = 's';
                n++;
            } else if (d == 's') {
                d = 'm';
                n++;
            }
        }
        if (d == 'f' && ans[0] == 'l' && ans[1] == 'y' && leapyear(n) == 1) {
            break;
        } else if (d == 'f' && ans[0] == 'n' && ans[1] == 'l' && leapyear(n) == 0) {
            break;
        }
    }
    printf("%d\n", n);
    return 0;
}

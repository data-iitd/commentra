#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    int a[5];
    int r[5];
    int b;
    int ans = 0;
    int last;
    int idx;
    for (int i = 0; i < 5; i++) {
        scanf("%d", &a[i]);
        r[i] = a[i] % 10;
        if (r[i]!= 0) {
            b = 10 - r[i];
            if (b == 10) {
                b = 0;
            }
            if (b == 1) {
                b = 9;
            }
            if (b == 2) {
                b = 8;
            }
            if (b == 3) {
                b = 7;
            }
            if (b == 4) {
                b = 6;
            }
            if (b == 5) {
                b = 5;
            }
            if (b == 6) {
                b = 4;
            }
            if (b == 7) {
                b = 3;
            }
            if (b == 8) {
                b = 2;
            }
            if (b == 9) {
                b = 1;
            }
            if (b == 0) {
                b = 10;
            }
            if (b == 11) {
                b = 1;
            }
            if (b == 12) {
                b = 2;
            }
            if (b == 13) {
                b = 3;
            }
            if (b == 14) {
                b = 4;
            }
            if (b == 15) {
                b = 5;
            }
            if (b == 16) {
                b = 6;
            }
            if (b == 17) {
                b = 7;
            }
            if (b == 18) {
                b = 8;
            }
            if (b == 19) {
                b = 9;
            }
            if (b == 20) {
                b = 10;
            }
            if (b == 21) {
                b = 1;
            }
            if (b == 22) {
                b = 2;
            }
            if (b == 23) {
                b = 3;
            }
            if (b == 24) {
                b = 4;
            }
            if (b == 25) {
                b = 5;
            }
            if (b == 26) {
                b = 6;
            }
            if (b == 27) {
                b = 7;
            }
            if (b == 28) {
                b = 8;
            }
            if (b == 29) {
                b = 9;
            }
            if (b == 30) {
                b = 10;
            }
            if (b == 31) {
                b = 1;
            }
            if (b == 32) {
                b = 2;
            }
            if (b == 33) {
                b = 3;
            }
            if (b == 34) {
                b = 4;
            }
            if (b == 35) {
                b = 5;
            }
            if (b == 36) {
                b = 6;
            }
            if (b == 37) {
                b = 7;
            }
            if (b == 38) {
                b = 8;
            }
            if (b == 39) {
                b = 9;
            }
            if (b == 40) {
                b = 10;
            }
            if (b == 41) {
                b = 1;
            }
            if (b == 42) {
                b = 2;
            }
            if (b == 43) {
                b = 3;
            }
            if (b == 44) {
                b = 4;
            }
            if (b == 45) {
                b = 5;
            }
            if (b == 46) {
                b = 6;
            }
            if (b == 47) {
                b = 7;
            }
            if (b == 48) {
                b = 8;
            }
            if (b == 49) {
                b = 9;
            }
            if (b == 50) {
                b = 10;
            }
            if (b == 51) {
                b = 1;
            }
            if (b == 52) {
                b = 2;
            }
            if (b == 53) {
                b = 3;
            }
            if (b == 54) {
                b = 4;
            }
            if (b == 55) {
                b = 5;
            }
            if (b == 56) {
                b = 6;
            }
            if (b == 57) {
                b = 7;
            }
            if (b == 58) {
                b = 8;
            }
            if (b == 59) {
                b = 9;
            }
            if (b == 60) {
                b = 10;
            }
            if (b == 61) {
                b = 1;
            }
            if (b == 62) {
                b = 2;
            }
            if (b == 63) {
                b = 3;
            }
            if (b == 64) {
                b = 4;
            }
            if (b == 65) {
                b = 5;
            }
            if (b == 66) {
                b = 6;
            }
            if (b == 67) {
                b = 7;
            }
            if (b == 68) {
                b = 8;
            }
            if (b == 69) {
                b = 9;
            }
            if (b == 70) {
                b = 10;
            }
            if (b == 71) {
                b = 1;
            }
            if (b == 72) {
                b = 2;
            }
            if (b == 73) {
                b = 3;
            }
            if (b == 74) {
                b = 4;
            }
            if (b == 75) {
                b = 5;
            }
            if (b == 76) {
                b = 6;
            }
            if (b == 77) {
                b = 7;
            }
            if (b == 78) {
                b = 8;
            }
            if (b == 79) {
                b = 9;
            }
            if (b == 80) {
                b = 10;
            }
            if (b == 81) {
                b = 1;
            }
            if (b == 82) {
                b = 2;
            }
            if (b == 83) {
                b = 3;
            }
            if (b == 84) {
                b = 4;
            }
            if (b == 85) {
                b = 5;
            }
            if (b == 86) {
                b = 6;
            }
            if (b == 87) {
                b = 7;
            }
            if (b == 88) {
                b = 8;
            }
            if (b == 89) {
                b = 9;
            }
            if (b == 90) {
                b = 10;
            }
            if (b == 91) {
                b = 1;
            }
            if (b == 92) {
                b = 2;
            }
            if (b == 93) {
                b = 3;
            }
            if (b == 94) {
                b = 4;
            }
            if (b == 95) {
                b = 5;
            }
            if (b == 96) {
                b = 6;
            }
            if (b == 97) {
                b = 7;
            }
            if (b == 98) {
                b = 8;
            }
            if (b == 99) {
                b = 9;
            }
            if (b == 100) {
                b = 10;
            }
            if (b == 101) {
                b = 1;
            }
            if (b == 102) {
                b = 2;
            }
            if (b == 103) {
                b = 3;
            }
            if (b == 104) {
                b = 4;
            }
            if (b == 105) {
                b = 5;
            }
            if (b == 106) {
                b = 6;
            }
            if (b == 107) {
                b = 7;
            }
            if (b == 108) {
                b = 8;
            }
            if (b == 109) {
                b = 9;
            }
            if (b == 110) {
                b = 10;
            }
            if (b == 111) {
                b = 1;
            }
            if (b == 112) {
                b = 2;
            }
            if (b == 113) {
                b = 3;
            }
            if (b == 114) {
                b = 4;
            }
            if (b == 115) {
                b = 5;
            }
            if (b == 116) {
                b = 6;
            }
            if (b == 117) {
                b = 7;
            }
            if (b == 118) {
                b = 8;
            }
            if (b == 119) {
                b = 9;
            }
            if (b == 120) {
                b = 10;
            }
            if (b == 121) {
                b = 1;
            }
            if (b == 122) {
                b = 2;
            }
            if (b == 123) {
                b = 3;
            }
            if (b == 124) {
                b = 4;
            }
            if (b == 125) {
                b = 5;
            }
            if (b == 126) {
                b = 6;
            }
            if (b == 127) {
                b = 7;
            }
            if (b == 128) {
                b = 8;
            }
            if (b == 129) {
                b = 9;
            }
            if (b == 130) {
                b = 10;
            }
            if (b == 131) {
                b = 1;
            }
            if (b == 132) {
                b = 2;
            }
            if (b == 133) {
                b = 3;
            }
            if (b == 134) {
                b = 4;
            }
            if (b == 135) {
                b = 5;
            }
            if (b == 136) {
                b = 6;
            }
            if (b == 137) {
                b = 7;
            }
            if (b == 138) {
                b =
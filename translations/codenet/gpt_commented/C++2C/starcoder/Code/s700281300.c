#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <limits.h>
#include <float.h>
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
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <limits.h>
#include <float.h>
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

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
    // Read the number of test cases
    int n;
    scanf("%d", &n);

    // Process each test case
    rep(i, n) {
        char s[100000];
        // Read the string for the current test case
        scanf("%s", s);

        // Initialize a set to store unique combinations of strings
        set_t st;
        // Insert the original string into the set
        st_insert(st, s);

        // Generate combinations by splitting the string at different positions
        REP(j, 1, strlen(s)) { 
            char res[100000];
            // Create the first part of the split string
            rep(k, j) {
                res[k] = s[k];
            }
            res[j] = '\0'; // Terminate the string

            char res2[100000];
            // Create the second part of the split string
            REP(k, j, strlen(s)) {
                res2[k-j] = s[k];
            }
            res2[strlen(s)-j] = '\0'; // Terminate the string

            // Create reversed versions of both parts
            char t[100000];
            strcpy(t, res);
            REP(k, 0, strlen(t)) {
                t[k] = t[strlen(t)-k-1];
            }

            char t2[100000];
            strcpy(t2, res2);
            REP(k, 0, strlen(t2)) {
                t2[k] = t2[strlen(t2)-k-1];
            }

            // Insert various combinations of the parts and their reverses into the set
            st_insert(st, t); // Original order
            st_insert(st, t2); // Reversed order

            st_insert(st, strcat(t, res2)); // First part + second part
            st_insert(st, strcat(res2, t)); // Second part + first part

            st_insert(st, strcat(res, t2)); // First part + reversed second part
            st_insert(st, strcat(t2, res)); // Reversed second part + first part

            st_insert(st, strcat(res, res2)); // First part + second part (both original)
            st_insert(st, strcat(res2, res)); // Second part + first part (both original)
        }

        // Output the number of unique combinations generated
        printf("%d\n", st_size(st));
    }

    return 0; // End of the program
}


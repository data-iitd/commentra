#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include <assert.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include <assert.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include <assert.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
    int n;
    scanf("%d",&n); // Step 1: Reading Input - The program starts by reading an integer n which represents the number of test cases.

    rep(i,n) { // Step 2: Processing Each Test Case - The outer loop rep(i,n) iterates over each test case.
        char s[100000];
        scanf("%s",s); // For each test case, the program reads a string s.

        set<char*> st; // Step 3: Generating Substrings and Checking for Palindromes - A set st is used to store unique substrings.
        st.insert(s); // The first substring is inserted into the set.

        REP(j,1,strlen(s)){ // The inner loop REP(j,1,s.size()) iterates over possible split points in the string s.
            char res[100000];
            rep(k,j) { // The first part of the string is extracted and reversed.
                res[k] = s[k];
            }
            for(int k=j;k<strlen(s);k++) {
                res[k] = s[k];
            }
            for(int k=0;k<j;k++) {
                res[k] = s[k];
            }
            reverse(res,res+strlen(res)); // The first part is reversed.

            char res2[100000];
            REP(k,j,strlen(s)) { // The second part of the string is extracted and reversed.
                res2[k-j] = s[k];
            }
            for(int k=0;k<strlen(s)-j;k++) {
                res2[k] = s[k+j];
            }
            reverse(res2,res2+strlen(res2)); // The second part is reversed.

            char t[100000];
            strcpy(t,res); // The first part is concatenated with the reversed second part in both orders and added to the set.
            strcat(t,res2);
            st.insert(t);

            char t2[100000];
            strcpy(t2,res2);
            strcat(t2,res);
            st.insert(t2);

            char t3[100000];
            strcpy(t3,res); // The first part is concatenated with the reversed first part and added to the set.
            strcat(t3,s+j);
            st.insert(t3);

            char t4[100000];
            strcpy(t4,s+j);
            strcat(t4,res);
            st.insert(t4);

            char t5[100000];
            strcpy(t5,res2); // The reversed first part is concatenated with the second part and added to the set.
            strcat(t5,s+j);
            st.insert(t5);

            char t6[100000];
            strcpy(t6,s+j);
            strcat(t6,res2);
            st.insert(t6);

            char t7[100000];
            strcpy(t7,res); // The reversed first and second parts are concatenated in both orders and added to the set.
            strcat(t7,res2);
            st.insert(t7);

            char t8[100000];
            strcpy(t8,res2);
            strcat(t8,res);
            st.insert(t8);
        }

        printf("%d\n",st.size()); // Step 4: Outputting the Result - After processing all split points for a string, the size of the set st is printed.
    }

    return 0; // Step 5: End of Program - The program ends with return 0.
}


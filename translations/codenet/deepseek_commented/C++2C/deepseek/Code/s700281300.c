#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <set>
#include <sstream>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

int main() {
    int n;
    scanf("%d", &n); // Step 1: Reading Input - The program starts by reading an integer n which represents the number of test cases.

    rep(i,n) { // Step 2: Processing Each Test Case - The outer loop rep(i,n) iterates over each test case.
        char s[1000];
        scanf("%s", s); // For each test case, the program reads a string s.

        set<char*> st; // Step 3: Generating Substrings and Checking for Palindromes - A set st is used to store unique substrings.
        st.insert(s); // The first substring is inserted into the set.

        REP(j,1,strlen(s)){ // The inner loop REP(j,1,strlen(s)) iterates over possible split points in the string s.
            char res[1000], res2[1000];
            int k = 0;
            for(int l = 0; l < j; l++) { // The first part of the string is extracted and reversed.
                res[k++] = s[l];
            }
            res[k] = '\0';
            for(int l = 0; l < k; l++) { // Reverse the first part.
                s[l] = res[k-l-1];
            }
            s[k] = '\0';

            int m = 0;
            for(int l = j; l < strlen(s); l++) { // The second part of the string is extracted and reversed.
                res2[m++] = s[l];
            }
            res2[m] = '\0';
            for(int l = 0; l < m; l++) { // Reverse the second part.
                s[l] = res2[m-l-1];
            }
            s[m] = '\0';

            char t[1000], t2[1000];
            strcpy(t, res);
            strcat(t, res2); // The first part is concatenated with the reversed second part in both orders and added to the set.
            strcat(t2, res2);
            strcat(t2, res);
            st.insert(t);
            st.insert(t2);

            strcat(t, res2); // The first part is concatenated with the reversed first part and added to the set.
            strcat(res2, t);
            st.insert(t);
            st.insert(res2);

            strcat(res, t2); // The reversed first part is concatenated with the second part and added to the set.
            strcat(t2, res);
            st.insert(res);
            st.insert(t2);

            strcat(res, res2); // The reversed first and second parts are concatenated in both orders and added to the set.
            strcat(res2, res);
            st.insert(res);
            st.insert(res2);
        }

        printf("%lu\n", st.size()); // Step 4: Outputting the Result - After processing all split points for a string, the size of the set st is printed.
    }

    return 0; // Step 5: End of Program - The program ends with return 0.
}

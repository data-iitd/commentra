#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
    int n;
    scanf("%d", &n); // Step 1: Reading Input - The program starts by reading an integer n which represents the number of test cases.

    rep(i,n) { // Step 2: Processing Each Test Case - The outer loop rep(i,n) iterates over each test case.
        char s[100000];
        scanf("%s", s); // For each test case, the program reads a string s.

        int st[100000]; // Step 3: Generating Substrings and Checking for Palindromes - An array st is used to store unique substrings.
        st[0] = s[0]; // The first substring is inserted into the array.

        REP(j,1,strlen(s)){ // The inner loop REP(j,1,strlen(s)) iterates over possible split points in the string s.
            char t[100000]; // A string t is used to construct substrings.
            rep(k,j) { // The first part of the string is extracted and reversed.
                t[k] = s[k];
            }
            t[j] = '\0';
            char *res = strrev(t); // The first part is reversed.

            char t2[100000]; // Another string t2 is used to extract the second part of the string.
            REP(k,j,strlen(s)) { // The second part of the string is extracted and reversed.
                t2[k-j] = s[k];
            }
            t2[strlen(s)-j] = '\0';
            char *res2 = strrev(t2); // The second part is reversed.

            char t3[100000]; // A string t3 is used to concatenate the first part with the reversed second part in both orders.
            strcpy(t3, t);
            strcat(t3, res2);
            st[strlen(t3)] = t3[0]; // The first part is concatenated with the reversed second part in both orders and added to the array.

            char t4[100000]; // Another string t4 is used to concatenate the first part with the reversed first part.
            strcpy(t4, t);
            strcat(t4, res);
            st[strlen(t4)] = t4[0]; // The first part is concatenated with the reversed first part and added to the array.

            char t5[100000]; // A string t5 is used to concatenate the reversed first part with the second part.
            strcpy(t5, res);
            strcat(t5, t2);
            st[strlen(t5)] = t5[0]; // The reversed first part is concatenated with the second part and added to the array.

            char t6[100000]; // Another string t6 is used to concatenate the reversed first and second parts in both orders.
            strcpy(t6, res);
            strcat(t6, res2);
            st[strlen(t6)] = t6[0]; // The reversed first and second parts are concatenated in both orders and added to the array.
        }

        int count = 0; // Step 4: Outputting the Result - After processing all split points for a string, the size of the array st is printed.
        rep(i,strlen(st)) {
            if(st[i] != '\0') {
                count++;
            }
        }
        printf("%d\n", count);
    }

    return 0; // Step 5: End of Program - The program ends with return 0.
}


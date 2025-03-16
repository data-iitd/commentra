
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

// Main function starts here
int main() {
    int n; // number of strings to be processed

    // Read the number of strings from the standard input
    scanf("%d",&n);

    // Iterate through each string
    rep(i,n) {
        char s[100000]; // string to be processed

        // Read the string from the standard input
        scanf("%s",s);

        // Create an empty set to store unique substrings
        char *st[100000];
        int st_size = 0;

        // Process each substring of the string
        REP(j,1,strlen(s)){
            // Create a stringstream to store the substring
            char res[100000];
            int res_size = 0;

            // Iterate through the first j characters of the string
            rep(k,j) {
                // Add the character to the stringstream
                res[res_size++] = s[k];
            }

            // Get the substring as a string from the stringstream
            res[res_size] = '\0';

            // Create another stringstream to process the remaining characters of the string
            char res2[100000];
            int res2_size = 0;

            // Iterate through the remaining characters of the string
            REP(k,j,strlen(s)){
                // Add the character to the stringstream
                res2[res2_size++] = s[k];
            }

            // Get the substring as a string from the stringstream
            res2[res2_size] = '\0';

            // Create two temporary strings by reversing the substrings
            char t[100000];
            strcpy(t,res);
            reverse(res);
            char t2[100000];
            strcpy(t2,res2);
            reverse(res2);

            // Insert all possible combinations of the substrings and their reversed versions into the set
            st[st_size++] = strcat(strcat(strcpy(res,t),res2),t2);
            st[st_size++] = strcat(strcat(strcpy(res2,t2),res),t);
            st[st_size++] = strcat(strcat(strcpy(res,t),res2),t2);
            st[st_size++] = strcat(strcat(strcpy(res2,t2),res),t);
            st[st_size++] = strcat(strcat(strcpy(res,t),res2),t2);
            st[st_size++] = strcat(strcat(strcpy(res2,t2),res),t);
            st[st_size++] = strcat(strcat(strcpy(res,t),res2),t2);
            st[st_size++] = strcat(strcat(strcpy(res2,t2),res),t);
        }

        // Print the size of the set, which represents the number of unique substrings
        printf("%d\n",st_size);
    }

    // Main function ends here
    return 0;
}


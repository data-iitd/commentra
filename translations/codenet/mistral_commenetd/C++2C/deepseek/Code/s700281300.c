#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

// Main function starts here
int main() {
    int n; // number of strings to be processed

    // Read the number of strings from the standard input
    scanf("%d", &n);

    // Iterate through each string
    rep(i,n) {
        char s[1000]; // string to be processed

        // Read the string from the standard input
        scanf("%s", s);

        // Create an empty set to store unique substrings
        // Using a dynamically allocated array to simulate a set
        char **st = (char **)malloc(1000000 * sizeof(char *));
        int st_size = 0;

        // Process each substring of the string
        REP(j,1,strlen(s)){
            // Create a string to store the substring
            char res[1000];
            int res_len = 0;

            // Iterate through the first j characters of the string
            rep(k,j) {
                // Add the character to the substring
                res[res_len++] = s[k];
            }
            res[res_len] = '\0';

            // Create another string to store the remaining characters of the string
            char res2[1000];
            int res2_len = 0;

            // Iterate through the remaining characters of the string
            REP(k,j,strlen(s)) {
                // Add the character to the substring
                res2[res2_len++] = s[k];
            }
            res2[res2_len] = '\0';

            // Create two temporary strings by reversing the substrings
            char t[1000];
            strcpy(t, res);
            int t_len = res_len;
            for(int k = 0; k < t_len / 2; k++) {
                char temp = t[k];
                t[k] = t[t_len - k - 1];
                t[t_len - k - 1] = temp;
            }
            char t2[1000];
            strcpy(t2, res2);
            int t2_len = res2_len;
            for(int k = 0; k < t2_len / 2; k++) {
                char temp = t2[k];
                t2[k] = t2[t2_len - k - 1];
                t2[t2_len - k - 1] = temp;
            }

            // Create two temporary strings by reversing the substrings
            char temp_res[1000];
            strcpy(temp_res, res);
            int temp_res_len = res_len;
            for(int k = 0; k < temp_res_len / 2; k++) {
                char temp = temp_res[k];
                temp_res[k] = temp_res[temp_res_len - k - 1];
                temp_res[temp_res_len - k - 1] = temp;
            }
            char temp_res2[1000];
            strcpy(temp_res2, res2);
            int temp_res2_len = res2_len;
            for(int k = 0; k < temp_res2_len / 2; k++) {
                char temp = temp_res2[k];
                temp_res2[k] = temp_res2[temp_res2_len - k - 1];
                temp_res2[temp_res2_len - k - 1] = temp;
            }

            // Insert all possible combinations of the substrings and their reversed versions into the set
            char comb1[2000];
            strcpy(comb1, res);
            strcat(comb1, t2);
            int comb1_len = res_len + res2_len;
            for(int k = 0; k < comb1_len / 2; k++) {
                char temp = comb1[k];
                comb1[k] = comb1[comb1_len - k - 1];
                comb1[comb1_len - k - 1] = temp;
            }
            int found = 0;
            rep(k, st_size) {
                if (strcmp(st[k], comb1) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                st[st_size++] = strdup(comb1);
            }

            char comb2[2000];
            strcpy(comb2, res2);
            strcat(comb2, t);
            int comb2_len = res2_len + res_len;
            for(int k = 0; k < comb2_len / 2; k++) {
                char temp = comb2[k];
                comb2[k] = comb2[comb2_len - k - 1];
                comb2[comb2_len - k - 1] = temp;
            }
            found = 0;
            rep(k, st_size) {
                if (strcmp(st[k], comb2) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                st[st_size++] = strdup(comb2);
            }

            char comb3[2000];
            strcpy(comb3, res);
            strcat(comb3, temp_res2);
            int comb3_len = res_len + temp_res2_len;
            for(int k = 0; k < comb3_len / 2; k++) {
                char temp = comb3[k];
                comb3[k] = comb3[comb3_len - k - 1];
                comb3[comb3_len - k - 1] = temp;
            }
            found = 0;
            rep(k, st_size) {
                if (strcmp(st[k], comb3) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                st[st_size++] = strdup(comb3);
            }

            char comb4[2000];
            strcpy(comb4, temp_res2);
            strcat(comb4, res);
            int comb4_len = temp_res2_len + res_len;
            for(int k = 0; k < comb4_len / 2; k++) {
                char temp = comb4[k];
                comb4[k] = comb4[comb4_len - k - 1];
                comb4[comb4_len - k - 1] = temp;
            }
            found = 0;
            rep(k, st_size) {
                if (strcmp(st[k], comb4) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                st[st_size++] = strdup(comb4);
            }

            char comb5[2000];
            strcpy(comb5, t);
            strcat(comb5, temp_res);
            int comb5_len = t_len + temp_res_len;
            for(int k = 0; k < comb5_len / 2; k++) {
                char temp = comb5[k];
                comb5[k] = comb5[comb5_len - k - 1];
                comb5[comb5_len - k - 1] = temp;
            }
            found = 0;
            rep(k, st_size) {
                if (strcmp(st[k], comb5) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                st[st_size++] = strdup(comb5);
            }

            char comb6[2000];
            strcpy(comb6, temp_res);
            strcat(comb6, t);
            int comb6_len = temp_res_len + t_len;
            for(int k = 0; k < comb6_len / 2; k++) {
                char temp = comb6[k];
                comb6[k] = comb6[comb6_len - k - 1];
                comb6[comb6_len - k - 1] = temp;
            }
            found = 0;
            rep(k, st_size) {
                if (strcmp(st[k], comb6) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                st[st_size++] = strdup(comb6);
            }

            char comb7[2000];
            strcpy(comb7, res);
            strcat(comb7, temp_res2);
            int comb7_len = res_len + temp_res2_len;
            for(int k = 0; k < comb7_len / 2; k++) {
                char temp = comb7[k];
                comb7[k] = comb7[comb7_len - k - 1];
                comb7[comb7_len - k - 1] = temp;
            }
            found = 0;
            rep(k, st_size) {
                if (strcmp(st[k], comb7) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                st[st_size++] = strdup(comb7);
            }

            char comb8[2000];
            strcpy(comb8, temp_res2);
            strcat(comb8, res);
            int comb8_len = temp_res2_len + res_len;
            for(int k = 0; k < comb8_len / 2; k++) {
                char temp = comb8[k];
                comb8[k] = comb8[comb8_len - k - 1];
                comb8[comb8_len - k - 1] = temp;
            }
            found = 0;
            rep(k, st_size) {
                if (strcmp(st[k], comb8) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                st[st_size++] = strdup(comb8);
            }
        }

        // Print the size of the set, which represents the number of unique substrings
        printf("%d\n", st_size);

        // Free the allocated memory for the set
        rep(k, st_size) {
            free(st[k]);
        }
        free(st);
    }

    // Main function ends here
    return 0;
}

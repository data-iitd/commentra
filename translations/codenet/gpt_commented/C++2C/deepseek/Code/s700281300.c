#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

typedef long long ll;

int main() {
    // Read the number of test cases
    int n;
    scanf("%d", &n);

    // Process each test case
    rep(i, n) {
        char s[1000];
        // Read the string for the current test case
        scanf("%s", s);

        // Initialize a set to store unique combinations of strings
        // Using a dynamically allocated array for simplicity
        char **st = (char **)malloc(1000 * sizeof(char *));
        int st_size = 0;

        // Insert the original string into the set
        st[st_size++] = strdup(s);

        // Generate combinations by splitting the string at different positions
        REP(j, 1, strlen(s)) { 
            char res[1000], res2[1000];
            // Create the first part of the split string
            int k = 0;
            for(int m = 0; m < j; m++) {
                res[k++] = s[m];
            }
            res[k] = '\0'; // Null-terminate the first part

            int l = 0;
            // Create the second part of the split string
            for(int m = j; m < strlen(s); m++) {
                res2[l++] = s[m];
            }
            res2[l] = '\0'; // Null-terminate the second part

            // Create reversed versions of both parts
            int len = strlen(res);
            for(int m = 0; m < len / 2; m++) {
                char temp = res[m];
                res[m] = res[len - m - 1];
                res[len - m - 1] = temp;
            }

            len = strlen(res2);
            for(int m = 0; m < len / 2; m++) {
                char temp = res2[m];
                res2[m] = res2[len - m - 1];
                res2[len - m - 1] = temp;
            }

            // Insert various combinations of the parts and their reverses into the set
            char temp[1000];
            strcpy(temp, res);
            strcat(temp, res2); // Original order
            int temp_len = strlen(temp);
            int found = 0;
            rep(m, st_size) {
                if (strcmp(st[m], temp) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                st[st_size++] = strdup(temp);
            }

            strcpy(temp, res2);
            strcat(temp, res); // Reversed order
            found = 0;
            rep(m, st_size) {
                if (strcmp(st[m], temp) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                st[st_size++] = strdup(temp);
            }

            strcpy(temp, res);
            strcat(temp, res2); // First part + second part
            found = 0;
            rep(m, st_size) {
                if (strcmp(st[m], temp) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                st[st_size++] = strdup(temp);
            }

            strcpy(temp, res2);
            strcat(temp, res); // Second part + first part
            found = 0;
            rep(m, st_size) {
                if (strcmp(st[m], temp) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                st[st_size++] = strdup(temp);
            }

            strcpy(temp, res);
            strcat(temp, res2); // First part + reversed second part
            found = 0;
            rep(m, st_size) {
                if (strcmp(st[m], temp) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                st[st_size++] = strdup(temp);
            }

            strcpy(temp, res2);
            strcat(temp, res); // Reversed second part + first part
            found = 0;
            rep(m, st_size) {
                if (strcmp(st[m], temp) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                st[st_size++] = strdup(temp);
            }

            strcpy(temp, res);
            strcat(temp, res2); // First part + second part (both original)
            found = 0;
            rep(m, st_size) {
                if (strcmp(st[m], temp) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                st[st_size++] = strdup(temp);
            }

            strcpy(temp, res2);
            strcat(temp, res); // Second part + first part (both original)
            found = 0;
            rep(m, st_size) {
                if (strcmp(st[m], temp) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                st[st_size++] = strdup(temp);
            }
        }

        // Output the number of unique combinations generated
        printf("%d\n", st_size);

        // Free allocated memory
        rep(j, st_size) {
            free(st[j]);
        }
        free(st);
    }

    return 0; // End of the program
}

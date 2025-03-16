#include <stdio.h>
#include <string.h>

// Initialize variables to store the number of each contest result
int n; // number of contest results to be read
int ac_count = 0; // number of AC (Accepted) results
int wa_count = 0; // number of WA (Wrong Answer) results
int tle_count = 0; // number of TLE (Time Limit Exceeded) results
int re_count = 0; // number of RE (Runtime Error) results

int main(){
    // Read the number of contest results from the standard input
    scanf("%d", &n);

    // Read each contest result and update the corresponding counter
    for (int i = 0; i < n; ++i){
        char s[10]; // array to store the contest result (AC, WA, TLE, or RE)
        scanf("%s", s);
        if (strcmp(s, "AC") == 0){ // if the contest result is AC
            ac_count += 1; // increment the number of AC results
        } else if (strcmp(s, "WA") == 0){ // if the contest result is WA
            wa_count += 1; // increment the number of WA results
        } else if (strcmp(s, "TLE") == 0){ // if the contest result is TLE
            tle_count += 1; // increment the number of TLE results
        } else if (strcmp(s, "RE") == 0){ // if the contest result is RE
            re_count += 1; // increment the number of RE results
        }
    }

    // Print the number of each contest result to the standard output
    printf("AC x %d\n", ac_count);
    printf("WA x %d\n", wa_count);
    printf("TLE x %d\n", tle_count);
    printf("RE x %d\n", re_count);
}

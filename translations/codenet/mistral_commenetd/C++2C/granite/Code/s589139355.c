

#include <stdio.h>
#include <string.h>

int main(){
    int a, t = 0, h = 0, lt, lh, tt, hh, l; // Initialize variables

    scanf("%d", &a); // Read number of strings from user

    for(int i = 0; i < a; ++i){ // Loop through each string pair
        scanf("%s %s", taro, hana); // Read two strings from user
        lt = strlen(taro); // Get length of first string
        lh = strlen(hana); // Get length of second string

        if(lt > lh){ // Check if first string is longer
            l = lt; // Set length to be the maximum length
        }
        else{
            l = lh; // Set length to be the minimum length
        }

        tt = 0; // Initialize variables for comparing characters
        hh = 0;

        if(strcmp(taro, hana) > 0){ // Check if first string is greater lexicographically
            t = t + 3; // Increment t if true
        }
        else if(strcmp(hana, taro) > 0){
            h = h + 3; // Increment h if true
        }
        else if(strcmp(hana, taro) == 0){ // Check if strings are equal
            h = h + 1; // Increment h if true
            t = t + 1; // Increment t if true
        }
    }

    printf("%d %d", t, h); // Output the result

    return 0;
}


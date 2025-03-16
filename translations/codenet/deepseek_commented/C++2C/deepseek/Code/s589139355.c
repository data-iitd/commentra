#include <stdio.h>
#include <string.h>

int main(){
    // Initialize variables
    int a, t = 0, h = 0, lt, lh, tt, hh, l;
    int scanf_result;
    char taro[100], hana[100];

    // Read the number of games
    scanf_result = scanf("%d", &a);

    // Loop through the number of games
    for(int i = 0; i < a; ++i){
        // Read the names of Taro and Hana
        scanf_result = scanf("%s %s", taro, hana);
        
        // Get the lengths of the names
        lt = strlen(taro);
        lh = strlen(hana);
        
        // Determine the maximum length of the names
        if(lt > lh){
            l = lt;
        }
        else{
            l = lh;
        }
        
        // Initialize score counters for this round
        tt = 0;
        hh = 0;

        // Compare the names and update the scores
        if(strcmp(taro, hana) > 0){
            t = t + 3;
        }
        else if(strcmp(hana, taro) > 0){
            h = h + 3;
        }
        else if(strcmp(hana, taro) == 0){
            h = h + 1;
            t = t + 1;
        }
    }
    
    // Output the final scores
    printf("%d %d\n", t, h);

    return 0;
}

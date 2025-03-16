#include <stdio.h>

int main() {
    int sec, per_num, max_sec;
    double max_sec_double;
    int ans_num = 0;

    // Reading the number of seconds from user input
    scanf("%d", &sec);
    
    // Reading the number of items per interval from user input
    scanf("%d", &per_num);
    
    // Reading the maximum time limit, adding 0.5 to ensure proper rounding
    scanf("%lf", &max_sec_double);
    max_sec = (int)(max_sec_double + 0.5);
    
    // Looping from 'sec' to 'max_sec' in increments of 'sec'
    for (int i = sec; i < max_sec; i += sec) {
        // Accumulating the total number of items produced
        ans_num += per_num;
    }
    
    // Outputting the total number of items produced
    printf("%d\n", ans_num);

    return 0;
}

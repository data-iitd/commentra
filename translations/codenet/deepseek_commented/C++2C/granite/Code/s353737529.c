
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    int n;

    scanf("%d", &n);

    char s[1000001];
    int i = 0;

/*
2. If `n` is 0, it immediately outputs '0' and terminates. Otherwise, it proceeds to convert the integer `n` to a base -2 representation.
*/
    if(n == 0){
        printf("0\n");
        return 0;
    }
    


/*
3. Inside the `main` function, an integer `n` is read from the input using `scanf`. A character array `s` is initialized with a size of 1,000,001 to store the base -2 representation. The variable `i` is initialized to 0 as the index for the character array `s`. The function then enters a loop that continues until `n` becomes 0. Inside the loop, it checks if `n` is even or odd. If `n` is even, it appends '0' to the character array `s`; if `n` is odd, it appends '1' to the character array `s`. The function then adjusts `n` by subtracting its remainder when divided by 2 (which is 0 for even numbers and 1 for odd numbers) and dividing `n` by -2.
*/

    while(n!= 0){
        if(n % 2 == 0){
            s[i] = '0';
        } else {
            s[i] = '1';
        }

        n -= abs(n % 2);

        n /= -2;

        i++;
    }

/*
4. After the loop, the character array `s` is reversed to correct the order of the digits in the base -2 representation. Finally, the function outputs the resulting string.
*/

    for(int j = i - 1; j >= 0; j--){
        printf("%c", s[j]);
    }

    printf("\n");

/*
5. The code includes several standard libraries such as <stdio.h>, <stdlib.h>, and <string.h>. These libraries provide various functionalities for input/output operations, memory management, and string manipulation.
*/

}

Translate the above C code to Python and end with comment "
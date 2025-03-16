#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	int n;

	scanf("%d", &n);

	char s[1000000];

/*
2. If `n` is 0, it immediately outputs '0' and terminates. Otherwise, it proceeds to convert the integer `n` to a base -2 representation.
*/
	if(n == 0){
		printf("0\n");
		return 0;
	}
	

	int i = 1;
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

	s[i] = '\0';

	printf("%s\n", s);

/*
3. Inside the `main` function, a string `s` is initialized as an empty string. The function then enters a loop that continues until `n` becomes 0. Inside the loop, it checks if `n` is even or odd. If `n` is even, it appends '0' to the string `s`; if `n` is odd, it appends '1' to the string `s`. The function then adjusts `n` by subtracting its remainder when divided by 2 (which is 0 for even numbers and 1 for odd numbers) and dividing `n` by -2.
*/

/*
4. After the loop, the string `s` is reversed to correct the order of the digits in the base -2 representation. Finally, the function outputs the resulting string.
*/

}


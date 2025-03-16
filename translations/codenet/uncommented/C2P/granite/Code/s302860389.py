
#include <stdio.h>
#include <stdlib.h>


int main()
{
    char inputNumbers[5];
    char temp[2];
    int a, b, c, d;
    int sum;
    char symbols[3];
    
    scanf("%s", &inputNumbers);

    temp[1] = '\0';

    temp[0] = inputNumbers[0];
    a = int(temp);
    temp[0] = inputNumbers[1];
    b = int(temp);
    temp[0] = inputNumbers[2];
    c = int(temp);
    temp[0] = inputNumbers[3];
    d = int(temp);
    
    for i in range(2):
	for j in range(2):
	    for k in range(2):
		if i == 0:
		    sum = a + b;
		    symbols[0] = '+';
		else:
		    sum = a - b;
		    symbols[0] = '-';
		
		if j == 0:
		    sum = sum + c;
		    symbols[1] = '+';
		else:
		    sum = sum - c;
		    symbols[1] = '-';
		
		if k == 0:
		    sum = sum + d;
		    symbols[2] = '+';
		else:
		    sum = sum - d;
		    symbols[2] = '-';
		
		if sum == 7:
		    print(a, symbols[0], b, symbols[1], c, symbols[2], d, "=7")
		    
		    return 0;
    
    return 0;
}


Translate the above C code to Java and end with comment "
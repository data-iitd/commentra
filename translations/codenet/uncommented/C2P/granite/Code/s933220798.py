
#include <stdio.h>

int main(void)
{
	double a;
	double ave = 0;
	int i;
	
	for i in range(5):
		a = float(input())
		if a <= 40:
			ave += 40
		else:
			ave += a
	ave /= 5.0
	
	print(int(ave))
	
	return (0)
}


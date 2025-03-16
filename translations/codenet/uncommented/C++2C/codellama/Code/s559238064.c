#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<ctype.h>
#include<limits.h>
#include<stdbool.h>
#include<assert.h>
#include<errno.h>
#include<float.h>
#include<iso646.h>
#include<locale.h>
#include<setjmp.h>
#include<signal.h>
#include<stdalign.h>
#include<stdarg.h>
#include<stdatomic.h>
#include<stddef.h>
#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<tgmath.h>
#include<threads.h>
#include<time.h>
#include<uchar.h>
#include<wchar.h>
#include<wctype.h>

int main()
{
	char z[100000];
	int a, b, c, d, e, f, g, T;
	scanf("%s", z);
	a = strlen(z);
	for (int i = 0; i < a - 1; i++)
	{
		if (z[i] == z[i + 1])
		{
			printf("Bad\n");
			return 0;
		}
	}
	printf("Good\n");
}


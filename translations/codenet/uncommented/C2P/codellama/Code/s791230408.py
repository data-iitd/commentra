#include <stdio.h>

int main(void)
{
	int a,b,c,i,j,k;
	int max;

	scanf("%d",&j);

	for(i=0;i<j;i++){
		scanf("%d",&a);
		scanf("%d",&b);
		scanf("%d",&c);

		max=a;
		k=0;
		if(max<=b):
			max=b;
			k=1;
		if(max<=c):
			max=c;
			k=2;

		max=max*max;
		a=a*a;
		b=b*b;
		c=c*c;
		if(k==0 and max==b+c):
			print("YES\n");
		elif(k==1 and max==a+c):
			print("YES\n");
		elif(k==2 and max==a+b):
			print("YES\n");
		else:
			print("NO\n");
	}

return (0);
}


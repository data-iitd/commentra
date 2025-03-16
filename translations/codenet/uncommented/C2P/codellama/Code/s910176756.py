#include<stdio.h>
int main():
a, b, c = 0, 0, 0
op = ''
scanf("%d %c %d", &a, &op, &b)
while( 1 ):
if ( op == '+' ):
c = a + b
printf("%d\n",c)
elif ( op == '-' ):
c = a - b
printf("%d\n",c)
elif ( op == '*' ):
c = a * b
printf("%d\n",c)
elif ( op == '/' ):
c = a / b
printf("%d\n",c)
else:
break
scanf("%d %c %d", &a, &op, &b)
return 0

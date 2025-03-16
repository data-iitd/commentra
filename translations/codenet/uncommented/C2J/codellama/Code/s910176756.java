#include<stdio.h>
public class Main {
public static void main(String[] args) {
int a, b, c;
char op;
scanf("%d %c %d", &a, &op, &b);
while( 1 ){
if ( op == '+' ){
c = a + b;
printf("%d\n",c);
} 
else if ( op == '-' ){
c = a - b;
printf("%d\n",c);
} 
else if ( op == '*' ){
c = a * b;
printf("%d\n",c);
} 
else if ( op == '/' ){
c = a / b;
printf("%d\n",c);
} 
else {
break;
}
scanf("%d %c %d", &a, &op, &b);
}
}
}

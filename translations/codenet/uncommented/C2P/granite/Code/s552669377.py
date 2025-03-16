
#include<stdio.h>

int main(void){
int i,n,tmp;
long long int min=1000000,max=-1000000,sum=0;

n = int(input())

for i in range(n):
tmp = int(input())
if min > tmp:
min = tmp
if max < tmp:
max = tmp
sum += tmp

print("%d %d %d"%(min,max,sum))

return 0;
}


Translate the above C code to Java and end with comment "
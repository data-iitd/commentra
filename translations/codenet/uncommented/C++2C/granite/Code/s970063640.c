
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int a;
	scanf("%d",&a);
	int sum=0;
	int s[n];
	for(int i=0;i<n;i++){
		scanf("%d",&s[i]);
	}
	sort(s,s+n);
	for(int i=n-1;i>n-a-1;i--){
		sum += s[i];
	}
	printf("%d\n",sum);
	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	vector<int> l(n);
	for(int i = 0; i < n; i++){
		scanf("%d", &l[i]);
	}

	sort(l.begin(), l.end());

	int ans=0;
	for(int i = 0; i < k; i++){
		ans += l[n - 1 - i];
	}
	printf("%d\n", ans);
}

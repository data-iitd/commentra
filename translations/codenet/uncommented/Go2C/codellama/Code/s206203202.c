#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int Abs(int x) {
	if (x < 0) {
		return -x;
	}
	return x;
}

int min(int a, int b) {
	if (a > b) {
		return b;
	}
	return a;
}

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
// 	hm := make(map[int]bool)
// 	for{
// 		if(!hm[N]){
// 			hm[N]=true;
// 			N = Abs(N-K)
// 		}else{
// 			break;
// 		}
// 	}
// 	var mini int;
// 	mini=999999999
// 	for k:= range hm{
// 		mini=min(mini,k)
// 	}
// 	printf("%d\n", mini)
// }
	int x;
	x = N % K;
	x = min(Abs(x - K), x);
	printf("%d\n", x);
}

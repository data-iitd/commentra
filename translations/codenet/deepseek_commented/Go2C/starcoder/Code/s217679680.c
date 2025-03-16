#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int arr[2];
	scanf("%d %d", &arr[0], &arr[1]);
	int a = arr[0], b = arr[1];
	int tap = 0, consent = 1;
	while (consent < b) {
		consent += a - 1;
		tap++;
	}
	printf("%d", tap);
}


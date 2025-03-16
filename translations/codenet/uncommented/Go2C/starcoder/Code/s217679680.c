#include <stdio.h>
#include <stdlib.h>

int main() {
	int arr[2];
	for (int i = 0; i < 2; i++) {
		scanf("%d", &arr[i]);
	}
	int a = arr[0], b = arr[1];
	int tap = 0, consent = 1;
	for (consent < b) {
		consent = consent + a - 1;
		tap++;
	}
	printf("%d", tap);
}

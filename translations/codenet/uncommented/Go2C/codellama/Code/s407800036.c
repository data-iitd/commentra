#include <stdio.h>

int main() {
	// Code for A - Between Two Integers
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);

	if (C >= A && C <= B) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}

	// 
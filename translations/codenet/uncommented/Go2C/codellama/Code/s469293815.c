// Package main provides
//
// File:  a.c
// Author: ymiyamoto
//
// Created on Sat Dec 29 04:47:30 2018
//
#include <stdio.h>

int main() {
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);

	if (A+B >= C) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}

	return 0;
}


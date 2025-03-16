#include<stdio.h>

def compare(a, b):
    return (b - a)

def main():
    array = [0] * 10
    for i in range(10):
        scanf("%d", array[i])
    qsort(array, 10, sizeof(int), compare)
    for i in range(3):
        printf("%d\n", array[i])
    return 0



#include<stdio.h>
#include<stdlib.h>

def compare(a, b):
    return b - a

array = [0] * 10

for i in range(10):
    array[i] = int(input())

array.sort(compare)

for i in range(3):
    print(array[i])


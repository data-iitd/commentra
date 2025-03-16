#include <string.h>
#include<stdio.h>
def main():
    i = 0
    sum = 0
    flag = 0
    x = []
    scanf("%s",x)
    while True:
        for i in range(1002):
            if x[i] == 0:
                print(sum)
                break
            else:
                sum += x[i] - 0x30
        sum = 0
        scanf("%s",x)
        if x[0] == 0x30:
            break

    return 0


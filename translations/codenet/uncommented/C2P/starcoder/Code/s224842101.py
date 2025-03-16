
#include <stdio.h>

def main():
    count = [0, 0, 0, 0]
    for i in range(3):
        a, b = map(int, input().split())
        count[a-1] += 1
        count[b-1] += 1
    s = 1
    for i in range(4):
        s *= count[i]
    if s == 4:
        print("YES")
    else:
        print("NO")

main()


#include <vector>
#include <iostream>
#include <algorithm>
n, k, t = 0, 0, 0
vec = []
ans = 1000000001
def main():
    stdin.readline()
    n, k = map(int, stdin.readline().split())
    for i in range(n):
        t = int(stdin.readline())
        vec.append(t)
    vec.sort()
    for i in range(n-k+1):
        diff = vec[i+k-1] - vec[i]
        if diff < ans:
            ans = diff
    print(ans)



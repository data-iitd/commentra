# Python 3.6.2
# Author: <NAME>
# Date: 2018-02-12
# License: MIT License
# Description: Solution to the problem "The Great Wall"
# Problem: https://www.codechef.com/FEB18/problems/WALLS
# Code:
tc, n, m = map(int, input().split())
for i in range(1, m+1):
    if i*tc >= n and i*tc <= m:
        print("OK")
        break
else:
    print("NG")
# 
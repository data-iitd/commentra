
import sys
import math
import bisect
import heapq
import random
import re
import collections
import itertools
import time
import string
import copy
import os
import json
import decimal

# A := strings.Split(nextLine(), " ")

X := strings.Split(nextLine(), " ")

# Z := strings.Split(nextLine(), " ")
# n, _ := strconv.Atoi(input[0])

N, _ = map(int, X[0])
A, _ = map(int, X[1])
B, _ = map(int, X[2])
C, _ = map(int, X[3])

# K, _ := strconv.Atoi(X[2]) #strconv.ParseInt(X[2], 10, 64)

# Y := strings.Split(nextLine(), " ")

arr = []
dp = []
ans = 10000
ss = A + B + C
# sort.Sort(sort.Reverse(sort.IntSlice(arr)))
for i in range(N):
    Y := strings.Split(nextLine(), " ")

    a, _ = map(int, Y[0])
    arr.append(a)

dfs(dp, 0, arr)

# print(ans)
print(ans)

# 
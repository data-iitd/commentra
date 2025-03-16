
import sys
import math

# n, q = map(int, input().split())
# C = list(map(int, input().split()))

# P = [-1] * (n + 1)
# Q = []

# for i in range(q):
#     l, r = map(int, input().split())
#     query = (i, l, r)
#     Q.append(query)

# Q.sort(key=lambda x: x[2])
# ft = FenwickTree(500000 + 50)

# k = 0
# for query in Q:
#     # Process each query
#     while k < query[2]:
#         if P[C[k]] != -1:
#             ft.add(P[C[k]] + 1, -1)
#         P[C[k]] = k
#         ft.add(k + 1, 1)

#         k += 1

#     # Calculate answer and print it
#     print(ft.sum(query[2]) - ft.sum(query[1] - 1))

# 
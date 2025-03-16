N, K = map(int, input().split())
v = list(map(int, input().split()))

count = ((N - 1) + ((K - 1) - 1)) // (K - 1)
print(count)


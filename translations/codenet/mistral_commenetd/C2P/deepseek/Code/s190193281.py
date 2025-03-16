N = 1000000
Q = 50000

def binary_search(key, S):
    left = 0
    right = len(S)
    while left < right:
        mid = (left + right) // 2
        if S[mid] == key:
            return 1
        elif key < S[mid]:
            right = mid
        else:
            left = mid + 1
    return 0

n = int(input("Enter the size of the array: "))
S = list(map(int, input().split()))

q = int(input("Enter the number of queries: "))
T = list(map(int, input().split()))

c = 0
for i in range(q):
    if binary_search(T[i], S) == 1:
        c += 1

print("Number of queries present in the array:", c)

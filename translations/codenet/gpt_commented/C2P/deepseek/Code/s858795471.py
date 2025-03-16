def search(A, n, key):
    i = 0
    A.append(key)
    while A[i] != key:
        i += 1
    return i != n

def main():
    n = int(input())
    A = list(map(int, input().split()))
    q = int(input())
    sum_ = 0
    for _ in range(q):
        key = int(input())
        if search(A, n, key):
            sum_ += 1
    print(sum_)

main()

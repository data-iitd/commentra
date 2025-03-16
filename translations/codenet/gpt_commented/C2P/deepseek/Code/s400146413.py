def linear_search(S, n, key):
    i = 0
    count = 0

    while S[i] != key:
        i += 1
        if i >= n:
            count = 1
            return count
    return count

def main():
    n = int(input())
    S = list(map(int, input().split()))
    q = int(input())
    T = list(map(int, input().split()))

    count = 0

    for key in T:
        if linear_search(S, n, key) == 0:
            count += 1

    print(count)

main()


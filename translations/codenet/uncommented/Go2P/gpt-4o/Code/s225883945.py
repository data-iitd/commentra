def next_int():
    return int(input().strip())

def next_ints(n):
    return list(map(int, input().strip().split()))[:n]

def main():
    n, k = next_int(), next_int()
    a = next_ints(n)
    # To avoid unused variable warning
    a[0] = 0

    sum = k
    ans = 1
    while sum < n:
        sum = sum - 1 + k
        ans += 1
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

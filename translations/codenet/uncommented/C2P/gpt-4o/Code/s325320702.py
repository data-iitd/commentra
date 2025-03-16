def count_divisible(l, r, d):
    ans = 0
    for i in range(l, r + 1):
        if i % d == 0:
            ans += 1
    return ans

if __name__ == "__main__":
    l = int(input())
    r = int(input())
    d = int(input())
    result = count_divisible(l, r, d)
    print(result)

# <END-OF-CODE>

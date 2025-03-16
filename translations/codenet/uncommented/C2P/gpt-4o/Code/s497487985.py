def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

def lcm(a, b):
    return a * b // gcd(a, b)

def main():
    n, k, q = map(int, input().split())
    a = [0] * q
    point = [0] * n

    for i in range(q):
        a[i] = int(input())
        point[a[i] - 1] += 1

    for i in range(n):
        if k - (q - point[i]) > 0:
            print("Yes")
        else:
            print("No")

if __name__ == "__main__":
    main()

# <END-OF-CODE>

def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

def lcm(a, b):
    return a * b // gcd(a, b)

def main():
    n = int(input())
    k = int(input())
    q = int(input())
    a = [int(input()) for _ in range(q)]
    point = [0] * (n + 1)

    for i in range(q):
        point[a[i] - 1] += 1

    for i in range(n):
        if k - (q - point[i]) > 0:
            print("Yes")
        else:
            print("No")

main()

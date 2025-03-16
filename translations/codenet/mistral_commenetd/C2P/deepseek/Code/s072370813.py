def main():
    # Read input
    N = int(input())
    A = list(map(int, input().split()))

    # Calculate sum and wa
    sum_A = sum(A)
    wa = sum(i + 1 for i in range(N))

    # Check if sum is divisible by wa
    if sum_A % wa != 0:
        print("NO")
        return

    # Calculate quotient of sum and wa
    shou = sum_A // wa

    # Calculate differences between adjacent elements and store in array sa
    sa = [(A[(i + 1) % N] - A[i] - shou) for i in range(N)]

    # Check if any difference is less than or equal to 0 and divisible by N
    for s in sa:
        if s > 0 or s % N != 0:
            print("NO")
            return

    print("YES")

if __name__ == "__main__":
    main()

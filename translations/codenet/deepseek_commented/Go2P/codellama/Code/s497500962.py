
import math

def main():
    R = int(input())
    G = int(input())
    B = int(input())
    N = int(input())

    ans = 0
    # Iterate over all possible values of x and y
    for x in range(N + 1):
        for y in range(N + 1):
            # Calculate the remaining value after subtracting x*R and y*G
            tmp = N - R*x - G*y
            # Check if the remaining value is non-negative and a multiple of B
            if tmp >= 0 and tmp % B == 0:
                ans += 1

    print(ans)

if __name__ == "__main__":
    main()


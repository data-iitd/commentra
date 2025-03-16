
import math

def main():
    N = int(input())
    count = 0
    temp = N
    ans = 0

    # Calculate the number of digits in N
    while temp > 0:
        temp //= 10
        count += 1

    # Iterate from 1 to the number of digits in N
    for i in range(1, count + 1):
        if i == count:  # Check if it's the last digit
            if i % 2 == 1:  # Check if the position is odd
                ans += (N - math.pow(10, i - 1) + 1)
        else:
            if i == 1:  # Check if it's the first digit
                ans += 9
            elif i % 2 == 1:  # Check if the position is odd
                ans += (math.pow(10, i) - math.pow(10, i - 1))

    print(ans)


if __name__ == "__main__":
    main()


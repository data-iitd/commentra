import sys

def main():
    # Reading the number of test cases (n) from the input
    n = int(sys.stdin.readline().strip())

    a = 0
    b = 0
    c = 0

    # Summing up the first number in each test case
    for _ in range(n):
        a += int(sys.stdin.readline().strip())

    # Summing up the second number in each test case (except the last one)
    for _ in range(n - 1):
        b += int(sys.stdin.readline().strip())

    # Summing up the third number in each test case (except the last two)
    for _ in range(n - 2):
        c += int(sys.stdin.readline().strip())

    # Calculating the differences
    x = a - b
    y = b - c

    # Printing the results
    print(x)
    print(y)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

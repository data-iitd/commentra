import sys

def main():
    # Reading the number of test cases from the standard input stream
    n = int(sys.stdin.readline().strip())

    # Initializing two variables to keep track of the sum of x and y coordinates respectively
    s1, s2 = 0, 0
    ch = []  # List to store characters

    # Reading input for each test case
    for _ in range(n):
        x, y = map(int, sys.stdin.readline().strip().split())

        temp1 = s1 + x
        temp2 = s2 + y

        # Checking if the difference between the sums is within the limit of 500
        if abs(temp1 - temp2) <= 500:
            s1 += x
            ch.append('A')
            continue

        # Checking if the difference between the absolute values of the sums is within the limit of 500
        if abs(temp1 - s2) <= 500:
            s2 += y
            ch.append('G')
            continue

        # If the difference between the sums is greater than 500, set the flag to 1
        print(-1)
        return

    # If the flag is not set to 1, print the result
    print(''.join(ch))

if __name__ == "__main__":
    main()

def main():
    # Read the value of n from standard input
    n = int(input())

    # Loop through numbers from 1 to n
    for i in range(1, n + 1):
        # Initialize x with the current number i
        x = i

        # Check if the number is divisible by 3 or ends with 3
        if x % 3 == 0 or x % 10 == 3:
            print(" " + str(i), end='')  # Output the number if the condition is met
            continue
        else:
            # Check each digit of the number to see if it contains 3
            s = str(x)
            k = len(s)
            while k > 0:
                k -= 1
                j = 10 ** k
                if (x // j) % 10 == 3:
                    print(" " + str(i), end='')  # Output the number if '3' is found in any digit
                    break

    # Output a newline character at the end of the program
    print()


if __name__ == "__main__":
    main()

def main():
    while True:
        try:
            # Read three integers from standard input
            a, b, n = map(int, input().split())
        except EOFError:
            break  # Break if input reading fails

        # Reduce 'a' to its remainder when divided by 'b'
        a -= a // b * b

        # Initialize sum to zero
        total_sum = 0

        # Outer loop runs 'n' times
        for i in range(1, n + 1):
            # Multiply 'a' by 10 to shift the decimal point
            a *= 10

            # Inner loop iterates from 9 down to 0
            for j in range(9, -1, -1):
                # Find the largest digit 'j' such that 'b*j' is less than or equal to 'a'
                if b * j <= a:
                    break

            # Subtract 'b*j' from 'a' and add 'j' to the sum
            a -= b * j
            total_sum += j

        # Output the sum of the digits
        print(total_sum)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

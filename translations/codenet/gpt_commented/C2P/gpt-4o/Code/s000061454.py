def main():
    while True:
        try:
            # Read three integers a, b, and n from standard input
            a, b, n = map(int, input().split())
        except EOFError:
            break  # Break the loop if input fails

        # Adjust 'a' to be the remainder when divided by 'b'
        a -= a // b * b
        # Initialize sum to accumulate the result
        total_sum = 0

        # Loop 'n' times to process each digit
        for i in range(1, n + 1):
            # Scale 'a' by 10 to shift left for the next digit
            a *= 10

            # Find the largest digit 'j' (0-9) such that b*j <= a
            for j in range(9, -1, -1):
                if b * j <= a:
                    break  # If condition is met, exit the loop

            # Subtract the value of b*j from 'a'
            a -= b * j
            # Add the digit 'j' to the sum
            total_sum += j

        # Output the final sum for the current input set
        print(total_sum)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

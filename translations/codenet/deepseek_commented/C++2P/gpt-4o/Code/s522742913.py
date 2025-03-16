import math

def main():
    # Step 1: Input Handling
    # The program starts by taking a string input from the user.
    source = input()

    # It checks if the length of the input string is within the valid range (1 to 10 characters).
    # If not, it returns -1.
    if len(source) > 10 or len(source) < 1:
        return -1

    # Step 2: Calculation Setup
    # The program calculates the maximum number of combinations that can be formed
    # by placing '+' signs between the digits of the input string.
    # This is done using the formula 2^(n-1), where n is the length of the input string.
    max_i = int(math.pow(2, len(source) - 1))

    # Step 3: Iterating Over Combinations
    # The program iterates over all possible combinations of placing '+' signs between the digits.
    # For each combination, it calculates the sum of the numbers formed by the substrings separated by '+' signs.
    total_sum = 0

    for i in range(max_i):
        plus = bin(i)[2:].zfill(len(source) - 1)  # Get binary representation of i
        number = 0
        working = source

        # Process the current combination of '+' placements
        for j in range(len(plus)):
            if plus[j] == '1':
                total_sum += float(working[:j + 1])  # Add the number formed so far
                working = working[j + 1:]  # Update working string

        total_sum += float(working)  # Add the last remaining part

    # Step 4: Output
    # Finally, the program outputs the sum of all possible combinations.
    print(f"{total_sum:.0f}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>

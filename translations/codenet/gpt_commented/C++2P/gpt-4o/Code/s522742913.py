import math

def main():
    # Declare a string variable to hold the input
    source = input()

    # Check if the input length is valid (between 1 and 10 characters)
    if len(source) > 10 or len(source) < 1:
        # Return -1 if the input length is invalid
        return -1

    # Calculate the maximum number of combinations of '+' placements
    max_i = int(math.pow(2, len(source) - 1))

    # Initialize a variable to hold the cumulative sum of the evaluated expressions
    total_sum = 0

    # Iterate through all possible combinations of '+' placements
    for i in range(max_i):
        # Create a bit representation of the current combination of '+' placements
        plus = bin(i)[2:].zfill(len(source) - 1)

        # Initialize a variable to hold the current number being evaluated
        working = source
        current_sum = 0

        # While there are still '+' placements to evaluate
        for j in range(len(plus)):
            # If the current bit is '1', we split the string
            if plus[j] == '1':
                # Convert the substring up to the current position to a float and add to current_sum
                current_sum += float(working[:j + 1])
                # Update the working string to remove the processed segment
                working = working[j + 1:]

        # Add the remaining part of the working string to the current_sum
        current_sum += float(working)
        # Add the current_sum to the total_sum
        total_sum += current_sum

    # Print the final sum
    print(f"{total_sum:.0f}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>

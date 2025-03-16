# Import the itertools module for working with combinations
import itertools

# Define a helper function 'find' to locate the indices of a character in a string
def find(s, ch):
    # Use list comprehension to create a list of indices where the character 'ch' appears in the string 's'
    return [i for i, ltr in enumerate(s) if ltr == ch]

# Check if the given input is valid and execute the main logic if it is
if __name__ == '__main__':
    # Read the number of test cases 'n' from the standard input
    n = int(input())

    # Read the string 's' from the standard input and remove any leading or trailing whitespaces
    s = input().replace("", "")

    # Check if the string 's' does not contain '0' character
    if '0' not in s:
        # If '0' is not present, print the result as the number of test cases minus one
        print(n - 1)

    # If '0' is present, proceed with further logic
    else:
        # Find the indices of '0' character in the string 's'
        indices = find(s, '0')

        # Check if there is only one '0' character in the string 's'
        if len(indices) == 1:
            # If there is only one '0', print the result as the number of '1's in the string
            print(n)

        # If there are multiple '0's, calculate the maximum combination score
        else:
            # Initialize the maximum combination score as 0
            maximum = 0

            # Generate all possible combinations of indices of '0' characters using itertools.combinations()
            combs = itertools.combinations(indices, 2)

            # Iterate through each combination and calculate the score for that combination
            for x in combs:
                # Calculate the score for the current combination using the given formula
                score = 2 + 2 * (abs(indices.index(x[0]) - indices.index(x[1])) - 1) - (abs(x[0] - x[1]) - 1)
                # Update the maximum combination score if the current combination score is greater
                maximum = max(maximum, score)

            # Print the final result which is the number of '1's in the string plus the maximum combination score
            print(s.count('1') + maximum)

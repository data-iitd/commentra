
def atc_079a(input_value: str) -> str:
    """
    This function checks if the given string has a substring of length n.
    :param input_value: A string to check for a substring of length n.
    :return: The string "Yes" if the string has a substring of length n, otherwise the string "No".
    """
    n = 3  # The length of the substring to search for.

    # Iterate through the input string with a sliding window of size n.
    for i in range(0, len(input_value) + 1 - n):
        # Initialize a nested for loop to check for a matching substring.
        for j in range(1, n):
            # Check if the characters at indices i and i+j are equal.
            if input_value[i] != input_value[i + j]:
                # If they are not equal, break out of the inner for loop.
                break
            # If the inner for loop completes without finding a mismatch,
            # return the string "Yes".
            if j == n - 1:
                return "Yes"

    # If the inner for loop completes and a mismatch is found, return the string "No".
    return "No"

# Get user input and call the function with the input.
input_value = input()
print(atc_079a(input_value))
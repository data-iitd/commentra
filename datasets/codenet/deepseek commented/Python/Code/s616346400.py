
def atc_079a(input_value: str) -> str:
    # Set the length of the substring to check
    n = 3
    # Iterate over the input string to find possible substrings of length n
    for i in range(0, len(input_value) + 1 - n):
        # Check each character in the substring
        for j in range(1, n):
            # If any character in the substring is different, break the inner loop
            if input_value[i] != input_value[i + j]:
                break
            # If all characters in the substring are the same, return "Yes"
            if j == n - 1:
                return "Yes"
    # If no such substring is found, return "No"
    return "No"

# Take an input from the user
input_value = input()
# Print the result of the function call
print(atc_079a(input_value))


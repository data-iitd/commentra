# Read two strings from user input
# The first string will be compared with the second string character by character
# The input() function captures user input from the console
# The map function will apply the lambda function to each pair of characters from the two strings
print(
    # Use the map function to compare characters from both input strings
    sum(
        # Lambda function that checks if characters from both strings are equal
        map(
            lambda x, y: x == y,  # Compare characters x and y for equality
            input(),              # First input string
            input()               # Second input string
        )
    )
)

# Declare a function to process the input string
def process_string(input_string):
    # Initialize an empty list to store the result
    ans = []
    
    # Iterate through each character of the input string
    for char in input_string:
        # If the current character is not 'B', append it to the 'ans' list
        if char != 'B':
            ans.append(char)
        # If the current character is 'B', remove the last character from 'ans' (if it exists)
        elif ans:
            ans.pop()
    
    # Join the list into a string and return it
    return ''.join(ans)

# Read a string input from the user
input_string = input()
# Process the input string and print the result
print(process_string(input_string))

# <END-OF-CODE>

import sys

# Define a function to check if a pair of brackets is valid
def is_paired(left_bracket, right_bracket):
    # Define a list of paired brackets
    paired_brackets = [
        ('(', ')'),
        ('[', ']'),
        ('{', '}'),
        ('<', '>'),
    ]
    
    # Iterate through the paired brackets to find a match
    for paired_bracket in paired_brackets:
        if left_bracket == paired_bracket[0] and right_bracket == paired_bracket[1]:
            return True # Return true if a matching pair is found
    return False # Return false if no matching pair is found

# Define a function to check if the input string of brackets is balanced
def is_balanced(brackets):
    # Check for null input and throw an exception if true
    if brackets is None:
        raise ValueError("Input string is null")
    
    # Create a stack to keep track of opening brackets
    brackets_stack = []
    
    # Iterate through each character in the input string
    for bracket in brackets:
        if bracket == '(' or bracket == '[' or bracket == '<' or bracket == '{':
            # If the character is an opening bracket, push it onto the stack
            brackets_stack.append(bracket)
        elif bracket == ')' or bracket == ']' or bracket == '>' or bracket == '}':
            # If the character is a closing bracket
            if len(brackets_stack) == 0 or not is_paired(brackets_stack.pop(), bracket):
                return False # Return false if not balanced
        else:
            return False # Return false if not a bracket
    
    # Return true if all opening brackets have been matched and the stack is empty
    return len(brackets_stack) == 0

# Read a line of input from the user
input_string = sys.stdin.readline().strip()

# Check if the input brackets are balanced and store the result
result = is_balanced(input_string)

# Print the result: either "Balanced" or "Not Balanced"
print("Balanced" if result else "Not Balanced")

# End of code

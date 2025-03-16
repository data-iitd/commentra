def is_paired(left_bracket, right_bracket):
    # Define a dictionary of paired brackets
    paired_brackets = {
        '(': ')',
        '[': ']',
        '{': '}',
        '<': '>',
    }
    
    # Return True if the brackets are a pair, otherwise False
    return paired_brackets.get(left_bracket) == right_bracket

def is_balanced(brackets):
    # Check for None input and raise an exception if true
    if brackets is None:
        raise ValueError("Input string is None")
    
    # Create a stack to keep track of opening brackets
    brackets_stack = []
    
    # Iterate through each character in the input string
    for bracket in brackets:
        # If the character is an opening bracket, push it onto the stack
        if bracket in "([{<":
            brackets_stack.append(bracket)
        # If the character is a closing bracket
        elif bracket in ")]}>":
            # Check if the stack is empty or if the brackets do not match
            if not brackets_stack or not is_paired(brackets_stack.pop(), bracket):
                return False  # Return False if not balanced
        # If the character is not a bracket, return False
        else:
            return False
    
    # Return True if all opening brackets have been matched and the stack is empty
    return not brackets_stack

# Main function to read input and print the result
def main():
    # Read a line of input from the user
    input_brackets = input()
    
    # Check if the input brackets are balanced and store the result
    result = is_balanced(input_brackets)
    
    # Print the result: either "Balanced" or "Not Balanced"
    print("Balanced" if result else "Not Balanced")

# Call the main function
main()

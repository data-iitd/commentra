import re
import sys

# Main method to start the application
def main():
    infixExpression = sys.stdin.readline().strip() # Read the infix expression from the user input

    try:
        prefixExpression = infix2Prefix(infixExpression) # Call the infix2Prefix method to convert infix expression to prefix expression
        print("Prefix Expression:") # Print the prefix expression to the console
        print(prefixExpression)
    except (ValueError, TypeError) as e: # Catch any ValueError or TypeError thrown during the execution
        print("Error: " + str(e)) # Print the error message to the console

# Method to convert infix expression to prefix expression
def infix2Prefix(infixExpression):
    if infixExpression is None: # Check if the input expression is null
        raise TypeError("Input expression cannot be null.") # Throw a TypeError if it is

    infixExpression = infixExpression.strip() # Trim any leading or trailing white spaces from the input expression

    if infixExpression == "": # Check if the input expression is empty
        return "" # Return an empty string if it is

    if not isBalanced(filterBrackets(infixExpression)): # Check if the input expression is balanced
        raise ValueError("Invalid expression: unbalanced brackets.") # Throw a ValueError if it is not balanced

    output = "" # Create a string to store the prefix expression
    stack = [] # Create a list to store the opening brackets or operators

    reversedInfix = infixExpression[::-1] # Reverse the input expression

    for element in reversedInfix: # Iterate through each character in the reversed input expression
        if element.isalpha() or element.isdigit(): # If the character is a letter or a digit, add it to the output
            output += element
        elif element == ')' or element == '}' or element == ']' or element == '>': # If the character is a closing bracket, pop and add the corresponding opening bracket to the output
            while stack and not isMatchingPair(stack[-1], element):
                output += stack.pop()
            stack.pop()
        else: # If the character is an operator, push it to the stack if it has higher or equal precedence than the top element
            while stack and precedence(stack[-1]) >= precedence(element):
                output += stack.pop()
            stack.append(element)

    while stack: # Add any remaining operators to the output
        output += stack.pop()

    return output[::-1] # Reverse the output and return it as the prefix expression

# Helper method to calculate the precedence of an operator
def precedence(operator):
    if operator == '+' or operator == '-':
        return 1
    elif operator == '*' or operator == '/':
        return 2
    elif operator == '^':
        return 3
    else:
        return 0

# Helper method to filter out any non-relevant characters from the input expression
def filterBrackets(input):
    return re.sub("[^(){}\\[\\]<>]", "", input) # Use a regular expression to match any non-bracket characters

# Helper method to check if two brackets are matching pairs
def isMatchingPair(open, close):
    return (open == '(' and close == ')') or \
           (open == '{' and close == '}') or \
           (open == '[' and close == ']') or \
           (open == '<' and close == '>') # Use a simple if-else statement to determine if the brackets are matching pairs

# Helper method to check if the input expression is balanced
def isBalanced(input):
    stack = [] # Create a list to store the opening brackets

    for element in input: # Iterate through each character in the input expression
        if element == '(' or element == '{' or element == '[' or element == '<': # If the character is an opening bracket, push it to the stack
            stack.append(element)
        elif element == ')' or element == '}' or element == ']' or element == '>': # If the character is a closing bracket, pop and add the corresponding opening bracket to the output
            if not stack or not isMatchingPair(stack[-1], element):
                return False
            stack.pop()

    return not stack # Check if the stack is empty

if __name__ == "__main__":
    main()


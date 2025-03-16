import re
import sys

# Function to convert infix expression to prefix expression
def infix2Prefix(infixExpression):
    # Check if the input expression is null and throw an exception if it is
    if infixExpression == None:
        raise Exception("Input expression cannot be null.")
    
    # Trim whitespace from the expression
    infixExpression = infixExpression.strip()
    
    # Return an empty string if the expression is empty
    if infixExpression == "":
        return ""
    
    # Check if the brackets in the expression are balanced
    if not isBalanced(filterBrackets(infixExpression)):
        raise Exception("Invalid expression: unbalanced brackets.")
    
    # Initialize a StringBuilder to hold the output prefix expression
    output = ""
    # Create a stack to hold operators and parentheses
    stack = []
    # Reverse the infix expression for processing
    reversedInfix = infixExpression[::-1]
    
    # Process each character in the reversed infix expression
    for element in reversedInfix:
        # If the character is an operand, add it to the output
        if element.isalpha() or element.isdigit():
            output += element
        # If the character is a closing parenthesis, push it onto the stack
        elif element == ")":
            stack.append(element)
        # If the character is an opening parenthesis, pop from the stack until a closing parenthesis is found
        elif element == "(":
            while len(stack) > 0 and stack[-1]!= ")":
                output += stack.pop()
            # Pop the closing parenthesis from the stack
            stack.pop()
        # If the character is an operator
        else:
            # Pop operators from the stack to the output based on precedence
            while len(stack) > 0 and precedence(element) <= precedence(stack[-1]):
                output += stack.pop()
            # Push the current operator onto the stack
            stack.append(element)
    
    # Pop any remaining operators from the stack to the output
    while len(stack) > 0:
        output += stack.pop()
    
    # Reverse the output to get the final prefix expression
    return output[::-1]

# Method to determine the precedence of operators
def precedence(operator):
    if operator == '+' or operator == '-':
        return 1 # Lowest precedence
    elif operator == '*' or operator == '/':
        return 2 # Medium precedence
    elif operator == '^':
        return 3 # Highest precedence
    else:
        return 0 # Non-operator

# Method to filter out non-bracket characters from the input
def filterBrackets(input):
    return re.sub("[^(){}\\[\\]<>]", "", input) # Return only the brackets

# Method to check if the brackets in the expression are balanced
def isBalanced(expression):
    stack = []
    for ch in expression:
        # Push opening brackets onto the stack
        if ch == '(' or ch == '{' or ch == '[' or ch == '<':
            stack.append(ch)
        # For closing brackets, check for matching opening brackets
        else:
            if len(stack) == 0:
                return False # Unmatched closing bracket
            top = stack.pop()
            if not isMatchingPair(top, ch):
                return False # Mismatched brackets
    # The expression is balanced if the stack is empty at the end
    return len(stack) == 0

# Method to check if a pair of brackets match
def isMatchingPair(open, close):
    return (open == '(' and close == ')') or \
           (open == '{' and close == '}') or \
           (open == '[' and close == ']') or \
           (open == '<' and close == '>')

# Read the infix expression from the user
infixExpression = sys.stdin.readline().strip()

try:
    # Convert the infix expression to prefix notation
    prefixExpression = infix2Prefix(infixExpression)
    # Output the resulting prefix expression
    print("Prefix Expression:")
    print(prefixExpression)
except Exception as e:
    # Handle any exceptions that occur during conversion
    print("Error: " + str(e))


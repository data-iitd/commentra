
import re

def infix2Prefix(infixExpression):
    # Check if the input expression is null and throw an exception if it is
    if infixExpression is None:
        raise ValueError("Input expression cannot be null.")
    
    # Trim whitespace from the expression
    infixExpression = infixExpression.strip()
    
    # Return an empty string if the expression is empty
    if not infixExpression:
        return ""
    
    # Check if the brackets in the expression are balanced
    if not isBalanced(infixExpression):
        raise ValueError("Invalid expression: unbalanced brackets.")
    
    # Initialize a StringBuilder to hold the output prefix expression
    output = []
    # Create a stack to hold operators and parentheses
    stack = []
    # Reverse the infix expression for processing
    reversedInfix = infixExpression[::-1]
    
    # Process each character in the reversed infix expression
    for element in reversedInfix:
        # If the character is an operand, add it to the output
        if element.isalpha() or element.isdigit():
            output.append(element)
        # If the character is a closing parenthesis, push it onto the stack
        elif element == ')':
            stack.append(element)
        # If the character is an opening parenthesis, pop from the stack until a closing parenthesis is found
        elif element == '(':
            while stack and stack[-1] != ')':
                output.append(stack.pop())
            # Pop the closing parenthesis from the stack
            stack.pop()
        # If the character is an operator
        else:
            # Pop operators from the stack to the output based on precedence
            while stack and precedence(element) <= precedence(stack[-1]):
                output.append(stack.pop())
            # Push the current operator onto the stack
            stack.append(element)
    
    # Pop any remaining operators from the stack to the output
    while stack:
        output.append(stack.pop())
    
    # Reverse the output to get the final prefix expression
    return "".join(output[::-1])

# Method to determine the precedence of operators
def precedence(operator):
    if operator in "+-":
        return 1 # Lowest precedence
    elif operator in "*/":
        return 2 # Medium precedence
    elif operator == "^":
        return 3 # Highest precedence
    else:
        return 0 # Non-operator

# Method to filter out non-bracket characters from the input
def filterBrackets(input):
    return re.sub("[^(){}\[\]<>]", "", input) # Return only the brackets

# Method to check if the brackets in the expression are balanced
def isBalanced(expression):
    stack = []
    for ch in expression:
        # Push opening brackets onto the stack
        if ch in "({[<":
            stack.append(ch)
        # For closing brackets, check for matching opening brackets
        elif ch in ")}]>":
            if not stack:
                return False # Unmatched closing bracket
            top = stack.pop()
            if not isMatchingPair(top, ch):
                return False # Mismatched brackets
    # The expression is balanced if the stack is empty at the end
    return not stack

# Method to check if a pair of brackets match
def isMatchingPair(open, close):
    return (open == "(" and close == ")") or \
           (open == "{" and close == "}") or \
           (open == "[" and close == "]") or \
           (open == "<" and close == ">")

# Test the function
print(infix2Prefix("(a+b)*c"))
print(infix2Prefix("(a+b)*(c+d)"))
print(infix2Prefix("(a+b)*(c+d)*(e+f)"))
print(infix2Prefix("(a+b)*(c+d)*(e+f)*(g+h)"))
print(infix2Prefix("(a+b)*(c+d)*(e+f)*(g+h)*(i+j)"))
print(infix2Prefix("(a+b)*(c+d)*(e+f)*(g+h)*(i+j)*(k+l)"))
print(infix2Prefix("(a+b)*(c+d)*(e+f)*(g+h)*(i+j)*(k+l)*(m+n)"))
print(infix2Prefix("(a+b)*(c+d)*(e+f)*(g+h)*(i+j)*(k+l)*(m+n)*(o+p)"))
print(infix2Prefix("(a+b)*(c+d)*(e+f)*(g+h)*(i+j)*(k+l)*(m+n)*(o+p)*(q+r)"))
print(infix2Prefix("(a+b)*(c+d)*(e+f)*(g+h)*(i+j)*(k+l)*(m+n)*(o+p)*(q+r)*(s+t)"))
print(infix2Prefix("(a+b)*(c+d)*(e+f)*(g+h)*(i+j)*(k+l)*(m+n)*(o+p)*(q+r)*(s+t)*(u+v)"))
print(infix2Prefix("(a+b)*(c+d)*(e+f)*(g+h)*(i+j)*(k+l)*(m+n)*(o+p)*(q+r)*(s+t)*(u+v)*(w+x)"))
print(infix2Prefix("(a+b)*(c+d)*(e+f)*(g+h)*(i+j)*(k+l)*(m+n)*(o+p)*(q+r)*(s+t)*(u+v)*(w+x)*(y+z)"))

# 
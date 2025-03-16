
import re

def infix2Prefix(infixExpression):
    if infixExpression is None:
        raise ValueError("Input expression cannot be null.")

    infixExpression = infixExpression.strip()

    if not infixExpression:
        return ""

    if not isBalanced(filterBrackets(infixExpression)):
        raise ValueError("Invalid expression: unbalanced brackets.")

    output = []
    stack = []

    reversedInfix = infixExpression[::-1]

    for element in reversedInfix:
        if element.isalpha() or element.isdigit():
            output.append(element)
        elif element in [')', '}', ']', '>']:
            while stack and not isMatchingPair(stack[-1], element):
                output.append(stack.pop())
            stack.pop()
        else:
            while stack and precedence(stack[-1]) >= precedence(element):
                output.append(stack.pop())
            stack.append(element)

    while stack:
        output.append(stack.pop())

    return "".join(output[::-1])

def precedence(operator):
    if operator == '+' or operator == '-':
        return 1
    elif operator == '*' or operator == '/':
        return 2
    elif operator == '^':
        return 3
    else:
        return 0

def filterBrackets(input):
    return re.sub(r'[^(){}[\]<>]+', '', input)

def isMatchingPair(open, close):
    return (open == '(' and close == ')') or \
           (open == '{' and close == '}') or \
           (open == '[' and close == ']') or \
           (open == '<' and close == '>')

def isBalanced(expression):
    stack = []

    for element in expression:
        if element in ['(', '{', '[', '<']:
            stack.append(element)
        elif element in [')', '}', ']', '>']:
            if not stack or not isMatchingPair(stack[-1], element):
                return False
            stack.pop()

    return not stack

# Main method to start the application
if __name__ == "__main__":
    infixExpression = input("Enter the infix expression: ")

    try:
        prefixExpression = infix2Prefix(infixExpression)
        print("Prefix Expression:")
        print(prefixExpression)
    except ValueError as e:
        print("Error:", e)

# End of code
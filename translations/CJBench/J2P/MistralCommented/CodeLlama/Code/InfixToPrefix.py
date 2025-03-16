
import re

def infix2Prefix(infixExpression):
    if infixExpression is None:
        raise ValueError("Input expression cannot be null.")

    infixExpression = infexExpression.strip()

    if len(infixExpression) == 0:
        return ""

    if not isBalanced(infixExpression):
        raise ValueError("Invalid expression: unbalanced brackets.")

    output = ""
    stack = []

    reversedInfix = infixExpression[::-1]

    for element in reversedInfix:
        if element.isalpha() or element.isdigit():
            output += element
        elif element == ')':
            while len(stack) > 0 and stack[-1] != '(':
                output += stack.pop()
            stack.pop()
        elif element == '}':
            while len(stack) > 0 and stack[-1] != '{':
                output += stack.pop()
            stack.pop()
        elif element == ']':
            while len(stack) > 0 and stack[-1] != '[':
                output += stack.pop()
            stack.pop()
        elif element == '>':
            while len(stack) > 0 and stack[-1] != '<':
                output += stack.pop()
            stack.pop()
        else:
            while len(stack) > 0 and precedence(stack[-1]) >= precedence(element):
                output += stack.pop()
            stack.append(element)

    while len(stack) > 0:
        output += stack.pop()

    return output[::-1]

def precedence(operator):
    if operator == '+' or operator == '-':
        return 1
    elif operator == '*' or operator == '/':
        return 2
    elif operator == '^':
        return 3
    else:
        return 0

def isBalanced(expression):
    stack = []

    for element in expression:
        if element == '(' or element == '{' or element == '[' or element == '<':
            stack.append(element)
        elif element == ')' or element == '}' or element == ']' or element == '>':
            if len(stack) == 0:
                return False
            top = stack.pop()
            if not isMatchingPair(top, element):
                return False

    return len(stack) == 0

def isMatchingPair(open, close):
    return open == '(' and close == ')' or \
           open == '{' and close == '}' or \
           open == '[' and close == ']' or \
           open == '<' and close == '>'

# 
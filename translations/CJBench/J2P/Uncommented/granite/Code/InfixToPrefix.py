
import re

def infix2Prefix(infixExpression):
    if infixExpression is None:
        raise Exception("Input expression cannot be null.")
    infixExpression = infixExpression.strip()
    if len(infixExpression) == 0:
        return ""
    if not isBalanced(filterBrackets(infixExpression)):
        raise Exception("Invalid expression: unbalanced brackets.")
    output = []
    stack = []
    reversedInfix = infixExpression[::-1]
    for element in reversedInfix:
        if element.isalpha() or element.isdigit():
            output.append(element)
        elif element == ')':
            stack.append(element)
        elif element == '(':
            while len(stack) > 0 and stack[-1]!= ')':
                output.append(stack.pop())
            stack.pop()
        else:
            while len(stack) > 0 and precedence(element) <= precedence(stack[-1]):
                output.append(stack.pop())
            stack.append(element)
    while len(stack) > 0:
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
    pattern = re.compile("[^(){}\\[\\]<>]")
    return pattern.sub("", input)

def isBalanced(expression):
    stack = []
    for ch in expression:
        if ch == '(' or ch == '{' or ch == '[' or ch == '<':
            stack.append(ch)
        elif ch == ')' or ch == '}' or ch == ']' or ch == '>':
            if len(stack) == 0:
                return False
            top = stack.pop()
            if not isMatchingPair(top, ch):
                return False
    return len(stack) == 0

def isMatchingPair(open, close):
    return (open == '(' and close == ')') or \
           (open == '{' and close == '}') or \
           (open == '[' and close == ']') or \
           (open == '<' and close == '>')

# 
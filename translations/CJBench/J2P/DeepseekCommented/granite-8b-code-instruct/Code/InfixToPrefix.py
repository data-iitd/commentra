
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
    for element in reversed(infixExpression):
        if element.isalpha() or element.isdigit():
            output.append(element)
        elif element == ")":
            stack.append(element)
        elif element == "(":
            while stack and stack[-1]!= ")":
                output.append(stack.pop())
            stack.pop()
        else:
            while stack and precedence(element) <= precedence(stack[-1]):
                output.append(stack.pop())
            stack.append(element)
    while stack:
        output.append(stack.pop())
    return "".join(output)

def precedence(operator):
    if operator == "+" or operator == "-":
        return 1
    elif operator == "*" or operator == "/":
        return 2
    elif operator == "^":
        return 3
    else:
        return 0

def filterBrackets(input):
    return re.sub(r"[^(){}[\]<>]", "", input)

def isBalanced(expression):
    stack = []
    for ch in expression:
        if ch == "(" or ch == "{" or ch == "[" or ch == "<":
            stack.append(ch)
        elif ch == ")" or ch == "}" or ch == "]" or ch == ">":
            if not stack:
                return False
            top = stack.pop()
            if not isMatchingPair(top, ch):
                return False
    return not stack

def isMatchingPair(open, close):
    return (open == "(" and close == ")") or \
           (open == "{" and close == "}") or \
           (open == "[" and close == "]") or \
           (open == "<" and close == ">")

# 
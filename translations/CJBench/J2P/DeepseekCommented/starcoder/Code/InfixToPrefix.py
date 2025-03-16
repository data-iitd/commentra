import re
import sys

def infix2Prefix(infixExpression):
    if infixExpression == None:
        raise Exception("Input expression cannot be null.")
    infixExpression = infixExpression.strip()
    if infixExpression == "":
        return ""
    if not isBalanced(filterBrackets(infixExpression)):
        raise Exception("Invalid expression: unbalanced brackets.")
    output = ""
    stack = []
    reversedInfix = infixExpression[::-1]
    for element in reversedInfix:
        if element.isalnum():
            output += element
        elif element == ')':
            stack.append(element)
        elif element == '(':
            while len(stack) > 0 and stack[-1]!= ')':
                output += stack.pop()
            stack.pop()
        else:
            while len(stack) > 0 and precedence(element) <= precedence(stack[-1]):
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

def filterBrackets(input):
    pattern = re.compile("[^(){}\\[\\]<>]")
    matcher = pattern.match(input)
    return matcher.group()

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

if __name__ == "__main__":
    infixExpression = sys.stdin.readline().strip()
    try:
        prefixExpression = infix2Prefix(infixExpression)
        print("Prefix Expression:")
        print(prefixExpression)
    except Exception as e:
        print("Error: " + e.message)


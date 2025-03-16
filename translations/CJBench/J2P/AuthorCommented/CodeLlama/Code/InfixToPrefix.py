
import re


def infix2prefix(infix_expression):
    if not infix_expression:
        return ""
    if not is_balanced(infix_expression):
        raise ValueError("Invalid expression: unbalanced brackets.")

    output = []
    stack = []
    for element in reversed(infix_expression):
        if element.isalpha() or element.isdigit():
            output.append(element)
        elif element == ')':
            stack.append(element)
        elif element == '(':
            while stack and stack[-1] != ')':
                output.append(stack.pop())
            stack.pop()
        else:
            while stack and precedence(element) <= precedence(stack[-1]):
                output.append(stack.pop())
            stack.append(element)

    while stack:
        output.append(stack.pop())

    return "".join(reversed(output))


def precedence(operator):
    if operator in "+-":
        return 1
    elif operator in "*/":
        return 2
    elif operator == "^":
        return 3
    else:
        return 0


def is_balanced(expression):
    stack = []
    for ch in expression:
        if ch in "({[<":
            stack.append(ch)
        elif ch in ")}]>":
            if not stack:
                return False
            top = stack.pop()
            if not is_matching_pair(top, ch):
                return False
    return not stack


def is_matching_pair(open, close):
    return open == "(" and close == ")" or \
           open == "{" and close == "}" or \
           open == "[" and close == "]" or \
           open == "<" and close == ">"


if __name__ == "__main__":
    infix_expression = input("Enter an infix expression: ")
    try:
        prefix_expression = infix2prefix(infix_expression)
        print("Prefix expression:")
        print(prefix_expression)
    except ValueError as e:
        print("Error:", e)



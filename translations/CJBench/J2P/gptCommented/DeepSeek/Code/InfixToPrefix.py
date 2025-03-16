import re

def infix2prefix(infix_expression):
    if infix_expression is None:
        raise ValueError("Input expression cannot be null.")
    
    infix_expression = infix_expression.strip()
    
    if not infix_expression:
        return ""
    
    if not is_balanced(filter_brackets(infix_expression)):
        raise ValueError("Invalid expression: unbalanced brackets.")
    
    output = []
    stack = []
    reversed_infix = infix_expression[::-1]
    
    for element in reversed_infix:
        if element.isalnum():
            output.append(element)
        elif element == ')':
            stack.append(element)
        elif element == '(':
            while stack and stack[-1] != ')':
                output.append(stack.pop())
            stack.pop()
        else:
            while stack and precedence(element) < precedence(stack[-1]):
                output.append(stack.pop())
            stack.append(element)
    
    while stack:
        output.append(stack.pop())
    
    return ''.join(output[::-1])

def precedence(operator):
    if operator in "+-":
        return 1
    elif operator in "*/":
        return 2
    elif operator == "^":
        return 3
    else:
        return 0

def filter_brackets(input_str):
    return re.sub(r'[^(){}\[\]<>]', '', input_str)

def is_balanced(expression):
    stack = []
    for ch in expression:
        if ch in "({[<":
            stack.append(ch)
        elif ch in ")}]>" and not stack:
            return False
        else:
            top = stack.pop()
            if not is_matching_pair(top, ch):
                return False
    return not stack

def is_matching_pair(open_ch, close_ch):
    return (open_ch, close_ch) in [('(', ')'), ('{', '}'), ('[', ']'), ('<', '>')]

# Example usage:
# infix_expression = input()
# prefix_expression = infix2prefix(infix_expression)
# print("Prefix Expression:")
# print(prefix_expression)


import re

def infix_to_prefix(infix_expression):
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
        if element.isalnum():  # Check if the character is a letter or digit
            output.append(element)
        elif element == ')':
            stack.append(element)
        elif element == '(':
            while stack and stack[-1] != ')':
                output.append(stack.pop())
            stack.pop()  # Pop the ')'
        else:
            while stack and precedence(element) <= precedence(stack[-1]):
                output.append(stack.pop())
            stack.append(element)
    
    while stack:
        output.append(stack.pop())
    
    return ''.join(reversed(output))

def precedence(operator):
    if operator in ('+', '-'):
        return 1
    elif operator in ('*', '/'):
        return 2
    elif operator == '^':
        return 3
    else:
        return 0

def filter_brackets(input_string):
    pattern = re.compile(r'[^(){}[\]<>]')
    return pattern.sub('', input_string)

def is_balanced(expression):
    stack = []
    for ch in expression:
        if ch in '({[<':
            stack.append(ch)
        elif ch in ')}]>':
            if not stack:
                return False
            top = stack.pop()
            if not is_matching_pair(top, ch):
                return False
    return not stack

def is_matching_pair(open_char, close_char):
    return (open_char == '(' and close_char == ')') or \
           (open_char == '{' and close_char == '}') or \
           (open_char == '[' and close_char == ']') or \
           (open_char == '<' and close_char == '>')

if __name__ == "__main__":
    infix_expression = input()
    try:
        prefix_expression = infix_to_prefix(infix_expression)
        print("Prefix Expression:")
        print(prefix_expression)
    except ValueError as e:
        print("Error:", e)

# <END-OF-CODE>

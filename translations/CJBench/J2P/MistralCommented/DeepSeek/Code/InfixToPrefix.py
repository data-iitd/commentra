import re

def is_balanced(expression):
    stack = []
    bracket_pairs = {'(': ')', '{': '}', '[': ']', '<': '>'}
    for char in expression:
        if char in bracket_pairs.keys():
            stack.append(char)
        elif char in bracket_pairs.values():
            if not stack or bracket_pairs[stack.pop()] != char:
                return False
    return not stack

def precedence(operator):
    if operator in ['+', '-']:
        return 1
    elif operator in ['*', '/']:
        return 2
    elif operator == '^':
        return 3
    else:
        return 0

def filter_brackets(input_str):
    return re.sub(r'[^(){}\[\]<>]', '', input_str)

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
    
    for char in reversed_infix:
        if char.isalnum():
            output.append(char)
        elif char in ")}]>" :
            stack.append(char)
        elif char in "({[ <":
            while stack and not is_matching_pair(stack[-1], char):
                output.append(stack.pop())
            stack.pop()
        else:
            while stack and precedence(stack[-1]) >= precedence(char):
                output.append(stack.pop())
            stack.append(char)
    
    while stack:
        output.append(stack.pop())
    
    return ''.join(output[::-1])

def is_matching_pair(open_bracket, close_bracket):
    return (open_bracket == '(' and close_bracket == ')') or \
           (open_bracket == '{' and close_bracket == '}') or \
           (open_bracket == '[' and close_bracket == ']') or \
           (open_bracket == '<' and close_bracket == '>')

# Main function to start the application
def main():
    infix_expression = input()
    try:
        prefix_expression = infix_to_prefix(infix_expression)
        print("Prefix Expression:")
        print(prefix_expression)
    except ValueError as e:
        print("Error:", e)

if __name__ == "__main__":
    main()

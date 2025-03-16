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
        if element.isalpha():
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

    return ''.join(output[::-1])


def precedence(operator):
    if operator == '+' or operator == '-':
        return 1
    elif operator == '*' or operator == '/':
        return 2
    elif operator == '^':
        return 3
    else:
        return 0


def filter_brackets(input_str):
    import re
    return re.sub(r'[^(){}\[\]<>]', '', input_str)


def is_balanced(expression):
    stack = []
    for ch in expression:
        if ch == '(' or ch == '{' or ch == '[' or ch == '<':
            stack.append(ch)
        elif ch == ')' or ch == '}' or ch == ']' or ch == '>':
            if not stack:
                return False
            top = stack.pop()
            if not is_matching_pair(top, ch):
                return False
    return not stack


def is_matching_pair(open_ch, close_ch):
    return (open_ch == '(' and close_ch == ')') or \
           (open_ch == '{' and close_ch == '}') or \
           (open_ch == '[' and close_ch == ']') or \
           (open_ch == '<' and close_ch == '>')


# Example usage:
# infix_expr = input()
# prefix_expr = infix2prefix(infix_expr)
# print("Prefix Expression:")
# print(prefix_expr)

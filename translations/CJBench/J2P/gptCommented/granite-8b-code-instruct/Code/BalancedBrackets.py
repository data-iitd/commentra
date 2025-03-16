
import sys

def is_paired(left_bracket, right_bracket):
    paired_brackets = {
        '(': ')',
        '[': ']',
        '{': '}',
        '<': '>',
    }
    return paired_brackets.get(left_bracket) == right_bracket

def is_balanced(brackets):
    if brackets is None:
        raise ValueError("Input string is null")
    stack = []
    for bracket in brackets:
        if bracket in '({[<':
            stack.append(bracket)
        elif bracket in ')}]>':
            if not stack or not is_paired(stack.pop(), bracket):
                return False
        else:
            return False
    return not stack

if __name__ == "__main__":
    input_string = input("Enter a string of brackets: ")
    print("Balanced" if is_balanced(input_string) else "Not Balanced")


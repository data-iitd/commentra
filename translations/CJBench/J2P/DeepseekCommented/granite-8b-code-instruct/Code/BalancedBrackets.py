
import sys

def is_paired(left_bracket, right_bracket):
    paired_brackets = {
        '(': ')',
        '[': ']',
        '{': '}',
        '<': '>',
    }
    return left_bracket in paired_brackets and right_bracket == paired_brackets[left_bracket]

def is_balanced(brackets):
    if brackets is None:
        print("Input string is null", file=sys.stderr)
        return False
    stack = []
    for bracket in brackets:
        if bracket in ['(', '[', '{', '<']:
            stack.append(bracket)
        elif bracket in [')', ']', '}', '>']:
            if not stack or not is_paired(stack.pop(), bracket):
                return False
        else:
            return False
    return not stack

# Test the function
input_string = input("Enter a string of brackets: ")
result = is_balanced(input_string)
print("Balanced" if result else "Not Balanced")


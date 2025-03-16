
import sys

def is_paired(left_bracket, right_bracket):
    paired_brackets = [
        ('(', ')'),
        ('[', ']'),
        ('{', '}'),
        ('<', '>'),
    ]

    for paired_bracket in paired_brackets:
        if left_bracket == paired_bracket[0] and right_bracket == paired_bracket[1]:
            return True
    return False

def is_balanced(brackets):
    if brackets is None:
        raise ValueError("Input string is null")

    brackets_stack = []

    for bracket in brackets:
        if bracket == '(' or bracket == '[' or bracket == '<' or bracket == '{':
            brackets_stack.append(bracket)
        elif bracket == ')' or bracket == ']' or bracket == '>' or bracket == '}':
            if len(brackets_stack) == 0 or not is_paired(brackets_stack.pop(), bracket):
                return False
        else:
            return False

    return len(brackets_stack) == 0

if __name__ == "__main__":
    input_string = sys.stdin.readline().strip()
    result = is_balanced(input_string)
    print("Balanced" if result else "Not Balanced")




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
        raise ValueError("Input string is null")
    brackets_stack = []
    for bracket in brackets:
        if bracket in ['(', '[', '<', '{']:
            brackets_stack.append(bracket)
        elif bracket in [')', ']', '>', '}']:
            if not brackets_stack or not is_paired(brackets_stack.pop(), bracket):
                return False
        else:
            return False
    return not brackets_stack

# 
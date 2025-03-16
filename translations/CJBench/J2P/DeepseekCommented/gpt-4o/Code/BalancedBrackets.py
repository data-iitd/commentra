def is_paired(left_bracket, right_bracket):
    paired_brackets = [('(', ')'), ('[', ']'), ('{', '}'), ('<', '>')]
    return (left_bracket, right_bracket) in paired_brackets

def is_balanced(brackets):
    if brackets is None:
        raise ValueError("Input string is None")
    brackets_stack = []
    for bracket in brackets:
        if bracket in "([{<":
            brackets_stack.append(bracket)
        elif bracket in ")]}>":
            if not brackets_stack or not is_paired(brackets_stack.pop(), bracket):
                return False
        else:
            return False
    return not brackets_stack

def main():
    input_brackets = input()
    result = is_balanced(input_brackets)
    print("Balanced" if result else "Not Balanced")

main()

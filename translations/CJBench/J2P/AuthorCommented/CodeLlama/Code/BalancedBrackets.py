
import sys

# Read input string
input = sys.stdin.readline()

# Check if the brackets are balanced
result = is_balanced(input)

# Print result
print("Balanced" if result else "Not Balanced")

def is_balanced(input):
    # Check if input is empty
    if not input:
        return True

    # Check if input is not empty
    stack = []
    for bracket in input:
        # Check if opening bracket
        if bracket == "(" or bracket == "[" or bracket == "<" or bracket == "{":
            stack.append(bracket)
        # Check if closing bracket
        elif bracket == ")" or bracket == "]" or bracket == ">" or bracket == "}":
            # Check if stack is empty
            if not stack:
                return False
            # Pop from stack
            top = stack.pop()
            # Check if pair is not matching
            if not is_paired(top, bracket):
                return False
    # Check if stack is not empty
    if stack:
        return False
    return True

def is_paired(left_bracket, right_bracket):
    # Check if left and right brackets are paired
    if left_bracket == "(" and right_bracket == ")":
        return True
    elif left_bracket == "[" and right_bracket == "]":
        return True
    elif left_bracket == "<" and right_bracket == ">":
        return True
    elif left_bracket == "{" and right_bracket == "}":
        return True
    return False

# END-OF-CODE

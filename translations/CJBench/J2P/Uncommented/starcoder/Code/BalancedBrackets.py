
import sys
import re

def isPaired(left, right):
    return (left + right) in ['()', '[]', '{}', '<>']

def isBalanced(brackets):
    if brackets == None:
        raise Exception("Input string is null")
    stack = []
    for bracket in brackets:
        if bracket in '([{<':
            stack.append(bracket)
        elif bracket in ')]}>':
            if len(stack) == 0 or not isPaired(stack.pop(), bracket):
                return False
    return len(stack) == 0

def main():
    if len(sys.argv)!= 2:
        print("Usage: python %s <input-file>" % sys.argv[0])
        sys.exit(1)
    with open(sys.argv[1], 'r') as f:
        for line in f:
            line = line.strip()
            if len(line) == 0:
                continue
            print(isBalanced(line))

if __name__ == '__main__':
    main()


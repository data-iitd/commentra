class Stack:
    def __init__(self):
        self.items = []

    def is_empty(self):
        return len(self.items) == 0

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if self.is_empty():
            raise IndexError("pop from empty stack")
        return self.items.pop()

    def peek(self):
        if self.is_empty():
            raise IndexError("peek from empty stack")
        return self.items[-1]


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
        raise ValueError("Input string is None")
    brackets_stack = Stack()
    for bracket in brackets:
        if bracket in "([{<":
            brackets_stack.push(bracket)
        elif bracket in ")]}>":
            if brackets_stack.is_empty() or not is_paired(brackets_stack.pop(), bracket):
                return False
        else:
            return False
    return brackets_stack.is_empty()


# Main function to read input and print result
def main():
    import sys
    input_string = sys.stdin.readline().strip()
    result = is_balanced(input_string)
    print("Balanced" if result else "Not Balanced")


if __name__ == "__main__":
    main()

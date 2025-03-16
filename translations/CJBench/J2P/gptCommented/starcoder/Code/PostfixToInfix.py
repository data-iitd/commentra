import sys

# Class to represent a node in a binary tree
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# Class to represent a binary tree
class BinaryTree:
    def __init__(self):
        self.root = None

    # Method to insert a node in the tree
    def insert(self, data):
        # If the root node is empty, create a new node and set it as the root
        if self.root is None:
            self.root = Node(data)
        # Otherwise, traverse the tree to find the correct location for the new node
        else:
            self._insert(data, self.root)

    # Recursive method to insert a node in the tree
    def _insert(self, data, node):
        # If the data is less than the node's data, go to the left subtree
        if data < node.data:
            # If the left subtree is empty, create a new node and set it as the left subtree
            if node.left is None:
                node.left = Node(data)
            # Otherwise, traverse the left subtree to find the correct location for the new node
            else:
                self._insert(data, node.left)
        # Otherwise, go to the right subtree
        else:
            # If the right subtree is empty, create a new node and set it as the right subtree
            if node.right is None:
                node.right = Node(data)
            # Otherwise, traverse the right subtree to find the correct location for the new node
            else:
                self._insert(data, node.right)

# Class to represent a stack
class Stack:
    def __init__(self):
        self.items = []

    # Method to check if the stack is empty
    def isEmpty(self):
        return self.items == []

    # Method to add an item to the stack
    def push(self, item):
        self.items.append(item)

    # Method to remove an item from the stack
    def pop(self):
        return self.items.pop()

    # Method to return the top item from the stack
    def peek(self):
        return self.items[len(self.items) - 1]

    # Method to return the size of the stack
    def size(self):
        return len(self.items)

# Method to check if a character is a valid operator
def isOperator(token):
    return token == '+' or token == '-' or token == '/' or token == '*' or token == '^'

# Method to validate if the given string is a valid postfix expression
def isValidPostfixExpression(postfix):
    # A single alphabetic character is a valid postfix expression
    if len(postfix) == 1 and postfix.isalpha():
        return True
    # Postfix expressions must have at least 3 characters to be valid
    if len(postfix) < 3:
        return False

    operandCount = 0 # Count of operands
    operatorCount = 0 # Count of operators

    # Iterate through each character in the postfix expression
    for token in postfix:
        if isOperator(token):
            operatorCount += 1 # Increment operator count
            # There must be at least one operand for each operator
            if operatorCount >= operandCount:
                return False
        else:
            operandCount += 1 # Increment operand count
    # A valid postfix expression must have exactly one more operand than operators
    return operandCount == operatorCount + 1

# Method to convert a valid postfix expression to infix expression
def getMain(postfix):
    # Return an empty string if the postfix expression is empty
    if postfix == "":
        return ""
    # Validate the postfix expression; throw an exception if invalid
    if not isValidPostfixExpression(postfix):
        raise Exception("Invalid Postfix Expression")

    stack = Stack() # Stack to hold operands

    # Iterate through each character in the postfix expression
    for token in postfix:
        if not isOperator(token):
            # Push operands onto the stack
            stack.push(token)
        else:
            # Pop the top two operands from the stack for the operator
            operandB = stack.pop()
            operandA = stack.pop()
            # Form a new infix expression and push it back onto the stack
            stack.push('(' + operandA + token + operandB + ')')
    # The final infix expression is the only element left in the stack
    return stack.pop()

# Main method to execute the program
def main():
    # Read the postfix expression from input
    postfix = sys.stdin.readline().strip()
    try:
        # Convert the postfix expression to infix and print it
        infix = getMain(postfix)
        print("Infix Expression: " + infix)
    except Exception as e:
        # Handle invalid postfix expression
        print("Error: " + e.args[0])

if __name__ == "__main__":
    main()


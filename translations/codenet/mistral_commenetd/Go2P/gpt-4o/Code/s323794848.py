# Import necessary modules
import sys

# Define a deque (double ended queue) class
class Deque:
    def __init__(self):
        self.front = []  # Front list to store elements
        self.back = []   # Back list to store elements

    # Check if deque is empty at the front
    def is_empty_front(self):
        return len(self.front) == 0

    # Check if deque is empty at the back
    def is_empty_back(self):
        return len(self.back) == 0

    # Add an element at the back of the deque
    def push_back(self, v):
        self.back.append(v)

    # Add an element at the front of the deque
    def push_front(self, v):
        self.front.append(v)

    # Remove an element from the back of the deque and return it
    def pop_back(self):
        if not self.is_empty_back():
            return self.back.pop()
        elif not self.is_empty_front():
            return self.front.pop(0)
        else:
            return None  # Deque is empty

    # Remove an element from the front of the deque and return it
    def pop_front(self):
        if not self.is_empty_front():
            return self.front.pop()
        elif not self.is_empty_back():
            return self.back.pop(0)
        else:
            return None  # Deque is empty

    # Get an element from the deque by its index
    def get(self, idx):
        total = len(self.front) + len(self.back)
        if idx < total:
            if idx < len(self.front):
                return self.front[len(self.front) - 1 - idx]
            else:
                return self.back[idx - len(self.front)]
        return None  # Index out of range

# Function to reverse a given string
def rev(s):
    return s[::-1]  # Return the reversed string

# Main function to read input and process it
def main():
    # Read the input string S from the standard input
    S = input().strip()
    # Read the number of operations Q from the standard input
    Q = int(input().strip())
    # Initialize a list of operations
    ops = []
    
    # Read the operations one by one and store them in the ops list
    for _ in range(Q):
        operation = list(map(str, input().strip().split()))
        if operation[0] == '1':
            ops.append({'rev': True})
        else:
            f = int(operation[1])
            c = operation[2]
            ops.append({'rev': False, 'front': f == 1, 'c': c})

    # Initialize an array of sums
    sum_ops = [0] * (Q + 1)
    
    # Calculate the sums of operations
    for i in range(Q - 1, -1, -1):
        if ops[i]['rev']:
            sum_ops[i] = sum_ops[i + 1] + 1
        else:
            sum_ops[i] = sum_ops[i + 1]

    # If the sum of the first operation is odd, reverse the input string
    if sum_ops[0] % 2 == 1:
        S = rev(S)

    # Initialize an empty deque
    deq = Deque()

    # Process the operations
    for i in range(Q):
        if not ops[i]['rev']:
            if ops[i]['front']:
                if sum_ops[i] % 2 == 1:
                    deq.push_front(ops[i]['c'])
                else:
                    deq.push_back(ops[i]['c'])
            else:
                if sum_ops[i] % 2 == 1:
                    deq.push_back(ops[i]['c'])
                else:
                    deq.push_front(ops[i]['c'])

    # Write the result to the standard output
    result = []
    result.extend(reversed(deq.front))  # Add front elements in reverse order
    result.extend(S)                     # Add the input string
    result.extend(deq.back)              # Add back elements

    # Print the result
    print(''.join(result))

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>

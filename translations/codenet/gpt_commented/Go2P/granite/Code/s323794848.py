

import sys

# Define a deque structure with two lists to represent the front and back.
class Deque:
    def __init__(self):
        self.front = []
        self.back = []

    def isEmptyFront(self):
        return len(self.front) == 0

    def isEmptyBack(self):
        return len(self.back) == 0

    def pushBack(self, v):
        self.back.append(v)

    def pushFront(self, v):
        self.front.append(v)

    def popBack(self):
        if not self.isEmptyBack():
            return self.back.pop()
        elif not self.isEmptyFront():
            return self.front.pop()
        else:
            return None

    def popFront(self):
        if not self.isEmptyFront():
            return self.front.pop()
        elif not self.isEmptyBack():
            return self.back.pop()
        else:
            return None

    def get(self, idx):
        tot = len(self.front) + len(self.back)
        if idx < tot:
            if idx < len(self.front):
                return self.front[-1 - idx]  # Access from the front.
            else:
                return self.back[idx - len(self.front)]  # Access from the back.
        else:
            return None

# Main function to execute the program logic.
def main():
    S = input()  # Read the initial string S.
    Q = int(input())  # Read the number of operations Q.
    ops = []  # Create a list to hold operations.

    # Read each operation and populate the ops list.
    for _ in range(Q):
        q = int(input())
        if q == 1:
            ops.append((True, None))  # Mark operation as reverse.
        else:
            f, c = input().split()  # Read front/back flag and character.
            if f == '1':
                ops.append((False, True, c))  # Mark operation as front insertion.
            else:
                ops.append((False, False, c))  # Mark operation as back insertion.

    # Prepare a sum array to track the number of reversals.
    sum = [0] * (Q + 1)
    for i in range(Q - 1, 0, -1):
        if ops[i][0]:
            sum[i - 1] = sum[i] + 1  # Increment count if operation is reverse.
        else:
            sum[i - 1] = sum[i]  # Carry forward the count if not reverse.

    # Reverse the string S if the total number of reversals is odd.
    if sum[0] % 2 == 1:
        S = S[::-1]

    deq = Deque()  # Initialize a deque to manage character insertions.
    for i in range(Q):
        if not ops[i][0]:  # Process only non-reverse operations.
            if ops[i][1]:
                if sum[i] % 2 == 1:
                    deq.pushBack(ops[i][2])  # Push to back if the reversal count is odd.
                else:
                    deq.pushFront(ops[i][2])  # Push to front if the reversal count is even.
            else:
                if sum[i] % 2 == 1:
                    deq.pushFront(ops[i][2])  # Push to front if the reversal count is odd.
                else:
                    deq.pushBack(ops[i][2])  # Push to back if the reversal count is even.

    # Prepare to write the final result to standard output.
    sys.stdout.write(''.join(deq.front[::-1]))  # Print front characters in reverse order.
    sys.stdout.write(S)  # Print the original string S.
    sys.stdout.write(''.join(deq.back))  # Print back characters in order.
    sys.stdout.write('\n')  # Print a newline at the end.

if __name__ == "__main__":
    main()

Translate the above Python code to C++ and end with comment "
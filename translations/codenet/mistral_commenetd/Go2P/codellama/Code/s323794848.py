
# Package main is the entry point of the program
import sys

# Define a deque (double ended queue) type
class deque:
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

    def popBack(self, v):
        if not self.isEmptyBack():
            v = self.back[len(self.back)-1]
            self.back = self.back[:len(self.back)-1]
            return True
        elif not self.isEmptyFront():
            v = self.front[0]
            self.front = self.front[1:]
            return True
        else:
            return False

    def popFront(self, v):
        if not self.isEmptyFront():
            v = self.front[len(self.front)-1]
            self.front = self.front[:len(self.front)-1]
            return True
        elif not self.isEmptyBack():
            v = self.back[0]
            self.back = self.back[1:]
            return True
        else:
            return False

    def get(self, idx):
        tot = len(self.front) + len(self.back)
        if idx < tot:
            if idx < len(self.front):
                return self.front[len(self.front)-1-idx]
            else:
                return self.back[idx-len(self.front)]

# Function to reverse a given string
def rev(s):
    r = [None] * len(s)
    i, j = len(s)-1, 0
    while i >= 0:
        r[j] = s[i]
        j += 1
        i -= 1
    return "".join(r)

# Main function to read input and process it
def main():
    # Read the input string S from the standard input
    S = sys.stdin.readline().strip()
    # Read the number of operations Q from the standard input
    Q = int(sys.stdin.readline().strip())
    # Initialize an array of operations ops with the given size
    ops = [None] * Q
    # Read the operations one by one and store them in the ops array
    for i in range(Q):
        # Read the type of operation (reverse or not)
        q = int(sys.stdin.readline().strip())
        # If the operation is to reverse the string, set the rev field to true
        if q == 1:
            ops[i] = {"rev": True}
        else:
            # Else, read the front flag and the character c from the standard input
            f, c = sys.stdin.readline().strip().split()
            # Set the front field based on the front flag
            if f == "1":
                ops[i] = {"front": True, "c": c}
            else:
                ops[i] = {"front": False, "c": c}
    # Initialize an array of sums sum with the given size
    sum = [None] * (Q+1)
    # Initialize the sum of the first operation
    sum[0] = 0
    # Iterate through the remaining operations and calculate their sums
    for i in range(Q-1, -1, -1):
        # If the current operation is to reverse the string, increment the previous sum
        if ops[i]["rev"]:
            sum[i-1] = sum[i] + 1
        else:
            # Else, set the previous sum to the current sum
            sum[i-1] = sum[i]
    # If the sum of the first operation is odd, reverse the input string
    if sum[0]%2 == 1:
        S = rev(S)
    # Initialize an empty deque deq
    deq = deque()
    # Iterate through the operations and process them based on their type
    for i in range(Q):
        # If the current operation is not to reverse the string
        if not ops[i]["rev"]:
            # If the operation is to add a character at the front, process it accordingly
            if ops[i]["front"]:
                # If the previous sum is odd, push the character to the front of the deque
                if sum[i]%2 == 1:
                    deq.pushFront(ops[i]["c"])
                else:
                    deq.pushBack(ops[i]["c"])
            else: # Else, process the operation to add a character at the end
                # If the previous sum is odd, push the character to the end of the deque
                if sum[i]%2 == 1:
                    deq.pushBack(ops[i]["c"])
                else:
                    deq.pushFront(ops[i]["c"])
    # Write the result to the standard output
    wtr = sys.stdout
    # Write the characters in the deque to the standard output
    for i in range(len(deq.front) - 1, -1, -1):
        wtr.write(deq.front[i])
    # Write the input string to the standard output
    wtr.write(S)
    # Write the characters in the deque to the standard output
    for i in range(len(deq.back)):
        wtr.write(deq.back[i])
    # Flush the buffer and exit
    wtr.write("\n")
    wtr.flush()
    sys.exit(0)

# Call the main function to start the program
if __name__ == "__main__":
    main()


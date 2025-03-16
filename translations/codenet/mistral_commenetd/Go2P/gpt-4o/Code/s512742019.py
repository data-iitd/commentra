import sys
import heapq

# I/O
class Scanner:
    def __init__(self):
        self.input = sys.stdin.read
        self.data = self.input().split()
        self.index = 0

    def next_str(self):
        result = self.data[self.index]
        self.index += 1
        return result

    def next_int(self):
        return int(self.next_str())

    def next_float(self):
        return float(self.next_str())

    def next_int_slice(self, n):
        return [self.next_int() for _ in range(n)]

# Arithmetic
def max_value(*nums):
    return max(nums)

def min_value(*nums):
    return min(nums)

def abs_value(x):
    return abs(x)

def pow_value(x, y):
    return x ** y

def ceil(a, b):
    return (a + b - 1) // b

# Main
MOD = int(1e9) + 7  # Modulus value for modular arithmetic
INF = 1 << 60      # Infinite value for comparison

# Mon represents a monster with x-coordinate and height
class Mon:
    def __init__(self, x, h):
        self.x = x
        self.h = h

# Node represents a node in the priority queue with x-coordinate and damage
class Node:
    def __init__(self, x, h):
        self.x = x
        self.h = h

# Queue is a priority queue implemented using heapq
class Queue:
    def __init__(self):
        self.arr = []

    def push(self, v):
        heapq.heappush(self.arr, (v.x, v.h))

    def first(self):
        return self.arr[0]

    def pop(self):
        return heapq.heappop(self.arr)

    def is_empty(self):
        return len(self.arr) == 0

def main():
    # Initialize a new Scanner
    sc = Scanner()

    # Read input values N, D, and A from the scanner
    N = sc.next_int()
    D = sc.next_int()
    A = sc.next_int()

    # Initialize a list of Mon objects
    M = []

    # Read x and h values for each Mon and store them in the M list
    for _ in range(N):
        M.append(Mon(sc.next_int(), sc.next_int()))

    # Sort the M list based on x-coordinates
    M.sort(key=lambda m: m.x)

    # Initialize an empty priority queue called q
    q = Queue()

    # Initialize answer variable ans to 0 and total variable total to 0
    ans = 0
    total = 0

    # Iterate through each Mon in the sorted M list
    for m in M:
        # While the priority queue is not empty and the current Mon's x-coordinate is smaller than the x-coordinate of the first Node in the priority queue
        while not q.is_empty() and q.first()[0] < m.x:
            total -= q.pop()[1]

        # If the total damage is less than the Mon's height, calculate the remaining damage, add it to the answer, and push it to the priority queue
        if total < m.h:
            damage = m.h - total
            ans += damage
            q.push(Node(m.x + 2 * D, damage))
            total += damage

    # Print the answer
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

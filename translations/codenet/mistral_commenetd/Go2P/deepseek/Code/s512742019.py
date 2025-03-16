import sys
import heapq

# I/O
class Scanner:
    def __init__(self):
        self.sc = sys.stdin

    def next_str(self):
        return self.sc.readline().strip()

    def next_int(self):
        return int(self.next_str())

    def next_float(self):
        return float(self.next_str())

    def next_rune_slice(self):
        return list(self.next_str())

    def next_int_slice(self, n):
        return [self.next_int() for _ in range(n)]

    def next_float_slice(self, n):
        return [self.next_float() for _ in range(n)]

# Arithmetic
def max(nums):
    return max(nums)

def min(nums):
    return min(nums)

def abs(x):
    return abs(x)

def pow(x, y):
    return x ** y

def ceil(a, b):
    return (a + b - 1) // b

# Sort
class RuneSlice(list):
    def __lt__(self, other):
        return self < other

# Main
MOD = 10**9 + 7
INF = 1 << 60

# Mon represents a monster with x-coordinate and height
class Mon:
    def __init__(self, x, h):
        self.x = x
        self.h = h

# Mons is a list of Mon structures
class Mons(list):
    def __lt__(self, other):
        return self[0].x < other[0].x

# Node represents a node in the priority queue with x-coordinate and damage
class Node:
    def __init__(self, x, h):
        self.x = x
        self.h = h

# Queue is a priority queue implemented as a list with custom push, pop, and isEmpty functions
class Queue:
    def __init__(self):
        self.arr = []

    def push(self, v):
        heapq.heappush(self.arr, v)

    def first(self):
        return self.arr[0]

    def pop(self):
        return heapq.heappop(self.arr)

    def isEmpty(self):
        return len(self.arr) == 0

# Main function initializes variables, sorts monsters, and calculates the answer
def main():
    # Initialize a new Scanner for input
    sc = Scanner()

    # Read input values N, D, and A from the scanner
    N, D, A = sc.next_int(), sc.next_int(), sc.next_int()

    # Initialize a list of Mon structures called M
    M = [Mon(sc.next_int(), sc.next_int()) for _ in range(N)]

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
        while q and q.first().x < m.x:
            # Pop the first Node from the priority queue
            total -= q.pop().h

        # If the total damage is less than the Mon's height, calculate the remaining damage, add it to the answer, and push it to the priority queue
        if total < m.h:
            damage = m.h - total
            ans += damage
            heapq.heappush(q.arr, Node(m.x + 2*D, damage))
            total += damage

    # Print the answer
    print(ans)

main()

import sys
import math
from collections import deque

# I/O
class Scanner:
    def __init__(self):
        self.sc = sys.stdin.read().split()
        self.index = 0

    def next_str(self):
        res = self.sc[self.index]
        self.index += 1
        return res

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

def ceil_div(a, b):
    return -(-a // b)

# Main
MOD = int(1e+9) + 7  # Define a constant for modulo operation
INF = 1 << 60        # Define a constant for infinity

# Mon represents a monster with position x and health h
class Mon:
    def __init__(self, x, h):
        self.x = x
        self.h = h

# Node represents a position and damage
class Node:
    def __init__(self, x, h):
        self.x = x
        self.h = h

# main function to execute the program logic
def main():
    sc = Scanner()  # Initialize the scanner for input
    N = sc.next_int()
    D = sc.next_int()
    A = sc.next_int()
    M = [Mon(sc.next_int(), sc.next_int()) for _ in range(N)]  # Read each monster's position and health
    M.sort(key=lambda m: m.x)  # Sort monsters by their position

    q = deque()  # Initialize a queue to manage damage
    ans = 0      # Variable to count the total number of attacks
    total = 0    # Variable to track total damage dealt

    # Iterate through each monster
    for m in M:
        # Remove monsters from the queue that are out of range
        while q and q[0].x < m.x:
            total -= q.popleft().h  # Decrease total damage by the damage of the popped monster
        # If the total damage is less than the monster's health
        if total < m.h:
            m.h -= total  # Reduce the monster's health by total damage
            count = ceil_div(m.h, A)  # Calculate how many attacks are needed
            ans += count  # Increment the total attack count
            damage = count * A  # Calculate the total damage dealt to this monster
            q.append(Node(m.x + 2 * D, damage))  # Add the monster's damage to the queue
            total += damage  # Update the total damage

    print(ans)  # Output the total number of attacks

if __name__ == "__main__":
    main()

# <END-OF-CODE>

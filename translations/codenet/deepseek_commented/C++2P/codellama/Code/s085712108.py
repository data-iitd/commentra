/*Lucky_Glass*/
import sys
from collections import deque

MOD = 7007

# Define a structure QUEUE to store the values of a, b, c, and the total number of operations.
class QUEUE:
    def __init__(self, a, b, c, tot):
        self.a = a
        self.b = b
        self.c = c
        self.tot = tot

# Define a transformation matrix F with six possible transformations.
F = [[1, 1, 0], [1, 0, 1], [0, 1, 1], [2, 0, 0], [0, 2, 0], [0, 0, 2]]

# Define a hash table as an array of deques to store unique states.
Hash = [deque() for _ in range(MOD)]

# Function to check if a state has been visited before.
def HASH(n):
    for i in range(len(Hash[n % MOD])):
        if n == Hash[n % MOD][i]:
            return False
    Hash[n % MOD].append(n)
    return True

# Main function to execute the program.
def main():
    Push = QUEUE(0, 0, 0, 0)
    que = deque()
    a, b, c = map(int, sys.stdin.readline().split())
    Push.a, Push.b, Push.c = a, b, c
    que.append(Push)
    while que:
        Fro = que.popleft()
        if Fro.a == Fro.b and Fro.b == Fro.c:
            print(Fro.tot)
            return
        for i in range(6):
            Push = QUEUE(Fro.a, Fro.b, Fro.c, Fro.tot + 1)
            Push.a += F[i][0]
            Push.b += F[i][1]
            Push.c += F[i][2]
            n = Push.a * 10000 + Push.b * 100 + Push.c
            if not HASH(n):
                continue
            que.append(Push)

if __name__ == "__main__":
    main()


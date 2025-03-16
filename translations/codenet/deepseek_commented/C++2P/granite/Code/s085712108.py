
# Lucky_Glass
import sys
sys.setrecursionlimit(10**6)

# Define a transformation matrix F with six possible transformations.
F = [[1,1,0],[1,0,1],[0,1,1],[2,0,0],[0,2,0],[0,0,2]]

# Define a hash table as a dictionary to store unique states.
Hash = {}

# Function to check if a state has been visited before.
def HASH(n):
    if n in Hash:
        return False
    Hash[n] = True
    return True

# Main function to execute the program.
def main():
    a, b, c = map(int, input().split())
    que = [(a, b, c, 0)]
    while que:
        a, b, c, tot = que.pop(0)
        if a == b == c:
            print(tot)
            return
        for i in range(6):
            na, nb, nc = a + F[i][0], b + F[i][1], c + F[i][2]
            n = (na, nb, nc)
            if HASH(n):
                que.append((na, nb, nc, tot + 1))

if __name__ == "__main__":
    main()


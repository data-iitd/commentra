MOD = 7007

class QueueItem:
    def __init__(self, a, b, c, tot):
        self.a = a
        self.b = b
        self.c = c
        self.tot = tot

# Define a transformation matrix F with six possible transformations.
F = [
    [1, 1, 0],
    [1, 0, 1],
    [0, 1, 1],
    [2, 0, 0],
    [0, 2, 0],
    [0, 0, 2]
]

# Define a hash table as a list of lists to store unique states.
Hash = [[] for _ in range(MOD)]

# Function to check if a state has been visited before.
def hash_function(n):
    for i in range(len(Hash[n % MOD])):
        if n == Hash[n % MOD][i]:
            return False
    Hash[n % MOD].append(n)
    return True

# Main function to execute the program.
def main():
    push = QueueItem(0, 0, 0, 0)
    que = []
    a, b, c = map(int, input().split())
    que.append(QueueItem(a, b, c, 0))
    while que:
        fro = que[0]
        if fro.a == fro.b == fro.c:
            print(fro.tot)
            return
        for i in range(6):
            push = QueueItem(fro.a, fro.b, fro.c, fro.tot + 1)
            push.a += F[i][0]
            push.b += F[i][1]
            push.c += F[i][2]
            n = push.a * 10000 + push.b * 100 + push.c
            if not hash_function(n):
                continue
            que.append(push)
        que.pop(0)

if __name__ == "__main__":
    main()

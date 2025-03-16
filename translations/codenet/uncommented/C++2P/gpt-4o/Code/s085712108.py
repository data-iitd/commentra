from collections import deque

MOD = 7007

class QUEUE:
    def __init__(self, a, b, c, tot):
        self.a = a
        self.b = b
        self.c = c
        self.tot = tot

F = [[1, 1, 0], [1, 0, 1], [0, 1, 1], [2, 0, 0], [0, 2, 0], [0, 0, 2]]
Hash = [[] for _ in range(MOD)]

def HASH(n):
    for value in Hash[n % MOD]:
        if n == value:
            return False
    Hash[n % MOD].append(n)
    return True

def main():
    a, b, c = map(int, input().split())
    Push = QUEUE(a, b, c, 0)
    que = deque([Push])
    
    while que:
        Fro = que.popleft()
        if Fro.a == Fro.b == Fro.c:
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

# <END-OF-CODE>

MOD = 7007

class Queue:
    def __init__(self, a, b, c, tot):
        self.a = a
        self.b = b
        self.c = c
        self.tot = tot

def hash_function(n):
    index = n % MOD
    if n in Hash[index]:
        return False
    Hash[index].append(n)
    return True

def main():
    global Hash
    Hash = [[] for _ in range(MOD)]
    Push = Queue(0, 0, 0, 0)
    Push.a, Push.b, Push.c = map(int, input().split())
    que = [Push]

    while que:
        Fro = que.pop(0)

        if Fro.a == Fro.b == Fro.c:
            print(Fro.tot)
            return

        for i in range(6):
            Push = Queue(Fro.a, Fro.b, Fro.c, Fro.tot + 1)
            Push.a += F[i][0]
            Push.b += F[i][1]
            Push.c += F[i][2]
            n = Push.a * 10000 + Push.b * 100 + Push.c

            if not hash_function(n):
                continue

            que.append(Push)

if __name__ == "__main__":
    F = [
        [1, 1, 0],
        [1, 0, 1],
        [0, 1, 1],
        [2, 0, 0],
        [0, 2, 0],
        [0, 0, 2]
    ]
    main()

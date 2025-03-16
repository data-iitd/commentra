MOD = 7007
class QueueItem:
    def __init__(self, a, b, c, tot):
        self.a = a
        self.b = b
        self.c = c
        self.tot = tot

def hash_function(n):
    index = n % MOD
    if n in hash_table[index]:
        return False
    hash_table[index].append(n)
    return True

def main():
    a, b, c = map(int, input().split())
    queue = [QueueItem(a, b, c, 0)]
    hash_table = [[] for _ in range(MOD)]

    while queue:
        fro = queue.pop(0)
        if fro.a == fro.b == fro.c:
            print(fro.tot)
            return
        for f in [[1, 1, 0], [1, 0, 1], [0, 1, 1], [2, 0, 0], [0, 2, 0], [0, 0, 2]]:
            push = QueueItem(fro.a + f[0], fro.b + f[1], fro.c + f[2], fro.tot + 1)
            n = push.a * 10000 + push.b * 100 + push.c
            if not hash_function(n):
                continue
            queue.append(push)

if __name__ == "__main__":
    main()

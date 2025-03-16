
MOD = 10000000000 + 7
ALPHABET_NUM = 26
INF_INT64 = 2 ** 60 - 1
INF_BIT60 = 1 << 60
INF_INT32 = 2 ** 30 - 1
INF_BIT30 = 1 << 30
NIL = -1

WHITE = 0
GRAY = 1
BLACK = 2

def init():
    global ReadString, stdout
    ReadString = newReadString(sys.stdin.buffer.readline)
    stdout = io.BytesIO()

n, q = map(int, ReadString().split())
C = list(map(int, ReadString().split()))

P = [-1] * (500000 + 50)
Answers = [0] * q

class Query:
    def __init__(self, idx, l, r):
        self.idx = idx
        self.l = l
        self.r = r

Q = []
for i in range(q):
    l, r = map(int, ReadString().split())
    query = Query(i, l, r)
    Q.append(query)

Q.sort(key=lambda x: x.r)

ft = FenwickTree(500000 + 50)

k = 0
for query in Q:
    while k < query.r:
        if P[C[k]]!= -1:
            ft.add(P[C[k]] + 1, -1)
        P[C[k]] = k
        ft.add(k + 1, 1)
        k += 1

    Answers[query.idx] = ft.sum(query.r) - ft.sum(query.l - 1)

for ans in Answers:
    stdout.write(str(ans).encode())
    stdout.write(b'\n')

sys.stdout.buffer.write(stdout.getvalue())
sys.stdout.buffer.flush()


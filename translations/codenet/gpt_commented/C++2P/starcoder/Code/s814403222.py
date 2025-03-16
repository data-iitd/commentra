
# Define a pair type to hold an integer and a string
P = namedtuple('P', ['first','second'])

# Array to hold pairs of scores and names
v = [P(0, '') for i in range(22)]

# Vector to hold lists of indices for each number
d = [[] for i in range(33)]

while True:
    n = int(input())
    if n == 0:
        break
    m = int(input())
    for i in range(n):
        v[i] = P(0, input())
    for i in range(m):
        a = int(input())
        v[i].first += n - len(d[a])
        for j in d[a]:
            v[j].first -= 1
        d[a].append(i)
    v.sort(key=lambda x: x.first, reverse=True)
    print(v[0].first, v[0].second)



n, q = map(int, raw_input().split())

Q = []

for i in range(n):
    name, time = raw_input().split()
    Q.append((name, int(time)))

elaps = 0

while Q:
    name, time = Q.pop(0)
    if time <= q:
        elaps += time
        print name, elaps
    else:
        Q.append((name, time - q))
        elaps += q


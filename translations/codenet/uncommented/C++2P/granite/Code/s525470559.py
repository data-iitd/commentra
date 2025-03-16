
n, q = map(int, input().split())

elaps = 0
Q = []

for i in range(n):
    name, time = input().split()
    Q.append((name, int(time)))

while Q:
    name, time = Q.pop(0)
    if time <= q:
        elaps += time
        print(name, elaps)
    else:
        time -= q
        elaps += q
        Q.append((name, time))


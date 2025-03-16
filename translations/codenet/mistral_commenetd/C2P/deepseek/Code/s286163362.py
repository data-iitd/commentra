def max(a, b):
    if a > b:
        return a
    return b

data = [0] * 111111
seq = [0] * 222222

while True:
    line = input().split()
    n = int(line[0])
    k = int(line[1])
    if n == 0 and k == 0:
        break

    for i in range(111111):
        data[i] = 0
    for i in range(222222):
        seq[i] = 0

    t_list = list(map(int, input().split()))
    for t in t_list:
        data[t] += 1

    p = 0
    for i in range(1, n + 1):
        if data[i]:
            seq[p] += 1
        else:
            p += 2
    p += 1

    ret = 0
    if data[0]:
        for i in range(p):
            ret = max(ret, seq[i] + seq[i + 2] + 1)
    else:
        for i in range(p):
            ret = max(ret, seq[i])

    print(ret)

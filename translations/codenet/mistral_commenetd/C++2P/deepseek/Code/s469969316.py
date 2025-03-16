import sys

def Not(x):
    return 2 - x

def And(x, y):
    if x * y == 0:
        return 0
    if x == 2 and y == 2:
        return 2
    return 1

def Or(x, y):
    if x == 2 or y == 2:
        return 2
    if x == 1 or y == 1:
        return 1
    return 0

def parse(ss, it):
    c = ss[it]
    it += 1
    if '0' <= c and c <= '2':
        return int(c)
    if c == '-':
        return Not(parse(ss, it))

    x = parse(ss, it)
    c = ss[it]
    it += 1
    y = parse(ss, it)
    it += 1
    if c == '*':
        return And(x, y)
    else:
        return Or(x, y)

while True:
    input_line = sys.stdin.readline().strip()
    if input_line == ".":
        break
    cnt = 0
    for i in range(3):
        for j in range(3):
            for k in range(3):
                a = [i, j, k]
                ss = input_line
                ss = ss.replace('P', str(a[0])).replace('Q', str(a[1])).replace('R', str(a[2]))
                it = 0
                if parse(ss, it) == 2:
                    cnt += 1
    print(cnt)

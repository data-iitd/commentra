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

def parse():
    global it
    c = ss[it]
    it += 1
    if '0' <= c and c <= '2':
        return ord(c) - ord('0')
    if c == '-':
        return Not(parse())

    x = parse()
    c = ss[it]
    it += 1
    y = parse()
    it += 1
    if c == '*':
        return And(x, y)
    else:
        return Or(x, y)

while True:
    input_line = sys.stdin.readline().strip()
    if input_line == ".":
        break
    a = [0, 1, 2]
    cnt = 0
    for i in a:
        for j in a:
            for k in a:
                ss = input_line
                ss = ss.replace('P', str(i))
                ss = ss.replace('Q', str(j))
                ss = ss.replace('R', str(k))
                it = 0
                if parse() == 2:
                    cnt += 1
    print(cnt)

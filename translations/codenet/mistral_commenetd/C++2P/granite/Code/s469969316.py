
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
    c = ss[it]
    it += 1
    if '0' <= c and c <= '2':
        return int(c)
    if c == '-':
        return Not(parse())
    x = parse()
    c = ss[it]
    it += 1
    y = parse()
    it += 1
    return And(x, y) if c == '*' else Or(x, y)

while True:
    input = input()
    if input == ".":
        break
    cnt = 0
    for i in range(3):
        for j in range(3):
            for k in range(3):
                a = [i, j, k]
                ss = input
                for c in ss:
                    if c == 'P':
                        c = a[0]
                    if c == 'Q':
                        c = a[1]
                    if c == 'R':
                        c = a[2]
                it = 0
                if parse() == 2:
                    cnt += 1
    print(cnt)


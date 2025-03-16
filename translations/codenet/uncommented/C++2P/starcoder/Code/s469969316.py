
# <START-OF-CODE>

input = raw_input()
while input!= ".":
    a = [0,1,2]
    cnt = 0
    for i in range(3):
        for j in range(3):
            for k in range(3):
                a[0] = i
                a[1] = j
                a[2] = k
                ss = input
                ss = ss.replace("P", str(a[0]))
                ss = ss.replace("Q", str(a[1]))
                ss = ss.replace("R", str(a[2]))
                it = 0
                if parse(ss) == 2:
                    cnt += 1
    print cnt
    input = raw_input()

def parse(ss):
    c = ss[it]
    if '0' <= c and c <= '2':
        return ord(c) - ord('0')
    if c == '-':
        return Not(parse(ss))

    x = parse(ss)
    c = ss[it+1]
    y = parse(ss)
    it += 2
    return c == '*' and And(x, y) or Or(x, y)

def Not(x):
    return 2-x

def And(x, y):
    if x*y == 0:
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

# 
def not_op(x):
    return 2 - x

def and_op(x, y):
    if x * y == 0:
        return 0
    if x == 2 and y == 2:
        return 2
    return 1

def or_op(x, y):
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
        return not_op(parse(ss, it))

    x = parse(ss, it)
    c = ss[it]
    y = parse(ss, it + 1)
    it += 2
    if c == '*':
        return and_op(x, y)
    else:
        return or_op(x, y)

while True:
    input_str = input().strip()
    if input_str == '.':
        break

    cnt = 0
    for i in range(3):
        for j in range(3):
            for k in range(3):
                a = [i, j, k]
                ss = input_str
                for idx, c in enumerate(ss):
                    if c == 'P':
                        ss = ss[:idx] + str(a[0]) + ss[idx+1:]
                    elif c == 'Q':
                        ss = ss[:idx] + str(a[1]) + ss[idx+1:]
                    elif c == 'R':
                        ss = ss[:idx] + str(a[2]) + ss[idx+1:]

                it = 0
                if parse(ss, it) == 2:
                    cnt += 1
    print(cnt)

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
    c = ss[it[0]]
    it[0] += 1
    if '0' <= c <= '2':
        return int(c)
    if c == '-':
        return Not(parse(ss, it))

    x = parse(ss, it)
    c = ss[it[0]]
    it[0] += 1
    y = parse(ss, it)
    it[0] += 1
    return And(x, y) if c == '*' else Or(x, y)

def main():
    while True:
        input_str = input()
        if input_str == ".":
            break
        
        cnt = 0
        for i in range(3):
            for j in range(3):
                for k in range(3):
                    a = [i, j, k]
                    ss = input_str
                    ss = ss.replace('P', str(a[0])).replace('Q', str(a[1])).replace('R', str(a[2]))
                    it = [0]
                    if parse(ss, it) == 2:
                        cnt += 1
        print(cnt)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

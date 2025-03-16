def mul(s, idx):
    res = int(s[idx])
    idx += 1
    while idx < len(s) and s[idx] == '*':
        idx += 1
        res *= int(s[idx])
        idx += 1
    return res

def add(s, idx):
    res = mul(s, idx)
    idx += 1
    while idx < len(s) and s[idx] == '+':
        idx += 1
        res += mul(s, idx)
        idx += 1
    return res

def bob(s, idx):
    res = int(s[idx])
    idx += 1
    while idx < len(s):
        if s[idx] == '+':
            res += int(s[idx+1])
        else:
            res *= int(s[idx+1])
        idx += 2
    return res

while True:
    try:
        s, d = input().split()
        d = int(d)
        idx = 0
        a = add(s, idx)
        idx = 0
        b = bob(s, idx)
        if a == d:
            print('U' if b == d else 'M')
        else:
            print('L' if b == d else 'I')
    except EOFError:
        break

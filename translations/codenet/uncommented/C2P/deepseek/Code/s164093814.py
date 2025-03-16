M = 1046527
L = 14

def get_char(ch):
    if ch == 'A':
        return 1
    elif ch == 'C':
        return 2
    elif ch == 'G':
        return 3
    elif ch == 'T':
        return 4
    return 0

def get_key(str_):
    sum_ = 0
    p = 1
    for ch in str_:
        sum_ += p * get_char(ch)
        p *= 5
    return sum_

def h1(key):
    return key % M

def h2(key):
    return 1 + (key % (M - 1))

def find(str_):
    key = get_key(str_)
    i = 0
    while True:
        hash_ = (h1(key) + i * h2(key)) % M
        if H[hash_] == str_:
            return True
        elif H[hash_] == '':
            return False
        i += 1
    return False

def insert(str_):
    key = get_key(str_)
    i = 0
    while True:
        hash_ = (h1(key) + i * h2(key)) % M
        if H[hash_] == str_:
            return True
        elif H[hash_] == '':
            H[hash_] = str_
            return False
        i += 1
    return False

H = [''] * M

n = int(input())

for _ in range(n):
    com, str_ = input().split()
    if com[0] == 'i':
        insert(str_)
    else:
        if find(str_):
            print("yes")
        else:
            print("no")


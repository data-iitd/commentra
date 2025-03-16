M = 1046527
L = 14

def getChar(ch):
    if ch == 'A':
        return 1
    elif ch == 'C':
        return 2
    elif ch == 'G':
        return 3
    elif ch == 'T':
        return 4
    return 0

def getKey(str):
    sum = 0
    p = 1
    for i in range(len(str)):
        sum += p * getChar(str[i])
        p *= 5
    return sum

def h1(key):
    return key % M

def h2(key):
    return 1 + (key % (M - 1))

def find(str):
    key = getKey(str)
    i = 0
    while True:
        hash = (h1(key) + i * h2(key)) % M
        if H[hash] == str:
            return True
        elif H[hash] == "":
            return False
        i += 1
    return False

def insert(str):
    key = getKey(str)
    i = 0
    while True:
        hash = (h1(key) + i * h2(key)) % M
        if H[hash] == "":
            H[hash] = str
            return False
        i += 1
    return False

n = int(input())
H = [""] * M

for _ in range(n):
    com, str = input().split()
    if com == 'i':
        insert(str)
    else:
        if find(str):
            print("yes")
        else:
            print("no")


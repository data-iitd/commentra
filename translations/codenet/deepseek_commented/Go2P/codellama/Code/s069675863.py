
# Package main defines the entry point of the program.
import sys



# Constants used in the program.
MOD = 1000000000 + 7
ALPHABET_NUM = 26
INF_INT64 = sys.maxsize
INF_BIT60 = 1 << 60
INF_INT32 = sys.maxsize
INF_BIT30 = 1 << 30
NIL = -1
WHITE = 0
GRAY = 1
BLACK = 2



# init function initializes the input reader and output writer.
def init():
    global ReadString
    global stdout
    ReadString = newReadString(sys.stdin, sys.stdin.readline)
    stdout = sys.stdout



# Main function reads input, processes the data, and prints the result.
def main():
    global S
    global x
    global y
    S = ReadString()
    x, y = map(int, ReadString().split())

    F = []
    cur = 0
    for i in range(len(S)):
        if S[i] == 'F':
            cur += 1
        else:
            F.append(cur)
            cur = 0
    F.append(cur)
    # PrintfDebug("%v\n", F)

    evens, odds = [], []
    for i in range(len(F)):
        if i % 2 == 0:
            evens.append(F[i])
        else:
            odds.append(F[i])

    dpx = [[False for _ in range(18001)] for _ in range(len(evens) + 1)]
    dpy = [[False for _ in range(18001)] for _ in range(len(odds) + 1)]
    dpx[0][10000], dpy[0][10000] = True, True
    for i in range(len(evens)):
        val = evens[i]
        for j in range(2000, 18001):
            if j + val <= 18000:
                dpx[i + 1][j + val] = dpx[i + 1][j + val] or dpx[i][j]
            if j - val >= 2000 and i != 0:
                dpx[i + 1][j - val] = dpx[i + 1][j - val] or dpx[i][j]
    for i in range(len(odds)):
        val = odds[i]
        for j in range(2000, 18001):
            if j + val <= 18000:
                dpy[i + 1][j + val] = dpy[i + 1][j + val] or dpy[i][j]
            if j - val >= 2000:
                dpy[i + 1][j - val] = dpy[i + 1][j - val] or dpy[i][j]
    # PrintfDebug("%v\n", dpx)
    # PrintfDebug("%v\n", dpy)

    if dpx[len(evens)][x + 10000] and dpy[len(odds)][y + 10000]:
        print("Yes")
    else:
        print("No")



# ReadString returns a WORD string.
def newReadString(ior, sf):
    if sf == None:
        sf = lambda x: x
    r = ior.readline()
    if not r: return None
    return sf(r)



# ReadInt returns an integer.
def ReadInt():
    return int(readInt64())
def ReadInt2():
    return int(readInt64()), int(readInt64())
def ReadInt3():
    return int(readInt64()), int(readInt64()), int(readInt64())
def ReadInt4():
    return int(readInt64()), int(readInt64()), int(readInt64()), int(readInt64())

def ReadInt64():
    return readInt64()
def ReadInt64_2():
    return readInt64(), readInt64()
def ReadInt64_3():
    return readInt64(), readInt64(), readInt64()
def ReadInt64_4():
    return readInt64(), readInt64(), readInt64(), readInt64()

def readInt64():
    return int(readFloat64())

def ReadIntSlice(n):
    b = list(range(n))
    for i in range(n):
        b[i] = ReadInt()
    return b

def ReadInt64Slice(n):
    b = list(range(n))
    for i in range(n):
        b[i] = ReadInt64()
    return b

def ReadFloat64():
    return float(readFloat64())

def readFloat64():
    return float(input())

def ReadFloat64Slice(n):
    b = list(range(n))
    for i in range(n):
        b[i] = ReadFloat64()
    return b

def ReadRuneSlice():
    return list(input())



def ZeroPaddingRuneSlice(n, digitsNum):
    sn = list(map(int, list(str(n))))

    if len(sn) < digitsNum:
        sn.insert(0, 0)

    return sn

def Strtoi(s):
    return int(s)

def PrintIntsLine(A):
    print(*A, sep=' ')

def PrintInts64Line(A):
    print(*A, sep=' ')

def PrintfDebug(format, *args):
    sys.stderr.write(format % args)

def PrintfBufStdout(format, *args):
    sys.stdout.write(format % args)



# Translate the above Go code to Python and end with comment "
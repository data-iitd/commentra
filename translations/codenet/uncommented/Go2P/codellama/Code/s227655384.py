
import sys

def readLongLines(times):
    result = []
    for i in range(times):
        line = sys.stdin.readline()
        result.append(line)
    return result

def main():
    m = {}
    lines = readLongLines(4)
    a = lines[1].split()
    for i in range(len(a)):
        n = int(a[i])
        m[n] = 1

    result = []
    b = lines[3].split()
    for i in range(len(b)):
        n = int(b[i])
        if n in m:
            del m[n]
        else:
            m[n] = 1
    for k in m.keys():
        result.append(k)
    result.sort()
    for j in range(len(result)):
        print(result[j])

if __name__ == '__main__':
    main()


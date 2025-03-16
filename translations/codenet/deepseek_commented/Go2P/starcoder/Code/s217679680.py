def scanArrayInt():
    ret = []
    stdin.readline()
    for s in stdin.readline().split():
        ret.append(int(s))
    return ret

def main():
    arr = scanArrayInt()
    a, b = arr[0], arr[1]
    tap = 0
    consent = 1
    while consent < b:
        consent += a - 1
        tap += 1
    print(tap)

main()


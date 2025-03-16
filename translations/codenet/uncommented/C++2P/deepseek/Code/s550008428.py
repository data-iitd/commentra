import sys

def main():
    s = int(input().strip())
    a = set([s])
    d = 2

    while True:
        if s % 2 == 0:
            x = s // 2
            if x in a:
                print(d)
                return
            a.add(x)
        else:
            x = 3 * s + 1
            if x in a:
                print(d)
                return
            a.add(x)
        s = x
        d += 1

    print(d)

if __name__ == "__main__":
    main()

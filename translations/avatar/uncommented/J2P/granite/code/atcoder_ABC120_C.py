
import sys
def main():
    x = sys.stdin.readline().strip()
    s = []
    c = 0
    for i in range(len(x)):
        s.append(x[i])
        while len(s) > 1:
            p = s.pop()
            q = s.pop()
            if (p == '1' and q == '0') or (p == '0' and q == '1'):
                c += 1
                continue
            else:
                s.append(q)
                s.append(p)
                break
    print(c * 2)

if __name__ == "__main__":
    main()


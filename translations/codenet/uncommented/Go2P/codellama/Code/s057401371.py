
import sys

def main():
    s = sys.stdin.readline().strip()
    d = ord('a') - ord('A')
    for r in s:
        rr = r
        if 'A' <= r <= 'Z':
            rr = chr(ord(r) + d)
        elif 'a' <= r <= 'z':
            rr = chr(ord(r) - d)
        print(rr, end='')
    print()

if __name__ == '__main__':
    main()


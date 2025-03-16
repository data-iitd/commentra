
import sys
import io
import bisect

def main():
    f = io.BufferedReader(io.StringIO(sys.stdin.read()))
    out = io.StringIO()
    st = next(f).split()
    n = int(st[0])
    k = int(st[1])
    cards = [0] * 26
    s = next(f)
    for t in range(n):
        cards[ord(s[t]) - ord('A')] += 1
    ans = 0
    for i in range(k):
        cards.sort()
        change = min(cards[25], k - i)
        ans += change * change
        cards[25] -= change
        i += change - 1
    out.write(str(ans) + '\n')
    sys.stdout.write(out.getvalue())

if __name__ == '__main__':
    main()


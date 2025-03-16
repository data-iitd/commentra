
import sys

def main():
    N, K = map(int, sys.stdin.readline().split())
    S = sys.stdin.readline().strip()
    blocks = run_length(S)
    sum, zero, l = 0, 0, 0
    for r in range(len(blocks)):
        sum += blocks[r].len
        if blocks[r].value == '0':
            zero += 1
        while K < zero:
            sum -= blocks[l].len
            if blocks[l].value == '0':
                zero -= 1
            l += 1
        ans = max(ans, sum)
    print(ans)

def run_length(s):
    r = []
    if len(s) == 0:
        return r
    t = Block(value=s[0], len=1)
    for v in s[1:]:
        if t.value == v:
            t.len += 1
        else:
            r.append(t)
            t = Block(value=v, len=1)
    r.append(t)
    return r

class Block:
    def __init__(self, value, len):
        self.value = value
        self.len = len

if __name__ == '__main__':
    main()


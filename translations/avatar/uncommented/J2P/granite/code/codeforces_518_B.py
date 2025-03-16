
import sys

def main():
    s = sys.stdin.readline().strip()
    t = sys.stdin.readline().strip()
    tmap = {}
    for ch in t:
        if ch not in tmap:
            tmap[ch] = 1
        else:
            tmap[ch] += 1
    length = len(s)
    ura = 0
    opa = 0
    for i in range(length):
        ch = s[i]
        if ch not in tmap:
            continue
        num = tmap[ch]
        if num == 1:
            del tmap[ch]
        else:
            tmap[ch] -= 1
        s = s[:i] + 'Я' + s[i+1:]
        ura += 1
    for i in range(length):
        ch = s[i]
        rch = reverse(ch)
        if rch not in tmap:
            continue
        num = tmap[rch]
        if num == 1:
            del tmap[rch]
        else:
            tmap[rch] -= 1
        opa += 1
    print(ura, opa)

def reverse(ch):
    if ch.islower():
        return ch.upper()
    else:
        return ch.lower()

if __name__ == '__main__':
    main()


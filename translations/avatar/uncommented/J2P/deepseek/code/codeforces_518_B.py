import sys

def reverse(ch):
    if ch.islower():
        return ch.upper()
    else:
        return ch.lower()

def main():
    s = input().strip()
    t = input().strip()
    ura = 0
    opa = 0
    tmap = {}
    
    for ch in t:
        if ch not in tmap:
            tmap[ch] = 1
        else:
            tmap[ch] += 1
    
    length = len(s)
    for i in range(length):
        ch = s[i]
        num = tmap.get(ch)
        if num is None:
            continue
        inum = num
        if inum == 1:
            del tmap[ch]
        else:
            tmap[ch] = inum - 1
        s = s[:i] + 'Я' + s[i+1:]
        ura += 1
    
    for i in range(length):
        ch = s[i]
        rch = reverse(ch)
        num = tmap.get(rch)
        if num is None:
            continue
        inum = num
        if inum == 1:
            del tmap[rch]
        else:
            tmap[rch] = inum - 1
        opa += 1
    
    print(ura, opa)

if __name__ == "__main__":
    main()

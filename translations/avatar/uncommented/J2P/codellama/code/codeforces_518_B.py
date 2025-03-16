import sys
s = sys.stdin.readline().strip()
t = sys.stdin.readline().strip()
ura = 0
opa = 0
tmap = {}
for i in range(len(t)):
    ch = t[i]
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
        tmap.pop(ch)
    else:
        tmap[ch] = inum - 1
    s = s[:i] + 'Я' + s[i+1:]
    ura += 1
for i in range(length):
    ch = s[i]
    rch = ch.lower() if ch.isupper() else ch.upper()
    num = tmap.get(rch)
    if num is None:
        continue
    inum = num
    if inum == 1:
        tmap.pop(rch)
    else:
        tmap[rch] = inum - 1
    opa += 1
print(ura, opa)



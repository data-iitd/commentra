
import sys

d = ord('a') - ord('A')
for c in sys.stdin.read():
    if 'A' <= c <= 'Z':
        c = chr(ord(c) + d)
    elif 'a' <= c <= 'z':
        c = chr(ord(c) - d)
    sys.stdout.write(c)
sys.stdout.flush()

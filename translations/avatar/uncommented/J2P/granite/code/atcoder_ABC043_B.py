
import sys
import io
import os

def main():
    input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
    s = input().decode().rstrip()
    d = []
    for c in s:
        if c == '0':
            d.append('0')
        elif c == '1':
            d.append('1')
        elif c == 'B':
            if len(d) > 0:
                d.pop()
    print(''.join(d))

if __name__ == "__main__":
    main()


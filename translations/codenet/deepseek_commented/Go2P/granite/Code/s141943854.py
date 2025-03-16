

import sys

def check(e):
    if e:
        raise SystemExit(e)

def main():
    for line in sys.stdin:
        sage = line.strip()
        if sage == "1":
            print("Hello World")
        elif sage == "2":
            sum = 0
            for _ in range(2):
                line = sys.stdin.readline().strip()
                num = int(line)
                sum += num
            print(sum)


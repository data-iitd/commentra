import sys

def main():
    input_line = sys.stdin.readline().strip()
    h, a = map(int, input_line.split())
    num = 0
    while h > 0:
        h -= a
        num += 1
    print(num)

if __name__ == "__main__":
    main()

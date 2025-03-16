import sys

def main():
    try:
        a, b = map(int, sys.stdin.readline().split())
        c = a - b * 2
        if c < 0:
            c = 0
        print(c)
    except:
        # Handle exceptions (not implemented in this code)

if __name__ == "__main__":
    main()


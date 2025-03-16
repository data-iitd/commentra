import sys

def main():
    input_line = sys.stdin.readline().strip().split()
    a, b = map(int, sys.stdin.readline().strip().split())
    u = sys.stdin.readline().strip()
    
    if u == input_line[0]:
        print(f"{a - 1} {b}")
    else:
        print(f"{a} {b - 1}")

if __name__ == "__main__":
    main()

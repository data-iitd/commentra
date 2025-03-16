import sys

def main():
    str_input = sys.stdin.readline().strip().split()
    a, b = map(int, sys.stdin.readline().strip().split())
    u = sys.stdin.readline().strip()
    
    if u == str_input[0]:
        print(a - 1, b)
    else:
        print(a, b - 1)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

import sys

def next_line():
    return sys.stdin.readline().strip()

def main():
    a = int(next_line())
    b = int(next_line())

    if (a * b) % 2 != 0:
        print("Odd")
    else:
        print("Even")

if __name__ == "__main__":
    main()

# <END-OF-CODE>

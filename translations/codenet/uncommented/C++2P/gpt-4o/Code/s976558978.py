import sys

def read_int():
    return int(sys.stdin.readline().strip())

def write_int(value):
    sys.stdout.write(f"{value}\n")

def main():
    a = read_int()
    b = read_int()
    
    if a < b:
        for _ in range(b):
            write_int(a)
    else:
        for _ in range(a):
            write_int(b)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

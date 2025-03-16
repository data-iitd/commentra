import sys

def next():
    return sys.stdin.readline().strip()

def next_int():
    return int(next())

def main():
    a = next_int()
    b = next_int()
    c = next_int()
    
    if a + b >= c:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()

# <END-OF-CODE>

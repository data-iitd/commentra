import sys

def main():
    input = sys.stdin.read
    data = input().split()
    a = int(data[0])
    b = int(data[1])
    c = int(data[2])
    d = int(data[3])
    
    if c > b:
        print(0)
    elif a > d:
        print(0)
    elif a < c:
        print(min(b, d) - c)
    else:
        l = [a, b, c, d]
        l.sort()
        print(l[2] - l[1])

if __name__ == "__main__":
    main()

# <END-OF-CODE>

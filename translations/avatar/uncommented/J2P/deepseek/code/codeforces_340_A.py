import sys

def main():
    x = int(input().strip())
    y = int(input().strip())
    a = int(input().strip())
    b = int(input().strip())
    
    c = max(x, y)
    if c > b:
        print(0)
        return
    
    j = 2
    while c % min(x, y) != 0:
        if x > y:
            c = x * j
        else:
            c = y * j
        j += 1
        if c > b:
            print(0)
            return
    
    count = 0
    i = a
    while i <= b:
        if i % c == 0:
            break
        i += 1
    
    if i != b + 1:
        print((b - i) // c + 1)
    else:
        print(0)

if __name__ == "__main__":
    main()

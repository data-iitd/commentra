import sys

def main():
    # Reading the input values
    x = int(sys.stdin.readline().strip())
    y = int(sys.stdin.readline().strip())
    a = int(sys.stdin.readline().strip())
    b = int(sys.stdin.readline().strip())
    
    # Initializing variables
    j = 2
    ans = True
    
    # Finding the maximum value between x and y
    c = max(x, y)
    
    # Checking if the maximum value is greater than b
    if c > b:
        print("0")
        ans = False
    
    while c % min(x, y) != 0 and ans:
        if x > y:
            c = x * j
        else:
            c = y * j
        j += 1
        
        if c > b:
            print("0")
            ans = False
            break
    
    if ans:
        count = 0
        i = a
        
        # Loop to find the number of times c divides i
        for i in range(a, b + 1):
            if i % c == 0:
                break
        
        if i != b + 1:
            print((b - i) // c + 1)
        else:
            print("0")

if __name__ == "__main__":
    main()

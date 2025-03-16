def abs_value(x):
    return -x if x < 0 else x

def main():
    N = int(input())
    nx = ny = nt = 0
    
    for _ in range(N):
        t, x, y = map(int, input().split())
        tmp = t - nt - (abs_value(x - nx) + abs_value(y - ny))
        
        if tmp < 0 or tmp % 2:
            print("No")
            return
    
    print("Yes")

if __name__ == "__main__":
    main()

# <END-OF-CODE>

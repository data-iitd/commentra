def main():
    a = int(input())
    ar = [int(input()) for _ in range(a)]
    max_val = 0
    min_val = 0
    
    for i in range(len(ar)):
        max_val = max(ar[i] - ar[0], ar[-1] - ar[i])
        
        if i == 0:
            min_val = ar[i + 1] - ar[i]
        elif i == len(ar) - 1:
            min_val = ar[i] - ar[i - 1]
        else:
            min_val = min(ar[i] - ar[i - 1], ar[i + 1] - ar[i])
        
        print(min_val, max_val)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

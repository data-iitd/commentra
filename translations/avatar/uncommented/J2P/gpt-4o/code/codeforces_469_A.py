def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    levels = int(data[1])
    arr = list(map(int, data[2:2 + levels]))
    
    level2 = int(data[2 + levels])
    level3 = levels + level2
    arr2 = arr + list(map(int, data[3 + levels:3 + level3]))
    
    count = 0
    arr3 = list(range(1, n + 1))
    
    for i in range(n):
        for x in range(len(arr2)):
            if arr3[i] == arr2[x]:
                count += 1
                break
    
    if count == n:
        print("I become the guy.")
    else:
        print("Oh, my keyboard!")

if __name__ == "__main__":
    main()

# <END-OF-CODE>

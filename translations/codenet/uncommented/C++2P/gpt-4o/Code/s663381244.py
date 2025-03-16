def main():
    import sys
    input = sys.stdin.read
    data = input().strip().splitlines()
    
    m = [10, 50, 100, 500]
    
    first = True
    index = 0
    while index < len(data):
        money = int(data[index])
        if money == 0:
            break
        
        if not first:
            print()
        
        first = False
        index += 1
        sum_value = 0
        num = [0] * 4
        
        for i in range(4):
            num[i] = int(data[index])
            sum_value += num[i] * m[i]
            index += 1
        
        change = sum_value - money
        for i in range(3, -1, -1):
            if change // m[i]:
                num[i] -= change // m[i]
                change %= m[i]
        
        for i in range(4):
            if num[i] > 0:
                print(m[i], num[i])

if __name__ == "__main__":
    main()

# <END-OF-CODE>

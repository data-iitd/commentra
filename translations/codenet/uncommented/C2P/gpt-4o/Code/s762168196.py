def main():
    a = []
    n = int(input())
    sum = 0
    
    for i in range(n):
        value = int(input())
        a.append(value)
        sum += value
    
    max_value = min_value = a[0]
    
    for i in range(1, n):
        if a[i] > max_value:
            max_value = a[i]
        if a[i] < min_value:
            min_value = a[i]
    
    print(min_value, max_value, sum)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

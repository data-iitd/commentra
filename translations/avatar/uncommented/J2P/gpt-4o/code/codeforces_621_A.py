def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    numbers = list(map(int, data[1:n+1]))
    
    odd = []
    total_sum = 0
    
    for number in numbers:
        if number % 2 == 0:
            total_sum += number
        else:
            odd.append(number)
    
    odd.sort()
    
    for number in odd:
        total_sum += number
    
    if len(odd) % 2 != 0:
        total_sum -= odd[0]
    
    print(total_sum)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

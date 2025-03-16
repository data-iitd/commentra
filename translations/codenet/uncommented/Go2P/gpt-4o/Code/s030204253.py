def main():
    n = int(input())
    a = list(map(float, input().split()))
    
    for _ in range(n - 1):
        a.sort()
        na = a[2:]  # Take all elements from index 2 to the end
        na.append((a[0] + a[1]) / 2)  # Append the average of the first two elements
        a = na  # Update a to the new list
    
    print(a[0])

if __name__ == "__main__":
    main()

# <END-OF-CODE>

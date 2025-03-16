def resolve():
    # Read the number of pairs
    n = int(input())
    
    # Initialize lists to store the lower and higher values of each pair
    low = []
    high = []
    
    # Loop to read each pair and append values to the lists
    for i in range(n):
        a, b = map(int, input().split())
        low.append(a)
        high.append(b)
    
    # Sort the lists
    low.sort()
    high.sort()
    
    # Check if the number of pairs is odd or even
    if n % 2:
        # If odd, calculate the range between the middle elements
        print(high[(n + 1) // 2 - 1] - low[(n + 1) // 2 - 1] + 1)
    else:
        # If even, calculate the average of the middle elements and print the range
        hh = (high[(n) // 2 - 1] + high[(n) // 2]) / 2
        ll = (low[(n) // 2 - 1] + low[(n) // 2]) / 2
        print(int((hh - ll) * 2) + 1)

# Call the resolve function when the script is executed
if __name__ == "__main__":
    resolve()

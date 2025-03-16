def resolve():
    # Read the number of intervals
    n = int(input())
    
    # Initialize lists to store the lower and upper bounds of the intervals
    low = []
    high = []
    
    # Read each interval and store the lower and upper bounds
    for i in range(n):
        a, b = map(int, input().split())
        low.append(a)  # Append the lower bound to the low list
        high.append(b)  # Append the upper bound to the high list
    
    # Sort the lower and upper bounds
    low.sort()
    high.sort()
    
    # Check if the number of intervals is odd
    if n % 2:
        # For odd number of intervals, calculate the range of the median interval
        print(high[(n + 1) // 2 - 1] - low[(n + 1) // 2 - 1] + 1)
    else:
        # For even number of intervals, calculate the average of the two middle values
        hh = (high[n // 2 - 1] + high[n // 2]) / 2  # Average of the two middle high values
        ll = (low[n // 2 - 1] + low[n // 2]) / 2    # Average of the two middle low values
        # Calculate the range and print the result
        print(int((hh - ll) * 2) + 1)

# Entry point of the program
if __name__ == "__main__":
    resolve()

def main():
    n, k = map(int, input().split())  # Read input values
    cnt = 0  # Initialize the count variable
    for _ in range(n):  # Use a for loop to read each height
        h = int(input())  # Read each height
        if h >= k:  # Check if the height is suitable
            cnt += 1  # Increment the count if the height is greater than or equal to k
    print(cnt)  # Print the final count


main()

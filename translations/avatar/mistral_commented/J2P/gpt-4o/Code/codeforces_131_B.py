# Initialize scanner object to read input from the console
def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    # Read the number of test cases from the console
    n = int(data[0])
    
    # Initialize an array to store the count of each number
    cnt = [0] * 21
    
    # Read the numbers one by one and update the count array accordingly
    for i in range(1, n + 1):
        num = int(data[i])  # Read the next number
        cnt[num + 10] += 1  # Increment the count of the number
    
    # Calculate the result using the given formula
    res = 0
    for i in range(10):
        res += cnt[i] * cnt[20 - i]  # Calculate the sum of products of pairs of numbers with absolute difference i
    res += (cnt[10] * (cnt[10] - 1)) // 2  # Calculate the sum of squares of numbers equal to 10 and add half of it
    
    # Print the result to the console
    print(res)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

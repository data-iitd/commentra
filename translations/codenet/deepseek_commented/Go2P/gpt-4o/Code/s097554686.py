size = 100001

def main():
    n, t = map(int, input().split())  # Read the number of intervals and time range
    mem = [0] * size  # Declare a list to store cumulative changes

    # Read each interval and update the cumulative changes in the list
    for _ in range(n):
        l, r = map(int, input().split())  # Read the left and right endpoints
        mem[l] += 1  # Increment the value at the left endpoint
        mem[r] -= 1  # Decrement the value at the right endpoint

    # Initialize ans with the value at mem[0]
    ans = mem[0]

    # Compute the prefix sum and find the maximum value in the list
    for i in range(1, t + 1):
        mem[i] += mem[i - 1]  # Compute the prefix sum
        if ans < mem[i]:  # Update ans if a larger value is found
            ans = mem[i]

    # Print the maximum value found
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

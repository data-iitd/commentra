# Define a constant for the maximum size of the memory array
size = 100001

def main():
    # Declare variables for the number of intervals (n), the maximum time (t),
    # and the left (l) and right (r) bounds of each interval
    n = int(input())
    t = int(input())
    l, r = 0, 0
    # Create a list to store the count of overlapping intervals at each time point
    mem = [0] * size

    # Process each interval
    for _ in range(n):
        # Read the left and right bounds of the interval
        l = int(input())
        r = int(input())
        # Increment the count at the start of the interval
        mem[l] += 1
        # Decrement the count just after the end of the interval
        mem[r] -= 1

    # Initialize the answer with the count at time 0
    ans = mem[0]

    # Calculate the number of overlapping intervals at each time point
    for i in range(1, t + 1):
        # Update the current count based on the previous count
        mem[i] += mem[i - 1]
        # Update the answer if the current count is greater than the previous maximum
        if ans < mem[i]:
            ans = mem[i]

    # Print the maximum number of overlapping intervals
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

import sys

inf = 10**14  # Define a large value to represent infinity for cost comparisons

def min(*args):
    return min(args)

def main():
    n = int(sys.stdin.readline().strip())  # Read the number of elements
    x = int(sys.stdin.readline().strip())  # Read some parameter x
    a = list(map(int, sys.stdin.readline().strip().split()))  # Fill the array a with integers from input
    v = a.copy()  # Create a copy of array a named v
    ans = inf  # Initialize the answer with a large value

    for k in range(n):  # Iterate over possible values of k
        kans = 0  # Initialize the temporary answer for the current k
        for i in range(n):  # Iterate over each element in the array
            if i - k < 0:  # If the index is out of bounds, wrap around
                v[i] = min(v[i], a[n + i - k])  # Update the value in v
            else:
                v[i] = min(v[i], a[i - k])  # Update the value in v
            kans += v[i]  # Add the updated value to the temporary answer
        ans = min(ans, kans + k * x)  # Update the final answer with the minimum cost

    print(ans)  # Print the minimum cost found

if __name__ == "__main__":
    main()

# <END-OF-CODE>

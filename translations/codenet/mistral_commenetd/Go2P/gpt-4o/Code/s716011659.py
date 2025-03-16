import sys

inf = 1e12  # Constants should be defined with clear names and values

def main():
    # Initialize variables and read input
    n = int(input().strip())

    arrA = list(map(int, input().strip().split()))  # Read the array of size n

    cumSumA = [0] * (n + 1)  # Create an array of size n+1 to store cumulative sum
    for i in range(n):  # Iterate through the array and calculate cumulative sum
        cumSumA[i + 1] = cumSumA[i] + arrA[i]

    # Initialize variable to store the answer
    ans = inf  # Initialize with a large value

    # Iterate through the array to find the answer
    for i in range(1, n):
        temp = cumSumA[n] - cumSumA[i] * 2  # Calculate the difference
        if abs(temp) < ans:  # If the difference is smaller than the current answer
            ans = abs(temp)  # Update the answer

    # Print the answer
    print(int(ans))

if __name__ == "__main__":
    main()

# <END-OF-CODE>

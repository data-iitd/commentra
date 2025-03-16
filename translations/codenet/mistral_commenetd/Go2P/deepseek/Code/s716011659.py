import sys

inf = 1e12  # Constants should be defined with clear names and values

def main():
    # Initialize variables and read input
    n = int(input().strip())
    arrA = list(map(int, input().strip().split()))

    # Create an array of size n+1 to store cumulative sum
    cumSumA = [0] * (n + 1)

    # Calculate cumulative sum
    for i, a in enumerate(arrA):
        cumSumA[i + 1] = cumSumA[i] + a

    # Initialize variable to store the answer
    ans = inf  # Initialize with a large value

    # Iterate through the array to find the answer
    for i in range(1, n):
        temp = float(cumSumA[n]) - float(cumSumA[i]) * 2  # Calculate the difference
        if abs(temp) < ans:  # If the difference is smaller than the current answer
            ans = temp  # Update the answer

    # Print the answer
    print(int(ans))

# End of the code

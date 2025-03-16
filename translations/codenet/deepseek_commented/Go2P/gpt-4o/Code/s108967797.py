import sys

# Function to read an integer from standard input.
def ri():
    return int(sys.stdin.readline().strip())

# Function to calculate the average of a list of float values.
def ave(s):
    return sum(s) / len(s)

# Function to calculate the absolute difference between two float values.
def diff(a, b):
    return abs(a - b)

# Main function is the entry point of the program.
if __name__ == "__main__":
    n = ri()  # Reads the number of elements.
    a = [float(ri()) for _ in range(n)]  # Reads n integers into a float list.

    avg = ave(a)  # Calculates the average of the list.

    min_diff = float('inf')
    ans_index = -1
    for i, v in enumerate(a):
        d = diff(v, avg)  # Calculates the absolute difference between each element and the average.
        if d < min_diff:
            min_diff = d
            ans_index = i

    print(ans_index)  # Outputs the index with the smallest difference.

# <END-OF-CODE>

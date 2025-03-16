import sys

# Data class to represent a single data entry with a string field
class Data:
    def __init__(self, x):
        self.x = x

# Function to read an integer from input
def next_int():
    return int(sys.stdin.readline().strip())

# Function to read a string from input
def next_string():
    return sys.stdin.readline().strip()

def main():
    N = next_int()  # Read the number of data entries
    L = next_int()  # Read an additional integer (not used further in the code)
    
    s = []  # Create a list to hold Data entries

    # Read N strings into the list s
    for _ in range(N):
        s.append(Data(next_string()))  # Populate each Data entry with a string

    # Sort the list of Data entries based on the string field x
    s.sort(key=lambda data: data.x)

    # Concatenate all strings in the sorted list into a single result
    ans = ''.join(data.x for data in s)
    print(ans)  # Print the concatenated result

if __name__ == "__main__":
    main()

# <END-OF-CODE>

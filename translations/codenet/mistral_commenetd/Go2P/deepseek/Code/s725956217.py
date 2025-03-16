# Python code

# Function out is used for printing output to the console
def out(*x):
    print(*x)

# Function getInt is used for reading an integer value from the standard input
def getInt():
    return int(input())

# Function getString is used for reading a string value from the standard input
def getString():
    return input()

# Function max returns the maximum value between two integers
def max(a, b):
    return a if a > b else b

# Function min returns the minimum value between two integers
def min(a, b):
    return a if a < b else b

# Function asub returns the absolute difference between two integers
def asub(a, b):
    return a - b if a > b else b - a

# Function abs returns the absolute value of an integer
def abs(a):
    return a if a >= 0 else -a

# Function lowerBound returns the index of the first element in the slice that is greater than or equal to the given value
def lowerBound(a, x):
    left, right = 0, len(a)
    while left < right:
        mid = (left + right) // 2
        if a[mid] < x:
            left = mid + 1
        else:
            right = mid
    return left

# Function upperBound returns the index of the first element in the slice that is greater than the given value
def upperBound(a, x):
    left, right = 0, len(a)
    while left < right:
        mid = (left + right) // 2
        if a[mid] <= x:
            left = mid + 1
        else:
            right = mid
    return left

# Type shop represents a data structure for storing two integers
class Shop:
    def __init__(self, a, b):
        self.a = a
        self.b = b

# Type Datas is a list of shop data structures
class Datas(list):
    def __init__(self, *args):
        super().__init__(*args)

    def __len__(self):
        return len(self)

    def __getitem__(self, idx):
        return self.__class__(super().__getitem__(idx))

    def __setitem__(self, idx, value):
        if isinstance(value, Shop):
            super().__setitem__(idx, (value.a, value.b))
        else:
            super().__setitem__(idx, value)

    def __repr__(self):
        return "[" + ", ".join(f"Shop({a}, {b})" for a, b in self) + "]"

    def sort(self, key=lambda x: x.a):
        super().sort(key=key)

# Main function is the entry point of the program
def main():
    # Read the number of shops N and the number of customers M from the standard input
    N, M = map(getInt, getString().split())
    # Initialize a list of shop data structures named s with a length of N
    s = Datas()
    # For each shop in the list
    for _ in range(N):
        # Read the capacity 'a' and demand 'b' of the shop from the standard input
        a, b = map(getInt, getString().split())
        # Create a new shop data structure with the read values and append it to the list
        s.append(Shop(a, b))
    # Sort the list in ascending order based on the 'a' field of each shop
    s.sort(key=lambda x: x.a)

    # Initialize a variable named total to store the total capacity used by the shops
    total = 0
    # For each shop in the sorted list
    for e in s:
        # Calculate the minimum capacity that can be served by the shop without exceeding the maximum demand
        n = min(e.b, M)
        # Add the capacity of the shop multiplied by the number of customers it can serve to the total capacity
        total += n * e.a
        # Decrease the maximum demand by the number of customers served by the shop
        M -= n
        # If the maximum demand becomes zero, break the loop
        if M == 0:
            break
    # Print the total capacity used by the shops
    out(total)

# Call the main function
main()



ns = []

# Read the first line of input containing 4 integers and store them in ns list
print("Reading input")
ns = list(map(int, input().split()))

# Sort the ns list in ascending order
print("Sorting the numbers in ns list")
ns.sort()

# Check if the sorted ns list matches the specific condition (1, 4, 7, 9)
print("Checking the condition")
if ns == [1, 4, 7, 9]:
    print("The condition is true, print YES")
    print("Output: YES")
    print()
    print("End of the program")
    exit()
else:
    print("The condition is false, print NO")
    print("Output: NO")
    print()
    print("End of the program")
    exit()


# Take an integer n as input, which represents the number of elements in the list a.
n = int(input())

# Take a list a as input, where each element is a string.
# We convert each string to an integer using the map function and int constructor.
a = list(map(int, input().split()))

# Create an empty list b.
b = []

# Populate list b by reversing every other element in list a starting from the second element
# and appending it to b. Then, we append the next non-reversed element to b.
for i in range(1, len(a), 2):
    b.append(a[i][::-1])
    if i < len(a) - 1:
        b.append(a[i+1])

# Check if the length of a is even or odd.
if len(a) % 2 == 0:
    # If the length of a is even, we print the list b as space-separated strings.
    print(' '.join(map(str, b)))
else:
    # If the length of a is odd, we print the reversed list b as space-separated strings.
    print(' '.join(map(str, b[::-1])))

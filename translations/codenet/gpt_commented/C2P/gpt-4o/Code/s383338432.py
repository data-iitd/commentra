# Declare variables for height and width of the input
height, width = map(int, input().split())

# Print the top border of the box, consisting of '#' characters
print('#' * (width + 2))

# Read each line of input and print it with '#' borders
for _ in range(height):
    input_str = input()
    # Print the string with '#' on both sides
    print(f'#{input_str}#')

# Print the bottom border of the box, consisting of '#' characters
print('#' * (width + 2))

# <END-OF-CODE>

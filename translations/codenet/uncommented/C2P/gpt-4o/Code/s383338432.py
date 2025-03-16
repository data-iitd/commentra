height, width = map(int, input().split())
input_str = ""

# Print the top border
print("#" * (width + 2))

# Read and print each line with side borders
for _ in range(height):
    input_str = input()
    print(f"#{input_str}#")

# Print the bottom border
print("#" * (width + 2))

# End of code
# <END-OF-CODE>

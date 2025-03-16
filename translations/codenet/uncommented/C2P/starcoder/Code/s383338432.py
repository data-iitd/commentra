
# <START-OF-CODE>

height, width = map(int, input().split())

for i in range(width + 2):
    print("#", end="")
print()

for i in range(height):
    input_str = input()
    print("#", input_str, "#")

for i in range(width + 2):
    print("#", end="")
print()

# 
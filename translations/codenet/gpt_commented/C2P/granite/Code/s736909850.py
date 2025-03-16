
# Read the number of sheep and wolves from user input
sheep, wolf = map(int, input().split())

# Check if the number of wolves is greater than or equal to the number of sheep
if wolf >= sheep:
    # If there are more wolves than sheep, it's unsafe
    print("unsafe")
else:
    # If there are fewer wolves than sheep, it's safe
    print("safe")

# Return 0 to indicate successful execution of the program
print(0)


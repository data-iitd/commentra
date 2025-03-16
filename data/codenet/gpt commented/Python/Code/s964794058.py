# Read the number of members (time) from input
memTime = int(input())

# Read the late times of members and convert them to a list of integers
memLate = input().split()
memLate = [int(i) for i in memLate]

# Initialize an empty list to keep track of unique color categories
colorList = []

# Initialize counters for high late members and unique color categories
memColor = 0
highLate = 0

# Iterate through each member's late time
for color in range(memTime):
    member = memLate[color]
    
    # Check if the member is categorized as high late (late time >= 3200)
    if member // 400 >= 8:
        highLate += 1
    # Check if the color category (member // 400) is not already in the colorList
    elif ((member // 400) in colorList) == False:
        colorList.append(member // 400)  # Add the unique color category to the list

# Calculate the maximum number of color categories (including high late members)
maxColor = len(colorList) + highLate

# Calculate the minimum number of color categories (excluding high late members)
minColor = len(colorList)

# Ensure minColor is at least 1 to avoid zero categories
if minColor == 0:
    minColor = 1

# Print the minimum and maximum number of color categories
print(str(minColor) + " " + str(maxColor))

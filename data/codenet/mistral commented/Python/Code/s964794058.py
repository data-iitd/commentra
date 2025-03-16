# Get the total number of members and initialize an empty list to store colors of members in groups of 400
memTime = int(input())
memLate = input().split()
memLate = [int(i) for i in memLate]
color_list = []  # Initialize an empty list to store colors of members in groups of 400

# Initialize variables for counting high late members and current color group index
mem_color = 0
high_late = 0

# Iterate through each member and process their color group
for color in range(memTime):
    member = memLate[color]
    
    # Check if the current member belongs to a high late group (has more than 7 members in a group of 400)
    if member // 400 >= 8:
        high_late += 1
        
    # Check if the color group of the current member is already in the list, if not add it
    elif (member // 400) not in color_list:
        color_list.append(member // 400)

# Calculate the minimum and maximum number of color groups
min_color = len(color_list)
max_color = len(color_list) + high_late

# Print the minimum and maximum number of color groups
print(str(min_color) + " " + str(max_color))

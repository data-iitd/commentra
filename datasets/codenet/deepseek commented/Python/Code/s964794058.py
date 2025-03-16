
memTime = int(input())  # Read the number of members
memLate = input().split()  # Read the late times as a string and split into a list
memLate = [int(i) for i in memLate]  # Convert each string in the list to an integer
colorList = []  # Initialize an empty list to store color categories
memColor = 0  # Initialize a variable to keep track of the current color
highLate = 0  # Initialize a variable to count members with very high lateness

# Loop through each member's late time
for color in range(memTime):
    member = memLate[color]  # Get the late time of the current member
    if member // 400 >= 8:  # Check if the late time is very high
        highLate += 1  # Increment the highLate counter
    elif ((member // 400) in colorList) == False:  # Check if the color category is not already in colorList
        colorList.append(member // 400)  # Append the color category to colorList

maxColor = len(colorList) + highLate  # Calculate the maximum number of color categories
minColor = len(colorList)  # The minimum number of color categories is the length of colorList
if minColor == 0:  # If minColor is 0, set it to 1
    minColor = 1

print(str(minColor) + " " + str(maxColor))  # Print the results


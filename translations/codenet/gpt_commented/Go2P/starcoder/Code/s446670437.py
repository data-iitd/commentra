# -*- coding: utf-8 -*-

# Dice class represents a dice with its six faces numbered.
class Dice:
    def __init__(self):
        self.nums = [] # Array to hold the numbers on the faces of the dice

    # rotate method rotates the dice in a specified direction a certain number of times.
    def rotate(self, direction, times):
        times %= 4 # Normalize the number of rotations to be within 0-3
        if direction == "W": # Rotate West
            for i in range(times):
                self.nums[0], self.nums[2], self.nums[5], self.nums[3] = self.nums[2], self.nums[5], self.nums[3], self.nums[0]
        elif direction == "E": # Rotate East
            for i in range(times):
                self.nums[0], self.nums[2], self.nums[5], self.nums[3] = self.nums[3], self.nums[0], self.nums[2], self.nums[5]
        elif direction == "N": # Rotate North
            for i in range(times):
                self.nums[0], self.nums[4], self.nums[5], self.nums[1] = self.nums[1], self.nums[0], self.nums[4], self.nums[5]
        elif direction == "S": # Rotate South
            for i in range(times):
                self.nums[5], self.nums[1], self.nums[0], self.nums[4] = self.nums[1], self.nums[0], self.nums[4], self.nums[5]

    # roll method rolls the dice in a specified direction a certain number of times.
    def roll(self, direction, times):
        times %= 4 # Normalize the number of rolls to be within 0-3
        if direction == "R": # Roll Right
            for i in range(times):
                self.nums[3], self.nums[1], self.nums[2], self.nums[4] = self.nums[1], self.nums[2], self.nums[4], self.nums[3]
        elif direction == "L": # Roll Left
            for i in range(times):
                self.nums[3], self.nums[1], self.nums[2], self.nums[4] = self.nums[4], self.nums[3], self.nums[1], self.nums[2]

    # printStatus method prints the current status of the dice in a formatted manner.
    def printStatus(self):
        status =
`	　　　 _ _ _ _
     _ _ _|_%3d_|_ _ _ _ _ _
    |_%3d_|_%3d_|_%3d_|_%3d_|
 　       |_%3d_|
`
        print(status % (self.nums[0], self.nums[3], self.nums[1], self.nums[2], self.nums[4], self.nums[5]))

    # getIndex function returns the index of a target number in the nums slice.
    def getIndex(self, target):
        for i, v in enumerate(self.nums):
            if target == v:
                return i # Found the target, return its index
        return -1 # Target not found, return -1

    # isEqual method checks if two dice are in the same state (same numbers on each face).
    def isEqual(self, other):
        for i, v in enumerate(self.nums):
            if v!= other.nums[i]:
                return False # If any face differs, return false
        return True # All faces match, return true

# main function to execute the dice comparison logic.
def main():
    # Initialize two dice
    dice1 = Dice() # Create a dice
    dice2 = Dice() # Create a dice

    # Input numbers for the first dice
    for i in range(6):
        n = int(input()) # Read input for each face
        dice1.nums.append(n) # Assign input to the dice

    # Input numbers for the second dice
    for i in range(6):
        n = int(input()) # Read input for each face
        dice2.nums.append(n) # Assign input to the dice

    # Define the order of directions and rolls for testing
    directionOrder = ["N", "S", "W", "E"]
    rollOrder = ["R", "L"]
    flag = False # Flag to indicate if a match is found

    # Check all combinations of rotations and rolls
    for i in range(3): # Rotate 0 to 2 times
        for j in range(3): # Roll 0 to 2 times
            for direction in directionOrder: # Iterate through directions
                for roll in rollOrder: # Iterate through roll directions
                    tmp = Dice() # Create a temporary dice
                    tmp.nums = dice2.nums[:] # Copy the numbers from dice2
                    tmp.rotate(direction, i) # Rotate the temporary dice
                    tmp.roll(roll, j) # Roll the temporary dice
                    if tmp.isEqual(dice1): # Check if it matches dice1
                        flag = True # Match found
                        break # Break out of all loops
                if flag:
                    break
            if flag:
                break
        if flag:
            break

    # Output the result based on the flag
    if flag:
        print("Yes") # If a match was found
    else:
        print("No") # If no match was found

# 
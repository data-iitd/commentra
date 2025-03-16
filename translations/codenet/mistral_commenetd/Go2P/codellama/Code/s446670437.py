
# Go:
# package main

# import "fmt"

# Define a Dice struct with a Numbers slice to store the numbers on the dice.
class Dice:
    def __init__(self):
        self.Nums = []

# Function to rotate the dice in a given direction by a given number of times.
    def rotate(self, direction, times):
        times %= 4 # Ensure times is less than or equal to 3 to avoid index out of bounds error.
        if direction == "W": # West direction rotation logic
            for i in range(times):
                self.Nums[0], self.Nums[2], self.Nums[5], self.Nums[3] = self.Nums[2], self.Nums[5], self.Nums[3], self.Nums[0]
        elif direction == "E": # East direction rotation logic
            for i in range(times):
                self.Nums[0], self.Nums[2], self.Nums[5], self.Nums[3] = self.Nums[3], self.Nums[0], self.Nums[2], self.Nums[5]
        elif direction == "N": # North direction rotation logic
            for i in range(times):
                self.Nums[0], self.Nums[4], self.Nums[5], self.Nums[1] = self.Nums[1], self.Nums[0], self.Nums[4], self.Nums[5]
        elif direction == "S": # South direction rotation logic
            for i in range(times):
                self.Nums[5], self.Nums[1], self.Nums[0], self.Nums[4] = self.Nums[1], self.Nums[0], self.Nums[4], self.Nums[5]

# Function to roll the dice in a given direction by a given number of times.
    def roll(self, direction, times):
        times %= 4 # Ensure times is less than or equal to 3 to avoid index out of bounds error.
        if direction == "R": # Right direction roll logic
            for i in range(times):
                self.Nums[3], self.Nums[1], self.Nums[2], self.Nums[4] = self.Nums[1], self.Nums[2], self.Nums[4], self.Nums[3]
        elif direction == "L": # Left direction roll logic
            for i in range(times):
                self.Nums[3], self.Nums[1], self.Nums[2], self.Nums[4] = self.Nums[4], self.Nums[3], self.Nums[1], self.Nums[2]

# Function to print the current status of the dice.
    def printStatus(self):
        status = \
            `	　　　 _ _ _ _
	     _ _ _|_%3d_|_ _ _ _ _ _
	    |_%3d_|_%3d_|_%3d_|_%3d_|
	 　       |_%3d_|
	`
        print(status % (self.Nums[0], self.Nums[3], self.Nums[1], self.Nums[2], self.Nums[4], self.Nums[5]))
        print()

# Function to get the index of a target number in a given slice.
def getIndex(nums, target):
    for i, v in enumerate(nums):
        if target == v:
            return i
    return -1

# Function to check if two dice have the same numbers.
    def isEqual(self, other):
        for i, v in enumerate(self.Nums):
            if v != other.Nums[i]:
                return False
        return True

# Main function to read user input and check if two dice are the same after certain rotations and rolls.
def main():
    dice1 = Dice()
    dice2 = Dice()
    for i in range(6):
        n = int(input())
        dice1.Nums.append(n)
    for i in range(6):
        n = int(input())
        dice2.Nums.append(n)

    directionOrder = ["N", "S", "W", "E"] # Order of directions to rotate
    rollOrder = ["R", "L"]             # Order of rolls
    flag = False

    # Check all possible combinations of rotations and rolls to find if the dice are the same.
    CHECK:
        for i in range(0, 3):
            for j in range(0, 3):
                for direction in directionOrder:
                    for roll in rollOrder:
                        tmp = Dice()
                        tmp.Nums = dice2.Nums[:]
                        tmp.rotate(direction, i)
                        tmp.roll(roll, j)
                        if tmp.isEqual(dice1):
                            flag = True
                            break CHECK
    if flag:
        print("Yes")
    else:
        print("No")

# 
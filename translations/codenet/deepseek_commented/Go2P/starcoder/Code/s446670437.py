
# -*- coding: utf-8 -*-

# Dice represents a die with six faces
class Dice:
    def __init__(self):
        self.Nums = []

    def rotate(self, direction, times):
        times %= 4 # Normalize the number of rotations to 4 or less
        if direction == "W":
            for i in range(times):
                self.Nums[0], self.Nums[2], self.Nums[5], self.Nums[3] = self.Nums[2], self.Nums[5], self.Nums[3], self.Nums[0]
        elif direction == "E":
            for i in range(times):
                self.Nums[0], self.Nums[2], self.Nums[5], self.Nums[3] = self.Nums[3], self.Nums[0], self.Nums[2], self.Nums[5]
        elif direction == "N":
            for i in range(times):
                self.Nums[0], self.Nums[4], self.Nums[5], self.Nums[1] = self.Nums[1], self.Nums[0], self.Nums[4], self.Nums[5]
        elif direction == "S":
            for i in range(times):
                self.Nums[5], self.Nums[1], self.Nums[0], self.Nums[4] = self.Nums[1], self.Nums[0], self.Nums[4], self.Nums[5]

    def roll(self, direction, times):
        times %= 4 # Normalize the number of rolls to 4 or less
        if direction == "R":
            for i in range(times):
                self.Nums[3], self.Nums[1], self.Nums[2], self.Nums[4] = self.Nums[1], self.Nums[2], self.Nums[4], self.Nums[3]
        elif direction == "L":
            for i in range(times):
                self.Nums[3], self.Nums[1], self.Nums[2], self.Nums[4] = self.Nums[4], self.Nums[3], self.Nums[1], self.Nums[2]

    def printStatus(self):
        status =
"""	　　　 _ _ _ _
     _ _ _|_%3d_|_ _ _ _ _ _
    |_%3d_|_%3d_|_%3d_|_%3d_|
 　       |_%3d_|
"""
        print(status % (self.Nums[0], self.Nums[3], self.Nums[1], self.Nums[2], self.Nums[4], self.Nums[5]))
        print()

    def getIndex(self, target):
        for i, v in enumerate(self.Nums):
            if target == v:
                return i
        return -1

    def isEqual(self, other):
        for i, v in enumerate(self.Nums):
            if v!= other.Nums[i]:
                return False
        return True

def main():
    dice1 = Dice()
    dice2 = Dice()
    for i in range(6):
        n = int(input())
        dice1.Nums.append(n)
    for i in range(6):
        n = int(input())
        dice2.Nums.append(n)

    directionOrder = ["N", "S", "W", "E"]
    rollOrder = ["R", "L"]
    flag = False

    for i in range(3):
        for j in range(3):
            for direction in directionOrder:
                for roll in rollOrder:
                    tmp = Dice()
                    tmp.Nums = dice2.Nums[:]
                    tmp.rotate(direction, i)
                    tmp.roll(roll, j)
                    if tmp.isEqual(dice1):
                        flag = True
                        break
                if flag:
                    break
            if flag:
                break
        if flag:
            break

    if flag:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()

# 
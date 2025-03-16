
import sys

class Dice:
    def __init__(self):
        self.nums = [0] * 6

    def rotate(self, direction, times):
        times %= 4
        if direction == "W":
            for i in range(times):
                self.nums[0], self.nums[2], self.nums[5], self.nums[3] = self.nums[2], self.nums[5], self.nums[3], self.nums[0]
        elif direction == "E":
            for i in range(times):
                self.nums[0], self.nums[2], self.nums[5], self.nums[3] = self.nums[3], self.nums[0], self.nums[2], self.nums[5]
        elif direction == "N":
            for i in range(times):
                self.nums[0], self.nums[4], self.nums[5], self.nums[1] = self.nums[1], self.nums[0], self.nums[4], self.nums[5]
        elif direction == "S":
            for i in range(times):
                self.nums[5], self.nums[1], self.nums[0], self.nums[4] = self.nums[1], self.nums[0], self.nums[4], self.nums[5]

    def roll(self, direction, times):
        times %= 4
        if direction == "R":
            for i in range(times):
                self.nums[3], self.nums[1], self.nums[2], self.nums[4] = self.nums[1], self.nums[2], self.nums[4], self.nums[3]
        elif direction == "L":
            for i in range(times):
                self.nums[3], self.nums[1], self.nums[2], self.nums[4] = self.nums[4], self.nums[3], self.nums[1], self.nums[2]

    def printStatus(self):
        status = "     _ _ _|_%3d_|_ _ _ _ _ _\n    |_%3d_|_%3d_|_%3d_|_%3d_|\n 　       |_%3d_|\n"
        print(status % (self.nums[0], self.nums[3], self.nums[1], self.nums[2], self.nums[4], self.nums[5]))

    def isEqual(self, other):
        for i in range(6):
            if self.nums[i] != other.nums[i]:
                return False
        return True

def getIndex(nums, target):
    for i, v in enumerate(nums):
        if target == v:
            return i
    return -1

def main():
    dice1 = Dice()
    dice2 = Dice()
    for i in range(6):
        dice1.nums[i] = int(sys.stdin.readline().rstrip())
    for i in range(6):
        dice2.nums[i] = int(sys.stdin.readline().rstrip())

    directionOrder = ["N", "S", "W", "E"]
    rollOrder = ["R", "L"]
    flag = False

    CHECK:
        for i in range(3):
            for j in range(3):
                for direction in directionOrder:
                    for roll in rollOrder:
                        tmp = Dice()
                        tmp.nums = list(dice2.nums)
                        tmp.rotate(direction, i)
                        tmp.roll(roll, j)
                        if tmp.isEqual(dice1):
                            flag = True
                            break CHECK
    if flag:
        print("Yes")
    else:
        print("No")


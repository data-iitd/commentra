

class Dice:
    def __init__(self, nums):
        self.Nums = nums

    def rotate(self, direction, times):
        times %= 4
        if direction == "W":
            self.Nums[0], self.Nums[2], self.Nums[5], self.Nums[3] = self.Nums[2], self.Nums[5], self.Nums[3], self.Nums[0]
        elif direction == "E":
            self.Nums[0], self.Nums[2], self.Nums[5], self.Nums[3] = self.Nums[3], self.Nums[0], self.Nums[2], self.Nums[5]
        elif direction == "N":
            self.Nums[0], self.Nums[4], self.Nums[5], self.Nums[1] = self.Nums[1], self.Nums[0], self.Nums[4], self.Nums[5]
        elif direction == "S":
            self.Nums[5], self.Nums[1], self.Nums[0], self.Nums[4] = self.Nums[1], self.Nums[0], self.Nums[4], self.Nums[5]

    def roll(self, direction, times):
        times %= 4
        if direction == "R":
            self.Nums[3], self.Nums[1], self.Nums[2], self.Nums[4] = self.Nums[1], self.Nums[2], self.Nums[4], self.Nums[3]
        elif direction == "L":
            self.Nums[3], self.Nums[1], self.Nums[2], self.Nums[4] = self.Nums[4], self.Nums[3], self.Nums[1], self.Nums[2]

    def printStatus(self):
        status =
"""	　　　 _ _ _ _
     _ _ _|_%3d_|_ _ _ _ _ _
    |_%3d_|_%3d_|_%3d_|_%3d_|
 　       |_%3d_|
"""
        print(status % (self.Nums[0], self.Nums[3], self.Nums[1], self.Nums[2], self.Nums[4], self.Nums[5]))

    def getIndex(self, nums, target):
        for i, v in enumerate(nums):
            if target == v:
                return i
        return -1

    def isEqual(self, other):
        for i, v in enumerate(self.Nums):
            if v!= other.Nums[i]:
                return False
        return True

dice1 = Dice([0, 0, 0, 0, 0, 0])
dice2 = Dice([0, 0, 0, 0, 0, 0])
for i in range(6):
    dice1.Nums[i] = int(input())
for i in range(6):
    dice2.Nums[i] = int(input())

directionOrder = ["N", "S", "W", "E"]
rollOrder = ["R", "L"]
flag = False

for i in range(3):
    for j in range(3):
        for direction in directionOrder:
            for roll in rollOrder:
                tmp = Dice(dice2.Nums)
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
    print("Yes")
else:
    print("No")


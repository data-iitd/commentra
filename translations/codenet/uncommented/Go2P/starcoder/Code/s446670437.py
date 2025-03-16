import sys

class Dice:
    def __init__(self):
        self.nums = [0, 0, 0, 0, 0, 0]

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
        status =
`	　　　 _ _ _ _
     _ _ _|_%3d_|_ _ _ _ _ _
    |_%3d_|_%3d_|_%3d_|_%3d_|
 　       |_%3d_|
`
        print(status % (self.nums[0], self.nums[3], self.nums[1], self.nums[2], self.nums[4], self.nums[5]))

    def getIndex(self, target):
        for i, v in enumerate(self.nums):
            if target == v:
                return i
        return -1

    def isEqual(self, other):
        for i, v in enumerate(self.nums):
            if v!= other.nums[i]:
                return False
        return True

def main():
    dice1 = Dice()
    dice2 = Dice()
    for i in range(6):
        dice1.nums[i] = int(sys.stdin.readline())
    for i in range(6):
        dice2.nums[i] = int(sys.stdin.readline())

    directionOrder = ["N", "S", "W", "E"]
    rollOrder = ["R", "L"]
    flag = False

    for i in range(3):
        for j in range(3):
            for direction in directionOrder:
                for roll in rollOrder:
                    tmp = Dice()
                    tmp.nums = dice2.nums[:]
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


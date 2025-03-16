
# 展開図の展開の仕方を固定して、回転動作によってどのように展開図の数字が移るかを記録する。
# 展開図は次の通り。手前の目2番を中心に据える展開の仕方。
#         ___
#     ____|_1_|_______
#     |_4_|_2_|_3_|_5_|
#         |_6_|

# サイコロの状態は上面と前面を指定することで一意に決定される。それぞれを指定された目に揃えて、
# 展開図の3番を記録。
# 入力された二つのサイコロについて上面前面を揃えた上で右側面の値を比較することで判定。
# で、できるかと思ったが、サイコロの各面の数字がすべて異なるという制約は今回の問題にはないので、
# この判定方法は不完全。

# よって、力ずくで全通り調べる。

# Dice represents a die with six faces
class Dice:
    def __init__(self):
        self.nums = [0, 0, 0, 0, 0, 0]

    # rotate rotates the die in a specified direction a given number of times
    def rotate(self, direction, times):
        times %= 4 # Normalize the number of rotations to 4 or less
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

    # roll rolls the die in a specified direction a given number of times
    def roll(self, direction, times):
        times %= 4 # Normalize the number of rolls to 4 or less
        if direction == "R":
            for i in range(times):
                self.nums[3], self.nums[1], self.nums[2], self.nums[4] = self.nums[1], self.nums[2], self.nums[4], self.nums[3]
        elif direction == "L":
            for i in range(times):
                self.nums[3], self.nums[1], self.nums[2], self.nums[4] = self.nums[4], self.nums[3], self.nums[1], self.nums[2]

    # printStatus prints the current status of the die in a formatted string
    def printStatus(self):
        status = \
"""
    　　　 _ _ _ _
     _ _ _|_%3d_|_ _ _ _ _ _
    |_%3d_|_%3d_|_%3d_|_%3d_|
 　       |_%3d_|
"""
        print(status % (self.nums[0], self.nums[3], self.nums[1], self.nums[2], self.nums[4], self.nums[5]))

    # getIndex returns the index of the target number in the slice
    def getIndex(self, target):
        for i, v in enumerate(self.nums):
            if target == v:
                return i
        return -1

    # isEqual checks if two Dice objects have the same faces
    def isEqual(self, other):
        for i, v in enumerate(self.nums):
            if v != other.nums[i]:
                return False
        return True

# main
dice1 = Dice()
dice2 = Dice()
for i in range(6):
    n = int(input())
    dice1.nums[i] = n
for i in range(6):
    n = int(input())
    dice2.nums[i] = n

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


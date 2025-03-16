class Dice:
    def __init__(self, nums):
        self.nums = nums

    def rotate(self, direction, times):
        times %= 4
        if direction == "W":
            for _ in range(times):
                self.nums[0], self.nums[2], self.nums[5], self.nums[3] = self.nums[2], self.nums[5], self.nums[3], self.nums[0]
        elif direction == "E":
            for _ in range(times):
                self.nums[0], self.nums[2], self.nums[5], self.nums[3] = self.nums[3], self.nums[0], self.nums[2], self.nums[5]
        elif direction == "N":
            for _ in range(times):
                self.nums[0], self.nums[4], self.nums[5], self.nums[1] = self.nums[1], self.nums[0], self.nums[4], self.nums[5]
        elif direction == "S":
            for _ in range(times):
                self.nums[5], self.nums[1], self.nums[0], self.nums[4] = self.nums[1], self.nums[0], self.nums[4], self.nums[5]

    def roll(self, direction, times):
        times %= 4
        if direction == "R":
            for _ in range(times):
                self.nums[3], self.nums[1], self.nums[2], self.nums[4] = self.nums[1], self.nums[2], self.nums[4], self.nums[3]
        elif direction == "L":
            for _ in range(times):
                self.nums[3], self.nums[1], self.nums[2], self.nums[4] = self.nums[4], self.nums[3], self.nums[1], self.nums[2]

    def print_status(self):
        status = (
            "        _ _ _ _ \n"
            "     _ _ _|_%3d_|_ _ _ _ _ _ \n"
            "    |_%3d_|_%3d_|_%3d_|_%3d_| \n"
            "        |_%3d| \n"
        )
        print(status % (self.nums[0], self.nums[3], self.nums[1], self.nums[2], self.nums[4], self.nums[5]))

    def get_index(self, target):
        for i, v in enumerate(self.nums):
            if target == v:
                return i
        return -1

    def is_equal(self, other):
        return all(x == y for x, y in zip(self.nums, other.nums))

def main():
    dice1 = Dice([0] * 6)
    dice2 = Dice([0] * 6)
    for i in range(6):
        dice1.nums[i] = int(input())
    for i in range(6):
        dice2.nums[i] = int(input())

    direction_order = ["N", "S", "W", "E"]
    roll_order = ["R", "L"]
    flag = False

    for i in range(3 + 1):
        for j in range(3 + 1):
            for direction in direction_order:
                for roll in roll_order:
                    tmp = Dice(dice2.nums[:])
                    tmp.rotate(direction, i)
                    tmp.roll(roll, j)
                    if tmp.is_equal(dice1):
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

main()

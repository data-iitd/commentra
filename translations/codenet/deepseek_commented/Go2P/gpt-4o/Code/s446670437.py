class Dice:
    def __init__(self, nums):
        self.nums = nums  # List of integers representing the faces of the die

    def rotate(self, direction, times):
        times %= 4  # Normalize the number of rotations to 4 or less
        for _ in range(times):
            if direction == "W":
                self.nums[0], self.nums[2], self.nums[5], self.nums[3] = self.nums[2], self.nums[5], self.nums[3], self.nums[0]
            elif direction == "E":
                self.nums[0], self.nums[2], self.nums[5], self.nums[3] = self.nums[3], self.nums[0], self.nums[2], self.nums[5]
            elif direction == "N":
                self.nums[0], self.nums[4], self.nums[5], self.nums[1] = self.nums[1], self.nums[0], self.nums[4], self.nums[5]
            elif direction == "S":
                self.nums[5], self.nums[1], self.nums[0], self.nums[4] = self.nums[1], self.nums[0], self.nums[4], self.nums[5]

    def roll(self, direction, times):
        times %= 4  # Normalize the number of rolls to 4 or less
        for _ in range(times):
            if direction == "R":
                self.nums[3], self.nums[1], self.nums[2], self.nums[4] = self.nums[1], self.nums[2], self.nums[4], self.nums[3]
            elif direction == "L":
                self.nums[3], self.nums[1], self.nums[2], self.nums[4] = self.nums[4], self.nums[3], self.nums[1], self.nums[2]

    def print_status(self):
        status = (
            "         _ _ _ _\n"
            "     _ _ _|_%3d_|_ _ _ _ _ _\n"
            "    |_%3d_|_%3d_|_%3d_|_%3d_|\n"
            " 　       |_%3d_|\n"
        )
        print(status % (self.nums[0], self.nums[3], self.nums[1], self.nums[2], self.nums[4], self.nums[5]))
        print()

    def is_equal(self, other):
        return self.nums == other.nums


def main():
    dice1_nums = list(map(int, input().split()))
    dice2_nums = list(map(int, input().split()))

    dice1 = Dice(dice1_nums)
    dice2 = Dice(dice2_nums)

    direction_order = ["N", "S", "W", "E"]
    roll_order = ["R", "L"]
    flag = False

    for i in range(3):  # 0 to 2
        for j in range(3):  # 0 to 2
            for direction in direction_order:
                for roll in roll_order:
                    tmp = Dice(dice2.nums[:])  # Create a copy of dice2
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
            break

    if flag:
        print("Yes")
    else:
        print("No")


if __name__ == "__main__":
    main()

# <END-OF-CODE>

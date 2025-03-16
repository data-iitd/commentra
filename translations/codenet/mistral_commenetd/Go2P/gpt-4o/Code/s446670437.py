class Dice:
    def __init__(self):
        self.nums = [0] * 6

    def rotate(self, direction, times):
        times %= 4  # Ensure times is less than or equal to 3 to avoid index out of bounds error.
        for _ in range(times):
            if direction == "W":  # West direction rotation logic
                self.nums[0], self.nums[2], self.nums[5], self.nums[3] = self.nums[2], self.nums[5], self.nums[3], self.nums[0]
            elif direction == "E":  # East direction rotation logic
                self.nums[0], self.nums[2], self.nums[5], self.nums[3] = self.nums[3], self.nums[0], self.nums[2], self.nums[5]
            elif direction == "N":  # North direction rotation logic
                self.nums[0], self.nums[4], self.nums[5], self.nums[1] = self.nums[1], self.nums[0], self.nums[4], self.nums[5]
            elif direction == "S":  # South direction rotation logic
                self.nums[5], self.nums[1], self.nums[0], self.nums[4] = self.nums[1], self.nums[0], self.nums[4], self.nums[5]

    def roll(self, direction, times):
        times %= 4  # Ensure times is less than or equal to 3 to avoid index out of bounds error.
        for _ in range(times):
            if direction == "R":  # Right direction roll logic
                self.nums[3], self.nums[1], self.nums[2], self.nums[4] = self.nums[1], self.nums[2], self.nums[4], self.nums[3]
            elif direction == "L":  # Left direction roll logic
                self.nums[3], self.nums[1], self.nums[2], self.nums[4] = self.nums[4], self.nums[3], self.nums[1], self.nums[2]

    def print_status(self):
        status = (
            "            _ _ _ _\n"
            "         _ _ _|_%3d_|_ _ _ _ _ _\n"
            "        |_%3d_|_%3d_|_%3d_|_%3d_|\n"
            "               |_%3d_|\n"
        )
        print(status % (self.nums[0], self.nums[3], self.nums[1], self.nums[2], self.nums[4], self.nums[5]))
        print()

    @staticmethod
    def get_index(nums, target):
        try:
            return nums.index(target)
        except ValueError:
            return -1

    def is_equal(self, other):
        return self.nums == other.nums


def main():
    dice1 = Dice()
    dice2 = Dice()

    for i in range(6):
        n = int(input())
        dice1.nums[i] = n

    for i in range(6):
        n = int(input())
        dice2.nums[i] = n

    direction_order = ["N", "S", "W", "E"]  # Order of directions to rotate
    roll_order = ["R", "L"]  # Order of rolls
    flag = False

    # Check all possible combinations of rotations and rolls to find if the dice are the same.
    for i in range(3):
        for j in range(3):
            for direction in direction_order:
                for roll in roll_order:
                    tmp = Dice()
                    tmp.nums = dice2.nums[:]  # Copy the numbers
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

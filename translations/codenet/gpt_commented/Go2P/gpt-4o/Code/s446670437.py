class Dice:
    def __init__(self, nums):
        self.nums = nums  # Array to hold the numbers on the faces of the dice

    def rotate(self, direction, times):
        times %= 4  # Normalize the number of rotations to be within 0-3
        for _ in range(times):
            if direction == "W":  # Rotate West
                self.nums[0], self.nums[2], self.nums[5], self.nums[3] = self.nums[2], self.nums[5], self.nums[3], self.nums[0]
            elif direction == "E":  # Rotate East
                self.nums[0], self.nums[2], self.nums[5], self.nums[3] = self.nums[3], self.nums[0], self.nums[2], self.nums[5]
            elif direction == "N":  # Rotate North
                self.nums[0], self.nums[4], self.nums[5], self.nums[1] = self.nums[1], self.nums[0], self.nums[4], self.nums[5]
            elif direction == "S":  # Rotate South
                self.nums[5], self.nums[1], self.nums[0], self.nums[4] = self.nums[1], self.nums[0], self.nums[4], self.nums[5]

    def roll(self, direction, times):
        times %= 4  # Normalize the number of rolls to be within 0-3
        for _ in range(times):
            if direction == "R":  # Roll Right
                self.nums[3], self.nums[1], self.nums[2], self.nums[4] = self.nums[1], self.nums[2], self.nums[4], self.nums[3]
            elif direction == "L":  # Roll Left
                self.nums[3], self.nums[1], self.nums[2], self.nums[4] = self.nums[4], self.nums[3], self.nums[1], self.nums[2]

    def print_status(self):
        status = f"""
                _ _ _ _
         _ _ _|_{self.nums[0]:3d}|_ _ _ _ _ _
        |_{self.nums[3]:3d}|_{self.nums[1]:3d}|_{self.nums[2]:3d}|_{self.nums[4]:3d}|
                |_{self.nums[5]:3d}|
        """
        print(status)

    def is_equal(self, other):
        return self.nums == other.nums  # Check if two dice are in the same state


def main():
    # Initialize two dice
    dice1 = Dice([0] * 6)  # Create a list for the first dice
    dice2 = Dice([0] * 6)  # Create a list for the second dice

    # Input numbers for the first dice
    for i in range(6):
        n = int(input())  # Read input for each face
        dice1.nums[i] = n  # Assign input to the dice

    # Input numbers for the second dice
    for i in range(6):
        n = int(input())  # Read input for each face
        dice2.nums[i] = n  # Assign input to the dice

    # Define the order of directions and rolls for testing
    direction_order = ["N", "S", "W", "E"]
    roll_order = ["R", "L"]
    flag = False  # Flag to indicate if a match is found

    # Check all combinations of rotations and rolls
    for i in range(3):  # Rotate 0 to 2 times
        for j in range(3):  # Roll 0 to 2 times
            for direction in direction_order:  # Iterate through directions
                for roll in roll_order:  # Iterate through roll directions
                    tmp = Dice(dice2.nums[:])  # Create a temporary dice
                    tmp.rotate(direction, i)  # Rotate the temporary dice
                    tmp.roll(roll, j)  # Roll the temporary dice
                    if tmp.is_equal(dice1):  # Check if it matches dice1
                        flag = True  # Match found
                        break  # Break out of the inner loop
                if flag:
                    break  # Break out of the direction loop
            if flag:
                break  # Break out of the roll loop
        if flag:
            break  # Break out of the rotation loop

    # Output the result based on the flag
    if flag:
        print("Yes")  # If a match was found
    else:
        print("No")  # If no match was found


if __name__ == "__main__":
    main()

# <END-OF-CODE>

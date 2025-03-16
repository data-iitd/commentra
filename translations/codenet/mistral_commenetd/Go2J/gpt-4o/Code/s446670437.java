import java.util.Scanner;

class Dice {
    int[] nums;

    public Dice() {
        nums = new int[6];
    }

    // Function to rotate the dice in a given direction by a given number of times.
    public void rotate(String direction, int times) {
        times %= 4; // Ensure times is less than or equal to 3 to avoid index out of bounds error.
        switch (direction) {
            case "W": // West direction rotation logic
                for (int i = 0; i < times; i++) {
                    int temp = nums[0];
                    nums[0] = nums[2];
                    nums[2] = nums[5];
                    nums[5] = nums[3];
                    nums[3] = temp;
                }
                break;
            case "E": // East direction rotation logic
                for (int i = 0; i < times; i++) {
                    int temp = nums[0];
                    nums[0] = nums[3];
                    nums[3] = nums[5];
                    nums[5] = nums[2];
                    nums[2] = temp;
                }
                break;
            case "N": // North direction rotation logic
                for (int i = 0; i < times; i++) {
                    int temp = nums[0];
                    nums[0] = nums[1];
                    nums[1] = nums[5];
                    nums[5] = nums[4];
                    nums[4] = temp;
                }
                break;
            case "S": // South direction rotation logic
                for (int i = 0; i < times; i++) {
                    int temp = nums[5];
                    nums[5] = nums[1];
                    nums[1] = nums[0];
                    nums[0] = nums[4];
                    nums[4] = temp;
                }
                break;
        }
    }

    // Function to roll the dice in a given direction by a given number of times.
    public void roll(String direction, int times) {
        times %= 4; // Ensure times is less than or equal to 3 to avoid index out of bounds error.
        switch (direction) {
            case "R": // Right direction roll logic
                for (int i = 0; i < times; i++) {
                    int temp = nums[3];
                    nums[3] = nums[1];
                    nums[1] = nums[2];
                    nums[2] = nums[4];
                    nums[4] = temp;
                }
                break;
            case "L": // Left direction roll logic
                for (int i = 0; i < times; i++) {
                    int temp = nums[3];
                    nums[3] = nums[4];
                    nums[4] = nums[2];
                    nums[2] = nums[1];
                    nums[1] = temp;
                }
                break;
        }
    }

    // Function to print the current status of the dice.
    public void printStatus() {
        String status = String.format(
            "          _ _ _ _\n" +
            "     _ _ _|_%3d_|_ _ _ _ _ _\n" +
            "    |_%3d_|_%3d_|_%3d_|_%3d_|\n" +
            "            |_%3d_|\n",
            nums[0], nums[3], nums[1], nums[2], nums[4], nums[5]
        );
        System.out.print(status);
    }

    // Function to check if two dice have the same numbers.
    public boolean isEqual(Dice other) {
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != other.nums[i]) {
                return false;
            }
        }
        return true;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Dice dice1 = new Dice();
        Dice dice2 = new Dice();

        for (int i = 0; i < 6; i++) {
            dice1.nums[i] = scanner.nextInt();
        }
        for (int i = 0; i < 6; i++) {
            dice2.nums[i] = scanner.nextInt();
        }

        String[] directionOrder = {"N", "S", "W", "E"}; // Order of directions to rotate
        String[] rollOrder = {"R", "L"}; // Order of rolls
        boolean flag = false;

        // Check all possible combinations of rotations and rolls to find if the dice are the same.
        CHECK:
        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j <= 2; j++) {
                for (String direction : directionOrder) {
                    for (String roll : rollOrder) {
                        Dice tmp = new Dice();
                        System.arraycopy(dice2.nums, 0, tmp.nums, 0, 6);
                        tmp.rotate(direction, i);
                        tmp.roll(roll, j);
                        if (tmp.isEqual(dice1)) {
                            flag = true;
                            break CHECK;
                        }
                    }
                }
            }
        }
        System.out.println(flag ? "Yes" : "No");
    }
}

// <END-OF-CODE>

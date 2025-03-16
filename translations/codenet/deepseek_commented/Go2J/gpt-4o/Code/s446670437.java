import java.util.Scanner;

class Dice {
    int[] nums; // Array representing the faces of the die

    public Dice() {
        nums = new int[6];
    }

    // Rotate the die in a specified direction a given number of times
    public void rotate(String direction, int times) {
        times %= 4; // Normalize the number of rotations to 4 or less
        for (int i = 0; i < times; i++) {
            switch (direction) {
                case "W":
                    int tempW = nums[0];
                    nums[0] = nums[2];
                    nums[2] = nums[5];
                    nums[5] = nums[3];
                    nums[3] = tempW;
                    break;
                case "E":
                    int tempE = nums[0];
                    nums[0] = nums[3];
                    nums[3] = nums[5];
                    nums[5] = nums[2];
                    nums[2] = tempE;
                    break;
                case "N":
                    int tempN = nums[0];
                    nums[0] = nums[1];
                    nums[1] = nums[5];
                    nums[5] = nums[4];
                    nums[4] = tempN;
                    break;
                case "S":
                    int tempS = nums[5];
                    nums[5] = nums[1];
                    nums[1] = nums[0];
                    nums[0] = nums[4];
                    nums[4] = tempS;
                    break;
            }
        }
    }

    // Roll the die in a specified direction a given number of times
    public void roll(String direction, int times) {
        times %= 4; // Normalize the number of rolls to 4 or less
        for (int i = 0; i < times; i++) {
            switch (direction) {
                case "R":
                    int tempR = nums[3];
                    nums[3] = nums[1];
                    nums[1] = nums[2];
                    nums[2] = nums[4];
                    nums[4] = tempR;
                    break;
                case "L":
                    int tempL = nums[3];
                    nums[3] = nums[4];
                    nums[4] = nums[2];
                    nums[2] = nums[1];
                    nums[1] = tempL;
                    break;
            }
        }
    }

    // Print the current status of the die in a formatted string
    public void printStatus() {
        System.out.printf("         _ _ _ _\n" +
                          "     _ _ _|_%3d_|_ _ _ _ _ _\n" +
                          "    |_%3d_|_%3d_|_%3d_|_%3d_|\n" +
                          " 　       |_%3d_|\n", 
                          nums[0], nums[3], nums[1], nums[2], nums[4], nums[5]);
        System.out.println();
    }

    // Check if two Dice objects have the same faces
    public boolean isEqual(Dice other) {
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != other.nums[i]) {
                return false;
            }
        }
        return true;
    }

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

        String[] directionOrder = {"N", "S", "W", "E"};
        String[] rollOrder = {"R", "L"};
        boolean flag = false;

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
        if (flag) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
        scanner.close();
    }
}

// <END-OF-CODE>

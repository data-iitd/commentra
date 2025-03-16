import java.util.Scanner;

class Dice {
    int[] nums;

    public Dice() {
        nums = new int[6];
    }

    public void rotate(String direction, int times) {
        times %= 4;
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

    public void roll(String direction, int times) {
        times %= 4;
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
                    int tempL = nums[4];
                    nums[4] = nums[3];
                    nums[3] = nums[1];
                    nums[1] = nums[2];
                    nums[2] = tempL;
                    break;
            }
        }
    }

    public void printStatus() {
        String status = String.format(
            "         ___\n" +
            "    ____|_%d_|_______\n" +
            "    |_4_|_%d_|_%d_|_%d_|\n" +
            "        |_6_|\n",
            nums[0], nums[3], nums[1], nums[2], nums[4], nums[5]
        );
        System.out.print(status);
    }

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
        System.out.println(flag ? "Yes" : "No");
    }
}

// <END-OF-CODE>

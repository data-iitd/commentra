import java.util.Scanner;

class Dice {
    int[] nums = new int[6];

    void rotate(String direction, int times) {
        times %= 4;
        switch (direction) {
            case "W":
                for (int i = 0; i < times; i++) {
                    int temp = nums[0];
                    nums[0] = nums[2];
                    nums[2] = nums[5];
                    nums[5] = nums[3];
                    nums[3] = temp;
                }
                break;
            case "E":
                for (int i = 0; i < times; i++) {
                    int temp = nums[0];
                    nums[0] = nums[3];
                    nums[3] = nums[5];
                    nums[5] = nums[2];
                    nums[2] = temp;
                }
                break;
            case "N":
                for (int i = 0; i < times; i++) {
                    int temp = nums[0];
                    nums[0] = nums[1];
                    nums[1] = nums[5];
                    nums[5] = nums[4];
                    nums[4] = temp;
                }
                break;
            case "S":
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

    void roll(String direction, int times) {
        times %= 4;
        switch (direction) {
            case "R":
                for (int i = 0; i < times; i++) {
                    int temp = nums[3];
                    nums[3] = nums[1];
                    nums[1] = nums[2];
                    nums[2] = nums[4];
                    nums[4] = temp;
                }
                break;
            case "L":
                for (int i = 0; i < times; i++) {
                    int temp = nums[4];
                    nums[4] = nums[2];
                    nums[2] = nums[1];
                    nums[1] = nums[3];
                    nums[3] = temp;
                }
                break;
        }
    }

    void printStatus() {
        System.out.printf("        _ _ _ _ \n" +
                          "    _ _ _|_%3d_|_ _ _ _ _ _ \n" +
                          "    |_%3d_|_%3d_|_%3d_|_%3d_| \n" +
                          "        |_%3d_| \n", nums[0], nums[3], nums[1], nums[2], nums[4], nums[5]);
    }

    int getIndex(int[] nums, int target) {
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == target) {
                return i;
            }
        }
        return -1;
    }

    boolean isEqual(Dice other) {
        for (int i = 0; i < 6; i++) {
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
    }
}

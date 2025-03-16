import java.util.Scanner;

class Dice {
    int[] nums = new int[6];

    void rotate(String direction, int times) {
        times %= 4;
        int[] temp = new int[6];
        System.arraycopy(nums, 0, temp, 0, 6);
        switch (direction) {
            case "W":
                for (int i = 0; i < times; i++) {
                    nums[0] = temp[2];
                    nums[2] = temp[5];
                    nums[5] = temp[3];
                    nums[3] = temp[0];
                }
                break;
            case "E":
                for (int i = 0; i < times; i++) {
                    nums[0] = temp[3];
                    nums[3] = temp[5];
                    nums[5] = temp[2];
                    nums[2] = temp[0];
                }
                break;
            case "N":
                for (int i = 0; i < times; i++) {
                    nums[0] = temp[1];
                    nums[1] = temp[5];
                    nums[5] = temp[4];
                    nums[4] = temp[0];
                }
                break;
            case "S":
                for (int i = 0; i < times; i++) {
                    nums[0] = temp[4];
                    nums[4] = temp[5];
                    nums[5] = temp[1];
                    nums[1] = temp[0];
                }
                break;
        }
    }

    void roll(String direction, int times) {
        times %= 4;
        int[] temp = new int[6];
        System.arraycopy(nums, 0, temp, 0, 6);
        switch (direction) {
            case "R":
                for (int i = 0; i < times; i++) {
                    nums[3] = temp[1];
                    nums[1] = temp[2];
                    nums[2] = temp[4];
                    nums[4] = temp[3];
                }
                break;
            case "L":
                for (int i = 0; i < times; i++) {
                    nums[3] = temp[4];
                    nums[4] = temp[2];
                    nums[2] = temp[1];
                    nums[1] = temp[3];
                }
                break;
        }
    }

    void printStatus() {
        System.out.println("        _ _ _ _");
        System.out.println("    _ _ _|_" + nums[0] + "_|_ _ _ _ _ _");
        System.out.println("   |_" + nums[3] + "_|_" + nums[1] + "_|_" + nums[2] + "_|_" + nums[4] + "_|");
        System.out.println("       |_" + nums[5] + "_|");
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

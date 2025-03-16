
import java.util.Scanner;

public class s446670437{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] dice1 = new int[6];
        int[] dice2 = new int[6];
        for (int i = 0; i < 6; i++) {
            dice1[i] = scanner.nextInt();
        }
        for (int i = 0; i < 6; i++) {
            dice2[i] = scanner.nextInt();
        }
        String[] directionOrder = {"N", "S", "W", "E"};
        String[] rollOrder = {"R", "L"};
        boolean flag = false;

        CHECK:
        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j <= 2; j++) {
                for (String direction : directionOrder) {
                    for (String roll : rollOrder) {
                        int[] tmp = dice2.clone();
                        rotate(tmp, direction, i);
                        roll(tmp, roll, j);
                        if (isEqual(tmp, dice1)) {
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

    private static void rotate(int[] dice, String direction, int times) {
        times %= 4;
        switch (direction) {
            case "W":
                for (int i = 0; i < times; i++) {
                    int temp = dice[0];
                    dice[0] = dice[2];
                    dice[2] = dice[5];
                    dice[5] = dice[3];
                    dice[3] = temp;
                }
                break;
            case "E":
                for (int i = 0; i < times; i++) {
                    int temp = dice[0];
                    dice[0] = dice[3];
                    dice[3] = dice[5];
                    dice[5] = dice[2];
                    dice[2] = temp;
                }
                break;
            case "N":
                for (int i = 0; i < times; i++) {
                    int temp = dice[0];
                    dice[0] = dice[1];
                    dice[1] = dice[5];
                    dice[5] = dice[4];
                    dice[4] = temp;
                }
                break;
            case "S":
                for (int i = 0; i < times; i++) {
                    int temp = dice[0];
                    dice[0] = dice[4];
                    dice[4] = dice[5];
                    dice[5] = dice[1];
                    dice[1] = temp;
                }
                break;
        }
    }

    private static void roll(int[] dice, String direction, int times) {
        times %= 4;
        switch (direction) {
            case "R":
                for (int i = 0; i < times; i++) {
                    int temp = dice[1];
                    dice[1] = dice[2];
                    dice[2] = dice[4];
                    dice[4] = dice[3];
                    dice[3] = temp;
                }
                break;
            case "L":
                for (int i = 0; i < times; i++) {
                    int temp = dice[1];
                    dice[1] = dice[3];
                    dice[3] = dice[4];
                    dice[4] = dice[2];
                    dice[2] = temp;
                }
                break;
        }
    }

    private static boolean isEqual(int[] dice1, int[] dice2) {
        for (int i = 0; i < 6; i++) {
            if (dice1[i]!= dice2[i]) {
                return false;
            }
        }
        return true;
    }
}


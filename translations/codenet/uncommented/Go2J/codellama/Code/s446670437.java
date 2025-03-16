
package main

import java.util.Scanner;

public class Main {
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
                        int[] tmp = new int[6];
                        for (int k = 0; k < 6; k++) {
                            tmp[k] = dice2[k];
                        }
                        rotate(tmp, direction, i);
                        roll(tmp, roll, j);
                        if (isEqual(dice1, tmp)) {
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

    public static void rotate(int[] dice, String direction, int times) {
        times %= 4;
        switch (direction) {
            case "W":
                for (int i = 0; i < times; i++) {
                    dice[0] = dice[2];
                    dice[2] = dice[5];
                    dice[5] = dice[3];
                    dice[3] = dice[0];
                }
                break;
            case "E":
                for (int i = 0; i < times; i++) {
                    dice[0] = dice[3];
                    dice[2] = dice[0];
                    dice[5] = dice[2];
                    dice[3] = dice[5];
                }
                break;
            case "N":
                for (int i = 0; i < times; i++) {
                    dice[0] = dice[1];
                    dice[1] = dice[0];
                    dice[4] = dice[5];
                    dice[5] = dice[4];
                }
                break;
            case "S":
                for (int i = 0; i < times; i++) {
                    dice[5] = dice[1];
                    dice[1] = dice[5];
                    dice[0] = dice[4];
                    dice[4] = dice[0];
                }
                break;
        }
    }

    public static void roll(int[] dice, String direction, int times) {
        times %= 4;
        switch (direction) {
            case "R":
                for (int i = 0; i < times; i++) {
                    dice[3] = dice[1];
                    dice[1] = dice[2];
                    dice[2] = dice[4];
                    dice[4] = dice[3];
                }
                break;
            case "L":
                for (int i = 0; i < times; i++) {
                    dice[3] = dice[4];
                    dice[1] = dice[3];
                    dice[2] = dice[1];
                    dice[4] = dice[2];
                }
                break;
        }
    }

    public static boolean isEqual(int[] dice1, int[] dice2) {
        for (int i = 0; i < 6; i++) {
            if (dice1[i] != dice2[i]) {
                return false;
            }
        }
        return true;
    }
}


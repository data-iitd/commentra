package main;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Dice dice1 = new Dice();
        Dice dice2 = new Dice();
        for (int i = 0; i < 6; i++) {
            int n = sc.nextInt();
            dice1.Nums[i] = n;
        }
        for (int i = 0; i < 6; i++) {
            int n = sc.nextInt();
            dice2.Nums[i] = n;
        }

        String[] directionOrder = {"N", "S", "W", "E"}; // Order of directions to rotate
        String[] rollOrder = {"R", "L"}; // Order of rolls
        boolean flag = false;

        // Check all possible combinations of rotations and rolls to find if the dice are the same.
        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j <= 2; j++) {
                for (String direction : directionOrder) {
                    for (String roll : rollOrder) {
                        Dice tmp = new Dice();
                        tmp.Nums = dice2.Nums.clone();
                        tmp.rotate(direction, i);
                        tmp.roll(roll, j);
                        if (tmp.isEqual(dice1)) {
                            flag = true;
                            break;
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

class Dice {
    int[] Nums;

    public Dice() {
        Nums = new int[6];
    }

    public void rotate(String direction, int times) {
        times %= 4; // Ensure times is less than or equal to 3 to avoid index out of bounds error.
        switch (direction) {
            case "W": // West direction rotation logic
                for (int i = 0; i < times; i++) {
                    int tmp = Nums[0];
                    Nums[0] = Nums[2];
                    Nums[2] = Nums[5];
                    Nums[5] = Nums[3];
                    Nums[3] = tmp;
                }
                break;
            case "E": // East direction rotation logic
                for (int i = 0; i < times; i++) {
                    int tmp = Nums[0];
                    Nums[0] = Nums[3];
                    Nums[3] = Nums[5];
                    Nums[5] = Nums[2];
                    Nums[2] = tmp;
                }
                break;
            case "N": // North direction rotation logic
                for (int i = 0; i < times; i++) {
                    int tmp = Nums[0];
                    Nums[0] = Nums[4];
                    Nums[4] = Nums[5];
                    Nums[5] = Nums[1];
                    Nums[1] = tmp;
                }
                break;
            case "S": // South direction rotation logic
                for (int i = 0; i < times; i++) {
                    int tmp = Nums[5];
                    Nums[5] = Nums[1];
                    Nums[1] = Nums[0];
                    Nums[0] = Nums[4];
                    Nums[4] = tmp;
                }
                break;
        }
    }

    public void roll(String direction, int times) {
        times %= 4; // Ensure times is less than or equal to 3 to avoid index out of bounds error.
        switch (direction) {
            case "R": // Right direction roll logic
                for (int i = 0; i < times; i++) {
                    int tmp = Nums[3];
                    Nums[3] = Nums[1];
                    Nums[1] = Nums[2];
                    Nums[2] = Nums[4];
                    Nums[4] = tmp;
                }
                break;
            case "L": // Left direction roll logic
                for (int i = 0; i < times; i++) {
                    int tmp = Nums[3];
                    Nums[3] = Nums[4];
                    Nums[4] = Nums[2];
                    Nums[2] = Nums[1];
                    Nums[1] = tmp;
                }
                break;
        }
    }

    public void printStatus() {
        String status =
                "	　　　 _ _ _ _\n" +
                "     _ _ _|_%3d_|_ _ _ _ _ _\n" +
                "    |_%3d_|_%3d_|_%3d_|_%3d_|\n" +
                " 　       |_%3d_|\n";
        System.out.printf(status, Nums[0], Nums[3], Nums[1], Nums[2], Nums[4], Nums[5]);
        System.out.println();
    }

    public boolean isEqual(Dice other) {
        for (int i = 0; i < 6; i++) {
            if (Nums[i]!= other.Nums[i]) {
                return false;
            }
        }
        return true;
    }
}



package main;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Initialize two dice
        Dice dice1 = new Dice();
        Dice dice2 = new Dice();

        // Input numbers for the first dice
        for (int i = 0; i < 6; i++) {
            int n = new Scanner(System.in).nextInt(); // Read input for each face
            dice1.nums[i] = n; // Assign input to the dice
        }

        // Input numbers for the second dice
        for (int i = 0; i < 6; i++) {
            int n = new Scanner(System.in).nextInt(); // Read input for each face
            dice2.nums[i] = n; // Assign input to the dice
        }

        // Define the order of directions and rolls for testing
        String[] directionOrder = {"N", "S", "W", "E"};
        String[] rollOrder = {"R", "L"};
        boolean flag = false; // Flag to indicate if a match is found

        CHECK: // Label for breaking out of nested loops
        // Check all combinations of rotations and rolls
        for (int i = 0; i <= 2; i++) { // Rotate 0 to 2 times
            for (int j = 0; j <= 2; j++) { // Roll 0 to 2 times
                for (String direction : directionOrder) { // Iterate through directions
                    for (String roll : rollOrder) { // Iterate through roll directions
                        Dice tmp = new Dice(); // Create a temporary dice
                        tmp.nums = dice2.nums.clone(); // Copy the numbers from dice2
                        tmp.rotate(direction, i); // Rotate the temporary dice
                        tmp.roll(roll, j); // Roll the temporary dice
                        if (tmp.isEqual(dice1)) { // Check if it matches dice1
                            flag = true; // Match found
                            break CHECK; // Break out of all loops
                        }
                    }
                }
            }
        }
        // Output the result based on the flag
        if (flag) {
            System.out.println("Yes"); // If a match was found
        } else {
            System.out.println("No"); // If no match was found
        }
    }

    static class Dice {
        int[] nums = new int[6]; // Array to hold the numbers on the faces of the dice

        // rotate method rotates the dice in a specified direction a certain number of times.
        void rotate(String direction, int times) {
            times %= 4; // Normalize the number of rotations to be within 0-3
            switch (direction) {
                case "W": // Rotate West
                    for (int i = 0; i < times; i++) {
                        nums[0] = nums[2];
                        nums[2] = nums[5];
                        nums[5] = nums[3];
                        nums[3] = nums[0];
                    }
                    break;
                case "E": // Rotate East
                    for (int i = 0; i < times; i++) {
                        nums[0] = nums[3];
                        nums[2] = nums[0];
                        nums[5] = nums[2];
                        nums[3] = nums[5];
                    }
                    break;
                case "N": // Rotate North
                    for (int i = 0; i < times; i++) {
                        nums[0] = nums[1];
                        nums[1] = nums[0];
                        nums[4] = nums[5];
                        nums[5] = nums[4];
                    }
                    break;
                case "S": // Rotate South
                    for (int i = 0; i < times; i++) {
                        nums[5] = nums[1];
                        nums[1] = nums[5];
                        nums[0] = nums[4];
                        nums[4] = nums[0];
                    }
                    break;
            }
        }

        // roll method rolls the dice in a specified direction a certain number of times.
        void roll(String direction, int times) {
            times %= 4; // Normalize the number of rolls to be within 0-3
            switch (direction) {
                case "R": // Roll Right
                    for (int i = 0; i < times; i++) {
                        nums[3] = nums[1];
                        nums[1] = nums[2];
                        nums[2] = nums[4];
                        nums[4] = nums[3];
                    }
                    break;
                case "L": // Roll Left
                    for (int i = 0; i < times; i++) {
                        nums[3] = nums[4];
                        nums[1] = nums[3];
                        nums[2] = nums[1];
                        nums[4] = nums[2];
                    }
                    break;
            }
        }

        // printStatus method prints the current status of the dice in a formatted manner.
        void printStatus() {
            String status =
                    "     _ _ _|_%3d_|_ _ _ _ _ _\n" +
                            "    |_%3d_|_%3d_|_%3d_|_%3d_|\n" +
                            "       |_%3d_|";
            System.out.printf(status, nums[0], nums[3], nums[1], nums[2], nums[4], nums[5]);
            System.out.println();
        }

        // getIndex function returns the index of a target number in the nums slice.
        int getIndex(int target) {
            for (int i = 0; i < nums.length; i++) {
                if (target == nums[i]) {
                    return i; // Found the target, return its index
                }
            }
            return -1; // Target not found, return -1
        }

        // isEqual method checks if two dice are in the same state (same numbers on each face).
        boolean isEqual(Dice other) {
            for (int i = 0; i < nums.length; i++) {
                if (nums[i] != other.nums[i]) {
                    return false; // If any face differs, return false
                }
            }
            return true; // All faces match, return true
        }
    }
}


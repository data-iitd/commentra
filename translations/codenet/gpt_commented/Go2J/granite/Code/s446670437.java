
import java.util.Scanner;

public class s446670437{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] dice1 = new int[6];
        int[] dice2 = new int[6];

        // Input numbers for the first dice
        for (int i = 0; i < 6; i++) {
            dice1[i] = scanner.nextInt();
        }

        // Input numbers for the second dice
        for (int i = 0; i < 6; i++) {
            dice2[i] = scanner.nextInt();
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
                        int[] tmp = dice2.clone(); // Create a temporary dice
                        rotate(tmp, direction, i); // Rotate the temporary dice
                        roll(tmp, roll, j); // Roll the temporary dice
                        if (isEqual(dice1, tmp)) { // Check if it matches dice1
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

    // Method to rotate the dice in a specified direction a certain number of times
    private static void rotate(int[] dice, String direction, int times) {
        times %= 4; // Normalize the number of rotations to be within 0-3
        switch (direction) {
            case "W": // Rotate West
                for (int i = 0; i < times; i++) {
                    int temp = dice[0];
                    dice[0] = dice[2];
                    dice[2] = dice[5];
                    dice[5] = dice[3];
                    dice[3] = temp;
                }
                break;
            case "E": // Rotate East
                for (int i = 0; i < times; i++) {
                    int temp = dice[0];
                    dice[0] = dice[3];
                    dice[3] = dice[5];
                    dice[5] = dice[2];
                    dice[2] = temp;
                }
                break;
            case "N": // Rotate North
                for (int i = 0; i < times; i++) {
                    int temp = dice[0];
                    dice[0] = dice[1];
                    dice[1] = dice[5];
                    dice[5] = dice[4];
                    dice[4] = temp;
                }
                break;
            case "S": // Rotate South
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

    // Method to roll the dice in a specified direction a certain number of times
    private static void roll(int[] dice, String direction, int times) {
        times %= 4; // Normalize the number of rolls to be within 0-3
        switch (direction) {
            case "R": // Roll Right
                for (int i = 0; i < times; i++) {
                    int temp = dice[1];
                    dice[1] = dice[2];
                    dice[2] = dice[4];
                    dice[4] = dice[3];
                    dice[3] = temp;
                }
                break;
            case "L": // Roll Left
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

    // Method to check if two dice are in the same state (same numbers on each face)
    private static boolean isEqual(int[] dice1, int[] dice2) {
        for (int i = 0; i < 6; i++) {
            if (dice1[i]!= dice2[i]) {
                return false; // If any face differs, return false
            }
        }
        return true; // All faces match, return true
    }
}


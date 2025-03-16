import java.util.Scanner;

class Dice {
    int[] nums; // Array to hold the numbers on the faces of the dice

    public Dice() {
        nums = new int[6]; // Initialize the array for six faces
    }

    // Rotate the dice in a specified direction a certain number of times
    public void rotate(String direction, int times) {
        times %= 4; // Normalize the number of rotations to be within 0-3
        for (int i = 0; i < times; i++) {
            switch (direction) {
                case "W": // Rotate West
                    int tempW = nums[0];
                    nums[0] = nums[2];
                    nums[2] = nums[5];
                    nums[5] = nums[3];
                    nums[3] = tempW;
                    break;
                case "E": // Rotate East
                    int tempE = nums[0];
                    nums[0] = nums[3];
                    nums[3] = nums[5];
                    nums[5] = nums[2];
                    nums[2] = tempE;
                    break;
                case "N": // Rotate North
                    int tempN = nums[0];
                    nums[0] = nums[1];
                    nums[1] = nums[5];
                    nums[5] = nums[4];
                    nums[4] = tempN;
                    break;
                case "S": // Rotate South
                    int tempS = nums[5];
                    nums[5] = nums[1];
                    nums[1] = nums[0];
                    nums[0] = nums[4];
                    nums[4] = tempS;
                    break;
            }
        }
    }

    // Roll the dice in a specified direction a certain number of times
    public void roll(String direction, int times) {
        times %= 4; // Normalize the number of rolls to be within 0-3
        for (int i = 0; i < times; i++) {
            switch (direction) {
                case "R": // Roll Right
                    int tempR = nums[3];
                    nums[3] = nums[1];
                    nums[1] = nums[2];
                    nums[2] = nums[4];
                    nums[4] = tempR;
                    break;
                case "L": // Roll Left
                    int tempL = nums[4];
                    nums[4] = nums[3];
                    nums[3] = nums[1];
                    nums[1] = nums[2];
                    nums[2] = tempL;
                    break;
            }
        }
    }

    // Check if two dice are in the same state (same numbers on each face)
    public boolean isEqual(Dice other) {
        for (int i = 0; i < 6; i++) {
            if (this.nums[i] != other.nums[i]) {
                return false; // If any face differs, return false
            }
        }
        return true; // All faces match, return true
    }

    // Print the current status of the dice in a formatted manner
    public void printStatus() {
        System.out.printf(
            "         ___\n" +
            "    ____|_%3d_|_______\n" +
            "    |_4_|_%3d_|_%3d_|_%3d_|\n" +
            "        |_6_|\n",
            nums[0], nums[3], nums[1], nums[2], nums[4], nums[5]
        );
        System.out.println();
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Initialize two dice
        Dice dice1 = new Dice();
        Dice dice2 = new Dice();

        // Input numbers for the first dice
        for (int i = 0; i < 6; i++) {
            dice1.nums[i] = scanner.nextInt(); // Read input for each face
        }

        // Input numbers for the second dice
        for (int i = 0; i < 6; i++) {
            dice2.nums[i] = scanner.nextInt(); // Read input for each face
        }

        // Define the order of directions and rolls for testing
        String[] directionOrder = {"N", "S", "W", "E"};
        String[] rollOrder = {"R", "L"};
        boolean flag = false; // Flag to indicate if a match is found

        // Check all combinations of rotations and rolls
        CHECK: // Label for breaking out of nested loops
        for (int i = 0; i <= 2; i++) { // Rotate 0 to 2 times
            for (int j = 0; j <= 2; j++) { // Roll 0 to 2 times
                for (String direction : directionOrder) { // Iterate through directions
                    for (String roll : rollOrder) { // Iterate through roll directions
                        Dice tmp = new Dice(); // Create a temporary dice
                        System.arraycopy(dice2.nums, 0, tmp.nums, 0, 6); // Copy the numbers from dice2
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

        scanner.close();
    }
}

// <END-OF-CODE>

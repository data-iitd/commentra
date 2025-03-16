package main;

import java.util.Scanner;

/*
Expand the diagram to fix the way the dice are expanded and record how the numbers in the diagram are moved by rotation.
The diagram is as follows. The way the dice are expanded is centered on the front two eyes.
         ___
    ____|_1_|_______
    |_4_|_2_|_3_|_5_|
        |_6_|

The state of the dice is determined uniquely by specifying the top and front. After specifying the top and front,
record the number in the third position of the diagram.

Compare the values on the right side of the dice with the numbers on the right side of the dice after the top and front are specified.
I thought that this method would work, but the constraint that all the numbers on the dice are different is not in this problem, so this method is incomplete.

Therefore, brute force all combinations.
*/

// Dice class represents a dice with its six faces numbered.
class Dice {
	int[] nums; // Array to hold the numbers on the faces of the dice

	// Constructor
	public Dice() {
		nums = new int[6]; // Create a slice for the numbers on the dice
	}

	// rotate method rotates the dice in a specified direction a certain number of times.
	public void rotate(String direction, int times) {
		times %= 4; // Normalize the number of rotations to be within 0-3
		switch (direction) {
		case "W": // Rotate West
			for (int i = 0; i < times; i++) {
				int tmp = nums[0];
				nums[0] = nums[2];
				nums[2] = nums[5];
				nums[5] = nums[3];
				nums[3] = tmp;
			}
			break;
		case "E": // Rotate East
			for (int i = 0; i < times; i++) {
				int tmp = nums[0];
				nums[0] = nums[3];
				nums[3] = nums[5];
				nums[5] = nums[2];
				nums[2] = tmp;
			}
			break;
		case "N": // Rotate North
			for (int i = 0; i < times; i++) {
				int tmp = nums[0];
				nums[0] = nums[4];
				nums[4] = nums[5];
				nums[5] = nums[1];
				nums[1] = tmp;
			}
			break;
		case "S": // Rotate South
			for (int i = 0; i < times; i++) {
				int tmp = nums[5];
				nums[5] = nums[1];
				nums[1] = nums[0];
				nums[0] = nums[4];
				nums[4] = tmp;
			}
			break;
		}
	}

	// roll method rolls the dice in a specified direction a certain number of times.
	public void roll(String direction, int times) {
		times %= 4; // Normalize the number of rolls to be within 0-3
		switch (direction) {
		case "R": // Roll Right
			for (int i = 0; i < times; i++) {
				int tmp = nums[3];
				nums[3] = nums[1];
				nums[1] = nums[2];
				nums[2] = nums[4];
				nums[4] = tmp;
			}
			break;
		case "L": // Roll Left
			for (int i = 0; i < times; i++) {
				int tmp = nums[3];
				nums[3] = nums[4];
				nums[4] = nums[2];
				nums[2] = nums[1];
				nums[1] = tmp;
			}
			break;
		}
	}

	// printStatus method prints the current status of the dice in a formatted manner.
	public void printStatus() {
		String status =
`	　　　 _ _ _ _
     _ _ _|_%3d_|_ _ _ _ _ _
    |_%3d_|_%3d_|_%3d_|_%3d_|
 　       |_%3d_|
`;
		System.out.printf(status, nums[0], nums[3], nums[1], nums[2], nums[4], nums[5]);
		System.out.println();
	}

	// getIndex function returns the index of a target number in the nums slice.
	public int getIndex(int target) {
		for (int i = 0; i < nums.length; i++) {
			if (target == nums[i]) {
				return i; // Found the target, return its index
			}
		}
		return -1; // Target not found, return -1
	}

	// isEqual method checks if two dice are in the same state (same numbers on each face).
	public boolean isEqual(Dice other) {
		for (int i = 0; i < nums.length; i++) {
			if (nums[i]!= other.nums[i]) {
				return false; // If any face differs, return false
			}
		}
		return true; // All faces match, return true
	}
}

// main function to execute the dice comparison logic.
public class Main {
	public static void main(String[] args) {
		// Initialize two dice
		Dice dice1 = new Dice();
		Dice dice2 = new Dice();

		// Input numbers for the first dice
		Scanner sc = new Scanner(System.in);
		for (int i = 0; i < 6; i++) {
			int n = sc.nextInt(); // Read input for each face
			dice1.nums[i] = n; // Assign input to the dice
		}

		// Input numbers for the second dice
		for (int i = 0; i < 6; i++) {
			int n = sc.nextInt(); // Read input for each face
			dice2.nums[i] = n; // Assign input to the dice
		}

		// Define the order of directions and rolls for testing
		String[] directionOrder = {"N", "S", "W", "E"};
		String[] rollOrder = {"R", "L"};
		boolean flag = false; // Flag to indicate if a match is found

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
							break; // Break out of all loops
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
}


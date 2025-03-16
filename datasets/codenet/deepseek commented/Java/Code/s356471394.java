
import java.util.Scanner;

public class Main {

	static Scanner sc = new Scanner(System.in);
	static String[] nums = sc.nextLine().split(" "); // Read input and split into array

	static int N = Integer.parseInt(nums[0]); // Initialize N with the first element of nums
	static int M = Integer.parseInt(nums[1]); // Initialize M with the second element of nums
	static char[][] room = new char[N][M]; // Declare a 2D char array to represent the room
	static int D = Integer.parseInt(nums[2]); // Initialize D with the third element of nums
	static int num = 0; // Initialize a counter for the number of possible positions

	public static void main(String[] args) {
		inputRoom(); // Call the method to read the room configuration

		if (M >= D) { // Check if the width allows for placing a hole of size D
			setWE(); // Call the method to check horizontal positions
		}

		if (N >= D) { // Check if the height allows for placing a hole of size D
			setNS(); // Call the method to check vertical positions
		}

		System.out.println(num); // Print the number of possible positions
		sc.close(); // Close the Scanner
	}

	private static void setWE() {
		boolean canPut = true; // Flag to check if a position is valid

		for (int i = 0; i < N; i++) { // Iterate over each row
			for (int j = 0; j < M - D + 1; j++) { // Iterate over each possible starting position in the row
				canPut = true; // Reset the flag for each position

				for(int k = 0; k < D; k++){ // Check each position in the potential hole
					if (Main.room[i][j + k] == '#') { // If there's a wall in the way
						canPut = false; // Mark the position as invalid
						break; // Exit the loop early
					}
				}

				if (canPut) { // If the position is valid
					num++; // Increment the counter
				}
			}
		}
	}

	private static void setNS() {
		boolean canPut = true; // Flag to check if a position is valid

		for (int i = 0; i < M; i++) { // Iterate over each column
			for (int j = 0; j < N - D + 1; j++) { // Iterate over each possible starting position in the column
				canPut = true; // Reset the flag for each position

				for(int k = 0; k < D; k++){ // Check each position in the potential hole
					if (Main.room[j + k][i] == '#') { // If there's a wall in the way
						canPut = false; // Mark the position as invalid
						break; // Exit the loop early
					}
				}

				if (canPut) { // If the position is valid
					num++; // Increment the counter
				}
			}
		}
	}

	private static void inputRoom() {
		String str_room = "";

		for (int i = 0; i < N; i++) { // Read each row of the room
			str_room = sc.nextLine();
			Main.room[i] = str_room.toCharArray(); // Convert the row string to a char array and store it in the room array
		}
	}
}
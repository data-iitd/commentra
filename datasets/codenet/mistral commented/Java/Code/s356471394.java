import java.util.Scanner;

public class Main {

	static Scanner sc = new Scanner(System.in);
	static String[] nums;

	// Initialize the room array, number of rows N, number of columns M, and the diameter D
	static char[][] room;
	static int N, M, D, num;

	public static void main(String[] args) {
		// Read input from the user
		inputRoom();

		// Check if the room width is greater than or equal to the diameter
		if (M >= D) {
			setWE();
		}

		// Check if the room height is greater than or equal to the diameter
		if (N >= D) {
			setNS();
		}

		// Print the number of circles that can be placed in the room
		System.out.println(num);
		sc.close();
	}

	// Read the room dimensions and number of circles from the user input
	private static void inputRoom() {
		nums = sc.nextLine().split(" ");

		// Initialize the room dimensions and number of circles
		N = Integer.parseInt(nums[0]);
		M = Integer.parseInt(nums[1]);
		D = Integer.parseInt(nums[2]);

		// Read the room layout from the user input
		nums = sc.nextLine().split(" ");
		room = new char[N][M];
		for (int i = 0; i < N; i++) {
			room[i] = nums[i].toCharArray();
		}
	}

	// Check for circles that can be placed in the room horizontally (west-east direction)
	private static void setWE() {
		boolean canPut = true;

		// Iterate through each row in the room
		for (int i = 0; i < N; i++) {
			// Iterate through each potential circle position in the row
			for (int j = 0; j < M - D + 1; j++) {
				canPut = true;

				// Check if the potential circle position is valid (no obstacles)
				for (int k = 0; k < D; k++) {
					if (room[i][j + k] == '#') {
						canPut = false;
						break;
					}
				}

				// If the potential circle position is valid, increment the number of circles
				if (canPut == true) {
					num++;
				}

			}
		}
	}

	// Check for circles that can be placed in the room vertically (north-south direction)
	private static void setNS() {
		boolean canPut = true;

		// Iterate through each column in the room
		for (int i = 0; i < M; i++) {
			// Iterate through each potential circle position in the column
			for (int j = 0; j < N - D + 1; j++) {
				canPut = true;

				// Check if the potential circle position is valid (no obstacles)
				for (int k = 0; k < D; k++) {
					if (room[j + k][i] == '#') {
						canPut = false;
						break;
					}
				}

				// If the potential circle position is valid, increment the number of circles
				if (canPut == true) {
					num++;
				}

			}
		}
	}

}

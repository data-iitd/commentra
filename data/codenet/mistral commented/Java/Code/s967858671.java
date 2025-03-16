
import java.util.Scanner; // Importing Scanner class for user input

public class Main {
	public static void main(String[] args) {
		// Declaring and initializing an integer array of size 11
		int[] Num;
		Num = new int[11];

		// Creating a Scanner object for reading user input
		Scanner n = new Scanner(System.in);

		// Reading 10 integers from the user and storing them in the Num array
		for (int i = 0; i < 10; i++) {
			Num[i] = n.nextInt(); // Reading an integer from the user and storing it in the current index of the Num array
		}

		// Sorting the Num array in descending order using bubble sort algorithm
		for (int a = 9; a >= 0; a--) { // Outer loop runs from the second last index to the first index
			for (int b = 0; b < a; b++) { // Inner loop runs from the first index to the index before the current index
				if (Num[b] < Num[b+1]) { // Comparing the current and next elements in the array
					// Swapping the elements if they are in the wrong order
					int temp = Num[b];
					Num[b] = Num[b+1];
					Num[b+1] = temp;
				}
			}
		}

		// Printing the first three sorted integers from the Num array
		System.out.println(Num[0]);
		System.out.println(Num[1]);
		System.out.println(Num[2]);
	}
}
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Step 1: Read three integers from input.
		Scanner sc = new Scanner(System.in);
		int[] c = new int[3];
		for (int i = 0; i < 3; i++) {
			c[i] = sc.nextInt();
		}
		
		// Step 2: Initialize an array to keep track of the cards.
		char[] card = new char[10];
		for (int i = 0; i < 10; i++) {
			card[i] = 0;
		}
		
		// Step 3: Loop through the cards and mark them in the array.
		for (int i = 0; i < 3; i++) {
			card[c[i] - 1] = 1;
		}
		
		// Step 4: Initialize a counter to count the number of valid cards.
		int count = 0;
		
		// Step 5: Initialize a sum variable to keep track of the sum of the two known cards.
		int sum = c[0] + c[1];
		
		// Step 6: Check which cards can be added to the sum without exceeding 20.
		for (int i = 0; i < 10; i++) {
			if (card[i] == 0 && sum + i + 1 <= 20) {
				count++;
			}
		}
		
		// Step 7: Determine if at least 4 such cards exist.
		if (count >= 4) {
			// Step 8: Print "YES" if such cards exist.
			System.out.println("YES");
		}
		else {
			// Step 9: Print "NO" otherwise.
			System.out.println("NO");
		}
		
		sc.close();
	}

}

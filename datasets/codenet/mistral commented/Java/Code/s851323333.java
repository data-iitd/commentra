
import java.util.LinkedList;
import java.util.Scanner;

/**
 * Main class for the program.
 */
public class Main {
	public static void main(String[] args) {
		/**
		 * Initialize a Scanner object to read input from the console.
		 */
		Scanner scan = new Scanner(System.in);

		/**
		 * Initialize an empty LinkedList to store integers.
		 */
		LinkedList<Integer> list = new LinkedList<Integer>();

		/**
		 * Continuously read integers from the console until there is no more input.
		 */
		while(scan.hasNextInt() == true){
			/**
			 * Read the next integer from the console.
			 */
			int a = scan.nextInt();

			/**
			 * Check if the read integer is 0.
			 */
			if(a == 0) {
				/**
				 * If the integer is 0, print and remove the last integer from the list.
				 */
				System.out.println(list.pop());
			} else {
				/**
				 * If the integer is not 0, add it to the list.
				 */
				list.push(a);
			}
		}

		/**
		 * Close the Scanner to free system resources.
		 */
		scan.close();
	}
}


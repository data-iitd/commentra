
import java.util.LinkedList;
import java.util.Scanner;


public class Main {
	public static void main(String[] args) {
		// Create a Scanner object to read input from the user
		Scanner scan = new Scanner(System.in);
		// Create a LinkedList to store integers
		LinkedList<Integer> list = new LinkedList<Integer>();
		
		// Continuously read integers from the user until no more input is available
		while(scan.hasNextInt() == true){
			// Read the next integer from the user
			int a = scan.nextInt();
			// If the integer is 0, pop an element from the list and print it
			if(a == 0) {
				System.out.println(list.pop());
			} else {
				// If the integer is not 0, push it onto the list
				list.push(a);
			}
		}
	}
}


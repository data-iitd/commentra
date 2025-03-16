import java.util.Scanner; // Importing the Scanner class for user input

public class Main {
    public static void main(final String[] args) { // Main method to start the program
    	Scanner scanner = new Scanner(System.in); // Creating a new Scanner object for user input
    	int a, b; // Declaring variables a and b to store user input

    	// Requesting user input for variables a and b
    	a = scanner.nextInt();
    	b = scanner.nextInt();

    	boolean flag = false; // Initializing a boolean flag variable to false

    	// Loop to find the solution
    	for(int i=1;i<=100000;i++) {
    		// Checking if the conditions are met
    		if (Math.floor(1.* i *.08) == a && b == Math.floor(.1 * i)) {
    			// If conditions are met, print the solution and set flag to true
    			System.out.println(i);
    			flag = true;
    			// Exit the loop once a solution is found
    			break;
    		}
    	}

    	// If no solution is found, print -1
    	if (!flag) {
    		System.out.println(-1);
    	}
    }
}

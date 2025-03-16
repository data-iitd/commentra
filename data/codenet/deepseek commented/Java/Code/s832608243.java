import java.util.Scanner; // Importing the Scanner class for input

public class Main {
    public static void main(final String[] args) {
    	Scanner scanner = new Scanner(System.in); // Initialize Scanner object to read input
    	int a = scanner.nextInt(), b = scanner.nextInt(); // Read two integers from the user
    	boolean flag = false; // Initialize a flag to check if a valid i is found
    	for(int i=1;i<=100000;i++) { // Loop from 1 to 100,000 to find the correct i
    		if (Math.floor(1.* i *.08) == a && b == Math.floor(.1 * i)) { // Check if the conditions are met
    			System.out.println(i); // Print the value of i if conditions are met
    			flag = true; // Set flag to true to break out of the loop
    			break;
    		}
    	}
    	if (!flag) { // Check if no valid i was found
    		System.out.println(-1); // Print -1 if no valid i was found
    	}
    	}
    }

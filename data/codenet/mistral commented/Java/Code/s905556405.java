import java.util.*; // We import the Java Util library to use the Scanner class

public class Main { // This is the main class of the program
    public static void main(String[] args) { // This is the main method where the program starts execution
        Scanner sc = new Scanner(System.in); // Create a new Scanner object to read input from the console

      	int[] numlist  = new int[5]; // Declare and initialize an integer array named numlist with a size of 5
      	int k; // Declare an integer variable named k

      	for(int i=0;i<5;i++){ // Use a for loop to read 5 integers from the user and store them in the numlist array
        	numlist[i] = sc.nextInt(); // Read an integer from the console and assign it to the current index of the numlist array
        }
      	k = sc.nextInt(); // Read an integer from the console and assign it to the variable k

      	if((numlist[4] - numlist[0])>k){ // Check if the difference between the last and first element of the numlist array is greater than k
        	System.out.println(":("); // If the condition is true, print a sad face emoticon
        }else{
         	System.out.println("Yay!"); // If the condition is false, print a happy face emoticon
        }

      	sc.close(); // Close the Scanner object to free up system resources
    }
}

import java.util.*; // We import the java.util.Scanner class to read input from the standard input stream.

public class Main {
	public static void main(String[] args){ // We define the main method to be the entry point of the program.
    	Scanner sc = new Scanner(System.in); // We create a new Scanner object named sc to read input from the user.
      	int a, b; // We declare and initialize two integer variables a and b.
		
      	a = sc.nextInt(); // We read the first integer value from the user input using the nextInt() method of the Scanner object and assign it to variable a.
		b = sc.nextInt(); // We read the second integer value from the user input using the nextInt() method of the Scanner object and assign it to variable b.
      	
      	if(b%a==0) { // We check if the second number b is divisible by the first number a using the modulo operator %.
        	System.out.println(a+b); // If b is divisible by a, we print the sum of a and b using the println() method of the System.out object.
      	} else { // If b is not divisible by a, we execute the code inside this else block.
        	System.out.println(b-a); // We print the difference between b and a using the println() method of the System.out object.
      	}
    }
}
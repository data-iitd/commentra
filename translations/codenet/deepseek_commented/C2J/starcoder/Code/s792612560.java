import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(); // Step 3: Read an integer input from the user and store it in n
		long m = n; // Step 3: Declare an unsigned long long integer variable m
		n--; // Step 6: Decrement the value of n by 1
		for(;n>1;n--) { // Step 7: Start a for loop that runs while n is greater than 1
			m*=n; // Inside the loop, multiply m by n and decrement n by 1
		}
		System.out.println(m); // Step 8: Print the value of m, which represents the factorial of the input number
	}
}

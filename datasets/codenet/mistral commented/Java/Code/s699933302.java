
import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		// Create a new Scanner object to read input from the console
		Scanner sc = new Scanner(System.in);

		// Declare and initialize three integer variables `a`, `b`, and `c` by reading their values from the console using the Scanner object
		int a = Integer.parseInt(sc.next());
		int b = Integer.parseInt(sc.next());
		int c = Integer.parseInt(sc.next());

		// Declare and initialize an integer variable `count` to keep track of the number of factors of `c` between `a` and `b`
		int count = 0;

		// Use a for loop to iterate through all the numbers between `a` and `b`
		for (int i = a ; i <= b ;i++ ) {
			// Inside the for loop, use an if statement to check if the current number `i` is a factor of `c`
			if (c % i ==0) {
				// If the current number `i` is a factor of `c`, increment the `count` variable by 1
				count++;
			}
		}

		// After the for loop, print the value of `count` to the console
		System.out.println(count);
	}
}
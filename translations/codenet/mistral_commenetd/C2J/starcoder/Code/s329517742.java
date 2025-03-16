
import java.util.*;

public class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in); // Creating a Scanner object to read from the standard input
		int a, b; // Declaring two integer variables a and b
		a = sc.nextInt(); // Reading an integer from the standard input and storing it in variable a
		b = sc.nextInt(); // Reading an integer from the standard input and storing it in variable b

		// Logical block to check if 500 times the value of variable 'a' is greater than or equal to the value of variable 'b'
		if(500*a >= b)
		{
			System.out.println("Yes"); // If the condition is true, print 'Yes' to the standard output
		}
		else
		{
			System.out.println("No"); // If the condition is false, print 'No' to the standard output
		}
	}
}


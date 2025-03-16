
import java.util.*;
import java.io.*;

public class Main
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);

		// Declare an integer variable 'n' and read its value from the standard input
		int n = in.nextInt();

		// Output the result, which is calculated as (n - 2) * 180
		System.out.println((n - 2) * 180);

		// Indicate successful termination of the program by returning 0
		return 0;
	}
}


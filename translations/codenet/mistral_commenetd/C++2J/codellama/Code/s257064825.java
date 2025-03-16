import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// Initialize I/O streams
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);

		// Read input string from standard input
		String str = br.readLine();

		// Initialize sum variable to 0
		int sum = 0;

		// Iterate through each character in the string and add its ASCII value (after converting to digit) to sum
		for(char x:str.toCharArray())
		{
			sum+=(x-48); // Subtract 48 to convert ASCII value of digit character to its integer value
		}

		// Check if sum is divisible by 9
		if(sum%9==0)
		{
			pw.println("Yes"); // Output "Yes" if sum is divisible by 9
		}
		else
		{
			pw.println("No"); // Output "No" otherwise
		}

		// Close I/O streams
		pw.close();
		br.close();
	}
}


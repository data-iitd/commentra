
import java.util.*;               // Import utility classes
import java.io.*;                // Import input/output stream classes
public class s257064825{               // Define the main class
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);  // Create a Scanner object to read input
		String str=sc.nextLine();         // Read input string
		long sum=0;                        // Initialize sum variable to store the sum of digits
		for(char x:str.toCharArray())    // Iterate over each character in the string
		{
			sum+=(x-'0');                // Convert character to integer and add to sum
		}
		if(sum%9==0)                       // Check if sum is divisible by 9
		{
            System.out.println("Yes");    // Print "Yes" if sum is divisible by 9
		}
		else                               // Otherwise
		   System.out.println("No");      // Print "No"
	}
}

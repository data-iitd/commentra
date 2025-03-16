
import java.util.*;
import java.math.*;

public class Main
{
	public static void main(String[] args)
	{
		// Initialize an empty string variable named'source'
		String source = "";

		// Read a string input from the standard input stream (cin) and store it in the'source' variable
		Scanner cin = new Scanner(System.in);
		source = cin.next();

		// Check if the length of the input string is valid (greater than 10 characters or less than 1 character)
		if(source.length() > 10 || source.length() < 1)
		{
			// If the condition is true, return an error code (-1)
			return -1;
		}

		// Calculate the maximum value of 'i' based on the length of the input string using bitwise operations
		int max_i = (int) Math.pow(2, source.length() - 1);

		// Initialize a variable named'sum' with a value of 0
		double sum = 0;

		// Iterate through the range of 'i' from 0 to'max_i' using a for loop
		for (int i = 0; i < max_i; ++i)
		{
			// Create a bitset named 'plus' with the binary representation of 'i'
			BitSet plus = new BitSet(100);
			plus.set(i);

			// Initialize a variable named 'number' with a value of 0
			double number = 0;

			// Initialize a string variable named 'working' with the value of the input string'source'
			String working = source;

			// Iterate through the bits of the 'plus' bitset from the least significant bit to the most significant bit
			while(plus.anySet())
			{
				// Find the index of the first '1' bit in the 'plus' bitset
				int index = plus.nextSetBit(0);

				// Add the substring of the 'working' string starting from the first '1' bit index to the'sum' variable
				sum += Double.parseDouble(working.substring(0, index + 1));

				// Shift the 'plus' bitset to the right by the index of the first '1' bit
				plus.clear(index);

				// Update the value of the 'working' string by removing the substring that has been added to the'sum' variable
				working = working.substring(index + 1);
			}

			// Add the remaining substring of the 'working' string to the'sum' variable
			sum += Double.parseDouble(working);
		}

		// Set the precision of the output stream (cout) to 0 decimal places
		System.out.printf("%.0f\n", sum);
	}
}


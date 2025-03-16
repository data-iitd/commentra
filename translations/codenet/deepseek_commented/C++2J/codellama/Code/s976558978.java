
/*
URL_HERE
*/
/*

*/
import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	
	public static void main(String[] args) {
		
		Scanner fin = new Scanner(System.in); // Set the input file to standard input
		PrintStream fout = System.out; // Set the output file to standard output
		
		int a = fin.nextInt(); // Read integer a
		int b = fin.nextInt(); // Read integer b
		if (a < b) // Check if a is less than b
		{
			for (int i = 0; i < b; ++i) fout.print(a + " "); // Print a b times
			fout.println(); // New line
		}
		else // Otherwise
		{
			for (int i = 0; i < a; ++i) fout.print(b + " "); // Print b a times
			fout.println(); // New line
		}
		
	}
	
}



/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/*
 * Main class
 */
public class Main {
	public static void main (String[] args) throws java.lang.Exception
	{
		/* Initialize Scanner object to read input from standard input */
		Scanner in =new Scanner(System.in);

		/* Declare variables a and b of integer type */
		int a, b;

		/* Read the first integer value from standard input and assign it to variable a */
		a=in.nextInt();

		/* Read the second integer value from standard input and assign it to variable b */
		b=in.nextInt();

		/* Check if either of the numbers a or b is even */
		if(a%2==0 || b%2==0 )
		{
			/* If the condition is true, print "No" */
			System.out.println("No");
		}
		else
		{
			/* If the condition is false, print "Yes" */
			System.out.println("Yes");
		}
	}
}
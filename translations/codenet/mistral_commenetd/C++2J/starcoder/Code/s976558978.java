/*
URL_HERE
*/
/*
This is the main Java file for solving a problem. Replace URL_HERE with the URL of the problem statement.
*/
import java.io.*;
import java.util.*;

public class Main
{
	public static void main(String[] args) throws Exception
	{
		Scanner fin = new Scanner(System.in);
		int a = fin.nextInt();
		int b = fin.nextInt();
		/*
		Read the two integers a and b from the input file.
		*/
		if (a < b)
		{
			for (int i = 0; i < b; ++i)
			{
				System.out.print(a);
				System.out.print(" ");
				/*
				If a is smaller than b, print a b times.
				*/
			}
			System.out.println();
			/*
			Print a newline at the end.
			*/
		}
		else
		{
			for (int i = 0; i < a; ++i)
			{
				System.out.print(b);
				System.out.print(" ");
				/*
				If b is smaller than a, print b a times.
				*/
			}
			System.out.println();
			/*
			Print a newline at the end.
			*/
		}
	}
}

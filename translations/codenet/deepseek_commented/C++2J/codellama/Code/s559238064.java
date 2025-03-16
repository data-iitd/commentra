import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		String z = sc.next();
		int a = z.length();
		for (int i = 0; i < a - 1; i++)
		{
			if (z.charAt(i) == z.charAt(i + 1))
			{
				System.out.println("Bad");
				return;
			}
		}
		System.out.println("Good");
	}
}


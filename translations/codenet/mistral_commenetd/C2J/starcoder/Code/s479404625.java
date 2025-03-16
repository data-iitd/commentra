
import java.util.*;

public class Main
{
	public static void main(String[] args)
	{
		// Declare three character arrays of size 20 each to store strings A, B, and C
		char[] A = new char[20], B = new char[20], C = new char[20];

		// Initialize the character arrays A, B, and C using scanf function
		Scanner sc = new Scanner(System.in);
		sc.next(A);
		sc.next(B);
		sc.next(C);

		// Calculate the length of strings A and B using strlen function and store the lengths in la and lb respectively
		int la = A.length, lb = B.length;

		// Logical block to check if the last character of string A is same as the first character of string B
		// and the last character of string B is same as the first character of string C
		if (A[la - 1] == B[0] && B[lb - 1] == C[0])
		{
			// If the condition is true, print YES on the console
			System.out.println("YES");
		}
		// Logical block to check if the condition in if block is false
		else
		{
			// If the condition is false, print NO on the console
			System.out.println("NO");
		}
	}
}


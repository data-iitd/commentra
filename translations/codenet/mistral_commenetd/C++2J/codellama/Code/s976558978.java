/*
URL_HERE
*/
/*
This is the main Java file for solving a problem. Replace URL_HERE with the URL of the problem statement.
*/
import java.io.*;
import java.util.*;
import java.math.*;
/*
Include the necessary standard libraries and the unordered_map from the STL.
*/

public class Main {
	public static void main(String[] args) throws Exception {
		/*
		The main function.
		*/
		Scanner fin = new Scanner(new File("dataabc155A.txt"));
		/*
		Open the input file for reading.
		*/
		int a = fin.nextInt();
		int b = fin.nextInt();
		/*
		Read the two integers a and b from the input file.
		*/
		if (a < b) {
			for (int i = 0; i < b; i++) {
				System.out.print(a + " ");
			}
			System.out.println();
			/*
			If a is smaller than b, print a b times.
			*/
		} else {
			for (int i = 0; i < a; i++) {
				System.out.print(b + " ");
			}
			System.out.println();
			/*
			If b is smaller than a, print b a times.
			*/
		}
	}
}

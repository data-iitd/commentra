import java.util.Scanner; // Importing the Scanner class from the Java standard library

public class Main{ // The main class, which is the starting point of the program
	public static void main(String[] args){ // The main function, which is the starting point of the program
		Scanner input=new Scanner(System.in); // Creating a Scanner object named input and initialising it to read from the standard input
		int n,x,min,m,i; // Declaring the variables n, x, min, m, and i

		n=input.nextInt(); // Reading an integer from the standard input and storing it in the variable n
		x=input.nextInt(); // Reading an integer from the standard input and storing it in the variable x
		min=input.nextInt(); // Reading an integer from the standard input and storing it in the variable min

		x-=min; // Subtracting the minimum value from x

		for(i=1;i<n;i++){ // Starting a for loop that iterates from 1 to n-1
			m=input.nextInt(); // Reading an integer from the standard input and storing it in the variable m

			x-=m; // Subtracting the current number from x

			if(min>m){ // Checking if the current number is smaller than the current minimum
				min=m; // Updating the minimum if it is
			}
		}

		System.out.println(n+x/min); // Printing the final result, which is the number of elements plus the quotient of the remaining difference and the minimum number
	}
}

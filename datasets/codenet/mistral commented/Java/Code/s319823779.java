
import java.util.*; // Importing the utility class Scanner

class Main
{
		public static void main(String[] args) // Main method to start the execution of the program
		{
			Scanner sc = new Scanner(System.in); // Creating an object of Scanner class to read input from the user

			// Declaring and initializing variables
			int a = sc.nextInt();
			int b = sc.nextInt();
			int c = sc.nextInt();
			int x = sc.nextInt();
			int res = 0;

			// Using nested loops to find the combination of 'a', 'b' and 'c' that results in 'x'
			for(int i=0 ; i<=a ; i++){ // Loop to iterate through the possible values of 'a'
				for(int j=0 ; j<=b ; j++){ // Loop to iterate through the possible values of 'b'
					for(int k=0 ; k<=c ; k++){ // Loop to iterate through the possible values of 'c'
						int total = 500*i + 100*j + 50*k; // Calculate the total sum of 'i', 'j' and 'k'

						// Check if the total sum equals to 'x' and if yes, increment the 'res' variable
						if( total==x ){
							res++;
						}
					}
				}
			}

			// Print the result
			System.out.println(res);
		}
}


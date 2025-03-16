
import java.util.Scanner; // Import standard input/output library for input/output operations

public class Main{
	public static void main(String[] args){
		int i; // Initialize integer variable 'i'
		int sum=0; // Initialize integer variable'sum' to zero
		int flag=0; // Initialize integer variable 'flag' to zero
		String x; // Initialize string variable 'x'

		// Read a string from standard input and store it in 'x'
		System.out.print("Enter a string of digits separated by spaces or newline: ");
		Scanner sc = new Scanner(System.in);
		x = sc.next();

		do{ // Begin a do-while loop

			// Initialize sum to zero before processing each string
			sum=0;

			// Process each character in the string 'x'
			for(i=0;i<x.length();i++){
				// Check if current character is end-of-string marker
				if(x.charAt(i)==0){
					// If so, print the sum of digits in the previous string and exit the loop
					System.out.println("Sum of digits in previous string: "+sum);
					break;
				}else{
					// Otherwise, add the ASCII value of the character to the sum (subtracting 0x30 to convert ASCII to integer)
					sum+=x.charAt(i)-0x30;
				}
			}

			// Initialize sum to zero for next iteration of the loop
			sum=0;

			// Read next string from standard input
			System.out.print("Enter a string of digits separated by spaces or newline: ");
			x = sc.next();

		}while(x.charAt(0)!=0x30); // Continue the loop until the first character of the input string is '0'
	}
}


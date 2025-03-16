import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in); // Create a Scanner object to read input
		int n,i,cnt; // Declare variables to store input, loop index, and count of pairs

		while(1){ // Infinite loop to read input until 'n' is zero
			n = sc.nextInt(); // Read an integer 'n' from the user
			if(n == 0){
				break; // Exit the loop if 'n' is zero
			}
			i = 2; // Initialize the starting prime number
			cnt = 0; // Initialize the count of pairs
			while(i*2 <= n){ // Loop to find pairs of primes summing to 'n'
				if(isPrime(i) && isPrime(n-i)){ // Check if both 'i' and 'n-i' are prime
					cnt++; // Increment the count if a valid pair is found
				}
				i++; // Move to the next potential prime number
			}
			System.out.println(cnt); // Print the count of pairs of primes summing to 'n'
		}
	}

	// Function to check if a number is prime
	public static boolean isPrime(int n){
		if(n == 2 || n == 3){ // Check if 'n' is 2 or 3
			return true; // Return true if 'n' is 2 or 3
		}
		if(n%2 == 0 || n%3 == 0){ // Check if 'n' is divisible by 2 or 3
			return false; // Return false if 'n' is divisible by 2 or 3
		}
		for(int i = 5;i*i <= n;i+=6){ // Iterate to check if 'n' is divisible by 5 or 7
			if(n%i == 0 || n%(i+2) == 0){ // Check if 'n' is divisible by 'i' or 'i+2'
				return false; // Return false if 'n' is divisible by 'i' or 'i+2'
			}
		}
		return true; // Return true if 'n' is prime
	}
}


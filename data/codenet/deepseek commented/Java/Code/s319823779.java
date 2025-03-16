import java.util.*;
class Main
{
		public static void main(String[] args)
		{
			// Initialize Scanner to read input from the user
			Scanner sc = new Scanner(System.in);
			
			// Read the number of 500-yen, 100-yen, and 50-yen coins, and the target amount
			int a = sc.nextInt();
			int b = sc.nextInt();
			int c = sc.nextInt();
			int x = sc.nextInt();
			
			// Initialize a variable to count the number of combinations
			int res = 0;
			
			// Use nested loops to iterate over all possible combinations of coins
			for(int i=0 ; i<=a ; i++){
				for(int j=0 ; j<=b ; j++){
					for(int k=0 ; k<=c ; k++){
						// Calculate the total value of the current combination of coins
						int total = 500*i + 100*j + 50*k;
						
						// Check if the total value equals the target amount
						if( total==x ){
							// Increment the count if the total matches the target
							res++;
						}
					}
				}
			}
			
			// Print the number of combinations that sum up to the target amount
			System.out.println(res);
		}
}

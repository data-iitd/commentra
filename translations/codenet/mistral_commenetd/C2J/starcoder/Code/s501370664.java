
import java.util.*;

public class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int n,i,cnt;
		int flag[];

		// Call prime function to find prime numbers up to 50000
		prime(50000);

		// Loop until user inputs 0
		while(1){
			// Read user input for number n
			n = sc.nextInt();
			// Break the loop if user inputs 0
			if(n == 0){
				break;
			}
			// Initialize i and cnt to 0
			i = 2;
			cnt = 0;
			// Loop through numbers from 2 to square root of n
			while(i*i <= n){
				// If i and n-i are both prime, increment cnt
				if(!flag[i] &&!flag[n-i]){
					cnt++;
				}
				// Increment i for next iteration
				i++;
			}
			// Print the result
			System.out.println(cnt);
		}
	}

	// Function to find prime numbers up to a given limit
	public static void prime(int num){
		int i,j;

		// Allocate memory for flag array of size num+1
		flag = new int[num+1];

		// Loop through numbers from 2 to num
		for(i = 2;i*i <= num;i++){
			// If a number is not marked as composite, mark all its multiples as composite
			if(flag[i] == 0){
				for(j = 2;i*j <= num;j++){
					flag[i*j] = 1;
				}
			}
		}
	}
}



import java.util.*;
public class Main{
	public static void main(String[] args){
		// Read the number of elements from the user
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

		// Read the size of the subarray from the user
		int a = sc.nextInt();

		// Declare and initialize variables
		int sum = 0;
		int s[] = new int[n];

		// Read the elements of the array from the user
		for(int i=0;i<n;i++){
			s[i] = sc.nextInt();
		}

		// Sort the array in ascending order
		Arrays.sort(s);

		// Calculate the sum of the last 'a' elements of the sorted array
		for(int i=n-1;i>n-a-1;i--){
			sum += s[i];
		}

		// Print the result
		System.out.println(sum);
	}
}


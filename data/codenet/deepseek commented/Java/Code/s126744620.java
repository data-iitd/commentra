
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// Initialize Scanner object to read input from the user
		Scanner sc = new Scanner(System.in);
		
		// Read the number of elements (n) and the number of smallest elements to consider (k)
		int n = sc.nextInt();
		int k = sc.nextInt();
		
		// Read n integers and store them in an array 'a'
		int[] a = new int[n];
		for(int i = 0 ; i < n ; i++) a[i] = sc.nextInt();
		
		// Initialize an array 'x' of size 200010 and fill it with zeros
		Integer[] x = new Integer[200010];
		Arrays.fill(x, 0);
		
		// Iterate over the array 'a' and increment the corresponding index in array 'x' by 1 for each element
		for(int i = 0 ; i < n ; i++) {
			x[a[i] - 1]++;
		}
		
		// Sort the array 'x' using a comparator that sorts integers in ascending order
		Arrays.sort(x, new Comparator<Integer>() {
			public int compare(Integer p1, Integer p2) {
				return p1 - p2;
			}
		});
		
		// Initialize a variable 'ans' to 0
		int ans = 0;
		
		// Iterate over the first 200010 - k elements of the sorted array 'x' and add each element to 'ans'
		for(int i = 0 ; i <= 200010 - k - 1 ; i++) {
			ans += x[i];
		}
		
		// Print the value of 'ans'
		System.out.println(ans);
	}
}
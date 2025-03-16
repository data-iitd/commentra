
import java.util.*;
import java.lang.*;
class Main {
	public static void main(String args[]){
		// Scanner class to read input from the standard input stream
		Scanner sc=new Scanner(System.in);
		
		// Read the number of test cases
		int t=sc.nextInt();
		
		// Array to store the counts of each number
		int[] count=new int[t+1];
		
		// Read numbers and count their occurrences
		for (int i=2;i<t+1;i++) {
			count[sc.nextInt()]++;
		}
		
		// Output the counts of each number
		for (int i=1;i<t+1 ;i++ ) {
			System.out.println(count[i]);
		}
	}
}


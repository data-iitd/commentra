
import java.lang.Math.*;   // Importing Math library for pow() function
import java.util.Scanner;  // Importing Scanner class for user input
import java.util.Arrays;   // Importing Arrays class for sorting array

class Main{
    public static void main(String[] args){
	// Creating a Scanner object for user input
	final Scanner sc = new Scanner(System.in);

	// Reading the number of test cases
	int n=sc.nextInt();

	// Initializing an integer array 'a' of size 3
	int[] a=new int[3];

	// Iterating through each test case
	for(int i=0;i<n;i++){
	    // Reading three integers from user input
	    a[0]=sc.nextInt();
	    a[1]=sc.nextInt();
	    a[2]=sc.nextInt();

	    // Sorting the array 'a' in ascending order
	    Arrays.sort(a);

	    // Checking if the square of the last element is equal to the sum of the squares of the first two elements
	    if(Math.pow(a[2],2)==Math.pow(a[0],2)+Math.pow(a[1],2)){
		// If true, print "YES"
		System.out.println("YES");
	    }
	    else{
		// If false, print "NO"
		System.out.println("NO");
	    }
	}
    }
}
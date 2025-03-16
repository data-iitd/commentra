import java.util.Scanner; // import the Scanner class from the java.util package

public class Main {
	public static void main(String[] args) { // main function declaration
		Scanner scan = new Scanner(System.in); // create a new Scanner object to read from the standard input
		int N = scan.nextInt(); // read the number of elements from the standard input
		int[] a = new int[N]; // create an array of size N to store the elements
		int[] b = new int[N]; // create an array of size N to store the elements
		int frontHalf, backHalf; // declare integers frontHalf and backHalf

		for(int i=0;i<N;i++) // iterate through the array a and assign each element to b
		{
			a[i] = scan.nextInt(); // read an integer from the standard input and assign it to the ith position in array a
			b[i] = a[i]; // copy the value of the ith position in array a to the ith position in array b
		}

		sort(b); // sort the elements in array b in ascending order

		frontHalf = b[N/2-1]; // assign the middle value of the first half of the sorted array b to frontHalf
		backHalf = b[N/2]; // assign the middle value of the second half of the sorted array b to backHalf

		for(int i=0;i<N;i++) // iterate through the array a and print the appropriate middle value based on the condition
		{
			if(a[i]<backHalf) // if the value at the ith position in array a is less than the middle value of the second half of the sorted array b
				System.out.println(backHalf); // print the middle value of the second half of the sorted array b
			else
				System.out.println(frontHalf); // print the middle value of the first half of the sorted array b
		}

		scan.close(); // close the Scanner object
	}

	public static void sort(int[] b) { // sort function declaration
		int temp; // declare an integer temp
		for(int i=0;i<b.length;i++) // iterate through the array b
		{
			for(int j=i+1;j<b.length;j++) // iterate through the array b
			{
				if(b[i]>b[j]) // if the value at the ith position in array b is greater than the value at the jth position in array b
				{
					temp = b[i]; // assign the value at the ith position in array b to temp
					b[i] = b[j]; // assign the value at the jth position in array b to the ith position in array b
					b[j] = temp; // assign the value at the temp position in array b to the jth position in array b
				}
			}
		}
	}
}


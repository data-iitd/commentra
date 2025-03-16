
import java.util.*;

public class Main {
	public static void main(String[] args){
		// Initialize answer variable and create a Scanner object
		int ans = 0;
		Scanner sc = new Scanner(System.in);

		// Read the number of elements in the list and create an array of integers with that size
		int n = sc.nextInt();
		int list[] = new int[n];
		
		// Read each element of the list into the array
		for(int i=0; i<n; i++){
			list[i] = sc.nextInt();
		}
		
		// Initialize two arrays of size 100000 to keep track of occurrences of integers in the list
		int numlist1[] = new int[100000];
		int numlist2[] = new int[100000];
		
		// Initialize all elements of the arrays to zero
		for(int i=0; i<100000; i++){
			numlist1[i] = 0;
			numlist2[i] = 0;
		}
		
		// Iterate through every other pair of elements in the list and increment the corresponding indices in the numlist1 and numlist2 arrays
		for(int i=0; i<n; i+=2){
			numlist1[list[i]-1] += 1;
			numlist2[list[i+1]-1] += 1;
		}
		
		// Initialize variables to store the maximum occurrences of integers in numlist1 and numlist2, and the indices of those integers
		int max11=0, max12=0, max21=0, max22=0;
		int val1=0, val2=0;
		
		// Iterate through all indices in numlist1 and numlist2 and update the variables if the current occurrence is greater than the previous maximum
		for(int i=0; i<100000; i++){
			if(numlist1[i] >= max11){
				// Update max12 and max11 with the current maximum and its previous maximum, and update val1 with the index of the maximum occurrence
				max12 = max11;
				max11 = numlist1[i];
				val1 = i;
			}
			else if(numlist1[i] >= max12){
				// Update max12 with the current maximum occurrence
				max12 = numlist1[i];
			}
			if(numlist2[i] >= max21){
				// Update max22 and max21 with the current maximum and its previous maximum, and update val2 with the index of the maximum occurrence
				max22 = max21;
				max21 = numlist2[i];
				val2 = i;
			}
			else if(numlist2[i] >= max22){
				// Update max22 with the current maximum occurrence
				max22 = numlist2[i];
			}
		}
		
		// Calculate the answer based on the maximum occurrences and indices of integers in numlist1 and numlist2
		if(val1 != val2){
			ans = n - max11 - max21;
		}
		else{
			ans = n - Math.max(max12+max21, max11+max22);
		}
		
		// Print the answer
		System.out.println(ans);
	}
}
import java.util.*;
public class Main {
	public static void main(String[] args){
		int ans = 0; // Initialize the answer variable to store the result
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt(); // Read the size of the list
		int list[] = new int[n]; // Declare and initialize the list array
		for(int i=0; i<n; i++){
			list[i] = sc.nextInt(); // Read the elements of the list
		}
		
		int numlist1[] = new int[100000]; // Declare numlist1 array of size 100000
		int numlist2[] = new int[100000]; // Declare numlist2 array of size 100000
		for(int i=0; i<100000; i++){
			numlist1[i] = 0; // Initialize numlist1 elements to 0
			numlist2[i] = 0; // Initialize numlist2 elements to 0
		}
		
		for(int i=0; i<n; i+=2){
			numlist1[list[i]-1] += 1; // Increment numlist1 for even index elements in list
			numlist2[list[i+1]-1] += 1; // Increment numlist2 for odd index elements in list
		}
		
		int max11=0, max12=0, max21=0, max22=0; // Initialize variables to store the max values
		int val1=0, val2=0; // Initialize variables to store the indices of the max values
		for(int i=0; i<100000; i++){
			if(numlist1[i] >= max11){
				max12 = max11; // Update the second max value
				max11 = numlist1[i]; // Update the max value
				val1 = i; // Update the index of the max value
			}
			else if(numlist1[i] >= max12){
				max12 = numlist1[i]; // Update the second max value
			}
			if(numlist2[i] >= max21){
				max22 = max21; // Update the second max value
				max21 = numlist2[i]; // Update the max value
				val2 = i; // Update the index of the max value
			}
			else if(numlist2[i] >= max22){
				max22 = numlist2[i]; // Update the second max value
			}
		}
		
		if(val1 != val2){
			ans = n - max11 - max21; // Calculate the answer if the indices are different
		}
		else{
			ans = n - Math.max(max12+max21, max11+max22); // Calculate the answer if the indices are the same
		}
		
		System.out.println(ans); // Print the final answer
	}
}

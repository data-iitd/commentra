
import java.util.*;

public class Main {

public static void main(String[] args) {

// Read the number of elements in the array
Scanner sc = new Scanner(System.in);
System.out.print("Enter the number of elements in the array: ");
int n = sc.nextInt();

// Initialize a for loop to read elements into the array and calculate sum
int[] a = new int[n];
long sum = 0;
for(int i = 0; i < n; i++){
// Read each element into the array
System.out.print("Enter element " + (i + 1) + ": ");
a[i] = sc.nextInt();

// Add the current element to the sum
sum += a[i];
}

// Initialize a for loop to find minimum and maximum elements in the array
int min = a[0], max = a[0];
for(int i = 1; i < n; i++){
// Initialize min and max with the first element of the array
if(a[i] > max)max = a[i];
if(a[i] < min)min = a[i];
}

// Print the minimum, maximum, and sum
System.out.println("Minimum element is " + min);
System.out.println("Maximum element is " + max);
System.out.println("Sum of all elements is " + sum);

// Return 0 to indicate successful execution
return 0;
}

}

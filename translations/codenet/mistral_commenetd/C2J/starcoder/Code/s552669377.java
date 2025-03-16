
import java.util.*;
// Include the standard input/output library

public class Main{
public static void main(String[] args){
// Function main starts the execution of the program
Scanner sc = new Scanner(System.in);
// Create a Scanner object to read from the standard input
int n, i, tmp; // Declare variables n, i, and tmp
long long int min = 1000000, max = -1000000, sum = 0; // Initialize variables min, max, and sum

n = sc.nextInt();
// Read the number of integers to be entered from the user
System.out.print("Enter the number of integers: ");
for(i=0;i<n;i++){
// Use a for loop to read and process each integer
tmp = sc.nextInt();
// Read the next integer from the user and store it in variable tmp
if(min>tmp)min=tmp;
// If the current integer is smaller than the current minimum, update the minimum
if(max<tmp)max=tmp;
// If the current integer is larger than the current maximum, update the maximum
sum+=tmp;
// Add the current integer to the sum
}

System.out.printf("%ld %ld %ld\n",min,max,sum);
// Print the minimum, maximum, and sum of the entered integers
}
}


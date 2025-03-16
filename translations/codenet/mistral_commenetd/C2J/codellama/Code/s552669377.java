
import java.util.Scanner;
// Import the Scanner class

public class Main {
// Declare a class Main
public static void main(String[] args) {
// Declare a function main
Scanner sc = new Scanner(System.in);
// Declare a Scanner object sc
int i, n, tmp;
// Declare variables i, n, and tmp
long min = 1000000, max = -1000000, sum = 0;
// Initialize variables min, max, and sum

System.out.print("Enter the number of integers: ");
n = sc.nextInt();
// Read the number of integers to be entered from the user
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

System.out.println(min+" "+max+" "+sum);
// Print the minimum, maximum, and sum of the entered integers
}
// Function main ends with a return statement
}


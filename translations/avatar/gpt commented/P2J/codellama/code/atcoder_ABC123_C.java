// Import necessary libraries
import java.util.Scanner;
import java.lang.Math;

// Read an integer input from the user
Scanner sc = new Scanner(System.in);
int N = sc.nextInt();

// Read 5 integer inputs from the user and store them in a list A
int[] A = new int[5];
for (int i = 0; i < 5; i++) {
    A[i] = sc.nextInt();
}

// Calculate the minimum value from the list A, divide N by this minimum value,
// take the ceiling of the result, and add 4 to it before printing the final result
System.out.println((int) Math.ceil((double) N / A[0]) + 4);


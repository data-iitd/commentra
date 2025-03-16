
// Import the Scanner class from the java.util package
import java.util.Scanner;

// Create a new Scanner object called sc
Scanner sc = new Scanner(System.in);

// Read an integer n from the standard input
int n = sc.nextInt();

// Create a new array a of size n
int[] a = new int[n];

// Read n integers from the standard input and store them in the array a
for (int i = 0; i < n; i++) {
    a[i] = sc.nextInt();
}

// Initialize two variables, pre and ans, to Integer.MAX_VALUE and 0, respectively
int pre = Integer.MAX_VALUE;
int ans = 0;

// Sort the array a in descending order using the Arrays.sort() method
Arrays.sort(a);

// Iterate through the array a using a for loop
for (int j = 0; j < n; j++) {
    // Calculate the maximum of 0 and the minimum of pre - 1 and a[j]. This value is added to ans.
    ans += Math.max(0, Math.min(pre - 1, a[j]));
    
    // Update the value of pre to be the minimum of pre - 1 and a[j].
    pre = Math.min(pre - 1, a[j]);
}

// After the loop, print the value of ans.
System.out.println(ans);


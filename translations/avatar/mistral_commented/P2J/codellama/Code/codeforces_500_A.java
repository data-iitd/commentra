// Importing the Scanner class
import java.util.Scanner;

// Creating a Scanner object
Scanner sc = new Scanner(System.in);

// Taking input for number of test cases and time limit
int n = sc.nextInt();
int t = sc.nextInt();

// Initializing an empty list to store the jumps
int[] s = new int[n];

// Taking input for the jumps
for (int i = 0; i < n; i++) {
    s[i] = sc.nextInt();
}

// Initializing the current cell position to 0
int currentCell = 0;

// Main logic of the program starts here
while (currentCell <= t) {
    // Incrementing the current cell position by the jump from the previous cell
    currentCell += s[currentCell - 1];

    // Checking if the current cell position is equal to the target position
    if (currentCell == t) {
        // If yes, then print "YES" and exit the program
        System.out.println("YES");
        sc.close();
        return;
    }

    // If not, then continue to the next iteration
    else {
        continue;
    }
}

// If the loop terminates without finding the target position, then print "NO"
System.out.println("NO");

sc.close();


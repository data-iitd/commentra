// Import the Math class for log2 function
import java.lang.Math;

// Take an integer input from the user and assign it to the variable n
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();

// Initialize a counter variable x to 1
int x = 1;

// While loop starts
while (true) {
    // Check if the log base 2 of n is an integer yet
    if (Math.log2(n) % 1 == 0) {
        break;
    }

    // Increment the counter variable x by 1
    x += 1;

    // Update the value of n by subtracting 2 raised to the power of the current log base 2 of n
    n -= (int) Math.pow(2, Math.log2(n));
}

// Print the output value of x
System.out.println(x);


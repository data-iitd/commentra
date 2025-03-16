// Define input variables
int N = Integer.parseInt(sc.nextLine());
int X = Integer.parseInt(sc.nextLine());
// Comment: Read input values N and X from the standard input

// Import java.util.Scanner for reading input
import java.util.Scanner;
// Comment: Import java.util.Scanner for reading input

// Define a function calc that takes an integer x as an argument
int calc(int x) {

    // Define a nested function sub that takes an integer y and an optional debug argument
    int sub(int y, boolean debug) {

        if (debug) {
            System.out.println("D " + y);
        }
        // If debug is set to true, print the intermediate values of y

        while (y > 1) {
            y = (int) Math.pow(3, y - 1);
            if (debug) {
                System.out.println("D " + y);
            }
        }
        // Calculate the result of the sub function

        return y;
    }
    // Return the result of the sub function

    int y = sub(x, false);
    // Calculate the result y of the sub function for the given input x

    if (y == 2) {
        sub(x - 1, true);
        System.out.println("=" + x);
    }
    // If the first element of y is 2, call the sub function recursively with x-1 and print x

    return y;
}
// Return the first element of the y list

if (X == 1 || X == N * 2 - 1) {
    // Check if X is equal to 1 or N*2-1

    System.out.println("No");
    // If it is, print "No"

} else {
    // Else, X is neither 1 nor N*2-1

    System.out.println("Yes");
    // Print "Yes"

    if (X == N * 2 - 2) {
        int[] xs = new int[N - 1];
        for (int i = 0; i < N - 1; i++) {
            xs[i] = i + 1;
        }
        xs[N - 2] = X + 2;
        xs[N - 1] = X - 1;
    } else {
        int[] ys = new int[N - 1];
        for (int i = 0; i < N - 1; i++) {
            ys[i] = i + 1;
        }
        int[] xs = new int[N];
        for (int i = 0; i < N - 3; i++) {
            xs[i] = ys[i];
        }
        xs[N - 3] = X + 2;
        xs[N - 2] = X - 1;
        xs[N - 1] = X;
    }
    // Calculate the list xs based on the value of X

    for (int x : xs) {
        System.out.println(x);
    }
    // Print each element of the list xs

}
// End of code

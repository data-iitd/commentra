
// Importing the Scanner class for reading input from the standard input
import java.util.Scanner;

// Assigning the function readLine to the variable input for reading lines from standard input
Scanner input = new Scanner(System.in);

// Initializing the arrays m and f with zeros for all indices up to N
int N = 368;
int[] m = new int[N];
int[] f = new int[N];

// Reading the number of operations from the standard input and processing each operation
for (int i = 0; i < input.nextInt(); i++) {
    // Reading an operation line and splitting it into components
    String[] operation = input.nextLine().split(" ");
    // Converting the components a and b to integers
    int a = Integer.parseInt(operation[0]);
    int b = Integer.parseInt(operation[1]) + 1;
    // If the operation is 'M', updating the m array accordingly
    if (operation[2].equals("M")) {
        m[a] += 2;
        m[b] -= 2;
    }
    // If the operation is 'F', updating the f array accordingly
    else {
        f[a] += 2;
        f[b] -= 2;
    }
}

// Initializing three variables a, b, and c with zeros
int a = 0, b = 0, c = 0;

// Calculating the prefix sums of m and f arrays
for (int i = 0; i < N; i++) {
    // Updating the variables a and b with the sum of m and f arrays respectively
    a += m[i];
    b += f[i];
    // Finding the minimum of a and b and updating the variable c if the minimum is greater than the current value of c
    if (Math.min(a, b) > c) {
        c = Math.min(a, b);
    }
}

// Printing the result, which is the minimum of the prefix sums of m and f arrays
System.out.println(c);


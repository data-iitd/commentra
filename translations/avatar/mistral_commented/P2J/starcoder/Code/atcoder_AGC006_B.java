// Define input variables
Scanner sc = new Scanner(System.in);
int N = sc.nextInt();
int X = sc.nextInt();
// Comment: Read input values N and X from the standard input

// Import itertools module for generating permutations
import java.util.stream.*;
// Comment: Import the Stream class from the Java standard library

// Define a function calc that takes an integer x as an argument
int calc(int x) {
// Define a nested function sub that takes an integer y and an optional debug argument
int sub(int y, boolean debug) {
    if (debug) {
        System.out.println("D " + y);
    }
    // If debug is set to True, print the intermediate values of y

    while (y.length > 1) {
        y = IntStream.range(0, y.length-2)
           .mapToObj(i -> IntStream.range(i, i+3).sorted().toArray())
           .map(a -> a[1])
           .toArray();
        if (debug) {
            System.out.println("D " + Arrays.toString(y));
        }
    }
    // Sort and select the middle element from sublists of length 3 in y

    return y[0];
}
// Return the result of the sub function

int y = sub(x);
// Calculate the result y of the sub function for the given input x

if (y == 2) {
    sub(x, true);
    System.out.println("= " + x);
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
        int[] xs = IntStream.range(N-1, X+2).toArray();
        xs = IntStream.concat(
            IntStream.range(1, N-1),
            IntStream.of(xs)
        ).toArray();
    } else {
        int[] ys = IntStream.range(1, X-1).toArray();
        ys = IntStream.concat(
            IntStream.of(ys),
            IntStream.range(X+3, N*2)
        ).toArray();
        int[] xs = Arrays.copyOf(ys, N-3);
        xs[N-3] = X+2;
        xs[N-2] = X-1;
        xs[N-1] = X;
        xs[N] = X+1;
        xs = IntStream.concat(
            IntStream.of(xs),
            IntStream.range(N+1, ys.length)
        ).toArray();
    }
    // Calculate the list xs based on the value of X

    for (int x : xs) {
        System.out.println(x);
    }
// Print each element of the list xs
}
// Comment: Print each element of the list xs


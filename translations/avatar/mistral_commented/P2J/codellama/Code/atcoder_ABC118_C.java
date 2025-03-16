// Ask the user for the number of elements in the list
Scanner scanner = new Scanner(System.in);
int N = scanner.nextInt();

// Get a list of integers from the user input
List<Integer> A = new ArrayList<>();
for (int i = 0; i < N; i++) {
    A.add(scanner.nextInt());
}

// Import the functools and fractions modules
import java.util.function.BinaryOperator;
import java.util.function.Function;
import java.util.function.UnaryOperator;

// Define a function to calculate the greatest common divisor (GCD) of two integers
public static int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Use reduce() from functools and gcd() from fractions to calculate the GCD of all integers in the list A
int gcd = A.stream().reduce(gcd).get();

// Print the result, which is the GCD of all the integers in the list A
System.out.println(gcd);


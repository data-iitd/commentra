// Ask the user for the number of elements in the list
int N = Integer.parseInt(input());

// Get a list of integers from the user input
List<Integer> A = Arrays.stream(input().split(" ")).map(Integer::parseInt).collect(Collectors.toList());

// Import the functools and fractions modules
import java.util.function.Function;
import java.util.function.BinaryOperator;

// Define a function to calculate the greatest common divisor (GCD) of two integers
Function<Integer, Function<Integer, Integer>> gcd = (a, b) -> (b == 0)? a : gcd.apply(b, a % b);

// Use reduce() from functools and gcd() from fractions to calculate the GCD of all integers in the list A
int gcd = A.stream().reduce(gcd.apply(A.get(0), A.get(1))).get();

// Print the result, which is the GCD of all the integers in the list A
System.out.println(gcd);


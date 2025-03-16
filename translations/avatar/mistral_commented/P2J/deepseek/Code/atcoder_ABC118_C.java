import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Ask the user for the number of elements in the list
        int N = scanner.nextInt();
        
        // Get a list of integers from the user input
        List<Integer> A = IntStream.range(0, N).map(i -> scanner.nextInt()).boxed().collect(Collectors.toList());
        
        // Define a method to calculate the greatest common divisor (GCD) of two integers
        int gcd = A.stream().reduce(0, (a, b) -> gcd(b, a % b));
        
        // Print the result, which is the GCD of all the integers in the list A
        System.out.println(gcd);
    }
    
    // Define a method to calculate the greatest common divisor (GCD) of two integers
    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}

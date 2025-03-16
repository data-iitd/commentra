import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt();
        
        // Calculate the greatest common divisor (gcd) using the Euclidean algorithm
        int gcdValue = gcd(360, x);
        
        // Calculate and print the number of equal parts in a full circle (360 degrees)
        // that can be formed with the given angle x using the gcd
        System.out.println(360 / gcdValue);
    }
    
    // Function to calculate the greatest common divisor (gcd) using the Euclidean algorithm
    public static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}

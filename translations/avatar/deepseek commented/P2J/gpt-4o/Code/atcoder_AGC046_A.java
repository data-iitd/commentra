import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Take an integer input x
        int x = scanner.nextInt();
        
        // Calculate the number of distinct cyclic permutations of a string of length x
        System.out.println(360 / gcd(360, x));
        
        scanner.close();
    }

    // Method to calculate the greatest common divisor (gcd)
    public static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}

// <END-OF-CODE>

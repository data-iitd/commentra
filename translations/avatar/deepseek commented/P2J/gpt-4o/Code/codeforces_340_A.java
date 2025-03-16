import java.util.Scanner;

public class Main {
    // Calculate the greatest common divisor (GCD) of a and b using the Euclidean algorithm
    public static int G(int a, int b) {
        while (a % b != 0) {
            int temp = a;
            a = b;
            b = temp % b;
        }
        return b;
    }

    // Calculate the least common multiple (LCM) of a and b using the relationship between GCD and LCM
    public static int L(int a, int b) {
        return a * (b / G(a, b));
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read four integers x, y, a, and b from the input
        String[] input = scanner.nextLine().split(" ");
        int x = Integer.parseInt(input[0]);
        int y = Integer.parseInt(input[1]);
        int a = Integer.parseInt(input[2]);
        int b = Integer.parseInt(input[3]);

        // Calculate the LCM of x and y
        int lcm = L(x, y);

        // Compute the number of integers in the range from a to b that are divisible by lcm
        // and print the result
        System.out.println(b / lcm - (a - 1) / lcm);
        
        scanner.close();
    }
}

// <END-OF-CODE>

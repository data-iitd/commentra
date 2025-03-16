
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read input values for costs of different types of drinks
        int q = sc.nextInt();
        int h = sc.nextInt();
        int s = sc.nextInt();
        int d = sc.nextInt();

        // Read the number of drinks to be purchased
        int n = sc.nextInt();

        // Calculate the best price for 1 liter of drink
        int best1L = Math.min(q * 4, h * 2, s);

        // Calculate the best price for 2 liters of drink
        int best2L = Math.min(d, best1L * 2);

        // Calculate and print the total cost based on whether n is even or odd
        if (n % 2 == 0) {
            System.out.println(best2L * (n / 2));  // Total cost for even number of drinks
        } else {
            System.out.println(best2L * (n / 2) + best1L);  // Total cost for odd number of drinks
        }
    }
}


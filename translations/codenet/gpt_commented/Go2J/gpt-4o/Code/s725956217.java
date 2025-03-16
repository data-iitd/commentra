import java.util.*;

public class Main {
    // Utility function to print output to the console.
    static void out(Object... x) {
        System.out.println(Arrays.toString(x));
    }

    // Class to represent a shop with a price (a) and available quantity (b).
    static class Shop {
        int a, b;

        Shop(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Scanner for reading input

        // Read the number of shops (N) and the total quantity needed (M)
        int N = sc.nextInt();
        int M = sc.nextInt();
        List<Shop> shops = new ArrayList<>(); // List to hold the shops

        // Read the price and quantity for each shop
        for (int i = 0; i < N; i++) {
            int a = sc.nextInt(); // Read price (a)
            int b = sc.nextInt(); // Read quantity (b)
            shops.add(new Shop(a, b)); // Store the shop information
        }

        // Sort the shops by price
        shops.sort(Comparator.comparingInt(shop -> shop.a));

        int total = 0; // Initialize total cost
        // Calculate the total cost based on available quantities and prices
        for (Shop shop : shops) {
            int n = Math.min(shop.b, M); // Determine how much can be bought from this shop
            total += n * shop.a; // Add to total cost
            M -= n; // Decrease the remaining quantity needed
            if (M == 0) {
                break; // Stop if the required quantity is met
            }
        }
        out(total); // Output the total cost
    }
}
// <END-OF-CODE>

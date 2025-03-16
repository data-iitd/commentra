import java.util.*;

public class Main {
    // Helper function to print output.
    public static void out(Object... x) {
        System.out.println(Arrays.deepToString(x));
    }

    // Function to read an integer from input.
    public static int getInt() {
        Scanner sc = new Scanner(System.in);
        return sc.nextInt();
    }

    // Function to read a string from input.
    public static String getString() {
        Scanner sc = new Scanner(System.in);
        return sc.nextLine();
    }

    // Function to return the maximum of two integers.
    public static int max(int a, int b) {
        return a > b ? a : b;
    }

    // Function to return the minimum of two integers.
    public static int min(int a, int b) {
        return a < b ? a : b;
    }

    // Function to return the absolute difference between two integers.
    public static int asub(int a, int b) {
        return a > b ? a - b : b - a;
    }

    // Function to return the absolute value of an integer.
    public static int abs(int a) {
        return a >= 0 ? a : -a;
    }

    // Struct to represent a shop with its price and stock.
    static class Shop {
        int a, b;

        Shop(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }

    // Comparator for sorting shops by price.
    static class ShopComparator implements Comparator<Shop> {
        public int compare(Shop s1, Shop s2) {
            return Integer.compare(s1.a, s2.a);
        }
    }

    // Main function to execute the program logic.
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();

        // Create a list of shops and read each shop's price and stock.
        List<Shop> shops = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            shops.add(new Shop(a, b));
        }

        // Sort the shops by price.
        Collections.sort(shops, new ShopComparator());

        // Calculate the total cost of buying the required number of items.
        int total = 0;
        for (Shop e : shops) {
            // Determine the number of items to buy from the current shop.
            int n = Math.min(e.b, M);
            // Update the total cost and the remaining items to buy.
            total += n * e.a;
            M -= n;
            // Break if all items are bought.
            if (M == 0) {
                break;
            }
        }

        // Print the total cost.
        out(total);
    }
}

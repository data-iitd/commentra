import java.util.*;

public class Main {
    // Helper function to print output.
    static void out(Object... x) {
        System.out.println(Arrays.toString(x));
    }

    // Function to read an integer from input.
    static int getInt(Scanner sc) {
        return Integer.parseInt(sc.next());
    }

    // Struct to represent a shop with its price and stock.
    static class Shop {
        int price, stock;

        Shop(int price, int stock) {
            this.price = price;
            this.stock = stock;
        }
    }

    // Main function to execute the program logic.
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the number of shops and the amount of items to buy.
        int N = getInt(sc);
        int M = getInt(sc);

        // Create a list of shops and read each shop's price and stock.
        List<Shop> shops = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            int a = getInt(sc);
            int b = getInt(sc);
            shops.add(new Shop(a, b));
        }

        // Sort the shops by price.
        shops.sort(Comparator.comparingInt(shop -> shop.price));

        // Calculate the total cost of buying the required number of items.
        int total = 0;
        for (Shop shop : shops) {
            // Determine the number of items to buy from the current shop.
            int n = Math.min(shop.stock, M);
            // Update the total cost and the remaining items to buy.
            total += n * shop.price;
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
// <END-OF-CODE>

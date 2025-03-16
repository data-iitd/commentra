
import java.util.*;

public class s725956217{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the number of shops and the amount of items to buy.
        int N = sc.nextInt();
        int M = sc.nextInt();

        // Create a list of shops and read each shop's price and stock.
        List<Shop> s = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            Shop shop = new Shop(a, b);
            s.add(shop);
        }

        // Sort the shops by price.
        Collections.sort(s);

        // Calculate the total cost of buying the required number of items.
        int total = 0;
        for (Shop shop : s) {
            // Determine the number of items to buy from the current shop.
            int n = Math.min(shop.b, M);
            // Update the total cost and the remaining items to buy.
            total += n * shop.a;
            M -= n;
            // Break if all items are bought.
            if (M == 0) {
                break;
            }
        }

        // Print the total cost.
        System.out.println(total);
    }

    // Struct to represent a shop with its price and stock.
    static class Shop implements Comparable<Shop> {
        int a;
        int b;

        public Shop(int a, int b) {
            this.a = a;
            this.b = b;
        }

        @Override
        public int compareTo(Shop o) {
            return this.a - o.a;
        }
    }
}

// End of code.
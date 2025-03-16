import java.util.*; // Importing the utility package for using Scanner
import static java.lang.System.*; // Importing System class for output

public class Main {
    public static void main(String[] args) {
        // Creating a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);
        
        // Reading the prices of different quantities of the item
        long Q = sc.nextLong(); // Price for 4 items
        long H = sc.nextLong(); // Price for 2 items
        long S = sc.nextLong(); // Price for 1 item
        long D = sc.nextLong(); // Price for 1 item when bought in pairs
        long N = sc.nextLong(); // Number of items to buy
        
        // Calculating the minimum price for a single item based on the given prices
        long onePrice = Math.min(Math.min(Q * 4, H * 2), S);
        
        // Checking if the price of one item is less than or equal to half the price of buying in pairs
        if ((double) onePrice <= (double) D / 2) {
            // If true, calculate the total cost for N items at the price of one item
            out.println(N * onePrice);
        } else {
            // If false, calculate the total cost using the pair price and the remaining single item price if N is odd
            out.println((N / 2) * D + (N % 2) * onePrice);
        }
    }
}

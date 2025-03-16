import java.util.Scanner;

public class TicketCostCalculator {
    public static final int DAYS = 365;  // Maximum number of days

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n;
        int[] nyuyoku_ticket = new int[DAYS];
        int[] pool_ticket = new int[DAYS];
        int[] nyuyoku_member = new int[DAYS];
        int[] pool_member = new int[DAYS];
        int[] seiki_ryoukin = new int[DAYS];
        int[] waribiki_ryoukin = new int[DAYS];
        int[] saiyasune = new int[DAYS];

        // Read the number of days
        n = scanner.nextInt();

        // Loop through each day
        for (int i = 0; i < n; i++) {
            // Read the ticket prices and usage counts for the day
            nyuyoku_ticket[i] = scanner.nextInt();
            pool_ticket[i] = scanner.nextInt();
            nyuyoku_member[i] = scanner.nextInt();
            pool_member[i] = scanner.nextInt();

            // Check if the group qualifies for a discount
            if (nyuyoku_member[i] >= 5 && pool_member[i] >= 2) {
                // Calculate the cost with the maximum discount
                seiki_ryoukin[i] = (nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * pool_member[i]) * 8 / 10;
                saiyasune[i] = seiki_ryoukin[i];
            } else if (nyuyoku_member[i] >= 5) {
                // Calculate the normal cost and the discounted cost if applicable
                seiki_ryoukin[i] = nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * pool_member[i];
                waribiki_ryoukin[i] = (nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * 2) * 8 / 10;
                saiyasune[i] = Math.min(seiki_ryoukin[i], waribiki_ryoukin[i]);
            } else if (pool_member[i] >= 2) {
                // Calculate the normal cost and the discounted cost if applicable
                seiki_ryoukin[i] = nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * pool_member[i];
                waribiki_ryoukin[i] = (nyuyoku_ticket[i] * 5 + pool_ticket[i] * pool_member[i]) * 8 / 10;
                saiyasune[i] = Math.min(seiki_ryoukin[i], waribiki_ryoukin[i]);
            } else {
                // Calculate the normal cost and the discounted cost if applicable
                seiki_ryoukin[i] = nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * pool_member[i];
                waribiki_ryoukin[i] = (nyuyoku_ticket[i] * 5 + pool_ticket[i] * 2) * 8 / 10;
                saiyasune[i] = Math.min(seiki_ryoukin[i], waribiki_ryoukin[i]);
            }
        }

        // Output the cheapest total cost for each day
        for (int i = 0; i < n; i++) {
            System.out.println(saiyasune[i]);
        }

        scanner.close();
    }
}
// <END-OF-CODE>

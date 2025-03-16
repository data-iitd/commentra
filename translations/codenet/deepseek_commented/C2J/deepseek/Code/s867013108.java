import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        final int DAYS = 365;  // Maximum number of days
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nyuyokuTicket = new int[DAYS];
        int[] poolTicket = new int[DAYS];
        int[] nyuyokuMember = new int[DAYS];
        int[] poolMember = new int[DAYS];
        int[] seikiRyoukin = new int[DAYS];
        int[] waribikiRyoukin = new int[DAYS];
        int[] saiyasune = new int[DAYS];

        // Loop through each day
        for (int i = 0; i < n; i++) {
            // Read the ticket prices and usage counts for the day
            nyuyokuTicket[i] = scanner.nextInt();
            poolTicket[i] = scanner.nextInt();
            nyuyokuMember[i] = scanner.nextInt();
            poolMember[i] = scanner.nextInt();

            // Check if the group qualifies for a discount
            if (nyuyokuMember[i] >= 5 && poolMember[i] >= 2) {
                // Calculate the cost with the maximum discount
                seikiRyoukin[i] = (nyuyokuTicket[i] * nyuyokuMember[i] + poolTicket[i] * poolMember[i]) * 8 / 10;
                saiyasune[i] = seikiRyoukin[i];
            } else if (nyuyokuMember[i] >= 5) {
                // Calculate the normal cost and the discounted cost if applicable
                seikiRyoukin[i] = nyuyokuTicket[i] * nyuyokuMember[i] + poolTicket[i] * poolMember[i];
                waribikiRyoukin[i] = (nyuyokuTicket[i] * nyuyokuMember[i] + poolTicket[i] * 2) * 8 / 10;
                saiyasune[i] = Math.min(seikiRyoukin[i], waribikiRyoukin[i]);
            } else if (poolMember[i] >= 2) {
                // Calculate the normal cost and the discounted cost if applicable
                seikiRyoukin[i] = nyuyokuTicket[i] * nyuyokuMember[i] + poolTicket[i] * poolMember[i];
                waribikiRyoukin[i] = (nyuyokuTicket[i] * 5 + poolTicket[i] * poolMember[i]) * 8 / 10;
                saiyasune[i] = Math.min(seikiRyoukin[i], waribikiRyoukin[i]);
            } else {
                // Calculate the normal cost and the discounted cost if applicable
                seikiRyoukin[i] = nyuyokuTicket[i] * nyuyokuMember[i] + poolTicket[i] * poolMember[i];
                waribikiRyoukin[i] = (nyuyokuTicket[i] * 5 + poolTicket[i] * 2) * 8 / 10;
                saiyasune[i] = Math.min(seikiRyoukin[i], waribikiRyoukin[i]);
            }
        }

        // Output the cheapest total cost for each day
        for (int i = 0; i < n; i++) {
            System.out.println(saiyasune[i]);
        }
    }
}

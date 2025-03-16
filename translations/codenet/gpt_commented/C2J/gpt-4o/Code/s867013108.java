import java.util.Scanner;

public class AizuOnsen {
    public static void main(String[] args) {
        final int DAYS = 365; // Maximum number of days
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt(); // Input the number of days for which prices need to be calculated
        int[] nyuyokuTicket = new int[DAYS]; // Array to store ticket prices for each day
        int[] poolTicket = new int[DAYS]; // Array to store ticket prices for each day
        int[] nyuyokuMember = new int[DAYS]; // Array to store the number of tickets used for each day
        int[] poolMember = new int[DAYS]; // Array to store the number of tickets used for each day
        int[] seikiRyoukin = new int[DAYS]; // Array to store calculated prices
        int[] waribikiRyoukin = new int[DAYS]; // Array to store discounted prices
        int[] saiyasune = new int[DAYS]; // Array to store the cheapest prices

        for (int i = 0; i < n; i++) {
            // Input ticket prices and the number of tickets used for the current day
            nyuyokuTicket[i] = scanner.nextInt();
            poolTicket[i] = scanner.nextInt();
            nyuyokuMember[i] = scanner.nextInt();
            poolMember[i] = scanner.nextInt();

            // Check if the discount condition for both tickets is met
            if (nyuyokuMember[i] >= 5 && poolMember[i] >= 2) {
                // Calculate the total price with discount
                seikiRyoukin[i] = (nyuyokuTicket[i] * nyuyokuMember[i] + poolTicket[i] * poolMember[i]) * 8 / 10;
                saiyasune[i] = seikiRyoukin[i]; // Store the discounted price
            }
            // Check if only the nyuyoku ticket discount condition is met
            else if (nyuyokuMember[i] >= 5) {
                // Calculate the total price without discount
                seikiRyoukin[i] = (nyuyokuTicket[i] * nyuyokuMember[i] + poolTicket[i] * poolMember[i]);
                // Calculate the price with discount for pool tickets
                waribikiRyoukin[i] = (nyuyokuTicket[i] * nyuyokuMember[i] + poolTicket[i] * 2) * 8 / 10;
                // Compare and store the cheaper option
                saiyasune[i] = Math.min(seikiRyoukin[i], waribikiRyoukin[i]);
            }
            // Check if only the pool ticket discount condition is met
            else if (poolMember[i] >= 2) {
                // Calculate the total price without discount
                seikiRyoukin[i] = (nyuyokuTicket[i] * nyuyokuMember[i] + poolTicket[i] * poolMember[i]);
                // Calculate the price with discount for nyuyoku tickets
                waribikiRyoukin[i] = (nyuyokuTicket[i] * 5 + poolTicket[i] * poolMember[i]) * 8 / 10;
                // Compare and store the cheaper option
                saiyasune[i] = Math.min(seikiRyoukin[i], waribikiRyoukin[i]);
            }
            // If no discount conditions are met
            else {
                // Calculate the total price without discount
                seikiRyoukin[i] = (nyuyokuTicket[i] * nyuyokuMember[i] + poolTicket[i] * poolMember[i]);
                // Calculate the price with discount for both tickets
                waribikiRyoukin[i] = (nyuyokuTicket[i] * 5 + poolTicket[i] * 2) * 8 / 10;
                // Compare and store the cheaper option
                saiyasune[i] = Math.min(seikiRyoukin[i], waribikiRyoukin[i]);
            }
        }
        // Output the cheapest total price for each day
        for (int i = 0; i < n; i++) {
            System.out.println(saiyasune[i]);
        }
        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Number of days for which prices need to be calculated
        int[] nyuyokuTicket = new int[365]; // Array to store nyuyoku ticket prices for each day
        int[] poolTicket = new int[365]; // Array to store pool ticket prices for each day
        int[] nyuyokuMember = new int[365]; // Array to store the number of nyuyoku tickets used for each day
        int[] poolMember = new int[365]; // Array to store the number of pool tickets used for each day
        int[] seikiRyoukin = new int[365]; // Array to store calculated prices without discount
        int[] waribikiRyoukin = new int[365]; // Array to store calculated prices with discount
        int[] saiyasune = new int[365]; // Array to store the cheapest total price for each day

        for (int i = 0; i < n; i++) {
            nyuyokuTicket[i] = scanner.nextInt(); // Input nyuyoku ticket price for the current day
            poolTicket[i] = scanner.nextInt(); // Input pool ticket price for the current day
            nyuyokuMember[i] = scanner.nextInt(); // Input the number of nyuyoku tickets used for the current day
            poolMember[i] = scanner.nextInt(); // Input the number of pool tickets used for the current day

            // Check if the discount condition for both tickets is met
            if (nyuyokuMember[i] >= 5 && poolMember[i] >= 2) {
                // Calculate the total price with discount
                seikiRyoukin[i] = ((nyuyokuTicket[i] * nyuyokuMember[i] + poolTicket[i] * poolMember[i]) * 8) / 10;
                saiyasune[i] = seikiRyoukin[i]; // Store the discounted price
            } else if (nyuyokuMember[i] >= 5) {
                // Calculate the total price without discount
                seikiRyoukin[i] = nyuyokuTicket[i] * nyuyokuMember[i] + poolTicket[i] * poolMember[i];
                // Calculate the price with discount for pool tickets
                waribikiRyoukin[i] = ((nyuyokuTicket[i] * nyuyokuMember[i] + poolTicket[i] * 2) * 8) / 10;
                // Compare and store the cheaper option
                saiyasune[i] = Math.min(seikiRyoukin[i], waribikiRyoukin[i]);
            } else if (poolMember[i] >= 2) {
                // Calculate the total price without discount
                seikiRyoukin[i] = nyuyokuTicket[i] * nyuyokuMember[i] + poolTicket[i] * poolMember[i];
                // Calculate the price with discount for nyuyoku tickets
                waribikiRyoukin[i] = ((nyuyokuTicket[i] * 5 + poolTicket[i] * poolMember[i]) * 8) / 10;
                // Compare and store the cheaper option
                saiyasune[i] = Math.min(seikiRyoukin[i], waribikiRyoukin[i]);
            } else {
                // Calculate the total price without discount
                seikiRyoukin[i] = nyuyokuTicket[i] * nyuyokuMember[i] + poolTicket[i] * poolMember[i];
                // Calculate the price with discount for both tickets
                waribikiRyoukin[i] = ((nyuyokuTicket[i] * 5 + poolTicket[i] * 2) * 8) / 10;
                // Compare and store the cheaper option
                saiyasune[i] = Math.min(seikiRyoukin[i], waribikiRyoukin[i]);
            }
        }

        // Output the cheapest total price for each day
        for (int i = 0; i < n; i++) {
            System.out.println(saiyasune[i]);
        }
    }
}

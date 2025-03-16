import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nyuyokuTicket = new int[365];
        int[] poolTicket = new int[365];
        int[] nyuyokuMember = new int[365];
        int[] poolMember = new int[365];
        int[] seikiRyoukin = new int[365];
        int[] waribikiRyoukin = new int[365];
        int[] saiyasune = new int[365];

        for (int i = 0; i < n; i++) {
            nyuyokuTicket[i] = scanner.nextInt();
            poolTicket[i] = scanner.nextInt();
            nyuyokuMember[i] = scanner.nextInt();
            poolMember[i] = scanner.nextInt();

            if (nyuyokuMember[i] >= 5 && poolMember[i] >= 2) {
                seikiRyoukin[i] = ((nyuyokuTicket[i] * nyuyokuMember[i] + poolTicket[i] * poolMember[i]) * 8) / 10;
                saiyasune[i] = seikiRyoukin[i];
            } else if (nyuyokuMember[i] >= 5) {
                seikiRyoukin[i] = nyuyokuTicket[i] * nyuyokuMember[i] + poolTicket[i] * poolMember[i];
                waribikiRyoukin[i] = ((nyuyokuTicket[i] * 5 + poolTicket[i] * poolMember[i]) * 8) / 10;
                saiyasune[i] = Math.min(seikiRyoukin[i], waribikiRyoukin[i]);
            } else if (poolMember[i] >= 2) {
                seikiRyoukin[i] = nyuyokuTicket[i] * nyuyokuMember[i] + poolTicket[i] * poolMember[i];
                waribikiRyoukin[i] = ((nyuyokuTicket[i] * 5 + poolTicket[i] * poolMember[i]) * 8) / 10;
                saiyasune[i] = Math.min(seikiRyoukin[i], waribikiRyoukin[i]);
            } else {
                seikiRyoukin[i] = nyuyokuTicket[i] * nyuyokuMember[i] + poolTicket[i] * poolMember[i];
                waribikiRyoukin[i] = ((nyuyokuTicket[i] * 5 + poolTicket[i] * 2) * 8) / 10;
                saiyasune[i] = Math.min(seikiRyoukin[i], waribikiRyoukin[i]);
            }
        }

        for (int i = 0; i < n; i++) {
            System.out.println(saiyasune[i]);
        }
    }
}

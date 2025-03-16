import java.util.Scanner;

public class AizuOnsen {
    public static void main(String[] args) {
        final int DAYS = 365; // 最大何日か？
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int[] nyuyokuTicket = new int[DAYS];
        int[] poolTicket = new int[DAYS];
        int[] nyuyokuMember = new int[DAYS];
        int[] poolMember = new int[DAYS];
        int[] seikiRyoukin = new int[DAYS];
        int[] waribikiRyoukin = new int[DAYS];
        int[] saiyasune = new int[DAYS];

        // 入場料金を入力受ける
        for (int i = 0; i < n; i++) {
            nyuyokuTicket[i] = scanner.nextInt();
            poolTicket[i] = scanner.nextInt();
            nyuyokuMember[i] = scanner.nextInt();
            poolMember[i] = scanner.nextInt();

            // 割引ルールをチェックして、最も安い合計料金を計算
            if (nyuyokuMember[i] >= 5 && poolMember[i] >= 2) {
                seikiRyoukin[i] = (nyuyokuTicket[i] * nyuyokuMember[i] + poolTicket[i] * poolMember[i]) * 8 / 10;
                saiyasune[i] = seikiRyoukin[i];
            } else if (nyuyokuMember[i] >= 5) {
                seikiRyoukin[i] = (nyuyokuTicket[i] * nyuyokuMember[i] + poolTicket[i] * poolMember[i]);
                waribikiRyoukin[i] = (nyuyokuTicket[i] * 5 + poolTicket[i] * poolMember[i]) * 8 / 10;
                saiyasune[i] = Math.min(seikiRyoukin[i], waribikiRyoukin[i]);
            } else if (poolMember[i] >= 2) {
                seikiRyoukin[i] = (nyuyokuTicket[i] * nyuyokuMember[i] + poolTicket[i] * poolMember[i]);
                waribikiRyoukin[i] = (nyuyokuTicket[i] * nyuyokuMember[i] + poolTicket[i] * 2) * 8 / 10;
                saiyasune[i] = Math.min(seikiRyoukin[i], waribikiRyoukin[i]);
            } else {
                seikiRyoukin[i] = (nyuyokuTicket[i] * nyuyokuMember[i] + poolTicket[i] * poolMember[i]);
                saiyasune[i] = seikiRyoukin[i];
            }
        }

        // 各日の最も安い合計料金を出力
        for (int i = 0; i < n; i++) {
            System.out.println(saiyasune[i]);
        }

        scanner.close();
    }
}
// <END-OF-CODE>

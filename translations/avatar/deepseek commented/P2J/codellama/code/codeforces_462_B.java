
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        String s = sc.next();
        int[] count = new int[26];
        for (int i = 0; i < s.length(); i++) {
            count[s.charAt(i) - 'A']++;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] >= k) {
                System.out.println(k * k);
                return;
            }
            k -= count[i];
        }
        System.out.println(k * k);
    }
}


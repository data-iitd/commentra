
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        sc.nextLine();
        String[] ds = sc.nextLine().split(" ");
        int[] dn = new int[ds.length];
        for (int i = 0; i < ds.length; i++) {
            dn[i] = Integer.parseInt(ds[i]);
        }
        int sum = 0;
        for (int i = 0; i < dn.length; i++) {
            for (int j = i + 1; j < dn.length; j++) {
                sum += dn[i] * dn[j];
            }
        }
        System.out.println(sum);
    }
}



import java.util.Scanner;

public class s692569558{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine();
        scanner.nextLine();
        String ds = scanner.nextLine();

        String[] dd = ds.split(" ");
        int[] dn = new int[dd.length];
        for (int i = 0; i < dd.length; i++) {
            dn[i] = Integer.parseInt(dd[i]);
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

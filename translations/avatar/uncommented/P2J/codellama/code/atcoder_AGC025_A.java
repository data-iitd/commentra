
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String n = sc.nextLine();
        String[] a = {"10", "100", "1000", "10000", "100000"};
        int new = 0;
        for (int i = 0; i < n.length(); i++) {
            new += Integer.parseInt(n.charAt(i) + "");
        }
        if (Arrays.asList(a).contains(n)) {
            System.out.println(10);
        } else {
            System.out.println(new);
        }
    }
}


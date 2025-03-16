
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int[] ns = new int[4];
        scanner.nextLine();
        String[] ns_str = scanner.nextLine().split(" ");
        for (int i = 0; i < ns.length; i++) {
            ns[i] = Integer.parseInt(ns_str[i]);
        }

        Arrays.sort(ns);
        if (ns[0] == 1 && ns[1] == 4 && ns[2] == 7 && ns[3] == 9) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}


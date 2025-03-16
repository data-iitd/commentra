
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] m = sc.nextLine().split(" ");
        boolean possible = true;
        for (String i : m) {
            if (m.length / 2 + 1 <= m.length) {
                possible = false;
                break;
            }
        }
        System.out.println(possible ? "YES" : "NO");
    }
}


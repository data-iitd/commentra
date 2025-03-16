
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();

        s = s.replace("dream", "D");
        s = s.replace("erase", "E");

        s = s.replace("Der", "");
        s = s.replace("Er", "");
        s = s.replace("D", "");
        s = s.replace("E", "");

        s = s.trim();

        if (s.equals("")) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}


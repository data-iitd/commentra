

import java.util.Scanner;

public class s876834921{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();

        s = s.replaceAll("dream", "D");
        s = s.replaceAll("erase", "E");
        s = s.replaceAll("Der", "");
        s = s.replaceAll("Er", "");
        s = s.trim();

        if (s.isEmpty()) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}


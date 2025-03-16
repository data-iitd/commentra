

import java.util.Scanner;

public class s079891640{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();

        for (int i = 0; i < s.length(); i++) {
            if (s.indexOf(s.charAt(i), i + 1)!= -1) {
                System.out.println("no");
                return;
            }
        }

        System.out.println("yes");
    }
}


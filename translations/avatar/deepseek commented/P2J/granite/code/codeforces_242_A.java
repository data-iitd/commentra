

import java.util.Scanner;

public class codeforces_242_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        scanner.close();
        java.util.ArrayList<String> games = new java.util.ArrayList<String>();
        for (int i = a; i <= x; i++) {
            if (i <= b) {
                continue;
            }
            for (int j = b; j <= y; j++) {
                if (i > j) {
                    games.add(i + " " + j);
                }
            }
        }
        System.out.println(games.size());
        for (String game : games) {
            System.out.println(game);
        }
    }
}

Translate the above Python code to C++ and end with comment "
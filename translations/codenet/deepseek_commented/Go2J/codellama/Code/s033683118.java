
package main;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        PrintWriter writer = new PrintWriter(System.out);
        int cnt = 0;

        if (System.getenv("MASPY") != null && System.getenv("MASPY").equals("ますピ")) {
            scanner = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
            cnt = 2;
        }
        if (System.getenv("MASPYPY") != null && System.getenv("MASPYPY").equals("ますピッピ")) {
            writer = new PrintWriter(System.out);
        }

        solve(scanner, writer);
        for (int i = 0; i < cnt; i++) {
            writer.println("-----------------------------------");
            solve(scanner, writer);
        }
        writer.flush();
    }

    public static void solve(Scanner scanner, PrintWriter writer) {
        int k = scanner.nextInt();
        int x = scanner.nextInt();

        String ans = "No";
        if (k * 500 >= x) {
            ans = "Yes";
        }
        writer.println(ans);
    }
}


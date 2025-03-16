import java.util.Scanner;

public class Main {
    static boolean debug = false;

    public static void log(String text) {
        if (debug) {
            System.out.println(text);
        }
    }

    public static String[] parseInput(String linesAsString) {
        String[] lines = linesAsString.split("\n");
        String c = lines[0].split(" ")[0];
        return new String[]{c};
    }

    public static char solve(char c) {
        String a = "abcdefghijklmnopqrstuvwxyz";
        int i = a.indexOf(c);
        return a.charAt(i + 1);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        char result = solve(parseInput(input)[0].charAt(0));
        System.out.println(result);
    }
}

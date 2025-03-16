import java.util.Scanner;

public class Main {
    static boolean debug = false;

    static void log(String text) {
        if (debug) {
            System.out.println(text);
        }
    }

    static String[] parseInput(String linesAsString) {
        String[] lines;
        if (linesAsString == null) {
            debug = false;
            Scanner scanner = new Scanner(System.in);
            lines = new String[]{scanner.nextLine()};
        } else {
            debug = true;
            lines = linesAsString.split("\n");
        }
        String c = lines[0].split(" ")[0];
        return new String[]{c};
    }

    static char solve(String c) {
        String a = "abcdefghijklmnopqrstuvwxyz";
        int i = a.indexOf(c);
        return a.charAt(i + 1);
    }

    public static void main(String[] args) {
        String[] input = parseInput(null);
        char result = solve(input[0]);
        System.out.print(result);
    }
}

// <END-OF-CODE>

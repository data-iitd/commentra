import java.io.*;
import java.util.Scanner;

public class Main {
    // getScanner initializes a new scanner to read input from a file.
    // It sets the split function to scan words and buffers the input to a specified size.
    private static Scanner getScanner(InputStream inputStream) {
        return new Scanner(inputStream);
    }

    // main function handles the program's flow.
    // It sets up the input and output files based on environment variables,
    // calls the solve function, and prints separators if necessary.
    public static void main(String[] args) throws IOException {
        InputStream inputStream = System.in;
        PrintWriter writer = new PrintWriter(System.out);
        int cnt = 0;

        String maspy = System.getenv("MASPY");
        String maspyPy = System.getenv("MASPYPY");
        
        if ("ますピ".equals(maspy)) {
            inputStream = new FileInputStream(System.getenv("BEET_THE_HARMONY_OF_PERFECT"));
            cnt = 2;
        }
        if ("ますピッピ".equals(maspyPy)) {
            writer = new PrintWriter(new FileOutputStream(System.getenv("NGTKANA_IS_GENIUS10")));
        }

        Scanner scanner = getScanner(inputStream);
        solve(scanner, writer);
        for (int i = 0; i < cnt; i++) {
            writer.println("-----------------------------------");
            solve(scanner, writer);
        }
        writer.flush();
    }

    // solve function reads two integers k and x, and determines if k * 500 is greater than or equal to x.
    // It writes "Yes" or "No" based on this condition.
    private static void solve(Scanner scanner, PrintWriter writer) {
        int k = scanner.nextInt();
        int x = scanner.nextInt();

        String ans = "No";
        if (k * 500 >= x) {
            ans = "Yes";
        }
        writer.println(ans);
    }
}

// <END-OF-CODE>

import java.io.*;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        int cnt = 0;

        if (System.getenv("MASPY").equals("ますピ")) {
            inputStream = new FileInputStream(System.getenv("BEET_THE_HARMONY_OF_PERFECT"));
            cnt = 2;
        }
        if (System.getenv("MASPYPY").equals("ますピッピ")) {
            outputStream = new FileOutputStream(System.getenv("NGTKANA_IS_GENIUS10"));
        }

        Scanner scanner = new Scanner(inputStream);
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(outputStream));
        solve(scanner, writer);
        for (int i = 0; i < cnt; i++) {
            writer.write("-----------------------------------\n");
            solve(scanner, writer);
        }
        writer.flush();
    }

    private static void solve(Scanner scanner, BufferedWriter writer) throws IOException {
        int k = scanner.nextInt();
        int x = scanner.nextInt();

        String ans = "No";
        if (k * 500 >= x) {
            ans = "Yes";
        }
        writer.write(ans + "\n");
    }
}

// <END-OF-CODE>

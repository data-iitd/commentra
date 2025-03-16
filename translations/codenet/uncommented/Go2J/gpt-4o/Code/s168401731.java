import java.io.*;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;

        if (args.length > 0) {
            inputStream = new FileInputStream(args[0]);
            if (args.length > 1) {
                outputStream = new FileOutputStream(args[1]);
            }
        }

        Scanner scanner = new Scanner(inputStream);
        PrintWriter writer = new PrintWriter(outputStream);

        int n = scanner.nextInt();
        String ans = "second";

        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt();
            if (a % 2 == 1) {
                ans = "first";
                break;
            }
        }

        writer.println(ans);
        writer.flush();
        scanner.close();
        writer.close();
    }
}

// <END-OF-CODE>

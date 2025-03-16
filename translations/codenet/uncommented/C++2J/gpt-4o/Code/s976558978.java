import java.io.*;
import java.util.*;

public class Main {
    private static final double PI = 3.141592653589793238462643383279502884197169399375105820974;
    private static final int ten5p1 = 100001;
    private static final int ten6p1 = 1000001;
    private static final int ten8p1 = 100000001;
    private static final int ten9p1 = 1000000001;

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter writer = new PrintWriter(System.out);

        int a = Integer.parseInt(reader.readLine());
        int b = Integer.parseInt(reader.readLine());

        if (a < b) {
            for (int i = 0; i < b; i++) {
                writer.print(a);
                writer.print(" ");
            }
            writer.println();
        } else {
            for (int i = 0; i < a; i++) {
                writer.print(b);
                writer.print(" ");
            }
            writer.println();
        }

        writer.flush();
        writer.close();
        reader.close();
    }
}

//<END-OF-CODE>

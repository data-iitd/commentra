import java.io.*;
import java.util.*;

public class Main {
    /*
    This is the main Java file for solving a problem. Replace URL_HERE with the URL of the problem statement.
    */

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter writer = new PrintWriter(System.out);

        int a = Integer.parseInt(reader.readLine());
        int b = Integer.parseInt(reader.readLine());
        /*
        Read the two integers a and b from the input.
        */

        if (a < b) {
            for (int i = 0; i < b; i++) {
                writer.print(a);
                if (i < b - 1) writer.print(" ");
            }
            writer.println();
            /*
            If a is smaller than b, print a b times.
            */
        } else {
            for (int i = 0; i < a; i++) {
                writer.print(b);
                if (i < a - 1) writer.print(" ");
            }
            writer.println();
            /*
            If b is smaller than a, print b a times.
            */
        }

        writer.close();
    }
}

/*

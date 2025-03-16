import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long k = scanner.nextLong();
        long a = scanner.nextLong();
        long b = scanner.nextLong();

        for (long i = a; i <= b; ++i) {
            if (i % k == 0) {
                System.out.println("OK");
                return;
            }
        }

        System.out.println("NG");
    }
}

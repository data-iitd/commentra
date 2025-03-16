import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int k = scanner.nextInt();
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        for (int i = a; i <= b; i++) {
            if (i % k == 0) {
                System.out.println("OK");
                return;
            }
        }
        System.out.println("NG");
    }
}

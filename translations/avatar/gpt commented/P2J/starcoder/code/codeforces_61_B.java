import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            String s1 = sc.next();
            String s2 = sc.next();
            String s3 = sc.next();
            String s = s1 + s2 + s3;
            s = s.toLowerCase();
            s = s.replaceAll("-", "");
            s = s.replaceAll(";", "");
            s = s.replaceAll("_", "");
            if (s.equals("hackerrank")) {
                System.out.println("ACC");
            } else {
                System.out.println("WA");
            }
        }
    }
}


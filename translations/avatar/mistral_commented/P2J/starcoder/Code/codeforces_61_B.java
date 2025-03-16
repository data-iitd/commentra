
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
            int n = sc.nextInt();
            while (n-- > 0) {
                String s4 = sc.next();
                if (s.contains(s4)) {
                    System.out.println("ACC");
                } else {
                    System.out.println("WA");
                }
            }
        }
    }
}



import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tcs = sc.nextInt();
        int tc = 1;
        while (tc <= tcs) {
            int a = sc.nextInt();
            if (a == 0) {
                System.out.println(1);
            } else {
                System.out.println(0);
            }
            tc++;
        }
    }
}


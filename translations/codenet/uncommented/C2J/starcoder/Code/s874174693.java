
import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int sum = 0;
        int m = n;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        if (m % sum == 0) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}


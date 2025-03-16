
import java.util.*;
import java.io.*;

public class s940603045{
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String N = in.nextLine();
        int sum = 0;
        for (int i = 0; i < N.length(); i++) {
            sum += N.charAt(i) - '0';
        }
        int m = Integer.parseInt(N);
        if (m % sum == 0) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}


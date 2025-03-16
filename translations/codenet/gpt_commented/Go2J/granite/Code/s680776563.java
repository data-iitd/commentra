
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class s680776563{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        int C = scanner.nextInt();
        if (B - A == C - B) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}

// 
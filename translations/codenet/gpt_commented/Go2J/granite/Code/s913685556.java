
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class s913685556{
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int A = sc.nextInt();
        int B = sc.nextInt();
        int mx = Math.max(A + B, A - B);
        mx = Math.max(mx, A * B);
        System.out.println(mx);
    }
}

// 
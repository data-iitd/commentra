
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = 368;
        int[] m = new int[N];
        int[] f = new int[N];
        int numOfOperations = sc.nextInt();
        for (int i = 0; i < numOfOperations; i++) {
            String gender = sc.next();
            int startTime = sc.nextInt();
            int endTime = sc.nextInt() + 1;
            if (gender.equals("M")) {
                m[startTime] += 2;
                m[endTime] -= 2;
            } else {
                f[startTime] += 2;
                f[endTime] -= 2;
            }
        }
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < N; i++) {
            a += m[i];
            b += f[i];
            if (Math.min(a, b) > c) {
                c = Math.min(a, b);
            }
        }
        System.out.println(c);
    }
}


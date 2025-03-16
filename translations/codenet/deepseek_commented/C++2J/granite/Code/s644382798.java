
import java.util.Scanner;

public class s644382798{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int q = scanner.nextInt();
        String[] name = new String[n];
        int[] t = new int[n];
        for (int i = 0; i < n; i++) {
            name[i] = scanner.next();
            t[i] = scanner.nextInt();
        }
        int head = 0;
        int tail = n;
        int elaps = 0;
        int c;
        String uName;
        int uTime;
        while (head!= tail) {
            uName = name[head];
            uTime = t[head];
            c = Math.min(q, uTime);
            uTime -= c;
            elaps += c;
            if (uTime > 0) {
                name[--tail] = uName;
                t[tail] = uTime;
            } else {
                System.out.println(uName + " " + elaps);
            }
            head++;
        }
    }
}

Translate the above Java code to Python and end with comment "
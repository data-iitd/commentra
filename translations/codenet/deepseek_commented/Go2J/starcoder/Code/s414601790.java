import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s = sc.next();

        int max = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            char r = s.charAt(i);
            if (r == 'I') {
                cnt++;
            } else {
                cnt--;
            }

            if (cnt > max) {
                max = cnt;
            }
        }

        System.out.println(max);
    }
}


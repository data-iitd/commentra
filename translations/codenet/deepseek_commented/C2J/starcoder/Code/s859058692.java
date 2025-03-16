import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long sum = 0;
        int m, i, min, max;
        for(i = 0; i < n; i++) {
            m = sc.nextInt();
            sum += m;
            if(i == 0) {
                min = m;
                max = m;
            }
            if(min > m) {
                min = m;
            }
            if(max < m) {
                max = m;
            }
        }
        System.out.println(min + " " + max + " " + sum);
    }
}

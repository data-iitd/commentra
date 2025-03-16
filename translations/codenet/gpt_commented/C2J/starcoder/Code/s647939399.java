import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a, b, c, i, j;
        char m;
        for(i = 0; i > -1; i++) {
            a = sc.nextInt();
            m = sc.next().charAt(0);
            b = sc.nextInt();
            if(m == '?') {
                break;
            }
            if(m == '+') {
                c = a + b;
            }
            if(m == '-') {
                c = a - b;
            }
            if(m == '*') {
                c = a * b;
            }
            if(m == '/') {
                c = a / b;
            }
            System.out.println(c);
        }
    }
}

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        final int N = 1000;
        char[] su = new char[N];
        int susum = 0;

        while (true) {
            int j = 0;
            while (j < N) {
                su[j] = scanner.next().charAt(0);
                if (su[j] == '\n') break;
                susum += (su[j] - '0');
                j++;
            }
            if (su[0] == '0') break;
            System.out.println(susum);
            susum = 0;
        }
        scanner.close();
    }
}
// <END-OF-CODE>

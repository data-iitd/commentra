import java.util.Scanner;

public class Main {
    public static void solve(int tc) {
        Scanner scanner = new Scanner(System.in);
        int a = Integer.parseInt(scanner.nextLine().trim());
        System.out.println(a == 0 ? 1 : 0);
    }

    public static void main(String[] args) {
        int tcs = 1;
        int tc = 1;
        while (tc <= tcs) {
            solve(tc);
            tc++;
        }
    }
}

// <END-OF-CODE>

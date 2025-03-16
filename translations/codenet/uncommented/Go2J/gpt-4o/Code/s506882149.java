import java.util.Scanner;

public class Main {
    public static int comp(int x, int a) {
        if (x < a) {
            return 0;
        }
        return 10;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt();
        int a = scanner.nextInt();
        
        System.out.println(comp(x, a));
    }
}

// <END-OF-CODE>

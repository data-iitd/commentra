import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        char B = scanner.next().charAt(0);
        char OUT;

        if (B == 'A') {
            OUT = 'T';
        } else if (B == 'T') {
            OUT = 'A';
        } else if (B == 'C') {
            OUT = 'G';
        } else {
            OUT = 'C';
        }

        System.out.println(OUT);
        scanner.close();
    }
}

// <END-OF-CODE>

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        int acCount = 0;
        int waCount = 0;
        int tleCount = 0;
        int reCount = 0;

        for (int i = 0; i < n; ++i) {
            String s = scanner.nextLine();
            if (s.equals("AC")) {
                acCount += 1;
            } else if (s.equals("WA")) {
                waCount += 1;
            } else if (s.equals("TLE")) {
                tleCount += 1;
            } else if (s.equals("RE")) {
                reCount += 1;
            }
        }

        System.out.println("AC x " + acCount);
        System.out.println("WA x " + waCount);
        System.out.println("TLE x " + tleCount);
        System.out.println("RE x " + reCount);
        
        scanner.close();
    }
}

// <END-OF-CODE>

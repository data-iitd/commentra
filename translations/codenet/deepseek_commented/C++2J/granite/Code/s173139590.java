
import java.util.Scanner;

public class s173139590{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int acCount = 0;
        int waCount = 0;
        int tleCount = 0;
        int reCount = 0;
        for (int i = 0; i < n; i++) {
            String s = scanner.next();
            if (s.equals("AC")) {
                acCount++;
            } else if (s.equals("WA")) {
                waCount++;
            } else if (s.equals("TLE")) {
                tleCount++;
            } else if (s.equals("RE")) {
                reCount++;
            }
        }
        System.out.println("AC x " + acCount);
        System.out.println("WA x " + waCount);
        System.out.println("TLE x " + tleCount);
        System.out.println("RE x " + reCount);
    }
}

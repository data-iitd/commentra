import java.util.Scanner;

public class TimeDifference {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String time1 = scanner.nextLine();
        String time2 = scanner.nextLine();
        
        String[] parts1 = time1.split(":");
        int h1 = Integer.parseInt(parts1[0]);
        int m1 = Integer.parseInt(parts1[1]);
        
        String[] parts2 = time2.split(":");
        int h2 = Integer.parseInt(parts2[0]);
        int m2 = Integer.parseInt(parts2[1]);
        
        m1 += h1 * 60;
        m2 += h2 * 60;
        
        int diff = m1 - m2;
        diff = (diff + 1440) % 1440; // Ensure the difference is positive
        
        System.out.printf("%02d:%02d%n", diff / 60, diff % 60);
    }
}

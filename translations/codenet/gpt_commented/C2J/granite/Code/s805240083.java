
import java.util.Scanner;

public class s805240083{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int q = scanner.nextInt();
        String[] names = new String[n];
        int[] times = new int[n];
        for (int i = 0; i < n; i++) {
            names[i] = scanner.next();
            times[i] = scanner.nextInt();
        }
        int head = 0;
        int tail = 0;
        int totalTime = 0;
        for (int i = 0; i < n; i++) {
            int time = times[i];
            while (time > q) {
                time -= q;
                totalTime += q;
            }
            totalTime += time;
            System.out.println(names[i] + " " + totalTime);
        }
    }
}

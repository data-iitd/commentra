
import java.util.Scanner;

public class s266720248{
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
        int tail = n;
        int elaps = 0;
        while (head < tail) {
            String name = names[head];
            int time = times[head];
            int c = Math.min(q, time);
            time -= c;
            elaps += c;
            if (time > 0) {
                names[tail] = name;
                times[tail] = time;
                tail++;
            } else {
                System.out.println(name + " " + elaps);
            }
            head++;
        }
    }
}

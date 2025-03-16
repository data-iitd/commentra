
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
        int c;
        String name;
        int time;
        while (head < tail) {
            name = names[head];
            time = times[head];
            c = Math.min(q, time);
            time -= c;
            elaps += c;
            if (time > 0) {
                names[--head] = name;
                times[head] = time;
            } else {
                System.out.println(name + " " + elaps);
                head++;
            }
        }
    }
}

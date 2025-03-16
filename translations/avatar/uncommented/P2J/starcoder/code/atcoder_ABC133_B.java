import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int d = sc.nextInt();
        int count = 0;
        ArrayList<Integer> points = new ArrayList<Integer>();
        for (int i = 0; i < n; i++) {
            points.add(sc.nextInt());
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (Math.sqrt(Math.pow(points.get(i) - points.get(j), 2)) % 1 == 0) {
                    count++;
                }
            }
        }
        System.out.println(count);
    }
}

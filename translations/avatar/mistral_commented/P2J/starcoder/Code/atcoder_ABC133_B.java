
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int d = sc.nextInt();

        List<List<Integer>> points = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            points.add(new ArrayList<>());
            for (int j = 0; j < d; j++) {
                points.get(i).add(sc.nextInt());
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (Math.abs(dist(points.get(i), points.get(j))) == 0) {
                    count++;
                }
            }
        }

        System.out.println(count);
    }

    public static double dist(List<Integer> x, List<Integer> y) {
        double tmp = 0.0;
        for (int i = 0; i < x.size(); i++) {
            tmp += Math.pow(x.get(i) - y.get(i), 2);
        }
        return Math.sqrt(tmp);
    }
}


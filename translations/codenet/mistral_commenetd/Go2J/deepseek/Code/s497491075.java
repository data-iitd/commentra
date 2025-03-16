import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        new Main().run(System.in, System.out);
    }

    void run(InputStream in, OutputStream out) {
        Scanner sc = new Scanner(in);
        PrintWriter pw = new PrintWriter(out);

        int N = sc.nextInt();
        int D = sc.nextInt();

        List<int[]> points = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            points.add(new int[]{sc.nextInt(), sc.nextInt()});
        }

        int count = 0;
        for (int[] point : points) {
            double distance = Math.sqrt(point[0] * point[0] + point[1] * point[1]);
            if (distance <= D) {
                count++;
            }
        }

        pw.println(count);
        pw.flush();
    }
}

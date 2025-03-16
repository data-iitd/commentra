import java.util.*;

class Edge implements Comparable<Edge> {
    long p;
    int i;
    String s;

    Edge(String s, long p, int i) {
        this.s = s;
        this.p = p;
        this.i = i;
    }

    @Override
    public int compareTo(Edge other) {
        int strComp = this.s.compareTo(other.s);
        if (strComp != 0) {
            return strComp;
        }
        if (this.p < other.p) {
            return 1;
        } else {
            return -1;
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Edge[] data = new Edge[n];
        for (int i = 0; i < n; i++) {
            String s = scanner.next();
            long p = scanner.nextLong();
            data[i] = new Edge(s, p, i);
        }
        Arrays.sort(data);
        for (int i = 0; i < n; i++) {
            System.out.println(data[i].i + 1);
        }
    }
}

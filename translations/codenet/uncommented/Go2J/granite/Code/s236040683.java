
import java.util.Scanner;

public class s236040683{

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();
        Node[] n = new Node[N];
        for (int i = 0; i < M; i++) {
            int from = sc.nextInt() - 1;
            int to = sc.nextInt() - 1;
            n[from].to.add(to);
            n[to].to.add(from);
        }

        for (int i = 0; i < N; i++) {
            System.out.println(n[i].to.size());
        }
    }

    static class Node {
        List<Integer> to = new ArrayList<>();
    }
}


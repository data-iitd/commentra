import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    static class Node {
        List<Integer> to = new ArrayList<>();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        int M = sc.nextInt();
        Node[] nodes = new Node[N];
        
        for (int i = 0; i < N; i++) {
            nodes[i] = new Node();
        }
        
        for (int i = 0; i < M; i++) {
            int from = sc.nextInt() - 1;
            int to = sc.nextInt() - 1;
            nodes[from].to.add(to);
            nodes[to].to.add(from);
        }

        for (int i = 0; i < N; i++) {
            System.out.println(nodes[i].to.size());
        }
        
        sc.close();
    }
}

// <END-OF-CODE>

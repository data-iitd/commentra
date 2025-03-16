
import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;

public class s525470559{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int q = sc.nextInt();
        int elaps = 0;
        Queue<String> Q = new LinkedList<>();

        for(int i = 0; i < n; i++) {
            String name = sc.next();
            int time = sc.nextInt();
            Q.add(name);
        }

        while(!Q.isEmpty()) {
            String name = Q.peek();
            int time = sc.nextInt();
            if(time <= q) {
                elaps += time;
                System.out.println(name + " " + elaps);
            }
            else {
                time -= q;
                elaps += q;
                Q.add(name);
            }
            Q.remove();
        }
    }
}

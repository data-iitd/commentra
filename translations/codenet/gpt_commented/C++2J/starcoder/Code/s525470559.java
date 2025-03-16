import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int q = sc.nextInt();
        int elaps = 0;
        Queue<task> Q = new LinkedList<task>();

        for(int i = 0; i < n; i++) {
            task tmp = new task();
            tmp.name = sc.next();
            tmp.time = sc.nextInt();
            Q.add(tmp);
        }

        while(!Q.isEmpty()) {
            task p = Q.peek();
            Q.remove();

            if(p.time <= q) {
                elaps += p.time;
                System.out.println(p.name + " " + elaps);
            }
            else {
                p.time -= q;
                elaps += q;
                Q.add(p);
            }
        }
    }
}


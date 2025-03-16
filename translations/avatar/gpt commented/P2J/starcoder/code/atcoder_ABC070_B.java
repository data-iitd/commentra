import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<Integer> A = new ArrayList<Integer>();
        for (int i = 0; i < 4; i++) {
            A.add(sc.nextInt());
        }
        if (A.get(1) <= A.get(2) || A.get(3) <= A.get(0)) {
            System.out.println(0);
        } else {
            Collections.sort(A);
            System.out.println(A.get(2) - A.get(1));
        }
    }
}

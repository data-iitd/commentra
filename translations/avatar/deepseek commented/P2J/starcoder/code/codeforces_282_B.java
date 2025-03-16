
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int firstline = sc.nextInt();
        int total = 0;
        List<String> memory = new ArrayList<>();

        for (int x = 0; x < firstline; x++) {
            int A = sc.nextInt();
            int G = sc.nextInt();
            if (total + A <= 500) {
                total += A;
                memory.add("A");
            } else {
                total -= G;
                memory.add("G");
            }
        }

        System.out.println(String.join("", memory));
    }
}


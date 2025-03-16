
import java.util.Arrays;
import java.util.Scanner;

public class s385901297{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int[] ns = new int[4];
        String[] nsStr = scanner.nextLine().split(" ");
        for (int i = 0; i < 4; i++) {
            ns[i] = Integer.parseInt(nsStr[i]);
        }

        Arrays.sort(ns);
        if (ns[0] == 1 && ns[1] == 4 && ns[2] == 7 && ns[3] == 9) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}

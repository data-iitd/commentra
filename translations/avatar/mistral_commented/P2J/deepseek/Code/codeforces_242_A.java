import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");
        int x = Integer.parseInt(input[0]);
        int y = Integer.parseInt(input[1]);
        int a = Integer.parseInt(input[2]);
        int b = Integer.parseInt(input[3]);

        List<int[]> games = new ArrayList<>();

        for (int i = a; i <= x; i++) {
            if (i <= b) {
                continue;
            }
            for (int j = b; j <= y; j++) {
                if (i > j) {
                    int[] game = {i, j};
                    games.add(game);
                }
            }
        }

        System.out.println(games.size());
        for (int[] game : games) {
            System.out.println(game[0] + " " + game[1]);
        }
    }
}

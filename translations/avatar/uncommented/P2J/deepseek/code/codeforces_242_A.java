import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        
        List<int[]> games = new ArrayList<>();
        
        for (int i = a; i <= x; i++) {
            if (i > b) {
                for (int j = b; j <= y; j++) {
                    if (i > j) {
                        int[] game = {i, j};
                        games.add(game);
                    }
                }
            }
        }
        
        System.out.println(games.size());
        for (int[] game : games) {
            System.out.println(game[0] + " " + game[1]);
        }
    }
}

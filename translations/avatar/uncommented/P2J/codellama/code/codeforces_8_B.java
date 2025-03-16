
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String record_of_movements = sc.nextLine();
        int x = 0, y = 0;
        int[][] d_movement = { { 0, -1 }, { 0, 1 }, { 1, 0 }, { -1, 0 } };
        boolean[][] d = new boolean[100][100];
        boolean bug = false;
        for (int i = 0; i < record_of_movements.length(); i++) {
            int tempX = x;
            int tempY = y;
            x += d_movement[record_of_movements.charAt(i) - 'A'][0];
            y += d_movement[record_of_movements.charAt(i) - 'A'][1];
            if (x >= 0 && x < 100 && y >= 0 && y < 100) {
                if (d[x][y]) {
                    bug = true;
                    break;
                } else {
                    d[x][y] = true;
                }
            } else {
                bug = true;
                break;
            }
            if (bug) {
                break;
            }
        }
        if (bug) {
            System.out.println("BUG");
        } else {
            System.out.println("OK");
        }
    }
}


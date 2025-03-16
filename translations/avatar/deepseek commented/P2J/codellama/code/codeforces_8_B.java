
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
            int temp_x = x, temp_y = y;
            x += d_movement[record_of_movements.charAt(i) - 'A'][0];
            y += d_movement[record_of_movements.charAt(i) - 'A'][1];

            if (!d[x][y]) {
                for (int j = 0; j < 4; j++) {
                    if (x + d_movement[j][0] != temp_x || y + d_movement[j][1] != temp_y) {
                        if (d[x + d_movement[j][0]][y + d_movement[j][1]]) {
                            bug = true;
                            break;
                        }
                    }
                }
            } else {
                bug = true;
            }

            if (bug) {
                break;
            }

            d[x][y] = true;
        }

        if (bug) {
            System.out.println("BUG");
        } else {
            System.out.println("OK");
        }
    }
}


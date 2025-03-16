import java.util.HashMap;
import java.util.Scanner;

public class MovementTracker {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String recordOfMovements = scanner.nextLine();
        int x = 0, y = 0;
        HashMap<String, int[]> dMovement = new HashMap<>();
        dMovement.put("L", new int[]{0, -1});
        dMovement.put("R", new int[]{0, 1});
        dMovement.put("U", new int[]{1, 0});
        dMovement.put("D", new int[]{-1, 0});

        HashMap<String, String> d = new HashMap<>();
        d.put(x + "," + y, "");
        boolean bug = false;

        for (char move : recordOfMovements.toCharArray()) {
            int[] temp = new int[]{x, y};
            x += dMovement.get(String.valueOf(move))[0];
            y += dMovement.get(String.valueOf(move))[1];
            String currentPosition = x + "," + y;
            if (!d.containsKey(currentPosition)) {
                for (String step : dMovement.keySet()) {
                    int[] direction = dMovement.get(step);
                    String nextPosition = (x + direction[0]) + "," + (y + direction[1]);
                    if (!nextPosition.equals(x + "," + y) && d.containsKey(nextPosition)) {
                        bug = true;
                        break;
                    }
                }
            } else {
                bug = true;
            }
            if (bug) {
                break;
            }
            d.put(currentPosition, "");
        }

        if (bug) {
            System.out.println("BUG");
        } else {
            System.out.println("OK");
        }
    }
}

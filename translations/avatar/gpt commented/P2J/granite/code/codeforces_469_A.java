
import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;

public class codeforces_469_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int maxLevel = scanner.nextInt();
        Set<Integer> xLevels = new HashSet<>();
        Set<Integer> yLevels = new HashSet<>();
        int xCount = scanner.nextInt();
        for (int i = 0; i < xCount; i++) {
            xLevels.add(scanner.nextInt());
        }
        int yCount = scanner.nextInt();
        for (int i = 0; i < yCount; i++) {
            yLevels.add(scanner.nextInt());
        }
        xLevels.remove(0);
        yLevels.remove(0);
        xLevels.addAll(yLevels);
        if (xLevels.size()!= maxLevel) {
            System.out.println("Oh, my keyboard!");
        } else {
            System.out.println("I become the guy.");
        }
    }
}

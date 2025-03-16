import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<List<String>> t = new ArrayList<>();
        
        for (int i = 0; i < 4; i++) {
            List<String> l = new ArrayList<>();
            String line = scanner.nextLine();
            for (char c : line.toCharArray()) {
                l.add(String.valueOf(c));
            }
            t.add(l);
        }
        
        int black = 0;
        int white = 0;
        boolean correct = false;
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                black = 0;
                white = 0;
                
                if (t.get(i).get(j).equals("#")) {
                    black++;
                } else {
                    white++;
                }
                
                if (t.get(i).get(j + 1).equals("#")) {
                    black++;
                } else {
                    white++;
                }
                
                if (t.get(i + 1).get(j).equals("#")) {
                    black++;
                } else {
                    white++;
                }
                
                if (t.get(i + 1).get(j + 1).equals("#")) {
                    black++;
                } else {
                    white++;
                }
                
                if (black == 0 || black == 3 || white == 0 || white == 3 || white == 4 || black == 4) {
                    correct = true;
                    break;
                }
            }
            if (correct) {
                break;
            }
        }
        
        if (correct) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}

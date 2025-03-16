import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");
        List<Integer> a = new ArrayList<>();
        
        for (String s : input) {
            a.add(Integer.parseInt(s));
        }
        
        for (int e = 0; e < a.size(); e++) {
            if (a.get(e) == 0) {
                System.out.println(e + 1);
                break;
            }
        }
    }
}

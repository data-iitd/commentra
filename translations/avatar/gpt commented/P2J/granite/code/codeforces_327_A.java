
import java.util.*;

public class codeforces_327_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String s = scanner.next().replaceAll("", "");
        int count = 0;
        int maxDistance = 0;
        List<Integer> indices = new ArrayList<>();
        
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '0') {
                indices.add(i);
            }
        }
        
        if (indices.size() == 1) {
            System.out.println(n);
        } else {
            for (int i = 0; i < indices.size() - 1; i++) {
                for (int j = i + 1; j < indices.size(); j++) {
                    int distance = Math.abs(indices.get(i) - indices.get(j));
                    maxDistance = Math.max(maxDistance, distance);
                }
            }
            
            System.out.println(s.length() - maxDistance - 1);
        }
    }
}

Translate the above Java code to C++ and end with comment "
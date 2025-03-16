import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<Integer> lst = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            lst.add(scanner.nextInt());
        }
        
        Collections.sort(lst);
        Collections.reverse(lst);
        
        int od = 0;
        
        for (int i : lst) {
            if ((i & 1) == 1) {
                od++;
            }
        }
        
        int sum = 0;
        boolean ok = false;
        
        for (int i = 0; i < n; i++) {
            if (lst.get(i) % 2 == 0) {
                sum += lst.get(i);
            } else {
                if (ok || od > 1) {
                    sum += lst.get(i);
                    od--;
                    ok = !ok;
                }
            }
        }
        
        System.out.println(sum);
    }
}


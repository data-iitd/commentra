import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // 整数の入力
        int n = sc.nextInt(); // Read the number of elements
        int minN = sc.nextInt()-1; // Read another integer and initialize minN to it - 1
        
        // Loop through the elements
        for(int i=0; i<n-1; i++){
            int h = sc.nextInt(); // Read the next integer in the sequence
            // Update minN based on the conditions
            if(minN == h){
                minN = h; // If minN is equal to h, update minN to h
            }else if(minN == h-1){
                minN = h-1; // If minN is equal to h-1, update minN to h-1
            }else if(minN < h-1){
                minN = h-1; // If minN is less than h-1, update minN to h-1
            }else if(minN > h){
                System.out.println("No"); // If minN is greater than h, print "No" and exit
                return;
            }
        }
        System.out.println("Yes"); // If all conditions are satisfied, print "Yes"
    }
}

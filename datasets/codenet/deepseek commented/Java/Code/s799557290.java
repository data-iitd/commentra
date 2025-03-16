
import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read the number of problems (a) and the number of submissions (b)
        int a = sc.nextInt();
        int b = sc.nextInt();
        
        // Initialize arrays to keep track of whether a problem has been judged and penalty counts
        boolean ju[] = new boolean[100001];
        int pe[] = new int[100001];
        
        // Initialize variables to count the number of wrong answers and correct answers
        int wa=0;
        int ac=0;
        
        // Loop through each submission
        for(int i=0; i<b; i++){
            // Read the problem number and the result of the submission
            int n = sc.nextInt();
            String res = sc.next();
            
            // If the result is "WA" and the problem has not been judged yet, increment the penalty count
            if(res.equals("WA") && ju[n-1] != true){
                pe[n-1]++;
            }
            
            // If the result is "AC", mark the problem as judged
            if(res.equals("AC")){
                ju[n-1] = true;
            }
        }
        
        // Loop through each problem to calculate the total number of correct answers and wrong answers
        for(int i=0; i<a ; i++){
            if(ju[i]){
                ac++;
                wa += pe[i];
            }
        }
        
        // Print the number of problems solved and the total number of wrong answers
        System.out.println(""+ac+" "+wa);
   }
}


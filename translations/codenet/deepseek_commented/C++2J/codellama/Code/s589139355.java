import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize variables
        int a, t = 0, h = 0, lt, lh, tt, hh, l;
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        String taro, hana;

        // Loop through the number of games
        for(int i = 0; i < a; ++i){
            // Read the names of Taro and Hana
            taro = sc.next();
            hana = sc.next();
            
            // Get the lengths of the names
            lt = taro.length();
            lh = hana.length();
            
            // Determine the maximum length of the names
            if(lt > lh){
                l = lt;
            }
            else{
                l = lh;
            }
            
            // Initialize score counters for this round
            tt = 0;
            hh = 0;

            // Compare the names and update the scores
            if(taro.compareTo(hana) > 0){
                t = t + 3;
            }
            else if(hana.compareTo(taro) > 0){
                h = h + 3;
            }
            else if(hana.compareTo(taro) == 0){
                h = h + 1;
                t = t + 1;
            }
        }
        
        // Output the final scores
        System.out.println(t + " " + h);

        sc.close();
    }
}



import java.util.*;
import java.math.*;
     
class Main{
    public static void main(String[] args) {
        
        try(Scanner sc = new Scanner(System.in)){

            // Read the number of questions and submissions
            int n = Integer.parseInt(sc.next());
            int m = Integer.parseInt(sc.next());

            // HashMap to keep track of wrong answers for each question
            HashMap<Integer, Integer> map = new HashMap<>();

            // Counters for accepted answers and total wrong answers
            int countAc = 0;
            int countWaAll = 0;
 
            // Loop through each submission
            for(int i = 0 ; i < m; i++){
                // Read the question number and the result (WA or AC)
                int question = Integer.parseInt(sc.next());
                String waOrAc = sc.next();

                // Check if the question is not in the map
                if(!map.containsKey(question)){
                    // Update the map with 1 for WA and -1 for AC
                    if(waOrAc.equals("WA")) map.put(question, 1);
                    else{
                        map.put(question, -1);
                        countAc++; // Increment the accepted answer counter
                    } 
                }else{
                    // Get the current count of wrong answers for the question
                    int countWa = map.get(question);
                    // Check if the previous result was not a final verdict
                    if(countWa < 0);
                    else{
                        // Update the map with the new count of wrong answers
                        if(waOrAc.equals("WA")) map.replace(question, countWa, countWa + 1);
                        else{
                            map.replace(question, countWa, -countWa);
                            countAc++; // Increment the accepted answer counter
                            countWaAll += countWa; // Add to the total wrong answers
                        }
                    }
                }
            }

            // Output the total number of accepted answers and the total number of wrong answers
            System.out.println(countAc + " " + countWaAll);

        }catch(Exception e){
            e.printStackTrace();
        }        
    }
}
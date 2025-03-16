
import java.util.*;
import java.math.*;

class Main{
    public static void main(String[] args) {
        
        // Initialize scanner to read input from System.in
        try(Scanner sc = new Scanner(System.in)){

            // Read the first two integers from the input
            int n = Integer.parseInt(sc.next());
            int m = Integer.parseInt(sc.next());

            // Initialize an empty HashMap to store the number of times each question appears as AC or WA
            HashMap<Integer, Integer> map = new HashMap<>();

            // Initialize counters for the number of questions answered correctly (AC) and the total number of questions answered (WA + AC)
            int countAc = 0;
            int countWaAll = 0;

            // Iterate through the next m lines of input, each representing a question and its answer status
            for(int i = 0 ; i < m; i++){
                // Read the next question number and its answer status from the input
                int question = Integer.parseInt(sc.next());
                String waOrAc = sc.next();

                // Check if the question has already been encountered in the HashMap
                if(!map.containsKey(question)){
                    // If it hasn't, add it to the HashMap with an initial value of 0 (indicating no previous WA or AC)
                    if(waOrAc.equals("WA")) map.put(question, 1);
                    else{
                        // If the answer was AC, increment the countAc counter
                        map.put(question, -1);
                        countAc++;
                    }
                }else{
                    // If the question has already been encountered, update its count in the HashMap
                    int countWa = map.get(question);
                    if(countWa < 0){
                        // If the previous answer was AC, do nothing
                    }else{
                        // If the previous answer was WA, update the count and increment the countAc and countWaAll counters
                        if(waOrAc.equals("WA")) map.replace(question, countWa, countWa + 1);
                        else{
                            map.replace(question, countWa, -countWa);
                            countAc++;
                            countWaAll += countWa;
                        }
                    }
                }
            }

            // Print the final result: the number of questions answered correctly and the total number of questions answered
            System.out.println(countAc + " " + countWaAll);

        }catch(Exception e){
            // Print any exceptions that occur during the execution of the program
            e.printStackTrace();
        }        
    }
}
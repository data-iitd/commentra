
import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in); // create a Scanner object to read input from the console

    while (scanner.hasNext()) { // read input lines until there is no more input
      String inputString = scanner.next(); // read a line of input as a String
      String[] stringArray = inputString.split(","); // split the input String into an array of Strings using the comma as a delimiter

      int[] lengthArray = new int[10]; // create an array of integers to store the lengths of the given segments

      int totalLength = 0; // initialize a variable to store the total length of the segments

      for (int i = 0; i < 10; i++) { // iterate through the first 10 elements of the string array and convert them to integers
        lengthArray[i] = Integer.parseInt(stringArray[i]); // assign the integer value to the corresponding index in the lengthArray
        totalLength += lengthArray[i]; // add the length of the current segment to the total length
      }

      int[] velocities = {Integer.parseInt(stringArray[10]), Integer.parseInt(stringArray[11])}; // initialize an array to store the two given velocities

      double time = (double) totalLength / (velocities[0] + velocities[1]); // calculate the time it takes for the sum of the lengths to be covered by the given velocities

      int currentLength = 0; // initialize a variable to store the current length

      for (int i = 0; i < 11; i++) { // iterate through the entire string array and find the index of the first segment that can be covered by the given velocities within the time calculated earlier
        if (velocities[0] * time <= currentLength) { // check if the current length is greater than the length that can be covered by the first velocity within the given time
          System.out.println(i); // print the index of the first segment that satisfies the condition
          break; // exit the loop once the condition is met
        }
        currentLength += lengthArray[i]; // add the length of the current segment to the current length
      }
    }

    scanner.close(); // close the Scanner object to release system resources
  }
}


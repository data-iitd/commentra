public class WeatherForecast {
  public static void main(String[] args) {
    // Declare a variable to hold the weather condition input
    String S = System.console().readLine();
    
    // Use a switch statement to determine the next weather condition based on the input
    switch (S) {
      case "Sunny":
        // If the input is "Sunny", print "Cloudy" as the next condition
        System.out.println("Cloudy");
        break;
      case "Cloudy":
        // If the input is "Cloudy", print "Rainy" as the next condition
        System.out.println("Rainy");
        break;
      case "Rainy":
        // If the input is "Rainy", print "Sunny" as the next condition
        System.out.println("Sunny");
        break;
    }
  }
}

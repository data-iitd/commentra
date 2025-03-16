import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation
    private Main() {
    }

    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner scanner = new Scanner(System.in);
        
        // Read the operation type (ipv4-to-ipv6 or ipv6-to-ipv4) from user input
        String operation = scanner.nextLine().trim();
        
        try {
            // Check if the operation is to convert IPv4 to IPv6
            if (operation.equalsIgnoreCase("ipv4-to-ipv6")) {
                // Read the IPv4 address from user input
                String ipv4Address = scanner.nextLine().trim();
                // Convert the IPv4 address to IPv6
                String ipv6Address = ipv4ToIpv6(ipv4Address);
                // Output the converted IPv6 address
                System.out.println("IPv6-mapped IPv6 Address: " + ipv6Address);
            } 
            // Check if the operation is to convert IPv6 to IPv4
            else if (operation.equalsIgnoreCase("ipv6-to-ipv4")) {
                // Read the IPv6 address from user input
                String ipv6Address = scanner.nextLine().trim();
                // Convert the IPv6 address to IPv4
                String ipv4Address = ipv6ToIpv4(ipv6Address);
                // Output the extracted IPv4 address
                System.out.println("Extracted IPv4 Address: " + ipv4Address);
            } 
            // Handle invalid operation input
            else {
                System.out.println("Invalid operation.");
            }
        } 
        // Catch exceptions related to unknown hosts or illegal arguments
        catch (UnknownHostException | IllegalArgumentException e) {
            System.out.println("Error: " + e.getMessage());
        } 
        // Ensure the scanner is closed to free resources
        finally {
            scanner.close();
        }
    }

    // Method to convert an IPv4 address to an IPv6-mapped IPv6 address
    public static String ipv4ToIpv6(String ipv4Address) throws UnknownHostException {
        // Check if the provided IPv4 address is null or empty
        if (ipv4Address == null || ipv4Address.isEmpty()) {
            throw new UnknownHostException("IPv4 address is empty.");
        }
        
        // Split the IPv4 address into its segments
        String[] segments = ipv4Address.split("\\.");
        
        // Validate that the IPv4 address has exactly 4 segments
        if (segments.length != 4) {
            throw new UnknownHostException("Invalid IPv4 address format.");
        }
        
        // Validate each segment of the IPv4 address
        for (String segment : segments) {
            int value = Integer.parseInt(segment);
            // Check if the segment value is within the valid range (0-255)
            if (value < 0 || value > 255) {
                throw new UnknownHostException("Invalid IPv4 address segment: " + segment);
            }
        }
        
        // Return the IPv6-mapped IPv6 address
        return "::ffff:" + ipv4Address;
    }

    // Method to convert an IPv6-mapped IPv4 address to an IPv4 address
    public static String ipv6ToIpv4(String ipv6Address) throws UnknownHostException {
        // Check if the provided IPv6 address is null or empty
        if (ipv6Address == null || ipv6Address.isEmpty()) {
            throw new UnknownHostException("IPv6 address is empty.");
        }
        
        // Validate that the IPv6 address starts with the IPv6-mapped prefix
        if (!ipv6Address.startsWith("::ffff:")) {
            throw new IllegalArgumentException("Not a valid IPv6-mapped IPv4 address.");
        }
        
        // Split the IPv6 address into its parts
        String[] parts = ipv6Address.split(":");
        
        // Validate that the IPv6 address has the correct format
        if (parts.length < 3 || !parts[2].contains(".")) {
            throw new IllegalArgumentException("Not a valid IPv6-mapped IPv4 address.");
        }
        
        // Return the extracted IPv4 address
        return parts[2];
    }
}

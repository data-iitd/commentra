
import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.Scanner;

/**
 * A utility class for converting between IPv6 and IPv4 addresses.
 *
 * - Converts IPv4 to IPv6-mapped IPv6 address.
 * - Extracts IPv4 address from IPv6-mapped IPv6.
 * - Handles exceptions for invalid inputs.
 *
 * @author Hardvan
 */
public final class IPv6Converter {
    private IPv6Converter() {
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String operation = scanner.nextLine().trim();

        try {
            if (operation.equalsIgnoreCase("ipv4-to-ipv6")) {
                String ipv4Address = scanner.nextLine().trim();
                String ipv6Address = ipv4ToIpv6(ipv4Address);
                System.out.println("IPv6-mapped IPv6 Address: " + ipv6Address);
            } else if (operation.equalsIgnoreCase("ipv6-to-ipv4")) {
                String ipv6Address = scanner.nextLine().trim();
                String ipv4Address = ipv6ToIpv4(ipv6Address);
                System.out.println("Extracted IPv4 Address: " + ipv4Address);
            } else {
                System.out.println("Invalid operation.");
            }
        } catch (UnknownHostException | IllegalArgumentException e) {
            System.out.println("Error: " + e.getMessage());
        } finally {
            scanner.close();
        }
    }

    /**
     * Converts an IPv4 address (e.g., "192.0.2.128") to an IPv6-mapped IPv6 address.
     * Example: IPv4 "192.0.2.128" -> IPv6 "::ffff:192.0.2.128"
     *
     * @param ipv4Address The IPv4 address in string format.
     * @return The corresponding IPv6-mapped IPv6 address.
     * @throws UnknownHostException If the IPv4 address is invalid.
     * @throws IllegalArgumentException If the IPv6 address is not a mapped IPv4 address.
     */
    public static String ipv4ToIpv6(String ipv4Address) throws UnknownHostException {
        if (ipv4Address == null || ipv4Address.isEmpty()) {
            throw new UnknownHostException("IPv4 address is empty.");
        }

        String[] segments = ipv4Address.split("\\.");
        if (segments.length != 4) {
            throw new UnknownHostException("Invalid IPv4 address format.");
        }

        for (String segment : segments) {
            int value = Integer.parseInt(segment);
            if (value < 0 || value > 255) {
                throw new UnknownHostException("Invalid IPv4 address segment: " + segment);
            }
        }

        return "::ffff:" + ipv4Address;
    }

    /**
     * Extracts the IPv4 address from an IPv6-mapped IPv6 address.
     * Example: IPv6 "::ffff:192.0.2.128" -> IPv4 "192.0.2.128"
     *
     * @param ipv6Address The IPv6 address in string format.
     * @return The extracted IPv4 address.
     * @throws UnknownHostException If the IPv6 address is invalid or not a mapped IPv4 address.
     */

    public static String ipv6ToIpv4(String ipv6Address) throws UnknownHostException {
        if (ipv6Address == null || ipv6Address.isEmpty()) {
            throw new UnknownHostException("IPv6 address is empty.");
        }

        if (!ipv6Address.startsWith("::ffff:")) {
            throw new IllegalArgumentException("Not a valid IPv6-mapped IPv4 address.");
        }

        String[] parts = ipv6Address.split(":");
        if (parts.length < 3 || !parts[2].contains(".")) {
            throw new IllegalArgumentException("Not a valid IPv6-mapped IPv4 address.");
        }

        return parts[2];
    }
}

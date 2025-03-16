
import ipaddress

def main():
    # Create a Scanner object to read input from the console
    scanner = Scanner(System.in)
    
    # Read the operation type (ipv4-to-ipv6 or ipv6-to-ipv4) from user input
    operation = scanner.nextLine().trim()
    
    try:
        # Check if the operation is to convert IPv4 to IPv6
        if operation.lower() == "ipv4-to-ipv6":
            # Read the IPv4 address from user input
            ipv4_address = scanner.nextLine().trim()
            # Convert the IPv4 address to IPv6
            ipv6_address = ipv4_to_ipv6(ipv4_address)
            # Output the converted IPv6 address
            print("IPv6-mapped IPv6 Address:", ipv6_address)
        # Check if the operation is to convert IPv6 to IPv4
        elif operation.lower() == "ipv6-to-ipv4":
            # Read the IPv6 address from user input
            ipv6_address = scanner.nextLine().trim()
            # Convert the IPv6 address to IPv4
            ipv4_address = ipv6_to_ipv4(ipv6_address)
            # Output the extracted IPv4 address
            print("Extracted IPv4 Address:", ipv4_address)
        # Handle invalid operation input
        else:
            print("Invalid operation.")
    # Catch exceptions related to unknown hosts or illegal arguments
    except (UnknownHostException, ValueError) as e:
        print("Error:", e)
    # Ensure the scanner is closed to free resources
    finally:
        scanner.close()

# Method to convert an IPv4 address to an IPv6-mapped IPv6 address
def ipv4_to_ipv6(ipv4_address):
    # Check if the provided IPv4 address is null or empty
    if ipv4_address is None or ipv4_address.strip() == "":
        raise UnknownHostException("IPv4 address is empty.")
    
    # Split the IPv4 address into its segments
    segments = ipv4_address.split(".")
    
    # Validate that the IPv4 address has exactly 4 segments
    if len(segments)!= 4:
        raise UnknownHostException("Invalid IPv4 address format.")
    
    # Validate each segment of the IPv4 address
    for segment in segments:
        value = int(segment)
        # Check if the segment value is within the valid range (0-255)
        if value < 0 or value > 255:
            raise UnknownHostException("Invalid IPv4 address segment: " + segment)
    
    # Return the IPv6-mapped IPv6 address
    return "::ffff:" + ipv4_address

# Method to convert an IPv6-mapped IPv4 address to an IPv4 address
def ipv6_to_ipv4(ipv6_address):
    # Check if the provided IPv6 address is null or empty
    if ipv6_address is None or ipv6_address.strip() == "":
        raise UnknownHostException("IPv6 address is empty.")
    
    # Validate that the IPv6 address starts with the IPv6-mapped prefix
    if not ipv6_address.startswith("::ffff:"):
        raise ValueError("Not a valid IPv6-mapped IPv4 address.")
    
    # Split the IPv6 address into its parts
    parts = ipv6_address.split(":")
    
    # Validate that the IPv6 address has the correct format
    if len(parts) < 3 or not parts[2].contains("."):
        raise ValueError("Not a valid IPv6-mapped IPv4 address.")
    
    # Return the extracted IPv4 address
    return parts[2]

# Call the main function to start the program
if __name__ == "__main__":
    main()


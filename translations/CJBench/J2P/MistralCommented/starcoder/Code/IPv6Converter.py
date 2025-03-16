
import socket
import sys

# Initialize a Scanner to read user input
scanner = sys.stdin

# Read user operation from the command line
operation = scanner.readline().strip()

try:
    # Check if the operation is valid
    if operation.lower() == "ipv4-to-ipv6":
        ipv4Address = scanner.readline().strip()

        # Convert IPv4 address to IPv6-mapped IPv6 address
        ipv6Address = ipv4ToIpv6(ipv4Address)

        # Print the result
        print("IPv6-mapped IPv6 Address: " + ipv6Address)
    elif operation.lower() == "ipv6-to-ipv4":
        ipv6Address = scanner.readline().strip()

        # Convert IPv6-mapped IPv4 address to IPv4 address
        ipv4Address = ipv6ToIpv4(ipv6Address)

        # Print the result
        print("Extracted IPv4 Address: " + ipv4Address)
    else:
        # Print an error message for invalid operation
        print("Invalid operation.")
except socket.error as e:
    # Print an error message with the exception details
    print("Error: " + e.strerror)
finally:
    # Close the Scanner to free system resources
    scanner.close()

# Convert IPv4 address to IPv6-mapped IPv6 address
def ipv4ToIpv6(ipv4Address):
    if ipv4Address == None or ipv4Address.strip() == "":
        # Throw an exception if the IPv4 address is empty
        raise socket.error("IPv4 address is empty.")

    segments = ipv4Address.split(".")
    if len(segments)!= 4:
        # Throw an exception if the IPv4 address has an incorrect number of segments
        raise socket.error("Invalid IPv4 address format.")

    for segment in segments:
        value = int(segment)
        if value < 0 or value > 255:
            # Throw an exception if any segment value is out of range
            raise socket.error("Invalid IPv4 address segment: " + segment)

    # Return the IPv6-mapped IPv6 address
    return "::ffff:" + ipv4Address

# Convert IPv6-mapped IPv4 address to IPv4 address
def ipv6ToIpv4(ipv6Address):
    if ipv6Address == None or ipv6Address.strip() == "":
        # Throw an exception if the IPv6 address is empty
        raise socket.error("IPv6 address is empty.")

    if not ipv6Address.startswith("::ffff:"):
        # Throw an exception if the IPv6 address is not a valid IPv6-mapped IPv4 address
        raise ValueError("Not a valid IPv6-mapped IPv4 address.")

    parts = ipv6Address.split(":")
    if len(parts) < 3 or not parts[2].contains("."):
        # Throw an exception if the IPv6 address has an incorrect format
        raise ValueError("Not a valid IPv6-mapped IPv4 address.")

    # Return the IPv4 address
    return parts[2]


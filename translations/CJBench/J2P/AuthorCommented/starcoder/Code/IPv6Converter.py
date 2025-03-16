
import socket
import sys

def ipv4_to_ipv6(ipv4_address):
    """
    Converts an IPv4 address (e.g., "192.0.2.128") to an IPv6-mapped IPv6 address.
    Example: IPv4 "192.0.2.128" -> IPv6 "::ffff:192.0.2.128"

    :param ipv4_address: The IPv4 address in string format.
    :return: The corresponding IPv6-mapped IPv6 address.
    """
    if not ipv4_address:
        raise ValueError("IPv4 address is empty.")

    segments = ipv4_address.split(".")
    if len(segments)!= 4:
        raise ValueError("Invalid IPv4 address format.")

    for segment in segments:
        value = int(segment)
        if value < 0 or value > 255:
            raise ValueError("Invalid IPv4 address segment: " + segment)

    return "::ffff:" + ipv4_address


def ipv6_to_ipv4(ipv6_address):
    """
    Extracts the IPv4 address from an IPv6-mapped IPv6 address.
    Example: IPv6 "::ffff:192.0.2.128" -> IPv4 "192.0.2.128"

    :param ipv6_address: The IPv6 address in string format.
    :return: The extracted IPv4 address.
    """
    if not ipv6_address:
        raise ValueError("IPv6 address is empty.")

    if not ipv6_address.startswith("::ffff:"):
        raise ValueError("Not a valid IPv6-mapped IPv4 address.")

    parts = ipv6_address.split(":")
    if len(parts) < 3 or not parts[2].contains("."):
        raise ValueError("Not a valid IPv6-mapped IPv4 address.")

    return parts[2]


def main():
    """
    Main function.
    """
    if len(sys.argv)!= 2:
        print("Usage: " + sys.argv[0] + " <ipv4-to-ipv6|ipv6-to-ipv4>")
        sys.exit(1)

    operation = sys.argv[1]
    if operation.lower() == "ipv4-to-ipv6":
        ipv4_address = input("IPv4 address: ")
        ipv6_address = ipv4_to_ipv6(ipv4_address)
        print("IPv6-mapped IPv6 address: " + ipv6_address)
    elif operation.lower() == "ipv6-to-ipv4":
        ipv6_address = input("IPv6 address: ")
        ipv4_address = ipv6_to_ipv4(ipv6_address)
        print("Extracted IPv4 address: " + ipv4_address)
    else:
        print("Invalid operation.")


if __name__ == "__main__":
    main()


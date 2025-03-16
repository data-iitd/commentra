import socket
import sys

def ipv4_to_ipv6(ipv4_address):
    if not ipv4_address:
        raise UnknownHostException("IPv4 address is empty.")
    segments = ipv4_address.split(".")
    if len(segments)!= 4:
        raise UnknownHostException("Invalid IPv4 address format.")
    for segment in segments:
        value = int(segment)
        if value < 0 or value > 255:
            raise UnknownHostException("Invalid IPv4 address segment: " + segment)
    return "::ffff:" + ipv4_address

def ipv6_to_ipv4(ipv6_address):
    if not ipv6_address:
        raise UnknownHostException("IPv6 address is empty.")
    if not ipv6_address.startswith("::ffff:"):
        raise UnknownHostException("Not a valid IPv6-mapped IPv4 address.")
    parts = ipv6_address.split(":")
    if len(parts) < 3 or not parts[2].contains("."):
        raise UnknownHostException("Not a valid IPv6-mapped IPv4 address.")
    return parts[2]

if __name__ == "__main__":
    try:
        operation = sys.stdin.readline().strip()
        if operation.lower() == "ipv4-to-ipv6":
            ipv4_address = sys.stdin.readline().strip()
            ipv6_address = ipv4_to_ipv6(ipv4_address)
            print("IPv6-mapped IPv6 Address: " + ipv6_address)
        elif operation.lower() == "ipv6-to-ipv4":
            ipv6_address = sys.stdin.readline().strip()
            ipv4_address = ipv6_to_ipv4(ipv6_address)
            print("Extracted IPv4 Address: " + ipv4_address)
        else:
            print("Invalid operation.")
    except UnknownHostException as e:
        print("Error: " + e.args[0])
    except Exception as e:
        print("Error: " + e.args[0])


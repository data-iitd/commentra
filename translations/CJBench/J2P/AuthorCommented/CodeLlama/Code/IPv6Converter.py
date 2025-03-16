
import ipaddress


def ipv4_to_ipv6(ipv4_address):
    try:
        ipv4_address = ipaddress.IPv4Address(ipv4_address)
        return str(ipaddress.IPv6Address(int(ipv4_address) + 2**32))
    except ipaddress.AddressValueError:
        raise ValueError("Invalid IPv4 address.")


def ipv6_to_ipv4(ipv6_address):
    try:
        ipv6_address = ipaddress.IPv6Address(ipv6_address)
        return str(ipaddress.IPv4Address(int(ipv6_address) - 2**32))
    except ipaddress.AddressValueError:
        raise ValueError("Invalid IPv6 address.")


if __name__ == "__main__":
    operation = input().strip()

    try:
        if operation == "ipv4-to-ipv6":
            ipv4_address = input().strip()
            ipv6_address = ipv4_to_ipv6(ipv4_address)
            print("IPv6-mapped IPv6 Address:", ipv6_address)
        elif operation == "ipv6-to-ipv4":
            ipv6_address = input().strip()
            ipv4_address = ipv6_to_ipv4(ipv6_address)
            print("Extracted IPv4 Address:", ipv4_address)
        else:
            raise ValueError("Invalid operation.")
    except ValueError as e:
        print("Error:", e)


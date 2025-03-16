

import ipaddress

def ipv4_to_ipv6(ipv4_address):
    try:
        ipv4_address = ipaddress.IPv4Address(ipv4_address)
        ipv6_address = ipaddress.IPv6Address("::ffff:" + str(ipv4_address))
        return ipv6_address
    except ValueError:
        raise ValueError("Invalid IPv4 address format.")

def ipv6_to_ipv4(ipv6_address):
    try:
        ipv6_address = ipaddress.IPv6Address(ipv6_address)
        if not ipv6_address.ipv4_mapped:
            raise ValueError("Not a valid IPv6-mapped IPv4 address.")
        ipv4_address = ipaddress.IPv4Address(str(ipv6_address).split(":")[-1])
        return ipv4_address
    except ValueError:
        raise ValueError("Invalid IPv6 address format or not a valid IPv6-mapped IPv4 address.")

# 
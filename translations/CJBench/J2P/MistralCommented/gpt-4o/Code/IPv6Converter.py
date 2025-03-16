import socket

class Main:
    @staticmethod
    def main():
        # Read user operation from the command line
        operation = input().strip()

        try:
            # Check if the operation is valid
            if operation.lower() == "ipv4-to-ipv6":
                ipv4_address = input().strip()

                # Convert IPv4 address to IPv6-mapped IPv6 address
                ipv6_address = Main.ipv4_to_ipv6(ipv4_address)

                # Print the result
                print("IPv6-mapped IPv6 Address:", ipv6_address)
            elif operation.lower() == "ipv6-to-ipv4":
                ipv6_address = input().strip()

                # Convert IPv6-mapped IPv4 address to IPv4 address
                ipv4_address = Main.ipv6_to_ipv4(ipv6_address)

                # Print the result
                print("Extracted IPv4 Address:", ipv4_address)
            else:
                # Print an error message for invalid operation
                print("Invalid operation.")
        except (socket.error, ValueError) as e:
            # Print an error message with the exception details
            print("Error:", e)

    # Convert IPv4 address to IPv6-mapped IPv6 address
    @staticmethod
    def ipv4_to_ipv6(ipv4_address):
        if not ipv4_address:
            # Throw an exception if the IPv4 address is empty
            raise socket.error("IPv4 address is empty.")

        segments = ipv4_address.split(".")
        if len(segments) != 4:
            # Throw an exception if the IPv4 address has an incorrect number of segments
            raise socket.error("Invalid IPv4 address format.")

        for segment in segments:
            value = int(segment)
            if value < 0 or value > 255:
                # Throw an exception if any segment value is out of range
                raise socket.error("Invalid IPv4 address segment: " + segment)

        # Return the IPv6-mapped IPv6 address
        return "::ffff:" + ipv4_address

    # Convert IPv6-mapped IPv4 address to IPv4 address
    @staticmethod
    def ipv6_to_ipv4(ipv6_address):
        if not ipv6_address:
            # Throw an exception if the IPv6 address is empty
            raise socket.error("IPv6 address is empty.")

        if not ipv6_address.startswith("::ffff:"):
            # Throw an exception if the IPv6 address is not a valid IPv6-mapped IPv4 address
            raise ValueError("Not a valid IPv6-mapped IPv4 address.")

        parts = ipv6_address.split(":")
        if len(parts) < 3 or "." not in parts[2]:
            # Throw an exception if the IPv6 address has an incorrect format
            raise ValueError("Not a valid IPv6-mapped IPv4 address.")

        # Return the IPv4 address
        return parts[2]

if __name__ == "__main__":
    Main.main()

# <END-OF-CODE>

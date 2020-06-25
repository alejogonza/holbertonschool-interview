#!/usr/bin/python3

def validUTF8(data):
        """
        A character in UTF-8 can be 1 to 4 bytes long
        The data set can contain multiple characters
        The data will be represented by a list of integers
        Each integer represents 1 byte of data, therefore you only need to handle the 8 least significant bits of each integer
        data = [65]
        True
        data = [80, 121, 116, 104, 111, 110, 32, 105, 115, 32, 99, 111, 111, 108, 33]
        True
        data = [229, 65, 127, 256]
        False
        """
        successive_10 = 0
        for b in data:
                b = bin(b).replace('0b','').rjust(8, '0')
                if successive_10 != 0:
                        successive_10 -= 1
                        if not b.startswith('10'):
                                return False
                elif b[0] == '1':
                        successive_10 = len(b.split('0')[0]) - 1
        return True

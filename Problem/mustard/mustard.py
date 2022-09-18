#!/usr/bin/python3
from Cryptodome.Util.number import getStrongPrime, bytes_to_long, long_to_bytes
from Crypto.Util.Padding import pad

try:
    FLAG = open('./flag', 'rb').read()
except:
    FLAG = "STEALTH{EXAMPLE_FLAG}".encode('utf-8')

secret_recipe = bytes_to_long(pad(FLAG, 256, style='pkcs7'))

material = [512, 1024, 1536, 2048]
e = 13


def RSA(key):
    key = bytes_to_long(bytes.fromhex(key))
    key %= 4
    p = getStrongPrime(material[key])
    q = getStrongPrime(material[(key - 1)])
    return p * q


print("Welcome to STEALTH's prime Number factory\n")
print("I'll give you several chances.")
print("Good Luck!")

for i in range(e):
    key = input("input(hex) : ")
    n = RSA(key)
    print(f"prime Number outcome: {hex(n)}")
    print(f"by-product: {hex(pow(secret_recipe, e, n))}\n")

print("good bye~")

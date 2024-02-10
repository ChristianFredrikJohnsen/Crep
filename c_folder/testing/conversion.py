from icecream import ic
import math

def hex_to_decimal(hex_num):
    if (hex_num[:2] == '0x'):
        hex_num = hex_num[2:]
    return int(hex_num, 16)


streng = '0x559244e046b0'
bob = streng[:2] + 'f' * (len(streng) - 2)
ic(bob)

print(hex_to_decimal('0x559244e046b0'))
bobc = hex_to_decimal(bob)
for i in range(0, math.ceil(len(str(bobc)) / 3)):
    print(f"{str(bobc)[i*3:i*3+3]},", end="")
print()



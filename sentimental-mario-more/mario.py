# TODO
from cs50 import get_int

h=0;
while(h<1 or h>8):
    h=get_int("Height: ")

str=""
sp=""
for i in range(h):
    str+='#'
    sp+=' '


for i in range(h):
    left=""
    right=""
    left+=(sp[0:h-i-1]+str[h-i-1:])
    # left+=(str[h-i-1:])
    right+=str[0:i+1]
    print(f'{left}  {right}')


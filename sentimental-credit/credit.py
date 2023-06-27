# TODO
from cs50 import get_string
import re

def main():
    card=get_string("Number: ")
    if isAMEX(card):
        print("AMEX")
    elif isMASTERCARD(card):
        print("MASTERCARD")
    elif isVISA(card):
        print("VISA")
    else:
        print("INVALID")

def isAMEX(card):
    if len(card)!=15:
        return False

    if re.match("34",card)==None and re.match("37",card)==None:
        return False

    if formula(card):
        return True
    else:
        return False

def isMASTERCARD(card):
    if len(card)!=16:
        return False

    if re.match("51",card)==None and re.match("52",card)==None and re.match("53",card)==None and re.match("54",card)==None and re.match("55",card)==None:
        return False

    if formula(card):
        return True
    else:
        return False

def isVISA(card):
    if len(card)!=13 and len(card)!=16:
        return False

    if re.match("4",card)==None:
        return False

    if formula(card):
        return True
    else:
        return False

def formula(card):
    sum=0
    ptr=len(card)-1
    cnt=1
    while ptr>=0:
        if cnt%2==1:
            sum+=int(card[ptr])
        else:
            # sum+=int(card[ptr])<<1
            tmp=int(card[ptr])<<1
            if tmp>=10:
                sum+=tmp-10
                sum+=tmp//10
            else:
                sum+=tmp
        # print(sum)
        cnt+=1
        ptr-=1
    # print(sum)
    if(sum%10==0):
        return True
    else:
        return False


main()

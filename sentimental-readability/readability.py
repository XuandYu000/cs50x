# TODO
from cs50 import get_string
def main():
    text=get_string("Text: ")
    nw=getwords(text)
    ns=getsentences(text)
    nch=getchars(text)
    L=nch/nw*100
    S=ns/nw*100
    grade=int(round(L*0.0588-0.296*S-15.8))
    # print('{} {} {}'.format(nch,S,grade))
    output(grade)

def output(grade):
    if grade<1:
        print("Before Grade 1")
    elif grade>=16:
        print("Grade 16+")
    else:
        print(f'Grade {grade}')

def getwords(text):
    cnt=0
    l=len(text)
    # print(l)
    for i in range(l):
        if text[i]==' ':
            cnt+=1
    # print(cnt+1)
    return cnt+1

def getsentences(text):
    cnt=0
    l=len(text)
    # print(l)
    for i in range(l):
        if text[i]=='.' or text[i]=='!' or text[i]=='?':
            cnt+=1
    # print(cnt+1)
    return cnt

def getchars(text):
    cnt=0
    l=len(text)
    # print(l)
    for i in range(l):
        if text[i].isalpha():
            # print(text[i],end="")
            cnt+=1
    # print(cnt+1)
    return cnt


main()
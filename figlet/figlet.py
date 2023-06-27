import sys
from pyfiglet import Figlet


if len(sys.argv)!=1 and len(sys.argv)!= 3:
    # print(len(sys.argv))
    print("Invalid usage")
    sys.exit(1)


figlet = Figlet()

# 在这里赋值如果命令行指定字体那么其后的异常会因为已知没有输入从而阻塞导致超时
# str=input("Input: ")

if len(sys.argv) == 3:
    if (sys.argv[1] in ["-f","--font"])==False:
        print("Invalid usage")
        sys.exit(2)


    if (sys.argv[2] in figlet.getFonts())==False:
        print("Invalid usage")
        sys.exit(3)


    figlet.setFont(font=sys.argv[2])



str = input("Input: ")
print(figlet.renderText(str))

str = input("Greeting: ")
# print(str)
array = str.lstrip().lower().split(" ")
# print(array)
if "hello" in array[0]:
    print("$0")
elif "h" in array[0][0]:
    print("$20")
else:
    print("$100")

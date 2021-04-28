def fun(ascii):
    return "+"*ascii + ".> ; '" + chr(ascii) + "'\n"


string = "test ;++>>,.[;"

print(''.join(list(map(fun, map(ord, string)))))

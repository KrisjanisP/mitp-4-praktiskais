def summa(a, b):
    return a + b

def atnemsana(a, b):
    return a - b

def multiplikacija(a, b):
    return a * b

def dalisana(a, b):
    return a / b

def eksponenta(a, b):
    return a ** b

if __name__ == "__main__":
    print("Tetstēt funkciju", __main__)
    assert summa(1,2) == 3
    assert atnemsana(3,1) == 2
    assert multiplikacija(1,2) == 2
    assert dalisana(2,2) == 1
    assert eksponenta(2,2) == 4 

## Šo daļu nedzēst!
# assert summa(1,2) == 3
# assert atnemsana(3,1) == 2
# assert multiplikacija(1,2) == 2
# assert dalisana(2,2) == 1
# assert eksponenta(2,2) == 4
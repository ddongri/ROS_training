class Test():
    def __init__(self):
        self.a = 0.5
        self.string ='hi'

    def hi(self):
        self.c = 2
        self.a = 2

cl = Test()

print(cl.a)
print(cl.string)

cl.hi()

print(cl.a)
print(cl.string)

class TwoStack:

    def __init__(self, n):
        self.size = n
        self.arr = [None] *n
        self.top = -1
        self.half = int(n/2)
        self.top2 = self.half - 1

    def push1(self, data):
        try:
            if self.top is not self.half:
                self.top += 1
                self.arr[self.top] = data
        except Exception as e:
            print(e)

    def push2(self, data):
        try:
            if self.top2 is not self.size:
                self.top2 += 1
                self.arr[self.top2] = data
        except Exception as e:
            print(e)


    def pop1(self):
        try:
            if self.top is not -1:
                data = self.arr[self.top]
                self.top -= 1
                return data
        except Exception as e:
            print(e)


    def pop2(self):
        try:
            if self.top2 is not self.half - 1:
                data = self.arr[self.top2]
                self.top2 -= 1
                return data
        except Exception as e:
            print(e)



ts = TwoStack(5)
ts.push1(5)
ts.push2(10)
ts.push2(15)
ts.push1(11)
ts.push2(7)

print("Popped element from stack1 is " + str(ts.pop1()))
ts.push1(40)
print("Popped element from stack2 is " + str(ts.pop2()))
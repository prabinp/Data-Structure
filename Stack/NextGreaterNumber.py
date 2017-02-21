class Stack:
    def __init__(self, n):
        self.size = n
        self.arr = [None] * n
        self.top = -1

    def isEmpty(self):
         if self.top is not self.size-1:
             return True
         else:
             return False

    def isFull(self):
        if self.top is self.size-1:
            return True
        else:
            return False

    def push(self, data):
        try:
            if(isEmpty(self)):
                self.top += 1
                self.arr[self.top] = data
        except Exception as e:
            print(e)

    def printNextGreaterNumber(self):
        if(isEmpty() == False):
            for i in range(0, self.top):
                max = self.arr[i]
                for j in range(i, self.top):
                    if max < self.arr[j]:
                        print(self.arr[j])
                        break
                    else:
                        print(-1)


def Main():

    obj = Stack();
    size = int(input("Enter the size of the stack - "))

    for i in range(0, size):
        data = int(input())
        obj.push(data)

    obj.printNextGreaterNumber()


if __name__ == "__Main__":
    Main()

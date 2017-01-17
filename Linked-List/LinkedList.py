
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def insert(self, data, pos):

        temp = Node(data)
        current = self.head

        if pos is 0:
            if self.head is None:
                self.head = temp
            else:
                temp.next = self.head
                self.head = temp

        else:
            if self.head is None:
                self.head = temp
            else:
                i = self.getLength()
                if(i > pos):
                    a = 1
                    while(a < pos-1 and current.next):
                        a = a + 1
                        print(". ", end="")
                        current = current.next

                    if a is pos-1 and current.next is not None:
                        temp.next = current.next
                        current.next = temp

                elif i is pos or i < pos:
                    while current.next:
                        current = current.next
                    current.next = temp

    def getLength(self):
        a = 0
        current = self.head
        while(current):
            current = current.next
            a += 1
        return a


    def deleteNode(self, key):
        current = self.head

        if current is not None:
            if current.data is key:
                self.head = current.next
                current = None
                return

            while current.next.data is not key and current.next:
                current = current.next

            if current.next.data is key and current.next.next is not None:
                current.next = current.next.next

            elif current.next.data is key and current.next.next is None:
                current.next = None

            else:
                return



    def printList(self):
        current = self.head
        while(current):
            print(current.data," ",end="")
            current = current.next
        print()



def Main():
    LLobj = LinkedList();

    while True:
        print("1 - To push")
        print("2 - To append")
        print("3 - To insert at position")
        print("4 - To display")
        print("5 - To get the length")
        print("6 - To delete")
        print("7 - To exit")

        ch = int(input("\nEnter your option - "))

        if ch is 1:
            data = int(input("Enter the data - "))
            LLobj.insert(data, 0)
        elif ch is 2:
            while True:
                data = int(input("Enter the data - "))
                if data is 0:
                    break
                else:
                    LLobj.insert(data, LLobj.getLength()+1)
        elif ch is 3:
            pos = int(input("Enter the position - "))
            data = int(input("Enter the data - "))
            LLobj.insert(data, pos)

        elif ch is 4:
            LLobj.printList()

        elif ch is 5:
            print(LLobj.getLength())

        elif ch is 6:
            key = int(input("Enter the key - "))
            LLobj.deleteNode(key)

        elif ch is 7:
            exit()

if __name__ == "__main__":
    Main()
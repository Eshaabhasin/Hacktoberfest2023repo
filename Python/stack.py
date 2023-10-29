stack = []

# push the elements in the stack
def insert(val): 
    stack.append(val)

# pop the elements from the stack
def remove():
    stack.pop()

if __name__ == "__main__":
    
    insert(1)
    insert(2)
    remove()
    insert(3)
    insert(4)
    insert(5)

    # print stack in LIFO order
    print(stack.pop())
    print(stack.pop())
    print(stack.pop())
    print(stack.pop())
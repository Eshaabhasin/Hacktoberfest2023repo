
class Person:
    def __init__(self):
        super().__init__()
        self.name = input("Enter the name of the person: ")
        self.age = int(input("Enter the age of the person: "))


class Company:
    def __init__(self):
        super().__init__()
        self.cname = input("Enter the name of the company: ")
        self.address = input("Enter the address of the company: ")


class Employee(Person, Company):
    def __init__(self):
        super().__init__()
        self.salary = int(input("Enter the salary of the employee: "))
        self.skill = input("Enter the skill of the employee: ")

    def str1(self):
        print(self.name, self.age,self.cname,self.address, self.salary, self.skill)


emp = Employee()
emp.str1()

from abc import ABC,abstractmethod
class Employee(ABC):
    @abstractmethod
    def disp(self):
        pass
    def get_salary(self):
        pass
    def payroll(self):
        pass


class Fulltimeemployee(Employee):
    def __init__(self):
        self.name=input("enter your full name: ")
        

    def disp(self):
        print("name : ",self.name)
    def get_salary(self):
        self.sal=30000
    def payroll(self):
        print("total salary: ",self.sal)


class Parttimeemployee(Employee):
    def __init__(self):
        self.name=input("enter your full name: ")
        self.hours=int(input("enter wrking hours: "))
        
    def disp(self):
        print("name : ",self.name)
    def get_salary(self):
        self.sal=300*self.hours
    def payroll(self):
        print("total salary: ",self.sal)



obj1=Fulltimeemployee()
print("Details about Full time employee")
obj1.disp()
obj1.get_salary()
obj1.payroll()

obj2=Parttimeemployee()
print("Details about Part time employee")
obj2.disp()
obj2.get_salary()
obj2.payroll()


        

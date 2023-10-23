class vehicle:
    def __init__(self):
        self.vehicletype=input("enter type of vehicle: ")
        self.engine=int(input("enter  engine number : "))

        
class car(vehicle):
    def __init__(self):
        super().__init__()
        self.companyname=input("enter  name of company: ")
    def disp(self):
        print(self.vehicletype , self.engine , self.companyname)

        
class truck(vehicle):
    def __init__(self):
        super().__init__()
        self.capacity=int(input("enter  capacity: "))
    def disp(self):
        print(self.vehicletype , self.engine , self.capacity)

obj1=car()

obj2=truck()
obj1.disp()
obj2.disp()

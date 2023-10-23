class vehicle:
    def __init__(self):
        super().__init__()
        self.vehicletype=input("enter type of vehicle: ")
        self.engine=int(input("enter  engine number : "))
class car(vehicle):
    def __init__(self):
        super().__init__()
        self.companyname=input("enter  name of company: ")
class sportscar(car):
    def __init__(self):
        super().__init__()
        self.maneuverability=input("enter maneuverability: ")
    def display(self):
        print("type of vehicle:{0};engine number:{1};name of company:{2};maneuverability:{3}".format(self.vehicletype,self.engine,self.companyname,self.maneuverability))
        
c1=sportscar()
c1.display()

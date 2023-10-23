class circle:
    def __init__(self):
        self.rad=int(input("enter rad:"))
    def area(self):
        self.area=3.14*self.rad*self.rad
        print(self.area)
class cylinder(circle):
    def __init__(self):
        super().__init__()
        self.h=int(input("enter height:"))
    def volume(self):
        self.volume=3.14*self.rad*self.h*2
        print(self.volume)



b=cylinder()
b.area()
b.volume()

//Calculate the areas of shapes using Classes
#include <iostream>
using namespace std;

//Creating Classes
class Shapes{
    private:
        //private members
        double length;
        double breadth;
        double height;
    public:
        //public members(functions)
        //Square
        void square_area(){
            cout<<"Enter The length of the side: ";
            cin>>length;

            cout<<"The area of Square is "<<(length*length)<<" Sq.units"<<endl;
        }
        //Cube
        void cube_area(){
            cout<<"Enter The length of the side: ";
            cin>>length;

            cout<<"The area of Cube is "<<(6*length*length)<<" Sq.units"<<endl;
        }
        //Rectangle
        void rectangle_area(){
            cout<<"Enter The length of the Rectangle: ";
            cin>>length;
            cout<<"Enter The breadth of the Rectangle: ";
            cin>>breadth;
            cout<<"The area of Rectangle is "<<(length * breadth)<<" Sq.units"<<endl;
        }
        //Cuboid
        void cuboid_area(){
            cout<<"Enter The length of the Cuboid: ";
            cin>>length;
            cout<<"Enter The breadth of the Cuboid: ";
            cin>>breadth;
            cout<<"Enter The height of the Cuboid: ";
            cin>>height;

            cout<<"The area of Cuboid of is "<<(2*((length*breadth)+(breadth*height)+(height*length)))<<" Sq.units"<<endl;
        }
};


void menu(){
    //menu of the program
    cout<<"a. Square"<<endl;
    cout<<"b. Cube"<<endl;
    cout<<"c. Rectangle"<<endl;
    cout<<"d. Cuboid"<<endl;
    cout<<"e. Exit"<<endl;
    cout<<"Enter You Choice:";
}


int main(){
    char choice;
    Shapes shape1;//initialising
    do{
        menu();
        cin>>choice;
        switch(choice){
            case 'a':
                shape1.square_area();
                break;

            case 'b':
                shape1.cube_area();
                break;
            case 'c':
                shape1.rectangle_area();
                break;

            case 'd':
                shape1.cuboid_area();
                break;

            case 'e':
                cout<<"Program Exits"<<endl;
                break;
            default:
                cout<<"Invalid Input"<<endl;
        }
    }
    while(choice!='e');
    return 0;
}


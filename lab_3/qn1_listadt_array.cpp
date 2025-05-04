//Menu-driven program to implement List ADT using array of size 5
#include <iostream>
using namespace std;

class list{
    private:
        int current=0;
        int limit=5;
        int arr[5];
    public:
        int insertb(int num);               //To insert an element in the begining
        int inserte(int num);               //To insert an element at the end
        int insertp(int num,int index);     //To insert an element at the specified position
        int delb();                         //To delete an element from the begining
        int dele();                         //To delete an element from the end
        int delp(int index);                //To delete an element from the specified position
        int search(int num);                //To search for a specified element
        void display();                     //To display the array
        int rotate(int k);                  //To rotate the array in right k times
};

int menu(){
    //menu of the program
    cout<<endl;
    cout<<"Which function to do"<<endl;
    cout<<"1. Insert Begining"<<endl;
    cout<<"2. Insert End"<<endl;
    cout<<"3. Insert Position"<<endl;
    cout<<"4. Delete Begining"<<endl;
    cout<<"5. Delete End"<<endl;
    cout<<"6. Delete Position"<<endl;
    cout<<"7. Search"<<endl;
    cout<<"8. Display"<<endl;
    cout<<"9. Rotate"<<endl;
    cout<<"10. Exit"<<endl;
    cout<<"Enter Your Choice : ";
    return 0;
}

int main(){
    list LIST;
    int num;
    int index;
    int result;
    int choice;
    int rot;

    do{
        menu();
        cin>>choice;
        cout<<endl;
        switch (choice){
            case 1:
                cout<<"Enter the element to be inserted : ";
                cin>>num;
                result=LIST.insertb(num);
                if(result==-1){
                    cout<<"The List is Full"<<endl;
                }
                break;
            case 2:
                cout<<"Enter the element to be inserted : ";
                cin>>num;
                result=LIST.inserte(num);
                if(result==-1){
                    cout<<"The List is Full"<<endl;
                }
                break;
            case 3:
                cout<<"Enter the element to be inserted : ";
                cin>>num;
                cout<<"Enter The Index : ";
                cin>>index;
                result=LIST.insertp(num,index);
                if(result==-1){
                    cout<<"The List is Full"<<endl;
                }
                break;
            case 4:
                result=LIST.delb();
                if(result==-1){
                    cout<<"The List is Empty"<<endl;
                }
                else{
                    cout<<result<<endl;
                }
                break;
            case 5:
                result=LIST.dele();
                if(result==-1){
                    cout<<"The List is Empty"<<endl;
                }
                else{
                    cout<<result<<endl;
                }
                break;
            case 6:
                cout<<"Enter The Index : ";
                cin>>index;
                result=LIST.delp(index);
                if(result==-1){
                    cout<<"The List is Empty"<<endl;
                }
                else{
                    cout<<result<<endl;
                }
                break;
            case 7:
                cout<<"Enter Element to Search : ";
                cin>>num;
                result=LIST.search(num);
                if(result==-1){
                    cout<<"The List is Empty"<<endl;
                }
                if(result==0){
                    cout<<"Element NOT Found"<<endl;
                }
                else{
                    cout<<"Element found at index = "<<result<<endl;
                }
                break;
            case 8:
                LIST.display();
                break;
            case 9:
                cout<<"Enter Number of times to Rotate: ";
                cin>>rot;
                result=LIST.rotate(rot);
                if(result==-1){
                    cout<<"The List is Empty"<<endl;
                }
            case 10:
                 break;
            default:
                cout<<"Invalid Input"<<endl;


        }

    }
    while(choice!=10);
    return 0;
}

//Displaying the list
void list::display(){
    for(int i=0;i<=(current-1);i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

//Inserting an element to the beginning of the list
int list::insertb(int num){
    if(current>=5){
        return -1;
    }
    for(int i=current;i>=0;i--){
        arr[i]=arr[i-1];
    }
    arr[0]=num;
    current++;
    return 1;
}

//Inserting an element to the end of the list
int list::inserte(int num){
    if(current>=5){
        return -1;
    }
    arr[current]=num;
    current++;
    return 1;
}

//Inserting an element in the given index position
int list::insertp(int num,int index){
    if(current>=5){
        return -1;
    }
    for(int i=current;i>=index;i--){
        arr[i]=arr[i-1];
    }
    arr[index]=num;
    current++;
    return 1;
}

//Deleting an element from the beginning of the list
int list::delb(){
    int del=arr[0];
    if(current==0){
        return -1;
    }
    for(int i=0;i<current;i++){
        arr[i]=arr[i+1];
    }
    current--;
    return del;
}

//Deleting an element from the end of the list
int list::dele(){
    int del=arr[current-1];
    if(current ==0){
        return -1;
    }
    current--;
    return del;
}

//Deleting an element from the given index position
int list::delp(int index){
    int del=arr[index];
    if(current ==0){
        return -1;
    }
    for(int i=index;i<current;i++){
        arr[i]=arr[i+1];
    }
    current--;
    return del;
}

//Searching for a given number in the list
int list::search(int num){
    for(int i=0;i<current;i++){
        if(arr[i]==num){
            return i;
        }
    }
    return 0;
}

//Rotating the list
int list::rotate(int rot){
    if(current==0){
        return -1;
    }
    rot=rot%5;
    int last=arr[current-1];
    for(int j=0;j<rot;j++){
        for(int i=current-1;i>=0;i--){
            arr[i]=arr[i-1];

        }
        arr[0]=last;
    }
    return 1;
}

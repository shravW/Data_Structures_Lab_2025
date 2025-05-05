//Finding the maximum number of blocks in 1st tower
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//A vector class to store the vector with the number of blocks in each tower
class vectors{
    private:
        vector<int> v1;
    public:
        int findnum();
};

int main(){
    class vectors v2;
    vector<int> v3;
    int test;
    int s;
    cout<<"Enter the number of test cases"<<" ";
    cin>>test;
    for (int i=0;i<test;i++){
        s=v2.findnum();
        v3.push_back(s);
    }
    for (auto p:v3){
        cout<<p<<" ";
    }
    cout<<endl;
    return 0;
}
//Function to return the maximum number of blocks possible in tower 1
int vectors::findnum(){
    int temp;
    int tow;
    int c;
    int block;
    cout<<"Enter the number of towers"<<": ";
    cin>>tow;
    for (int i=0;i<tow;i++){
        cout<<"Enter the number of blocks in "<<i+1<<" tower";
        cin>>block;
        v1.push_back(block);
    }
    
    sort(v1.begin()+1,v1.end());
    for (int i=1;i<tow;i++){
        c=v1[i]-v1[0];
        if (c>0){
            if (c%2==0){
                v1[0]=v1[0]+c/2;
                v1[i]=v1[i]-c/2;
            }
            else{
                v1[0]=v1[0]+c/2+1;
                v1[i]=v1[i]-c/2-1;
            }
        }
    }
    temp=v1[0];
    v1.clear();
    return temp;

}
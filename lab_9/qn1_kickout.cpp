//Nene's game of kicking out
#include <iostream>
using namespace std;

int main(){
    //Initialising all the variables
    int t,k,q;
    int qvalarray[100];
    int mainarray[100][100];
    cin >> t;//Total number of testcases
    if (t>250 || t<0){
        return 0;
    }
    int counter=0;
    while (t--){
        cin >> k;//Sequence to kick out
        cin >> q;//Number of players
        if (k<1 || q<1 || q>100){
            return 0;
        }
        int karr[k];
        int qarr[q];
        qvalarray[counter]=q;
        for (int i=0;i<k;i++){
            cin >> karr[i];//Array input
        }
        int min=karr[0];
        for (int i=0;i<k;i++){
            if (min>karr[i] || karr[i]>100 || karr[i]<1){
                return 0;
            }
        }
        for (int i=0;i<q;i++){
            cin >> qarr[i];//Array input
        }
        for (int i=0;i<q;i++){
            if (qarr[i]>100 || qarr[i]<1){
                return 0;
            }
        }
        //Kicking out
        for (int i=0;i<q;i++){
            if (qarr[i]>=karr[0]){
                mainarray[counter][i]=karr[0]-1;
            }
            else{
                mainarray[counter][i]=qarr[i];
            }
        }
        counter++;
    }
    //Displaying the results
    for (int i=0;i<counter;i++){
        for (int j=0;j<qvalarray[i];j++){
            cout << mainarray[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
//Finding the difference in strength
#include <iostream>
using namespace std;

int main(){
    //Initialising all the variables
    int t,n;
    int mainarray[100][100];
    int nvalarray[100];
    cin >> t;//Total number of testcases
    if (t>1000 || t<1){
        return 0;
    }
    int counter=0;
    while (t--){
        cin >> n;//Number of people
        if (n>200000 || n<1){
            return 0;
        }
        nvalarray[counter]=n;
        int narr[n];
        for (int i=0;i<n;i++){
            cin >> narr[i];//Array input
        }
        int max=narr[0];
        int secmax=narr[0];
        for (int i=0;i<n;i++){
            if (narr[i]<1 || narr[i]>1000000000){
                return 0;
            }
            if (max<narr[i]){
                max=narr[i];//Finding the maximum
            }
        }
        if (max==narr[0]){
            secmax=narr[1];
        }
        for (int i=0;i<n;i++){
            if (secmax<narr[i] && narr[i]<max){
                secmax=narr[i];//Finding the second maximum
            }
        }
        //Finding the difference
        for (int i=0;i<n;i++){
            if (narr[i]==max){
                mainarray[counter][i]=narr[i]-secmax;
            }
            else{
                mainarray[counter][i]=narr[i]-max;
            }
        }
        counter++;
    }
    //Displaying the results
    for (int i=0;i<counter;i++){
        for (int j=0;j<nvalarray[i];j++){
            cout << mainarray[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
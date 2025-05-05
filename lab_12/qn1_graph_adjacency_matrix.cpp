//Program to Implement Graph ADT with Adjacency matrix
#include <iostream>
#include <vector>
using namespace std;
class adjacency{
    private:
        vector<vector<int>> adj_matrix;
        int num_vert;

    public:
        adjacency(int vertices) {
            num_vert = vertices;
            adj_matrix.resize(vertices, vector<int>(vertices, 0));
        }

        int insert(int u,int v);
        int del(int u,int v);
        int search(int u,int v);
        void display();

};

void menu() {
    cout << "\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit."<<endl;
    cout << "Enter Your Choice: ";
}

int main(){
    int choice, result, num;
    int u,v;
    
    int vertices;
    cin >> vertices;

    if (vertices <= 0) {
        cout << "Number of vertices must be positive."<<endl;
        return 1;
    }
    adjacency matrix(vertices);

    do {
        menu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the vertices to Insert : ";
                cin >> u>>v;
                result = matrix.insert(u,v);
                if (result == -2)
                    cout << "Invalid vertices!"<<endl;
                else
                    cout << "Inserted Successfully."<<endl;
                break;

            case 2:
                cout << "Enter the vertices to be deleted: ";
                cin >> u>>v;
                result = matrix.del(u,v);
                if (result == -1)
                    cout << "Invalid Vertices"<<endl;
                else
                    cout << "Deleted successfully."<<endl;
                break;

            case 3:
                cout << "Enter vertices to search: ";
                cin >> u>>v;
                result = matrix.search(u,v);
                if (result == -1)
                    cout << "Edge not found.\n";
                else
                    cout << "Edge Exists between " << u<<"and "<<v << endl;
                break; 

            case 4:
                matrix.display();
                break;

            case 5:
                cout << "Exiting..."<<endl;
                break;

            default:
                cout << "Invalid Input."<<endl;
        }
    } while (choice != 5);

    return 0;
}

int adjacency::insert(int u,int v){
    if(u<0 || v<0 || u>= num_vert || v>=num_vert){
        return -2;
    }
    adj_matrix[u][v]=1;
    adj_matrix[v][u]=1;
    return 1;

}

int adjacency::del(int u,int v){
    if(u<0 || v<0 || u>= num_vert || v>=num_vert){
        return -1;
    }
    adj_matrix[u][v]=0;
    adj_matrix[v][u]=0;
    return 1;
}

int adjacency::search(int u,int v){
    if(u<0 || v<0 || u>= num_vert || v>=num_vert){
        return -1;
    }
    if(adj_matrix[u][v]==1){
        return 1;
    }
    return -1;
}

void adjacency::display(){

    for(int i=0; i<num_vert;i++){
        for(int j=0;j<num_vert;j++){
            cout<<adj_matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
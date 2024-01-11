#include <bits/stdc++.h>
using namespace std;

class matrix{
    int rows;
    int columns;
    vector <vector <int>> data;
public:
    matrix(int r, int c){
        rows = r;
        columns = c;
    }

    void initiate_0(){
        vector <int> row;
        for(int i = 0; i < rows; i++){
            data.push_back(row);
            for(int j = 0; j < columns; j++){
                data[i].push_back(0);
            }
        }
    }

    void initiate(){
        cout << "enter the data for matrix\n";
        vector <int> row;
        for(int i = 0; i < rows; i++){
            data.push_back(row);
            for(int j = 0; j < columns; j++){
                int a; cin >> a;
                data[i].push_back(a);
            }
        }
    }

    matrix operator * (matrix m){
        if(columns == m.rows){
            matrix mul(rows, m.columns);
            mul.initiate_0();
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < m.columns; j++){
                    for(int k = 0; k < columns; k++){
                        mul.data[i][j] += data[i][k] * m.data[k][j];
                    }
                }
            }
            return mul;
        }else{
            matrix err(1, 1);
            err.initiate_0();
            return err;
        }
    }
    void show(){
        cout << " the matrix is- \n";
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                cout << data[i][j] <<" ";
            }
            cout << endl;
        }
    }
};

int main(){
    matrix A(4, 4);
    A.initiate();
    matrix B(4, 4);
    B.initiate();
    matrix C = A*B;
    C.show();
}

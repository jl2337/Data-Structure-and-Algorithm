//
//  main.cpp
//  Three Sum Brute Force
//
//  Created by 刘佳杰 on 2/22/19.
//  Copyright © 2019 刘佳杰. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Three_Sum{
public:
    Three_Sum(const vector<int> &);
    vector<vector<int>> Find_Pair();
    void Print_Result();
private:
    vector<int> data;
};

Three_Sum::Three_Sum(const vector<int> &vec):data(vec){};

vector<vector<int>> Three_Sum::Find_Pair(){
    vector<vector<int>> vec = {};
    for(int i=0;i<data.size();i++){
        for(int j=i+1;j<data.size();j++){
            for(int k=j+1;k<data.size();k++){
                if(data[i]+data[j]+data[k] == 0){   // using three For loop, Brute Force, time complexity is O(N^3)
                    vec.push_back({i,j,k});
                }
            }
        }
    }
    return vec; // if failed to find pairs, return {}
}

void Three_Sum::Print_Result(){
    vector<vector<int>> vec = this->Find_Pair();
    cout << "Find pair(s) as below:\n";
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[i].size();j++){
            cout << vec[i][j] << ' ';
        }
        cout << endl;
    }
}

int main(int argc, const char * argv[]) {
    vector<int> my_vec = {30,-40,-20,-10,40,0,10,5};
    Three_Sum obj(my_vec);
    obj.Print_Result();
    return 0;
}

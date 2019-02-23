//
//  main.cpp
//  Selection Sort
//
//  Created by 刘佳杰 on 2/23/19.
//  Copyright © 2019 刘佳杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void my_swap(double &a,double &b){
    double temp = a;
    a = b;
    b = temp;
}

void Selection_Sort(vector<double> &vec){
    for(int i=0;i<vec.size();i++){
        for(int j=i+1;j<vec.size();j++){    // double For loop, Time complexity is O(N^2)
            if(vec[i] > vec[j]){
                my_swap(vec[i], vec[j]);
            }
        }
    }
    for(int i=0;i<vec.size();i++){
        cout << vec[i] << ' ';
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    fstream infile;
    vector<double> my_vec;
    infile.open("8192int.txt");
    if(!infile){
        cout << "Failed\n";
        return 0;
    }
    else{
        cout << "Succeed\n";
    }
    while(infile.get()!=EOF){
        double temp;
        infile >> temp;
        my_vec.push_back(temp);
    }
    Selection_Sort(my_vec);
    return 0;
}

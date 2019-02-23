//
//  main.cpp
//  Insertion Sort
//
//  Created by 刘佳杰 on 2/23/19.
//  Copyright © 2019 刘佳杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void my_swap(double &a, double &b){
    double temp = a;
    a = b;
    b = temp;
}

void Insertion_Sort(vector<double> &vec){
    for(int i=0;i<vec.size();i++){
        for(int j=i;j>0;j--){
            if(vec[j] < vec[j-1]){
                my_swap(vec[j], vec[j-1]);
            }
            else{
                break;  // Time complexity is O(N^2), but Insertion Sort is more efficient than Selection Sort
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
    infile.open("8192int.txt");
    if(!infile){
        cout << "Failed\n";
        return 0;
    }
    else{
        cout << "Succeed\n";
    }
    vector<double> my_vec;
    while(infile.get()!=EOF){
        double temp;
        infile >> temp;
        my_vec.push_back(temp);
    }
    Insertion_Sort(my_vec);
    return 0;
}

//
//  main.cpp
//  Shell Sort
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

void Shell_Sort(vector<double> &vec){   // Shell Sort is also called Improved Insertion Sort
    int h = 1;
    while(h < vec.size()/3){
        h = 3*h + 1;    // 1,4,13,40,121,364
    }
    while(h >= 1){
        // h- sort the vector
        for(int i=h;i<vec.size();i++){
            for(int j=i;j>=h&&(vec[j]<vec[j-h]);j-=h){
                my_swap(vec[j], vec[j-h]);
            }
        }
        h /= 3; // The worst-case number of compares used by shellsort with the 3x+1 increments is O(N 3/2).
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
    Shell_Sort(my_vec);
    return 0;
}

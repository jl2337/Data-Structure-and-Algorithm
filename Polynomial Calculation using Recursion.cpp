//
//  main.cpp
//  Polynomial Calculation using Recursion
//
//  Created by 刘佳杰 on 2/23/19.
//  Copyright © 2019 刘佳杰. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    double poly_cal(vector<double>, double);
    vector<double> a;
    unsigned int size;
    cout << "Input size\n";
    cin >> size;
    for(int i=0;i<size;i++){
        cout << "a[" << i << "]?\n";
        double temp;
        cin >> temp;
        a.push_back(temp);
    }
    cout << "x?\n";
    double x;
    cin >> x;
    cout << "The result is: " << poly_cal(a, x) << endl;
    return 0;
}

// Idea of recursion: f(x) = a[0] + x(a[1] + x(...(a[n-1] + x * a[n])...))
// A better way to calculate polynomial at a given point
double poly_cal(vector<double> a, double x){
    int n = static_cast<int>(a.size());
    double res = a[n-1];
    for(int i=n-1;i>0;i--){
        res = a[i-1] + x * res;
    }
    return res;
}

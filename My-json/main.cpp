/*************************************************************************
	> File Name: main.cpp
	> Author: 隔壁老孙无敌 
	> Mail:1686169484@qq.com 
	> Created Time: Wed Sep  6 09:14:51 2023
 ************************************************************************/

#include <iostream>
#include "json.h"
using std::cin;
using std::cout;
using std::endl;

using namespace My::json;

int main() {
    Json v1;
    Json v2 = true;
    Json v3 = 123;
    Json v4 = 1.23;
    Json v5 = "hello world";
/*
    bool b = v2;
    int i = v3;
    double f = v4;
    const std::string& s = v5;
    */
    /*Json arr;
    arr[0] = true;
    arr[1] = 123;
    arr.append(1.23);
    arr.append("hello world");
    cout << arr.str() << endl;
    bool b = arr[0];
    int i = arr[1];
    double f = arr[2];
    const std::string& s = arr[3]; 
*/
    Json obj;
    obj["bool"] = true;
    obj["int"] = 123;
    obj["double"] = 1.23;
    obj["str"] = "hello world";

    std::cout << obj.str() << std::endl;
    
    Json arr;
    arr[0] = true;
    arr[1] = 123;
    arr[2] = 1.23;
    arr[3] = "hello world"; 

    for (auto it = arr.begin(); it != arr.end(); it++) {
        std::cout << (*it).str() << std::endl;
    }
    
    cout << arr.has(0) << endl;
    cout << arr.has(4) << endl;
    
    arr.remove(0);
    cout << arr.str() << endl;
    arr.clear();
    obj.clear();
    return 0;
}

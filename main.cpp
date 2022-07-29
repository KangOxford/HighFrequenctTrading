//
// Created by kang on 29/07/2022.
//
#include <unordered_map>
#include "stdio.h"
#include <tuple>
#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "CSVRow.h"

using namespace  std;



int main()
{
    std::unordered_map<string, std::tuple<string, string, string, string>> RunningData;
//    std::unordered_map<string, std::tuple<unsigned long, int, int>> RunningData;
    std::ifstream file("/Users/kang/CppCourse/Trading/HFT/input.csv");
//    for(auto& row: CSVRange(file))
//    {
//        std::cout << "4th Element(" << row[3] << ")\n";
//    }
    int i = 0;
    for(auto& row: CSVRange(file))
    {
//        RunningData.insert(std::make_pair("aaa",std::make_tuple(1234567, 10, 12)));
        auto key = "aaa";
        if (RunningData.find(key) == RunningData.end())
        {
            RunningData.insert(std::make_pair((string)(row[1]),std::make_tuple(row[0], row[2], row[3], row[0])));
        }


//        auto iter = RunningData.find("aaa");
//        auto value = std::get<0>(*iter);
//        cout<< ">>> " << value <<endl;

//        RunningData.insert(std::make_pair((string)(row[1]),std::make_tuple((unsigned long)(row[0]), (int)(row[2]), (int)(row[3])));
//        std::cout << "4th Element(" << row[3] << ")\n";
    }
//    auto iter = RunningData.find("aaa");

//    for(auto& row: CSVRange(file))
//    {
//        std::cout << " , " << row[0] <<  " , " << row[1] << " , " << row[2] << " , " << row[3] << ")\n";
//    }


//    std::unordered_map<string, std::tuple<unsigned long, int, int>> RunningData;
//    RunningData.insert(std::make_pair("aaa",std::make_tuple(1234567, 10, 12)));
//    auto iter = RunningData.find("aaa");
//    int nSize = RunningData.size();
//    std::cout<<nSize;
//    auto lambda = [](auto x, auto y) {return x + y;}; ###



}
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
#include <charconv>
#include "CSVRow.h"

using namespace  std;



int main()
{
    std::unordered_map<string, std::tuple<string, string, string, string>> RunningData;
//    std::unordered_map<string, std::tuple<unsigned long, int, int>> RunningData;
    std::ifstream file("/Users/kang/CppCourse/Trading/HFT/input.csv");

//    string s1("123");
//    string s2("122");
//    auto judge = s1<s2;
//    cout<< judge <<endl;

    unsigned long data;
    std::string_view sv = "124";
    std::from_chars(sv.data(), sv.data() + sv.size(), data);


//    for(auto& row: CSVRange(file))
//    {
//
//        string key = std::string{row[1]};
//        if (RunningData.find(key) == RunningData.end()) //if it is a new key
//        {
//            auto min_time = row[0];
//            auto max_time = row[0];
//            RunningData.insert(std::make_pair((string)(row[1]),std::make_tuple(min_time, row[2], row[3], max_time)));
//        }
//        else //if the key has already existed
//        {
//            auto time_value = std::get<0>(*RunningData.find(key));
//            auto min_time = (row[0]<time_value) ? row[0] : time_value;
//            auto max_time = row[0];
//            RunningData.insert(std::make_pair((string)(row[1]),std::make_tuple(min_time, row[2], row[3], max_time)));
//        }


//        auto iter = RunningData.find("aaa");
//        auto value = std::get<0>(*iter);
//        cout<< ">>> " << value <<endl;

//        RunningData.insert(std::make_pair((string)(row[1]),std::make_tuple((unsigned long)(row[0]), (int)(row[2]), (int)(row[3])));
//        std::cout << "4th Element(" << row[3] << ")\n";
//    }





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
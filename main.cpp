//
// Created by kang on 29/07/2022.
//
#include <unordered_map>
#include "stdio.h"
#include "stdlib.h"
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
    std::unordered_map<string, std::tuple<unsigned long, string, string, unsigned long>> RunningData;
    std::ifstream file("/Users/kang/CppCourse/Trading/HFT/input.csv");

    for(auto& row: CSVRange(file))
    {
        unsigned long time;
        std::from_chars(row[0].data(), row[0].data() + row[0].size(), time);

        string key = std::string{row[1]};
        if (RunningData.find(key) == RunningData.end()) //if it is a new key
        {
            auto min_time = time;
            auto max_time = time;
            RunningData.insert(std::make_pair((string)(row[1]),std::make_tuple(min_time, row[2], row[3], max_time)));
        }
        else //if the key has already existed
        {
            auto time_value1 = std::get<0>(RunningData.find(key)->second);
            auto time_value2 = std::get<3>(RunningData.find(key)->second);
            auto min_time = (time > time_value1) ? time : time_value1;
            auto max_time = (time < time_value1) ? time : time_value2;
            RunningData.insert(std::make_pair((string)(row[1]),std::make_tuple(min_time, row[2], row[3], max_time)));
        }
    }

    int i =0;
    for(auto iter = RunningData.begin(); iter!=RunningData.end(); iter++)
    {
        i ++;
        auto key = iter->first;
        auto value = iter->second;
        auto min_time = std::get<0>(value);
        auto max_time = std::get<0>(value);
        std::cout << "iteration "<<i<<"min_time "<<min_time<<endl;
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
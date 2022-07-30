//
// Created by kang on 29/07/2022.
//

#include <tuple>
#include <vector>
#include <string>
#include <charconv>
#include <map>
#include <filesystem>
#include "CSVRow.h"
using namespace std;
namespace fs = std::__fs::filesystem;


int main()
{
    std::map<string, std::tuple<unsigned long, double, int, unsigned long, int>> RunningData;
//    std::ifstream infile("/Users/kang/CppCourse/Trading/HFT/input.csv");
//    std::ifstream infile("/Users/kang/CppCourse/Trading/HFT/split_aa");
//    std::__fs::filesystem::create_dicretories("");
    std::string path = "/Users/kang/CppCourse/Trading/HFT/Input";
    for (const auto & entry : fs::directory_iterator(path))
    {
//        std::cout<<0;
        std::cout << entry.path() << std::endl;
    }

//    for(auto& row: CSVRange(infile))
//    {
//        unsigned long min_time;
//        int max_price, quantity_sum, quantity;
//        std::from_chars(row[0].data(), row[0].data() + row[0].size(), min_time);
//        std::from_chars(row[2].data(), row[2].data() + row[2].size(), quantity);
//        std::from_chars(row[3].data(), row[3].data() + row[3].size(), max_price);
//
//        string key = std::string{row[1]};
//        if (RunningData.find(key) == RunningData.end()){RunningData.insert(std::make_pair((string)(row[1]),std::make_tuple(min_time, max_price, max_price, int(0), quantity)));}
//        else //if the key has already existed
//        {
//            quantity_sum = std::get<4>(RunningData.find(key)->second) + quantity;
//            double WeightedAveragePirce = std::get<1>(RunningData.find(key)->second) * (quantity_sum-quantity)/quantity_sum + 1.0 * quantity*max_price/quantity_sum;
//            max_price = std::max(max_price,std::get<2>(RunningData.find(key)->second));
//            auto diff_time = min_time - std::get<0>(RunningData.find(key)->second);
//            diff_time = std::max(diff_time, std::get<3>(RunningData.find(key)->second));
//
//            RunningData.find(key)->second =std::make_tuple(min_time, WeightedAveragePirce, max_price, diff_time, quantity_sum);
//        }
//    }
//
//
//    std::vector<string> out_string(RunningData.size());
//    std::transform(RunningData.begin(),RunningData.end(),out_string.begin(),[](auto&x){return x.first+","+to_string(get<3>(x.second))+","+to_string(get<4>(x.second))+","+to_string((int)get<1>(x.second))+","+to_string(get<2>(x.second));});
//
//
//    std::ofstream outfile;
//    outfile.open ("/Users/kang/CppCourse/Trading/HFT/output.csv");
//    for_each(out_string.begin(),out_string.end(),[&outfile](auto&x){ outfile << (x +"\n");});
//    outfile.close();

    return 0;
}
#include <tuple>
#include <vector>
#include <string>
#include <charconv>
#include <map>
#include <filesystem>
#include "CSVRow.h"
using namespace std;
namespace fs = std::__fs::filesystem;

// ========================================================== //
//                                                            //
//    High Frequency Trading Engine Jul.2022                  //
//    @Author  Kang                                           //
//    @Contact kang.li2020@outlook.com                        //
//    Funtion:                                                //
//      Calculate some tech indicator                         //
//      based on the price-quantity data                      //
//    Dependency:                                             //
//      CSVRow.h as an iterator of reading all kinds of csv   //
//                                                            //
//                                            ┌─────────┐     //
//                                      ┌────►|splitedaa│     //
//                                      │     └─────────┘     //
//    ┌─────────┐  lines   ┌────────┐   │                     //
//    │input.csv├─────────►│split.sh├───┤     ┌─────────┐     //
//    └─────────┘          └────────┘   ├────►│splitedab│     //
//                                      │     └─────────┘     //
//                                      │                     //
//                                      └────► .........      //
//                                                            //
//    ┌──────┐  ┌────┬───────┬────────┬──────────┬──────┐     //
//    │Symbol├─►│Time│WAPrice│MaxPrice│MaxTimeGap│Volume│     //
//    └──────┘  └────┴───────┴────────┴──────────┴──────┘     //
//                                                            //
// ========================================================== //

int main()
{
    std::map<string, std::tuple<unsigned long, double, int, unsigned long, int>> RunningData;
    std::string path = "/Users/kang/CppCourse/Trading/HFT/Input";
    std::vector<string> pathVector;
    for (const auto & entry : fs::directory_iterator(path)) {pathVector.push_back(entry.path());}
    std::sort(pathVector.begin(), pathVector.end());
    for(auto iter = pathVector.begin(); iter<pathVector.end(); iter++)
    {
        std::ifstream infile(*iter);
        for(auto& row: CSVRange(infile))
        {
            unsigned long min_time;
            int max_price, quantity_sum, quantity;
            std::from_chars(row[0].data(), row[0].data() + row[0].size(), min_time);
            std::from_chars(row[2].data(), row[2].data() + row[2].size(), quantity);
            std::from_chars(row[3].data(), row[3].data() + row[3].size(), max_price);

            string key = std::string{row[1]};
            if (RunningData.find(key) == RunningData.end()){RunningData.insert(std::make_pair((string)(row[1]),std::make_tuple(min_time, max_price, max_price, int(0), quantity)));}
            else //if the key has already existed
            {
                quantity_sum = std::get<4>(RunningData.find(key)->second) + quantity;
                double WeightedAveragePirce = std::get<1>(RunningData.find(key)->second) * (quantity_sum-quantity)/quantity_sum + 1.0 * quantity*max_price/quantity_sum;
                max_price = std::max(max_price,std::get<2>(RunningData.find(key)->second));
                auto diff_time = min_time - std::get<0>(RunningData.find(key)->second);
                diff_time = std::max(diff_time, std::get<3>(RunningData.find(key)->second));

                RunningData.find(key)->second =std::make_tuple(min_time, WeightedAveragePirce, max_price, diff_time, quantity_sum);
            }
        }
    }

    std::vector<string> out_string(RunningData.size());
    std::transform(RunningData.begin(),RunningData.end(),out_string.begin(),[](auto&x){return x.first+","+to_string(get<3>(x.second))+","+to_string(get<4>(x.second))+","+to_string((int)get<1>(x.second))+","+to_string(get<2>(x.second));});

    std::ofstream outfile;
    outfile.open ("/Users/kang/CppCourse/Trading/HFT/output.csv");
    for_each(out_string.begin(),out_string.end(),[&outfile](auto&x){ outfile << (x +"\n");});
    outfile.close();

    return 0;
}
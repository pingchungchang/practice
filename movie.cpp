#include<vector>
#include<string>
#include <algorithm>
#include "movie.h"
using namespace std;

bool mcmp(pair<cinema*,movietime> a,pair<cinema*,movietime> b){
    return a.second<b.second;
}
movie::movie(string name1, movietime duration1, string description1, int price_factor1)
{
    name = name1;
    duration = duration1;
    description = description1;
    time_based_table.resize(0);
    price_factor = price_factor1;
}
// movie* movie::Search(cinema* c_id, movietime t){
//     if (c_id->time_based_table.size() == 0) return NULL;
//     else{
//         for (int i = 0; i < c_id->time_based_table.size(); i++){
//             if (c_id->time_based_table[i].first == t) {
//                 return c_id->time_based_table[i].second;
//                 break;
//             }
//         }
//     }
// }
// vector<pair<cinema*, movietime>> movie::Get_Table(){
//     return this->time_based_table;
// }
bool movie::Add_Movie(cinema* c_id,movietime t){
    time_based_table.push_back(make_pair(c_id,t));
    sort(time_based_table.begin(),time_based_table.end(),mcmp);
    return true;
}
// bool movie::Delete_Movie(cinema* c_id,movietime t){
// }
#ifndef SBTREEHASH_H
#define SBTREEHASH_H

#include <map> //  a self-balancing tree (red-black)
#include <unordered_map> // a hash table
#include <string>
#include <vector>

using std::string;
using std::sort;
using std::vector;
using std::unordered_map;
using std::pair;
using std::map;

struct ana_result {
    bool found = false;
    string s1;
    string s2;
};

//Do there exist two strings that are anagrams of each other ? (use std::sort and a custom Compare)
// See https://en.cppreference.com/w/cpp/algorithm/sort
// lambda functions are fine, even preferable here
ana_result anyAnagramsSorting(vector<string> ss){
    ana_result ar;
    vector < string > sortGrams;
    for (int x = 0; x < ss.size(); x++){
        string word = ss[x];
        sort(word.begin(), word.end());
        sortGrams.push_back(word);
    }
    for (int x = 0; x < sortGrams.size(); x++){
        for (int y = x + 1; y < sortGrams.size(); y++){
            if (sortGrams[x] == sortGrams[y]){
                ar.found = true;
                ar.s1 = ss[x];
                ar.s2 = ss[y];           
                }
        }
    }
    return ar;
}

//Do there exist two strings that are anagrams of each other ? (use map, self-balancing tree)
ana_result anyAnagramsMap(vector<string> strings){
    ana_result res;

    map < string, string > sortMaps;
    for( int x = 0; x < strings.size(); x++){
        string sorting = strings[x];
        sort(sorting.begin(), sorting.end());
        if (sortMaps.find(sorting) == sortMaps.end())
        sortMaps.insert(pair < string, string > (sorting, strings[x]));
        else{
            res.found = true;
            res.s1 = sortMaps.find(sorting)-> second;
            res.s2 = strings[x];
        }
        
    }
    return res;
}

//Do there exist two strings that are anagrams of each other ? (use unordered_map, hash table)
ana_result anyAnagramsHash(vector<string> strings){
    ana_result res;
    
    unordered_map < string, string > sortMaps;
    for (int x = 0; x < strings.size(); x++){
        string sorting = strings[x];
        sort(sorting.begin(), sorting.end());
        if (sortMaps.find(sorting) == sortMaps.end())
        sortMaps.insert(pair < string, string > (sorting, strings[x]));
        else{
             res.found = true; 
             res.s1 = sortMaps.find(sorting) -> second;
             
    }
  }

    return res;
}

#endif //SBTREEHASH_H

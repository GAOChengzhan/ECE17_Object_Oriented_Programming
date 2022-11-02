//
//  MadlibWordProvider.hpp
//  Assignment2
//

#ifndef MadlibWordProvider_hpp
#define MadlibWordProvider_hpp

#include <fstream>
#include <iostream>
#include <map>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

//This enum determines the TYPES of words we can interact with...
enum class WordType {invalid, noun, pluralnoun, name, verb, adjective,
                     adverb, number, color, fruit, animal, place};

//WOW -- what is this? Someone should ask about it in class!
static std::map<WordType, std::string> gLabels = {
  std::make_pair(WordType::noun, "noun"),
  std::make_pair(WordType::pluralnoun, "pluralnoun"),
  std::make_pair(WordType::name, "name"),
  std::make_pair(WordType::verb, "verb"),
  std::make_pair(WordType::adjective, "adjective"),
  std::make_pair(WordType::adverb, "adverb"),
  std::make_pair(WordType::number, "number"),
  std::make_pair(WordType::color, "color"),
  std::make_pair(WordType::fruit, "fruit"),
  std::make_pair(WordType::animal, "animal"),
  std::make_pair(WordType::place, "place")
};

class MadlibWordProvider {
public:

    MadlibWordProvider() = default;

    //make sure you implement the OCF...
    virtual ~MadlibWordProvider() = default;

    //get a word of a particular type (noun, verb, etc...)
    virtual std::string getSubstituteWord(WordType aType)=0;

    //convert word-type string to enum value...
    static WordType getTypeForLabel(std::string &aWord) {

        std::transform(aWord.begin(), aWord.end(), aWord.begin(), ::tolower); //lowercase

        for(auto thePair : gLabels) {
            if(thePair.second==aWord) {
                return thePair.first;
            }
        }
        return WordType::invalid;
    }

    //pass in an enum (type), and get a representative label in return...
    static std::string getLabelForType(WordType aType) {
    return gLabels[aType];
    }
};

#endif /* MadlibWordProvider_hpp */

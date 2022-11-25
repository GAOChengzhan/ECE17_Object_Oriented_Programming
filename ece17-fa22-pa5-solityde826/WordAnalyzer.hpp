//
//  WordAnalyzer.hpp
//  Assignment5
//

#ifndef WordAnalyzer_hpp
#define WordAnalyzer_hpp

#include <stdio.h>
#include <iosfwd>
#include <iostream>
#include <fstream>
#include <map>
#include <functional>
#include <string>
#include <vector>
#include <algorithm>
using std::cout, std::endl,
        std::ifstream, std::map, std::string, std::vector, std::function,
        std::pair;
using WordFreq = map<string, size_t>;
using decode = map<string, string>;

namespace ECE17 {
  
  class WordAnalyzer {
  public:
    WordAnalyzer();
    WordAnalyzer(const WordAnalyzer &aCopy);
    ~WordAnalyzer();
    WordAnalyzer& operator=(const WordAnalyzer &aCopy);
    //student: finish this...
    size_t countWords(std::istream &anInput, std::ostream &anOutput);
    size_t getWordPairs(std::istream &anInput, std::ostream &anOutput);
    size_t compress(std::istream &anInput, std::ostream &anOutput);
    size_t decompress(std::istream &anInput, std::ostream &anOutput);
  private:
    WordFreq wordFreq;
    WordFreq pairFreq;
  };

}

#endif /* WordAnalyzer_hpp */

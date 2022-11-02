//
//  MadlibAutoWordProvider.hpp
//  Assignment2
//

#ifndef MadlibAutoWordProvider_hpp
#define MadlibAutoWordProvider_hpp


#include "MadlibWordProvider.hpp"

//a tiny little class, with a base class
class MadlibAutoWordProvider : public MadlibWordProvider {
public:
    MadlibAutoWordProvider(); //ctor (don't forget the rest of the OCF)
    MadlibAutoWordProvider(const MadlibAutoWordProvider &aMadlibAutoWordProvider);
    MadlibAutoWordProvider &operator=(const MadlibAutoWordProvider &aMadlibAutoWordProvider);
    ~MadlibAutoWordProvider() override;
    virtual std::string getSubstituteWord(WordType aType) override; //provide random words for each type...
    bool readJSON(const char *jsonPath);
    void categoryWords();

protected:
    std::map<std::string,std::vector<std::string>> CategoryWordList;
    struct WORD{
        std::string word;
        std::string pos;
        std::string category;
    };
    std::vector<WORD> word_list;
};



#endif /* MadlibAutoWordProvider_hpp */

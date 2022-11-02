//
//  MadlibUserWordProvider.hpp
//  Assignment2
//

#ifndef MadlibUserWordProvider_hpp
#define MadlibUserWordProvider_hpp

#include <stdio.h>
#include "MadlibWordProvider.hpp"

class MadlibUserWordProvider : public MadlibWordProvider {
public:
    MadlibUserWordProvider(); //ctor
    MadlibUserWordProvider(const MadlibUserWordProvider &aMadlibUserWordProvider);
    MadlibUserWordProvider &operator=(const MadlibUserWordProvider &aMadlibUserWordProvider);
    ~MadlibUserWordProvider() override;
    virtual std::string getSubstituteWord(WordType aType) override;

};

#endif /* MadlibUserWordProvider_hpp */

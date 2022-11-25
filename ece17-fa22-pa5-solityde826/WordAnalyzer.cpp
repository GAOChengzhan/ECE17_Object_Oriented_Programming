//
//  WordAnalyzer.cpp
//  Assignment5
//

#include "WordAnalyzer.hpp"
#include <ctype.h>
#include <vector>
#include <algorithm>
#include <sstream>
#include <stdio.h>
#include <iosfwd>
#include <iostream>
#include <fstream>
#include <map>
#include <functional>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using std::cout, std::endl,
        std::ifstream, std::map, std::string, std::vector, std::function,std::string,
        std::pair;
using WordDict = map<string, size_t>;
using DecodeDict = map<string , string>;

namespace ECE17 {
    WordAnalyzer::WordAnalyzer() = default;
    WordAnalyzer::WordAnalyzer(const WordAnalyzer &aCopy) {}
    WordAnalyzer::~WordAnalyzer() = default;
    WordAnalyzer &WordAnalyzer::operator=(const WordAnalyzer &aCopy) {
        return *this;
    }
    //student: finish this...
    bool isPunctuation(char aChar) {
        static string punct("\".;?!:,-(){}[]");
        return string::npos != punct.find(aChar);
    }
    string processWord(string &word){
        int i,j;
        for(i=0;i<word.length();i++){
            if (!isPunctuation(word[i])){
                break;
            }
        }
        word.erase(0,i);
        if(0==word.length()){
            return "";
        }
        for(j=word.length()-1;j>=0;j--){
            if (!isPunctuation(word[j])){
                break;
            }
        }
        if(j<(word.length()-1)){
            word.erase(word.begin()+1+j);
        }

        if(0==word.length()){
            return "";
        }
        if(isupper(word[0])){
            word[0]=(word[0]+32); //lowerCase to higherCase
        }
        return word;
    }
    size_t WordAnalyzer::countWords(std::istream &anInput, std::ostream &anOutput){
        string currentWord;
        size_t sumAllWords(0);
        while(anInput>>currentWord){
            currentWord= processWord(currentWord);
            if (currentWord!=""){
                if(wordFreq.count(currentWord)){ //determine if already know the word
                    wordFreq[currentWord]+=1;
                }
                else{
                    wordFreq[currentWord]=1;
                    sumAllWords+=1;
                }
            }
            else{
                continue;
            }
        }
        anOutput<<"Total Words:"<<sumAllWords<<'\n';
        for (map<string,size_t>::iterator i = wordFreq.begin(); i != wordFreq.end(); i++)
        {
            anOutput << i->first<<": "<< i->second << "\n";
        }
        anOutput<<endl;
        return sumAllWords;
    };
    size_t WordAnalyzer::getWordPairs(std::istream &anInput, std::ostream &anOutput){
        string currentWord;
        string lastWord;
        string pair;
        size_t sumPairs(0);
        if (anInput>>lastWord){
            lastWord = processWord(lastWord);
        }
        while(anInput>>currentWord){
            currentWord = processWord(currentWord);
            if(currentWord!=""){
                pair=lastWord+" "+currentWord;
                if(pairFreq.count(pair)){ //determine if already know the word
                    pairFreq[pair]+=1;
                }
                else{
                    pairFreq[pair]=1;
                    sumPairs+=1;
                }
                lastWord=currentWord;
            }
            else{
                continue;
            }
        }
        for (map<string,size_t>::iterator i = pairFreq.begin(); i != pairFreq.end(); i++)
        {
            anOutput << i->first<<": "<< i->second << "\n";
        }
        anOutput<<endl;
        return sumPairs;
    };

    size_t WordAnalyzer::compress(std::istream &anInput, std::ostream &anOutput){
        vector<std::pair<string, int>> suffixCheck = {
                {"self",4},
                {"est", 3},
                {"ing", 3},
                {"ive",3},
                {"ers",3},
                {"er", 2},
                {"es", 2},
                {"ed", 2},
                {"ss",2},
                {"ly",2},
        };
        string aWord;
        int DicIndex(0);
        size_t length(0);
        string back;
        bool enter(false);
        bool hasSuffix(false);
        bool hasS(false);
        string tempSuffix;
        WordDict wordDict;
        while(anInput>>aWord){
            enter = false;
            hasSuffix= false;
            tempSuffix="";
            hasS= false;
            back = "";
            while(!anInput.eof() && anInput.peek()=='\n') {
                enter = true;
                anInput.get();
            }

            while (isPunctuation(aWord[0])){
                anOutput<<aWord[0];
                aWord.erase(aWord.begin());
            }

            while(isPunctuation(aWord.back())){
                back=back+aWord.back();
                aWord.erase(aWord.end()-1);
            }
            if(back!="") reverse(back.begin(),back.end());
            if (aWord!="") {
                if (isupper(aWord[0])) {
                    aWord[0] = (aWord[0] + 32); //higherCase to lowerCase
                    anOutput << '`';
                }
                length=aWord.length();
                for(vector<std::pair<string, int>>::iterator i=suffixCheck.begin();i!=suffixCheck.end();i++){
                    if(length>(i->second) && aWord.substr(length-i->second)==i->first
                        && (length>((std::to_string(DicIndex).length())+length-i->second+1) ||wordDict.count(aWord.substr(0,length-i->second)))
                        ){
                        tempSuffix=aWord.substr(length-i->second);
                        hasSuffix= true;
                        aWord.erase(length-i->second,i->second);
                        break;
                    }
                }
                length=aWord.length();
                if(!hasSuffix && aWord.back()=='s' &&
                (length>4 || wordDict.count(aWord.substr(0,length-1)))
                ){
                    hasS= true;
                    aWord.erase(aWord.end()-1);
                }

                if (wordDict.count(aWord)) { //determine if already know the word
                    anOutput << wordDict[aWord];
                    if(hasSuffix) anOutput<<tempSuffix;
                } else {
                    wordDict[aWord] = DicIndex;
                    anOutput << aWord;
                    DicIndex += 1;
                    if(hasSuffix) anOutput<<'`'<<tempSuffix;
                }
            }
            if(hasS){
                anOutput<<'s';
            }
            //back punctuation
            if(back!=""){
                anOutput<<back;
            }
            // enter or space
            if(enter){
                anOutput<<"\n";
            }
            else{
                anOutput<<" ";
            }

        }

        return 1;
    };
    size_t WordAnalyzer::decompress(std::istream &anInput, std::ostream &anOutput){
        string aWord;
        string back;
        bool enter(false);
        bool capital(false);
        bool hasSuffix(false);
        bool hasS(false);
        size_t length;
        DecodeDict decodeDict;
        int DicIndex(0);
        string tempSuffix;
        while(anInput>>aWord){
            back="";
            enter = false;
            hasSuffix = false;
            hasS = false;
            capital= false;
            tempSuffix="";
            while(!anInput.eof() && anInput.peek()=='\n') {
                enter = true;
                anInput.get();
            }
            //front punctuation
            while (isPunctuation(aWord[0])){
                anOutput<<aWord[0];
                aWord.erase(aWord.begin());
            }
            //detect enter
            //back punctuation
            while(isPunctuation(aWord.back())){
                back=back+aWord.back();
                aWord.erase(aWord.end()-1);
            }
            if(back!="") reverse(back.begin(),back.end());
            if(aWord!=""){
                if (aWord[0]=='`'){
                    aWord.erase(aWord.begin());
                    capital = true;
                }

                if (isdigit(aWord[0])){
                    while(isalpha(aWord.back())){
                        tempSuffix=tempSuffix+aWord.back();
                        aWord.erase(aWord.end()-1);
                        hasSuffix = true;
                    }
                    if (hasSuffix) reverse(tempSuffix.begin(), tempSuffix.end());
                    length=aWord.length();
                    if(!hasSuffix && aWord.back()=='s' &&
                       (length>4 || decodeDict.count(aWord.substr(0,length-1)))
                            ){
                        hasS = true;
                        aWord.erase(aWord.end()-1);
                    }
                    aWord = decodeDict[aWord];
                }


                else{
                    length=aWord.length();
                    size_t j;
                    for(j=0;j<length;j++){
                        if(aWord[j]=='`'){
                            hasSuffix= true;
                            break;
                        }
                    }
                    if(hasSuffix){
                        tempSuffix=aWord.substr(j+1);
                        aWord.erase(j,length-j);
                    }
                    length=aWord.length();
                    if(!hasSuffix && aWord.back()=='s' &&
                       (length>4 || decodeDict.count(aWord.substr(0,length-1)))
                            ){
                        hasS = true;
                        aWord.erase(aWord.end()-1);
                    }
                    decodeDict[std::to_string(DicIndex)]=aWord;
                    DicIndex+=1;
                }

                if(capital) aWord[0]-=32;
                anOutput<<aWord;
            }
            if(hasSuffix) anOutput<<tempSuffix;
            if(hasS) anOutput<<'s';
            if(back!="") anOutput<<back;
            if(enter) anOutput<<"\n";
            else anOutput<<" ";

        }
        return 1;
    };

    

}

//
//  MadLibsController.cpp
//  Assignment2
//

#include "MadLibsController.hpp"
#include <fstream>
#include <ctype.h>
#include <vector>
#include <algorithm>
#include <sstream>

MadLibsController::MadLibsController() {
}

std::vector<std::string> MadLibsController::getWords() {
    return words;
}

bool isPunct(char aChar) {
  static std::string punct(".;?!:,'-");
  return std::string::npos != punct.find(aChar);
}

//Student: in this method, show the final result of your madlib (with user data) to given output
void MadLibsController::showFinishedStory(std::ostream &anOutput) {
    anOutput << "Your madlib is: \n";
    size_t j=0;
    for(size_t i=0;i<raw_file.size();++i) {
        if(i==subPosition[j]) {
            anOutput<<substituteWords[j]<<" ";
            ++j;
        }
        else {
            anOutput << raw_file[i] << " ";
        }
    }
    anOutput<<std::endl;
    //now show the user their madlib, with their words embedded in the output...
}

//Notice how we separated 'reading a file' from other operations?
//In this method, you read the madlib template file...
bool MadLibsController::readFile(const char *aPath) {
    std::fstream rawtxtFile;
    rawtxtFile.open(aPath);
    if (rawtxtFile.is_open()){ //checking whether the file is open
        std::string line;
        while (std::getline(rawtxtFile, line)) {
            std::stringstream  lineStream(line);
            std::string word;
            while (!lineStream.eof()) {
                lineStream >> word;
                raw_file.push_back(word);
            }
            raw_file.push_back("\n");// notice to add the "\n" manually, otherwise it would turn out as error
        }
        raw_file.pop_back(); // delete the last redundant "\n"
//        std::string word;
//        while (rawtxtFile >> word)
//        {
//            raw_file.push_back(word);
//        }
        rawtxtFile.close();
        return true;
    }
    else{
        std::cerr<<"Cannot open the raw txt file!"<<std::endl;
    }
    return false;
}

//Find all the capitalized words madlib (file), and ask provider for word substitutes...
void MadLibsController::getSubstitutes(MadlibWordProvider &aProvider) {
    //STUDENT: iterate through the madlib file (words), and ask your word provider for each CAPITALIZED word...
    for(size_t i=0;i<raw_file.size();i++){
        std::string word = raw_file[i];
        size_t index=0;
        bool substitute = false;
        bool hasPunt = false;
        std::string newWord;
        std::string punt;
        for (unsigned char c :word){
            if (!isPunct(c)){
                if(std::isupper(c)){
                    substitute = true;
                    index++;
                }
                else{
                    substitute = false;
                    break;
                }
            }
            else{
                punt=word.substr(index);
                newWord=word.substr(0,index);
                hasPunt = true;
                break;
            }
        }
        if (substitute){
            if (word=="A" or word.size()<=1){
                continue;
            }
            if (hasPunt){
                WordType aWordType = aProvider.getTypeForLabel(newWord);
                std::string subWord = aProvider.getSubstituteWord(aWordType);
                words.push_back(subWord);
                subWord+=punt;
                substituteWords.push_back(subWord);
                subPosition.push_back(i); 
            }
            else {
                WordType aWordType = aProvider.getTypeForLabel(word);
                std::string subWord = aProvider.getSubstituteWord(aWordType);
                words.push_back(subWord);
                substituteWords.push_back(subWord);
                subPosition.push_back(i);
            }
        }

//        if (std::all_of(word.begin(), word.end(),[](unsigned char c)
//                        { return std::isupper(c); })) {
//            //use two methods form class wordProvider
//            //store the substitute words
//        }
    }
}

bool MadLibsController::runStory(const char *aFilename, MadlibWordProvider &aProvider, std::ostream &anOutput) {
    if(readFile(aFilename)) {
        getSubstitutes(aProvider); //get replacement for each CAPITALIZED word (substitutes)
        showFinishedStory(anOutput);
        return true;
    }
    return false;
}


//
//  MadlibAutoWordProvider.cpp
//  Assignment2
//

#include "MadlibAutoWordProvider.hpp"

MadlibAutoWordProvider::MadlibAutoWordProvider() : MadlibWordProvider() {
    // We provide a json file that's loaded with starter words
    readJSON("words.json");
    categoryWords();
}
MadlibAutoWordProvider::MadlibAutoWordProvider(const MadlibAutoWordProvider &aMadlibAutoWordProvider) {
    *this = aMadlibAutoWordProvider;
}
MadlibAutoWordProvider &MadlibAutoWordProvider::operator=(const MadlibAutoWordProvider &aMadlibAutoWordProvider){
    return *this;
}
MadlibAutoWordProvider::~MadlibAutoWordProvider(){}

//STUDENT ask chatbot for word of given type; return that to caller...
std::string MadlibAutoWordProvider::getSubstituteWord(WordType aType) {
    //STUDENT: get bot to give you random word of given type...
    //Don't forget to handle the special case of plural nouns
    std::string substituteWord;
    std::string type = getLabelForType(aType);
    bool addS= false;
    if (type == "pluralnoun") {
        type = "noun";
        addS = true;
    }
    if (CategoryWordList.find(type) == CategoryWordList.end()){
        return "Error! Cannnot find "+ type +" type";
    }
    else {
        std::vector<std::string> temp = CategoryWordList[type];
        std::size_t length = temp.size();
        size_t randomIndex = (rand() % length) ;
        substituteWord=temp[randomIndex];
        if (addS){
            substituteWord+='s';
        }
        addS = false;
        return substituteWord;
    }
}

void MadlibAutoWordProvider::categoryWords() {
    for (size_t i = 0; i < word_list.size(); i++) {
        if (word_list[i].category == "") {
            CategoryWordList[word_list[i].pos].push_back(word_list[i].word);
        }
        else{
            CategoryWordList[word_list[i].category].push_back(word_list[i].word);
        }
    }


}

bool MadlibAutoWordProvider::readJSON(const char *jsonPath) {
   std::ifstream f;
   f.open(jsonPath);
   if(!f.is_open()) {
//        std::cout << jsonPath;
        std::cerr << "Error opening JSON file!" << std::endl;
        return false;
   }
   std::string line, word, first_split;
   while (!f.eof()) {
      WORD curr_line;
      if (line.find("\"WORD\"") != std::string::npos) {
         first_split = line.substr(line.find(":"), line.find("\","));
         word = first_split.substr(first_split.find("\"")+1, first_split.find("\",")-3);
         curr_line.word = word;
         std::getline(f, line);
      }
      if(line.find("\"POS\"") != std::string::npos){
         first_split = line.substr(line.find(":"), line.find(","));
         word = first_split.substr(first_split.find("\"")+1, first_split.find("\",")-3);
         curr_line.pos = word;
         std::getline(f, line);
      }
      if(line.find("\"CATEGORY\"") != std::string::npos){
         first_split = line.substr(line.find(":"), line.find(","));
         if(first_split.compare(": \"\"") != 0) {
            word = first_split.substr(first_split.find("\"")+1, first_split.find_last_of("\"")-3);
            curr_line.category = word;
         }
         word_list.push_back(curr_line);
         std::getline(f, line);
      }
      else {
         std::getline(f, line);
      }
   }
   return true;
}

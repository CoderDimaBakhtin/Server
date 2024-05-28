// Why here are spaces?

#include"FileHandler.h"


// Not sure this class gives a lot of improvements
FileHandler::FileHandler(std::string name){
    fout.open(name,std::ios::app);
    if (!fout.is_open()) {
        throw std::invalid_argument("\nOpen File failure \n");
    }
}


void FileHandler::WriteLine(std::string line){
    fout << line << std::endl;
}

FileHandler::~FileHandler(){
    fout.close();
}



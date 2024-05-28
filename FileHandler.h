
#include<iostream>
#include<string>
#include <fstream>

class FileHandler{
private:
    std::ofstream fout;

public:
    // const std::string&
    FileHandler(std::string name); // copy

    void WriteLine(std::string line); // std::string should be passed by const reference

    ~FileHandler();

};

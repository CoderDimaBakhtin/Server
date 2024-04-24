
#include<iostream>
#include<string>
#include <fstream>

class FileHandler{
private:
    std::ofstream fout;

public:
    FileHandler(std::string name);

    void WriteLine(std::string line);

    ~FileHandler();

};

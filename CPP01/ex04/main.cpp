#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>

void  replace(std::ifstream& iFile, std::ofstream& oFile, char *s1, char *s2){
  std::stringstream buffer;
  buffer << iFile.rdbuf();
  std::string content = buffer.str();

  size_t position = 0;
  while((position = content.find(s1, position)) != std::string::npos){
    std::string before = content.substr(0, position);
    std::string after = content.substr(position + strlen(s1));
    content = before + s2 + after;
    position += strlen(s2);
  }
  oFile << content;
}

int main(int arc, char **arv){
  if (arc != 4){
    std::cout << "Number of argument is incorrect!"<< std::endl;
    return 1;
  }

  std::ifstream iFile(arv[1],std::ios::in);
  if (!iFile.is_open()){
    std::cout << "Error: could not open file."<< std:: endl;
    return 1;
  }

  char *fileName = new char[std::strlen(arv[1]) + std::strlen(".replace") + 1];
  std::strcpy(fileName,arv[1]);
  std::strcat(fileName,".replace");

  std::ofstream oFile(fileName,std::ios::out); 
  if (!oFile.is_open()){
    std::cout << "Error: could not open file."<< std:: endl;
    return 1;
  }

  replace(iFile,oFile, arv[2], arv[3]);

  delete[] fileName;
  iFile.close();
  oFile.close();
  return 0;
}
#include "json.hpp"

#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){

  if(argc < 3){
    cout << "to few parameters" << endl << "Usage : " << argv[0] << " <input file> <output file> [minify = 0]" << endl;
    return 1;
  }else if(string(argv[1]) == string(argv[2])){
    cout << "Invalid parameters" << endl << "input and output files can\'t be the same" << endl;
    return 2;
  }
  string source, dest;
  source = argv[1];
  dest = argv[2];

  bool minify(false);
  if(argc >= 4)
    if(atoi(argv[3]) == 0) minify = false;
  json::Value::minify = minify;

  ifstream readFile(source);
  string test( (std::istreambuf_iterator<char>(readFile)),
               (std::istreambuf_iterator<char>()        ) );

  size_t i(0);
  json::Object global(json::parse(test, i));


  ofstream json(dest);
  json << global;
  json.close();

  return 0;
}

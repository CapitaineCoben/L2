#include <iostream>
#include "pugixml.hpp"
#include "pugiconfig.hpp"
#include "pugixml.cpp"
#include <string>

using namespace std;
using namespace pugi;

int main(int argc, char const *argv[]) {

  if (argc != 2) {
    cerr << "invalid number of arguments" << endl;
    return 1;
  }

  xml_document test;
  xml_node n1;
  xml_attribute a1;
  string s1;

  xml_parse_result result = test.load_file(argv[1]);
  n1 = test.first_child();
  n1 = n1.first_child().first_child();
  a1 = n1.first_attribute();
  s1 = n1.value();



for (xml_node library = test.first_child(); library; library = library.next_sibling())
{
    cout << "library:";

    for (xml_attribute attr = library.first_attribute(); attr; attr = attr.next_attribute())
    {
        cout << " " << attr.name() << " : " << attr.value();
    }
    cout << endl;

    for (xml_node days = library.first_child().first_child(); days; days=days.next_sibling()) {
      cout << " " << days.child_value() << endl;
    }

    cout << endl;
}



   cout << result.description() << endl;
  // cout << test.first_child().first_attribute().value() << endl;
  // cout << n1.child_value()<< endl;
  //

  cout << strcmp((const char*) "tata",(const char*) "tota")<<endl;

  return 0;
}

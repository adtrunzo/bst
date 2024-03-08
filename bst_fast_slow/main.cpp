//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

#include "bst_fast_and_slow.hh"
#include <fstream>
#include <iostream>
#include <cstdlib>
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

void fast_test(char *file){
  string next;
  
  //create fast tree
  BSTree_Fast<string> tree = BSTree_Fast<string>();
  std::ifstream inStream;
  inStream.open(file, std::ifstream::in);

  while(inStream >> next){
   tree.insert(next);
   
   }
  //tree.print();
 
 // cout<<"contains love"<<tree.contains("love");
 // cout<<"contains death"<<tree.contains(*death);
 // cout<<"contains tyranny"<<tree.contains(*tyranny);

}
//-----------------------------------
void slow_test(char *file){
  string next;
  //create slow tree
 // BSTree_Slow<char *> tree = BSTree_Slow<char *>();
  ifstream inStream;
  inStream.open(file, std::ifstream::in);

  while(inStream >> next){
    //tree.insert(next);
  }
  //tree.print();
 // cout<<"contains love"<<tree.contains("love");
 // cout<<"contains death"<<tree.contains("death");
 // cout<<"contains tyranny"<<tree.contains("tyranny");
}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

int main(int argc, char** argv)
{
  fast_test(argv[1]);
  slow_test(argv[1]);
  return 1;
}


//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

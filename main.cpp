#include <iostream>
#include "print_ip.h"

int main() 
{
  print_ip(char(-1),std::cout);
  std::cout << std::endl;

  print_ip(short(0),std::cout);
  std::cout << std::endl;

  print_ip(int(2130706433),std::cout);
  std::cout << std::endl;

  print_ip(long(8875824491850138409),std::cout);
  std::cout << std::endl;

/////////////////////////////////////////////////////////////////////////////////////////

  std::cout << std::endl << "print_string: " << std::endl;

  print_ip(std::string{"123.45.67.89.101.112.131.41"},std::cout);
  std::cout << std::endl;

/////////////////////////////////////////////////////////////////////////////////////////

  std::cout << std::endl << "print_containers: " << std::endl;

  print_ip(std::vector<char>{1,static_cast<char>(244),-1},std::cout);
  std::cout << std::endl;

  print_ip(std::vector<int>{1,1675,4598},std::cout);
  std::cout << std::endl;

  print_ip(std::list<short>{0,457,-254},std::cout);
  std::cout << std::endl;

  print_ip(std::list<long>{8875824491850138409,887582449185013840},std::cout);
  std::cout << std::endl;

////////////////////////////////////////////////////////////////////////////////////////////

  std::cout << std::endl << "print_tuple: " << std::endl;

  print_ip(std::make_tuple(static_cast<long>(8875824491850138409),std::vector<char>{1,2,-1},std::string{"111.111"}),std::cout);
  std::cout << std::endl;

  return 0;
}
#include <iostream>
#include <bitset>

template<typename T>
void print_ip(T value, std::ostream &out) {
  bool* mas = reinterpret_cast<bool*>(&value);
  for (int i = sizeof(T)-1; i > 0; --i)
    out << mas[i] << ".";
  out << mas[0];
}
#include <iostream>

#include <string>
#include <vector>
#include <list>
#include <tuple>

#include <type_traits>

void print_ip(bool* value, int N, std::ostream &out) {
  
  while (N>0) {
    out << *(value+N) << ".";
    N--;
  }

  out << *value;
}

/////////////////////////////////////////////////////////////////////////////

template<typename T>
typename std::enable_if<std::is_integral<T>::value,void>::type print_ip(T value, std::ostream &out) {
  print_ip(reinterpret_cast<bool*>(&value), sizeof(T)-1, out);
}

/////////////////////////////////////////////////////////////////////////////

void print_ip(const std::string &value, std::ostream &out) {
  out << value;
}

/////////////////////////////////////////////////////////////////////////////

template<typename T>
typename std::enable_if<std::is_integral<typename T::value_type>::value,void>::type print_ip(const T &value, std::ostream &out) {
  for (auto it = value.begin(); it != value.end(); it++) {
    if (it != value.begin())
      out << "..";
    print_ip(*it,out);
  }
}

/////////////////////////////////////////////////////////////////////////////

template<int index, typename ...Args>
struct print_tuple {
  void operator() (const std::tuple<Args...> &value,std::ostream &out) {
    print_tuple<index - 1, Args...>{}(value,out);
    out << "...";
    print_ip(std::get<index>(value),out);
  }
};

template<typename... Args>
struct print_tuple<0, Args...> {
  void operator() (const std::tuple<Args...> &value,std::ostream &out) {
    print_ip(std::get<0>(value),out);
  }
};

template<typename ...Args>
constexpr void print_ip(const std::tuple<Args...> &value, std::ostream &out) {
  const auto size = std::tuple_size<std::tuple<Args...>>::value;
  print_tuple<size-1,Args...>{}(value,out);
}
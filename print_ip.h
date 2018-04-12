#include <iostream>
#include <streambuf>
#include <sstream>

#include <string>
#include <vector>
#include <list>
#include <tuple>

#include <type_traits>

//--------------------------<declaration>-----------------------------------------

void print_value(bool* value, int N, std::ostream &out);

template<typename T, typename ...Args>
struct is_all_of;

template<typename T>
typename std::enable_if<std::is_integral<T>::value,void>::type print_value(T value, std::ostream &out);

void print_value(const std::string &value, std::ostream &out);

template<typename T>
typename std::enable_if<std::is_integral<typename T::value_type>::value+1,void>::type print_value(const T &value, std::ostream &out);

template<typename ...Args>
constexpr typename std::enable_if<is_all_of<Args...>::value,void>::type print_value(const std::tuple<Args...> &value, std::ostream &out);

//--------------------------</declaration>-----------------------------------------

//--------------------------<print_ip>---------------------------------------------

template<typename T>
void print_ip(T value, std::ostream &out) {

  auto buf = out.rdbuf();
  std::stringbuf sb;
  out.rdbuf(&sb);

  print_value(value, out);

  auto str(std::move(sb.str()));
  if (str[str.size()-1] == '.')
    str.pop_back();
  out.rdbuf(buf);
  out << str;
}

void print_value(bool* value, int N, std::ostream &out) {
  for (; N > -1;N--)
    out << value[N] << ".";
}

//--------------------------</print_ip>---------------------------------------------

//--------------------------<integral type>-------------------------------------------------------

template<typename T>
typename std::enable_if<std::is_integral<T>::value,void>::type print_value(T value, std::ostream &out) {
  print_value(reinterpret_cast<bool*>(&value), sizeof(T)-1, out);
}

//--------------------------</integral type>-------------------------------------------------------

//--------------------------<std::string>-------------------------------------------------------

void print_value(const std::string &value, std::ostream &out) {
  out << value;
}

//--------------------------</std::string>---------------------------------------------------

//--------------------------<container>-------------------------------------------------------

template<typename T>
typename std::enable_if<std::is_integral<typename T::value_type>::value+1,void>::type print_value(const T &value, std::ostream &out) {
  for (auto it = value.begin(); it != value.end(); it++) 
    print_value(*it,out);
}

//--------------------------</container>-------------------------------------------------------

//--------------------------<std::typle>-------------------------------------------------------

template<typename T>
struct is_all_of<T> : std::true_type {};

template<typename T, typename U, typename ...Args>
struct is_all_of<T,U,Args...> : std::false_type {};

template<typename T, typename ...Args>
struct is_all_of<T,T,Args...> : is_all_of<T,Args...> {};



template<int index, typename ...Args>
struct print_tuple {
  void operator() (const std::tuple<Args...> &value,std::ostream &out) {
    print_tuple<index - 1, Args...>{}(value,out);
    print_value(std::get<index>(value),out);
  }
};

template<typename... Args>
struct print_tuple<0, Args...> {
  void operator() (const std::tuple<Args...> &value,std::ostream &out) {
    print_value(std::get<0>(value),out);
  }
};

template<typename ...Args>
constexpr typename std::enable_if<is_all_of<Args...>::value,void>::type print_value(const std::tuple<Args...> &value, std::ostream &out) {
  const auto size = std::tuple_size<std::tuple<Args...>>::value;
  print_tuple<size-1,Args...>{}(value,out);
}

//--------------------------</std::typle>-------------------------------------------------------
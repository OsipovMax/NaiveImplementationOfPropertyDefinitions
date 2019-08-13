#include <iostream>

using namespace std;

template <typename T>
struct Constancy {
  static constexpr bool value = false;
};

template <typename T>
struct Constancy<const T> {
  static constexpr bool value = true;
};

template <typename T>
class ConstChacker {
 public:
  static constexpr bool value = Constancy<T>::value;
};

int main() {
  cout << std::boolalpha;
  cout << ConstChacker<int>::value << endl;
  cout << ConstChacker<const int>::value << endl;
  cout << ConstChacker<const int*>::value << endl;
  cout << ConstChacker<int* const>::value << endl;
  cout << ConstChacker<const int&>::value << endl;
  return 0;
}
using namespace std;

class A {
 public:
  int sum() { return a + b; }
 private:
  int a = 3, b = 3;
};

class B {
 public:
  int mul() { return c * d; }
 private:
  int c = 1, d = 3;
};

template <typename T1, typename T2>
class IsSame {
 public:
  static constexpr bool value = false;
};

template <typename T>
class IsSame<T, T> {
 public:
  static constexpr bool value = true;
};

template <typename T>
class IsMemberFunction {
 public:
  static void typeChaker(...);
  template <typename G>
  static auto typeChaker(G* g) -> decltype(g->sum());
  static constexpr bool resultValue =
      IsSame<int, decltype(typeChaker((T*) nullptr))>::value;
};
static_assert(IsMemberFunction<A>::resultValue == true,
              "There is no specified member function");
int main() { return 0; }
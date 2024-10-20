// NOTE: this lab is currently broken.
// After migrating to a new compiler version the speedup is no longer measurable consistently.
// You can still try to solve it to learn the concept, but the result is not guaranteed.

#include <array>

// Assume those constants never change
constexpr int N = 10000;
constexpr int minRandom = 0;
constexpr int maxRandom = 100;

// FIXME: this data structure can be reduced in size
#if 0
struct S {
  int i;
  long long l;
  short s;
  double d;
  bool b;

  bool operator<(const S &s) const { return this->i < s.i; }
};

#else
struct S {
  float d;
  long long l:16;      // bitfields - only 16 bits (1000 x 1000 is the max value)
  int i:8;             // bitfields - only 7 bits are needed, just added 1 extra bit
  /*unsigned*/ short s:7;  // bitfields - only 7
  bool b:1;            // bitfields - only 1 bit

  bool operator<(const S &s) const { return this->i < s.i; }
};
#endif

// Trick to find size of the structure S above
template <int N>
class TD;

// Never compiles but shows the value of sizeof(S)
//TD<sizeof(S)> td;

void init(std::array<S, N> &arr);
S create_entry(int first_value, int second_value);
void solution(std::array<S, N> &arr);

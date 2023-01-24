#include <string>

#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
using std::string;

string IntToString(int x) {
  string result;
  if(x==0)return "0";
  bool negative = false;
  if(x < 0) {
    negative = true;
  }
  while(x != 0) {
    result.insert(result.begin(), abs(x%10) + '0');
    x /= 10;
  }
  if(negative) result.insert(result.begin(), '-');
  return result;
}
int StringToInt(const string& s) {
  int result = 0;
  bool negative = false;
  int start = 0;
  if(s[0] == '-') 
  {
    negative = true;
    start = 1;
  }
  if(s[0] == '+') 
  {
    negative = false;
    start = 1;
  }
  for(int i = start; i < s.length(); i++) {
    int digit = s[i] - '0';
    result = result*10 + digit;
  }
  if(negative) result *= -1;
  return result;
}
void Wrapper(int x, const string& s) {
  if (stoi(IntToString(x)) != x) {
    throw TestFailure("Int to string conversion failed");
  }

  if (StringToInt(s) != x) {
    throw TestFailure("String to int conversion failed");
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "s"};
  return GenericTestMain(args, "string_integer_interconversion.cc",
                         "string_integer_interconversion.tsv", &Wrapper,
                         DefaultComparator{}, param_names);
}

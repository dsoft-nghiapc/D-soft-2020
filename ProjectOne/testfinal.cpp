#include <algorithm>
#include <iostream>
#include <vector>

bool CheckResult(std::vector<std::string> dst, std::vector<std::string> temp,
                 std::string x) {
  bool checknumber;

  std::vector<std::string>::iterator check =
      std::find(std::begin(temp), std::end(temp), x);
  if (check != temp.end()) {
    checknumber = true;
  } else {
    checknumber = false;
  }
  
  return checknumber;
}

std::vector<std::string> unique_names(const std::vector<std::string>& names1,
                                      const std::vector<std::string>& names2) {
  std::vector<std::string> dst;
  std::string x;
  std::merge(names1.begin(), names1.end(), names2.begin(), names2.end(),
             std::back_inserter(dst));
  std::vector<std::string> temp{};
  std::vector<std::string> result{};
  bool checknumber;
  for (int i = 0; i < dst.size(); i++) {
      
    x = dst[i];
    checknumber = CheckResult(dst, temp, x);

    if (checknumber == false) {
      temp.push_back(dst[i]);
      result.push_back(dst[i]);
    }
  }
  return result;
}

int main() {
  std::vector<std::string> names1 = {"Ava", "Emma", "Olivia"};
  std::vector<std::string> names2 = {"Olivia", "Sophia", "Emma"};

  std::vector<std::string> result = unique_names(names1, names2);

  for (auto element : result) {
    std::cout << element << ' ';  // should print Ava Emma Olivia Sophia
  }
}

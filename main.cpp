#include <iostream>
#include <fstream>
#include <cctype>


bool checkName(std::string &name) {
  if (!(std::isalpha(static_cast<unsigned char>(name[0]))) ||
      !(std::isupper(static_cast<unsigned char>(name[0])))) {
    return false;
  } else {
    for (int i = 1; i < name.length(); ++i) {
      if (!(std::isalpha(static_cast<unsigned char>(name[i])))) {
        return false;
      }
    }
  }
  return true;
}
bool checkDate(std::string &date) {
  if (date.length() != 10 ||
      std::stoi(date.substr(0, 2)) > 31 ||
      std::stoi(date.substr(3, 2)) > 12) {
    return false;
  } else {
    return true;
  }
}

int main() {
  std::cout << "Enter the number of entries: " << std::endl;
  int numberOfEntries;
  std::cin >> numberOfEntries;
  std::string path = R"(C:\Users\User\Desktop\list.txt)";
  std::ofstream list(path,std::fstream::out|std::fstream::app);
  if (!list.is_open()) {
    std::cout << "Incorrect path file!";
    return 1;
  }
  std::string name;
  std::string surname;
  std::string date;
  int salary;
  std::cout << "Enter <name>  <surname>  date(dd.mm.yyyy) <salary>" << std::endl;
  int count = 0;
  do {
    std::cin >> name >> surname >> date >> salary;
    if (!checkName(name)) {
      std::cout << "Incorrect name!" << std::endl;
      continue;
    }
    if (!checkName(surname)) {
      std::cout << "Incorrect surname!" << std::endl;
      continue;
    }
    if (!checkDate(date)) {
      std::cout << "Incorrect date!" << std::endl;
      continue;
    }
    if (salary <= 0) {
      std::cout << "Incorrect salary!" << std::endl;
      break;
    }
    list << name << " " << surname << " " << date << " " << salary << " RUB" << std::endl;
    count++;
  } while (numberOfEntries > count);
  list.close();
  std::cout << "Data entry is over." << std::endl;
  return 0;
}

#include <ctime>
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
  ostringstream date1;
  date1 << 20211119; //Date in YYMMDD format

  struct tm tm;
  strptime(date1.str().c_str(), "%Y%m%d", &tm);

  char date2[50];
  strftime(date2, sizeof(date2), "%d-%b-%Y", &tm);

  std::cout << date1.str() << " -> " << date2 << std::endl;
}

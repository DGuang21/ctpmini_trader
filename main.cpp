#include "main.h"

#include "include/traderapi/ThostFtdcTraderApi.h"
#include "iostream"

using namespace std;

int main() {
  cout << "ctp mini login" << endl;
  cout << CThostFtdcTraderApi::GetApiVersion() << endl;

  return 0;
}
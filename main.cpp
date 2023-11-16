#include "main.h"

#include <cstring>

#include "include/traderapi/ThostFtdcTraderApi.h"
#include "iostream"
using namespace std;

int main() {
  cout << "ctp mini login" << endl;
  cout << CThostFtdcTraderApi::GetApiVersion() << endl;
  CThostFtdcTraderApi *mApi = CThostFtdcTraderApi::CreateFtdcTraderApi();

  CThostFtdcReqUserLoginField loginReq;

  strcpy(loginReq.TradingDay, "20231116");
  strcpy(loginReq.BrokerID, "0001");
  strcpy(loginReq.UserID, "user123");
  strcpy(loginReq.Password, "password");
  strcpy(loginReq.ClientIPAddress, "127.0.0.1");

  mApi->ReqUserLogin(&loginReq, 0);

  return 0;
}
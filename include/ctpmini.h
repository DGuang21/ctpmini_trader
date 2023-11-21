#include <cstring>
#include <iostream>
#include <memory>
#include <string>

#include "include/traderapi/ThostFtdcTraderApi.h"

using namespace std;

class CTPMiniSpi : public CThostFtdcTraderSpi {
 public:
  void OnFrontConnected() override;
  void OnFrontDisconnected(int nReason) override;
  void OnHeartBeatWarning(int nTimeLapse) override;
  void OnRspAuthenticate(CThostFtdcRspAuthenticateField *pRspAuthenticateField, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) override;
};

class CTPMiniTrader {
 public:
  CTPMiniTrader(string address, string appId, string authCode, string brokerId);
  ~CTPMiniTrader();
  int GetTradingDay();
  int ReqUserLogout();
  int ReqAuthenticate(string userId);
  int ReqUserLogin(string userId, string password);
  void Join();

 private:
  int request = 0;
  string address;
  string appId;
  string authCode;
  string brokerId;
  string userId;
  CThostFtdcTraderApi *userApi;

  unique_ptr<CThostFtdcUserLogoutField> getUserLogoutRequest();
  unique_ptr<CThostFtdcReqUserLoginField> getUserLoginRequest(string userId, string password);
  unique_ptr<CThostFtdcReqAuthenticateField> getAuthRequest(string userId);
};
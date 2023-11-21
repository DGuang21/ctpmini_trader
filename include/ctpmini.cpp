#include "ctpmini.h"

using namespace std;

void CTPMiniSpi::OnFrontConnected() { cout << "OnFrontConnected" << endl; }

void CTPMiniSpi::OnFrontDisconnected(int nReason) { cout << "OnFrontDisconnected " << nReason << endl; }

void CTPMiniSpi::OnHeartBeatWarning(int nTimeLapse) { cout << "OnHeartBeatWarning " << nTimeLapse << endl; }

void CTPMiniSpi::OnRspAuthenticate(CThostFtdcRspAuthenticateField *pRspAuthenticateField, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) { cout << "OnRspAuthenticate" << endl; }

CTPMiniTrader::CTPMiniTrader(string address, string appId, string authCode, string brokerId) : address(address), appId(appId), authCode(authCode), brokerId(brokerId) {
  cout << "CTP Mini Trader initialization, API version: " << CThostFtdcTraderApi::GetApiVersion() << endl;
  userApi = CThostFtdcTraderApi::CreateFtdcTraderApi("./flow");
  CTPMiniSpi *userSpi = new CTPMiniSpi();

  userApi->RegisterSpi(userSpi);
  userApi->SubscribePrivateTopic(THOST_TERT_QUICK);
  userApi->SubscribePublicTopic(THOST_TERT_RESTART);
  userApi->RegisterFront(const_cast<char *>(address.c_str()));
  userApi->Init();
}

CTPMiniTrader::~CTPMiniTrader() {
  if (userApi) {
    userApi->Release();
    userApi = nullptr;
  }
}

int CTPMiniTrader::GetTradingDay() {
  cout << "Trading day: " << userApi->GetTradingDay() << endl;
  return 0;
}

int CTPMiniTrader::ReqUserLogout() { return userApi->ReqUserLogout(getUserLogoutRequest().get(), ++request); }

int CTPMiniTrader::ReqAuthenticate(string userId) { return userApi->ReqAuthenticate(getAuthRequest(userId).get(), ++request); }

int CTPMiniTrader::ReqUserLogin(string userId, string password) { return userApi->ReqUserLogin(getUserLoginRequest(userId, password).get(), ++request); }

void CTPMiniTrader::Join() { userApi->Join(); }

unique_ptr<CThostFtdcUserLogoutField> CTPMiniTrader::getUserLogoutRequest() {
  unique_ptr<CThostFtdcUserLogoutField> reqLogout(new CThostFtdcUserLogoutField());
  strcpy(reqLogout->BrokerID, brokerId.c_str());
  strcpy(reqLogout->UserID, userId.c_str());
  return reqLogout;
}

unique_ptr<CThostFtdcReqUserLoginField> CTPMiniTrader::getUserLoginRequest(string userId, string password) {
  unique_ptr<CThostFtdcReqUserLoginField> reqUserLogin(new CThostFtdcReqUserLoginField());
  strcpy(reqUserLogin->BrokerID, brokerId.c_str());
  strcpy(reqUserLogin->UserID, userId.c_str());
  strcpy(reqUserLogin->Password, password.c_str());
  return reqUserLogin;
}

unique_ptr<CThostFtdcReqAuthenticateField> CTPMiniTrader::getAuthRequest(string userId) {
  unique_ptr<CThostFtdcReqAuthenticateField> userRequest(new CThostFtdcReqAuthenticateField());
  strcpy(userRequest->UserID, userId.c_str());
  strcpy(userRequest->BrokerID, brokerId.c_str());
  strcpy(userRequest->AuthCode, authCode.c_str());
  strcpy(userRequest->AppID, appId.c_str());
  return userRequest;
}
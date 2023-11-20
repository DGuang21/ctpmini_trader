#include <cstring>
#include <memory>
#include "include/traderapi/ThostFtdcTraderApi.h"
#include "iostream"
using namespace std;

class CTPMiniTrader {
 private:
  CThostFtdcTraderApi *userApi = CThostFtdcTraderApi::CreateFtdcTraderApi();
  string userId = "";
  int request = 0;
  string address;
  string appId;
  string authCode;
  string brokerId;

 public:
  CTPMiniTrader(string address, string appId, string authCode, string brokerId)
      : address(address),
        appId(appId),
        authCode(authCode),
        brokerId(brokerId) {
    cout << "ctp mini init, api version: "
         << CThostFtdcTraderApi::GetApiVersion() << endl;
    return;
  };
  ~CTPMiniTrader() {
    userApi->Release();
    userApi = nullptr;
  };

 public:
  // 订阅私有流
  void SubscribePrivateTopic() {}
  // 订阅公共流
  void SubscribePublicTopic() {}
  // 客户端认证
  int ReqAuthenticate(string userId, string password) {
    unique_ptr <CThostFtdcReqAuthenticateField> authRequest =
        this->getAuthRequest(userId, password);
    unique_ptr <CThostFtdcReqUserLoginField> loginRequest =
        this->getUserLoginReqeust(userId, password);

    int res = this->userApi->ReqAuthenticate(authRequest.get(), this->request++);
    printf("客户端认证 = [%d] \n", res);

    res = this->userApi->ReqUserLogin(loginRequest.get(), this->request++);
    printf("用户登录 = [%d] \n", res);

    return res;
  }

 private:
  // 生成登录结构体
  unique_ptr<CThostFtdcReqUserLoginField> getUserLoginReqeust(string userId,
                                                   string password) {
    unique_ptr <CThostFtdcReqUserLoginField> reqUserLogin(new CThostFtdcReqUserLoginField);
    copy(this->brokerId.begin(), this->brokerId.end(), reqUserLogin->BrokerID);
    copy(userId.begin(), userId.end(), reqUserLogin->UserID);
    copy(password.begin(), password.end(), reqUserLogin->Password);

    return reqUserLogin;
  }
  // 生成客户端认证结构体
  unique_ptr<CThostFtdcReqAuthenticateField> getAuthRequest(string userId,
                                                 string password) {
    unique_ptr <CThostFtdcReqAuthenticateField> userRequest (new CThostFtdcReqAuthenticateField());
    copy(this->brokerId.begin(), this->brokerId.end(), userRequest->BrokerID);
    copy(this->authCode.begin(), this->authCode.end(), userRequest->AuthCode);
    copy(this->appId.begin(), this->appId.end(), userRequest->AppID);
    copy(userId.begin(), userId.end(), userRequest->UserID);
    return userRequest;
  }
};
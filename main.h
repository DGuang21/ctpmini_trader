#include <cstring>

#include "include/traderapi/ThostFtdcTraderApi.h"
#include "iostream"
using namespace std;

class CTPMiniTrader {
 private:
  CThostFtdcTraderApi *userApi;
  char *address;
  int request = 0;
  char *appId;
  char *authCode;
  char *brokerId;
  char *userId;

 public:
  CTPMiniTrader(char address, char appId, char authCode, char brokerId) {
    cout << "ctp mini init" << endl;
    cout << CThostFtdcTraderApi::GetApiVersion() << endl;

    strcpy(this->address, &address);
    strcpy(this->appId, &appId);
    strcpy(this->authCode, &authCode);
    strcpy(this->brokerId, &brokerId);
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
  int ReqAuthenticate(char *userId, char *password) {
    this->userApi = CThostFtdcTraderApi::CreateFtdcTraderApi();

    CThostFtdcReqAuthenticateField *authRequest =
        this->getAuthRequest(userId, password);
    CThostFtdcReqUserLoginField *loginRequest =
        this->getUserLoginReqeust(userId, password);

    int res = this->userApi->ReqAuthenticate(authRequest, this->request++);
    printf("客户端认证 = [%d]", res);

    if (res != 0) {
      return res;
    }

    res = this->userApi->ReqUserLogin(loginRequest, this->request++);
    printf("用户登录 = [%d]", res);

    return res;
  }

 private:
  // 生成登录结构体
  CThostFtdcReqUserLoginField *getUserLoginReqeust(char *userId,
                                                   char *password) {
    CThostFtdcReqUserLoginField reqUserLogin = {0};
    strcpy(reqUserLogin.BrokerID, this->brokerId);
    strcpy(reqUserLogin.UserID, userId);
    strcpy(reqUserLogin.Password, password);
    strcpy(reqUserLogin.LoginRemark, "test");
    return &reqUserLogin;
  }
  // 生成客户端认证结构体
  CThostFtdcReqAuthenticateField *getAuthRequest(char *userId, char *password) {
    this->userId = userId;
    CThostFtdcReqAuthenticateField userRequest = {0};
    strcpy(userRequest.BrokerID, this->brokerId);
    strcpy(userRequest.UserID, userId);
    strcpy(userRequest.AuthCode, this->authCode);
    strcpy(userRequest.AppID, this->appId);
    return &userRequest;
  }
};
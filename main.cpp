#include "main.h"

int main() {
  string address = "222.66.74.18:21205";
  string appid = "client_quantword_2.1";
  string authCode = "WUQ2KS75AL33MX2X";
  string brokerId = "8888";
  string userId = "1234";
  string password = "dlqh1552";

  CTPMiniTrader *mApi = new CTPMiniTrader(address, appid, authCode, brokerId);
  mApi->ReqAuthenticate(userId,password);

  return 0;
}
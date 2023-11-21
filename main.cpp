#include "include/ctpmini.h"

int main() {
  string address = "tcp://122.51.136.165:20002";
  string appid = "client_xtrader_2.9.0";
  string authCode = "WWBAHC9SY8HCTGPH";
  string brokerId = "8888";
  string userId = "12345";
  string password = "12345";

  CTPMiniTrader *mApi = new CTPMiniTrader(address, appid, authCode, brokerId);
  cout << mApi->ReqAuthenticate(userId) << endl;
  cout << mApi->ReqUserLogin(password) << endl;
  cout << mApi->GetTradingDay() << endl;
  mApi->Join();
  return 0;
}

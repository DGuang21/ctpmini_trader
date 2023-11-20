#include "lib/ctpmini/ctpmini.h"

int main() {
  string address = "tcp://121.36.146.182:20002";
  string appid = "client_xtrader_2.9.1";
  string authCode = "WWBAHC9SY8HCTGPH";
  string brokerId = "8888";
  string userId = "12345";
  string password = "12345";

  CTPMiniTrader *mApi = new CTPMiniTrader(address, appid, authCode, brokerId);

  cout << mApi->ReqAuthenticate(userId) << endl;
  cout << mApi->ReqUserLogin(password) << endl;
  cout << mApi->GetTradingDay() << endl;
  cout << mApi->ReqUserLogout() << endl;

  return 0;
}
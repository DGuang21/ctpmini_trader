#include "include/ctpmini.h"

int main() {
  string address = "tcp://140.207.168.9:42205";
  string appid = "client_xtrader_2.9.1";
  string authCode = "X4OC657YQ7S47R2I";
  string brokerId = "1080";
  string userId = "901208788";
  string password = "qtwdsolang123";

  CTPMiniTrader *mApi = new CTPMiniTrader(address, appid, authCode, brokerId);

  cout << mApi->ReqAuthenticate(userId) << endl;
  cout << mApi->ReqUserLogin(password) << endl;
  cout << mApi->GetTradingDay() << endl;
  cout << mApi->ReqUserLogout() << endl;

  return 0;
}
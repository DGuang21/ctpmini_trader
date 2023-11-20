#include "main.h"

int main() {
  string address = "tcp://140.207.168.9:42205";
  string appid = "client_xtrader_1.1";
  string authCode = "X4OC657YQ7S47R2I";
  string brokerId = "1080";
  string userId = "901208788";
  string password = "qtwdsolang123";

  CTPMiniTrader *mApi = new CTPMiniTrader(address, appid, authCode, brokerId);

  cout << mApi->ReqAuthenticate(userId) << endl;
  cout << mApi->ReqUserLogin(password) << endl;
  cout << mApi->GetTradingDay() << endl;
  mApi->ReqUserLogout();

  return 0;
}
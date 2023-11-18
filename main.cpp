#include "main.h"

int main() {
  CTPMiniTrader *mApi = new CTPMiniTrader("", "", "", "");
  mApi->~CTPMiniTrader();

  return 0;
}
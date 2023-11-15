#include "iostream"
#include "main.h"
#include "lib/traderapi/ThostFtdcTraderApi.h"

using namespace std;

int main() 
{
    cout << "ctp mini login" << endl;
    cout << CThostFtdcTraderApi::GetApiVersion() << endl;

    return 0;
}
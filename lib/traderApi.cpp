#include "traderApi.h"

void CTPMiniApi::Release()
{
	m_pApi->Release();
};

const char * CTPMiniApi::GetApiVersion() {
	return m_pApi->GetApiVersion();
}

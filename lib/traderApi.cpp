#pragma once
#include "traderApi.h"
#include "iostream"
#include "traderapi/ThostFtdcTraderApi.h"
#include "traderapi/ThostFtdcUserApiDataType.h"
#include "traderapi/ThostFtdcUserApiStruct.h"

using namespace std;

CTPMiniApi::CTPMiniApi() {
	m_pApi = CThostFtdcTraderApi::CreateFtdcTraderApi("./flow");
	cout << "lib/traderApi.cpp: init success\n" << endl;
	cout << "apiVersion: " << CThostFtdcTraderApi::GetApiVersion() << "\n" << endl;
};

CTPMiniApi::~CTPMiniApi() {
	m_pApi->Release();
	m_pApi = nullptr;
}

void CTPMiniApi::Init(bool bContinuous = false) {
	return m_pApi->Init(bContinuous);
}

const char * CTPMiniApi::GetApiVersion() {
	return CThostFtdcTraderApi::GetApiVersion();
}
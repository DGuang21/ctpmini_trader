#pragma once

class CTPMiniApi
{
private:
	CThostFtdcTraderApi *m_pApi;

public:
	
	///获取API的版本信息
	///@retrun 获取到的版本号
	static const char *GetApiVersion();

	///删除接口对象本身
	///@remark 不再使用本接口对象时,调用该函数删除接口对象
	virtual void Release() = 0;
	
	///初始化
	///@param bContinuous 为true表示线程不休眠
	///@remark 初始化运行环境,只有调用后,接口才开始工作
	virtual void Init(bool bContinuous = false) = 0;
	
	///用户登录请求
	virtual int ReqUserLogin(CThostFtdcReqUserLoginField *pReqUserLoginField, int nRequestID) = 0;

	///登出请求
	virtual int ReqUserLogout(CThostFtdcUserLogoutField *pUserLogout, int nRequestID) = 0;

	///获取当前交易日
	///@retrun 获取到的交易日
	///@remark 只有登录成功后,才能得到正确的交易日
	virtual const char *GetTradingDay() = 0;

	virtual const char *GetApiVersion() = 0;

};
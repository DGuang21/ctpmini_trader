#pragma once
#include "traderapi/ThostFtdcTraderApi.h"
#include "traderapi/ThostFtdcUserApiDataType.h"
#include "traderapi/ThostFtdcUserApiStruct.h"

class CTPMiniApi : public CThostFtdcTraderApi 
{
public:
	CTPMiniApi() {};
	~CTPMiniApi() {};

private:
	CThostFtdcTraderApi *m_pApi;

public:
	///创建TraderApi
	///@param pszFlowPath 存贮订阅信息文件的目录，默认为当前目录
	///@return 创建出的UserApi
	static CThostFtdcTraderApi *CreateFtdcTraderApi(const char *pszFlowPath = "");

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
	
	///等待接口线程结束运行
	///@return 线程退出代码
	virtual int Join() = 0;
	
	///获取当前交易日
	///@retrun 获取到的交易日
	///@remark 只有登录成功后,才能得到正确的交易日
	virtual const char *GetTradingDay() = 0;
	
	///注册前置机网络地址
	///@param pszFrontAddress：前置机网络地址。
	///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。 
	///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。
	virtual void RegisterFront(char *pszFrontAddress) = 0;
	
	///注册回调接口
	///@param pSpi 派生自回调接口类的实例
	virtual void RegisterSpi(CThostFtdcTraderSpi *pSpi) = 0;
	
	///订阅私有流。
	///@param nResumeType 私有流重传方式  
	///        THOST_TERT_RESTART:从本交易日开始重传
	///        THOST_TERT_RESUME:从上次收到的续传
	///        THOST_TERT_QUICK:只传送登录后私有流的内容
	///@remark 该方法要在Init方法前调用。若不调用则不会收到私有流的数据。
	virtual void SubscribePrivateTopic(THOST_TE_RESUME_TYPE nResumeType) = 0;
	
	///订阅公共流。
	///@param nResumeType 公共流重传方式  
	///        THOST_TERT_RESTART:从本交易日开始重传
	///        THOST_TERT_RESUME:从上次收到的续传
	///        THOST_TERT_QUICK:只传送登录后公共流的内容
	///@remark 该方法要在Init方法前调用。若不调用则不会收到公共流的数据。
	virtual void SubscribePublicTopic(THOST_TE_RESUME_TYPE nResumeType) = 0;

	///订阅交易所流控警告
	///@remark 该方法必须在登录成功之后调用。
	virtual int SubscribeFlowCtrlWarning(char *ppTraderID[], int nCount) = 0;

	///取消订阅交易所流控警告
	///@remark 该方法必须在登录成功之后调用。
	virtual int UnSubscribeFlowCtrlWarning(char *ppTraderID[], int nCount) = 0;

	///客户端认证请求
	virtual int ReqAuthenticate(CThostFtdcReqAuthenticateField *pReqAuthenticateField, int nRequestID) = 0 ;

	///用户登录请求
	virtual int ReqUserLogin(CThostFtdcReqUserLoginField *pReqUserLoginField, int nRequestID) = 0;
	
	///用户加密登录请求
	virtual int ReqUserLoginEncrypt(CThostFtdcReqUserLoginField *pReqUserLoginField, int nRequestID) = 0;

	///登出请求
	virtual int ReqUserLogout(CThostFtdcUserLogoutField *pUserLogout, int nRequestID) = 0;

	///报单录入请求
	virtual int ReqOrderInsert(CThostFtdcInputOrderField *pInputOrder, int nRequestID) = 0;

	///报单操作请求
	virtual int ReqOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, int nRequestID) = 0;

	///做市商批量报单操作请求
	virtual int ReqMKBatchOrderAction(CThostFtdcMKInputOrderActionField *pMKInputOrderAction, int nRequestID) = 0;

	///执行宣告录入请求
	virtual int ReqExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, int nRequestID) = 0;

	///执行宣告操作请求
	virtual int ReqExecOrderAction(CThostFtdcInputExecOrderActionField *pInputExecOrderAction, int nRequestID) = 0;

	///询价录入请求
	virtual int ReqForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, int nRequestID) = 0;

	///报价录入请求
	virtual int ReqQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, int nRequestID) = 0;

	///报价操作请求
	virtual int ReqQuoteAction(CThostFtdcInputQuoteActionField *pInputQuoteAction, int nRequestID) = 0;

	///批量报单操作请求
	virtual int ReqBatchOrderAction(CThostFtdcInputBatchOrderActionField *pInputBatchOrderAction, int nRequestID) = 0;

	///期权自对冲录入请求
	virtual int ReqOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose, int nRequestID) = 0;

	///期权自对冲操作请求
	virtual int ReqOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField *pInputOptionSelfCloseAction, int nRequestID) = 0;

	///申请组合录入请求
	virtual int ReqCombActionInsert(CThostFtdcInputCombActionField *pInputCombAction, int nRequestID) = 0;

	///请求查询报单
	virtual int ReqQryOrder(CThostFtdcQryOrderField *pQryOrder, int nRequestID) = 0;

	///请求查询成交
	virtual int ReqQryTrade(CThostFtdcQryTradeField *pQryTrade, int nRequestID) = 0;

	///请求查询投资者持仓
	virtual int ReqQryInvestorPosition(CThostFtdcQryInvestorPositionField *pQryInvestorPosition, int nRequestID) = 0;

	///请求查询资金账户
	virtual int ReqQryTradingAccount(CThostFtdcQryTradingAccountField *pQryTradingAccount, int nRequestID) = 0;

	///请求查询投资者
	virtual int ReqQryInvestor(CThostFtdcQryInvestorField *pQryInvestor, int nRequestID) = 0;

	///请求查询交易编码
	virtual int ReqQryTradingCode(CThostFtdcQryTradingCodeField *pQryTradingCode, int nRequestID) = 0;

	///请求查询合约保证金率
	virtual int ReqQryInstrumentMarginRate(CThostFtdcQryInstrumentMarginRateField *pQryInstrumentMarginRate, int nRequestID) = 0;

	///请求查询合约手续费率
	virtual int ReqQryInstrumentCommissionRate(CThostFtdcQryInstrumentCommissionRateField *pQryInstrumentCommissionRate, int nRequestID) = 0;

	///请求查询交易所
	virtual int ReqQryExchange(CThostFtdcQryExchangeField *pQryExchange, int nRequestID) = 0;

	///请求查询产品
	virtual int ReqQryProduct(CThostFtdcQryProductField *pQryProduct, int nRequestID) = 0;

	///请求查询合约
	virtual int ReqQryInstrument(CThostFtdcQryInstrumentField *pQryInstrument, int nRequestID) = 0;

	///请求查询申请组合合约
	virtual int ReqQryCombInstrument(CThostFtdcQryCombInstrumentField* pQryCombInstrument, int nRequestID) = 0;
	
	///请求单腿持仓汇总
	virtual int ReqQryInvestorPositionForComb(CThostFtdcQryInvestorPositionForCombField* pQryIPForComb, int nRequestID) = 0;
	
	///请求查询申请组合
	virtual int ReqQryCombAction(CThostFtdcQryCombActionField* pQryCombAction, int nRequestID) = 0;

	///请求查询行情
	virtual int ReqQryDepthMarketData(CThostFtdcQryDepthMarketDataField *pQryDepthMarketData, int nRequestID) = 0;

	///请求查询期权自对冲
	virtual int ReqQryOptionSelfClose(CThostFtdcQryOptionSelfCloseField *pQryOptionSelfClose, int nRequestID) = 0;

	///请求查询合约状态
	virtual int ReqQryInstrumentStatus(CThostFtdcQryInstrumentStatusField *pQryInstrumentStatus, int nRequestID) = 0;

	///请求查询投资者持仓明细
	///持仓明细不再维护，请勿以查询结果为准
	virtual int ReqQryInvestorPositionDetail(CThostFtdcQryInvestorPositionDetailField *pQryInvestorPositionDetail, int nRequestID) = 0;

	///请求查询交易所保证金率
	virtual int ReqQryExchangeMarginRate(CThostFtdcQryExchangeMarginRateField *pQryExchangeMarginRate, int nRequestID) = 0;

	///请求查询交易所调整保证金率
	virtual int ReqQryExchangeMarginRateAdjust(CThostFtdcQryExchangeMarginRateAdjustField *pQryExchangeMarginRateAdjust, int nRequestID) = 0;

	///请求查询期权交易成本
	virtual int ReqQryOptionInstrTradeCost(CThostFtdcQryOptionInstrTradeCostField *pQryOptionInstrTradeCost, int nRequestID) = 0;

	///请求查询期权合约手续费
	virtual int ReqQryOptionInstrCommRate(CThostFtdcQryOptionInstrCommRateField *pQryOptionInstrCommRate, int nRequestID) = 0;

	///请求查询执行宣告
	virtual int ReqQryExecOrder(CThostFtdcQryExecOrderField *pQryExecOrder, int nRequestID) = 0;

	///请求查询询价
	virtual int ReqQryForQuote(CThostFtdcQryForQuoteField *pQryForQuote, int nRequestID) = 0;

	///请求查询报价
	virtual int ReqQryQuote(CThostFtdcQryQuoteField *pQryQuote, int nRequestID) = 0;

	///请求查询申报费
	virtual int ReqQryInstrumentOrderCommRate(CThostFtdcQryInstrumentOrderCommRateField *pQryInstrumentOrderCommRate, int nRequestID) = 0;

	///请求查询询价价差
	virtual int ReqQryForQuoteParam(CThostFtdcQryForQuoteParamField *pQryForQuoteParam, int nRequestID) = 0;

	///请求查询交易员报盘机
	virtual int ReqQryTraderOffer(CThostFtdcQryTraderOfferField *pQryTraderOffer, int nRequestID) = 0;
	
	///请求查询投资者SPBM品种明细
	virtual int ReqQryInvestorProdSPBMDetail(CThostFtdcQryInvestorProdSPBMDetailField *pQryInvestorProdSPBMDetail, int nRequestID) = 0;

};
/////////////////////////////////////////////////////////////////////////
///@system 新一代交易所系统风险监控系统
///@company 上海期货信息技术有限公司
///@file FtdcRiskUserApi.h
///@brief 定义了客户端接口
///@history 
///@version v{main:6,max:7,server:v5.5.2}
///20070227	zhangjie		创建该文件
/////////////////////////////////////////////////////////////////////////

#if !defined(_FTDCRISKUSERAPI_H)
#define _FTDCRISKUSERAPI_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FtdcRiskUserApiStruct.h"
#define  ISLIB
#if defined(ISLIB) && defined(WIN32)
#ifdef LIB_RISKUSER_API_EXPORT
#define RISKUSER_API_EXPORT __declspec(dllexport)
#else
#define RISKUSER_API_EXPORT __declspec(dllimport)
//#pragma comment(lib, "riskuserapi.lib")
#endif
#else
#define RISKUSER_API_EXPORT 
#endif

class CShfeFtdcRiskUserSpi
{
public:
	///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
	virtual void OnFrontConnected(){};
	
	///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
	///@param nReason 错误原因
	///        0x1001 网络读失败
	///        0x1002 网络写失败
	///        0x2001 接收心跳超时
	///        0x2002 发送心跳失败
	///        0x2003 收到错误报文
	virtual void OnFrontDisconnected(int nReason){};
		
	///心跳超时警告。当长时间未收到报文时，该方法被调用。
	///@param nTimeLapse 距离上次接收报文的时间
	virtual void OnHeartBeatWarning(int nTimeLapse){};
	

	///错误应答
	virtual void OnRspError(CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///席位资金回报
	virtual void OnRtnBrokerDeposit(CShfeFtdcBrokerDepositField *pBrokerDeposit) {};

	///客户端结算组数据同步开始
	virtual void OnRtnClientSGDataSyncStart(CShfeFtdcSettlementSessionField *pSettlementSession) {};

	///客户端结算组数据同步结束
	virtual void OnRtnClientSGDataSyncEnd(CShfeFtdcSettlementSessionField *pSettlementSession) {};

	///登录请求响应
	virtual void OnRspRiskUserLogin(CShfeFtdcRspRiskUserLoginField *pRspRiskUserLogin, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///产品信息
	virtual void OnRtnProduct(CShfeFtdcProductField *pProduct) {};

	///合约信息
	virtual void OnRtnInstrument(CShfeFtdcInstrumentField *pInstrument) {};

	///查询报单排名应答
	virtual void OnRspQryOrderStat(CShfeFtdcOrderStatField *pOrderStat, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///交易所的基本信息
	virtual void OnRtnExchange(CShfeFtdcExchangeField *pExchange) {};

	///风控深度行情通知
	virtual void OnRtnRiskDepthMarketData(CShfeFtdcDepthMarketDataField *pDepthMarketData) {};

	///时间同步
	virtual void OnRtnTimeSync(CShfeFtdcCurrentTimeField *pCurrentTime) {};

	///合约持仓比例应答
	virtual void OnRspInstPositionRate(CShfeFtdcRspInstPositionRateField *pRspInstPositionRate, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///产品持仓比例应答
	virtual void OnRspProductPositionRate(CShfeFtdcRspProductPositionRateField *pRspProductPositionRate, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///投资者组
	virtual void OnRtnInvestorGroup(CShfeFtdcInvestorGroupField *pInvestorGroup) {};

	///经纪公司合约保证金率，删除则用RtnDelInstrumentMarginRate
	virtual void OnRtnInstrumentMarginRate(CShfeFtdcInstrumentMarginRateField *pInstrumentMarginRate) {};

	///经纪公司合约保证金率调整，删除则用RtnDelInstrumentMarginRateAdjust
	virtual void OnRtnInstrumentMarginRateAdjust(CShfeFtdcInstrumentMarginRateAdjustField *pInstrumentMarginRateAdjust) {};

	///交易所保证金率，删除则用RtnDelRtnExchangeMarginRate
	virtual void OnRtnExchangeMarginRate(CShfeFtdcExchangeMarginRateField *pExchangeMarginRate) {};

	///交易所保证金率调整，删除则用RtnDelRtnExchangeMarginRateAdjust
	virtual void OnRtnExchangeMarginRateAdjust(CShfeFtdcExchangeMarginRateAdjustField *pExchangeMarginRateAdjust) {};

	///有序的经纪公司用户事件回报，对应订阅请求ReqSubBrokerUserEvent
	virtual void OnRtnSequencialBrokerUserEvent(CShfeFtdcSequencialBrokerUserEventField *pSequencialBrokerUserEvent) {};

	///有序的成交回报，对应订阅请求ReqSubscribeTrade
	virtual void OnRtnSequencialTrade(CShfeFtdcSequencialTradeField *pSequencialTrade) {};

	///有序的报单回报，对应订阅请求ReqSubscribeOrder
	virtual void OnRtnSequencialOrder(CShfeFtdcSequencialOrderField *pSequencialOrder) {};

	///风控报单录入请求响应
	virtual void OnRspRiskOrderInsert(CShfeFtdcInputOrderField *pInputOrder, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///风控报单操作请求响应
	virtual void OnRspRiskOrderAction(CShfeFtdcInputOrderActionField *pInputOrderAction, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///有序的持仓回报，对应订阅请求ReqSubscribePosition
	virtual void OnRtnSequencialPosition(CShfeFtdcSequencialPositionField *pSequencialPosition) {};

	///组织架构
	virtual void OnRtnDepartment(CShfeFtdcDepartmentField *pDepartment) {};

	///风控预埋单录入应答
	virtual void OnRspRiskParkedOrderInsert(CShfeFtdcRiskParkedOrderField *pRiskParkedOrder, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///删除预埋单响应
	virtual void OnRspRemoveRiskParkedOrder(CShfeFtdcRemoveRiskParkedOrderField *pRemoveRiskParkedOrder, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///有序的风控预埋单回报
	virtual void OnRtnSeqRiskParkedOrder(CShfeFtdcSeqRiskParkedOrderField *pSeqRiskParkedOrder) {};

	///风控用户密码修改应答
	virtual void OnRspRiskUserPasswordUpd(CShfeFtdcUserPasswordUpdateField *pUserPasswordUpdate, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///有序的出入金回报，对应订阅请求ReqSubSeqDeposit
	virtual void OnRtnSeqDeposit(CShfeFtdcSeqDepositField *pSeqDeposit) {};

	///有序的交易编码回报，对应订阅请求ReqSubSeqTradingCode
	virtual void OnRtnSeqTradingCode(CShfeFtdcSeqTradingCodeField *pSeqTradingCode) {};

	///投资者基础信息回报，只同步盘中变化数据，可以配合{ReqQryInvestorLinkMan,RspQryInvestorLinkMan}使用
	virtual void OnRtnRiskInvestor(CShfeFtdcRiskSyncInvestorField *pRiskSyncInvestor) {};

	///查询投资者和联系人信息应答
	virtual void OnRspQryInvestorLinkMan(CShfeFtdcInvestorLinkManField *pInvestorLinkMan, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///删除经纪公司合约保证金率
	virtual void OnRtnDelInstrumentMarginRate(CShfeFtdcInstrumentMarginRateField *pInstrumentMarginRate) {};

	///删除经纪公司合约保证金率调整
	virtual void OnRtnDelInstrumentMarginRateAdjust(CShfeFtdcInstrumentMarginRateAdjustField *pInstrumentMarginRateAdjust) {};

	///删除交易所保证金率
	virtual void OnRtnDelExchangeMarginRate(CShfeFtdcExchangeMarginRateField *pExchangeMarginRate) {};

	///删除交易所保证金率调整
	virtual void OnRtnDelExchangeMarginRateAdjust(CShfeFtdcExchangeMarginRateAdjustField *pExchangeMarginRateAdjust) {};

	///查询组织架构投资者对应关系应答
	virtual void OnRspQryInvestorDepartment(CShfeFtdcInvestorDepartmentFlatField *pInvestorDepartmentFlat, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///返回投资者组织架构Hash值
	virtual void OnRtnInvestorDepartmentHash(CShfeFtdcInvestorLinkManHashField *pInvestorLinkManHash) {};

	///投资者当日资金回报；昨日资金使用{ReqSubPreRiskAccount,RtnSeqPreRiskAccount}
	virtual void OnRtnRiskSyncAccount(CShfeFtdcRiskSyncAccountField *pRiskSyncAccount) {};

	///有序的昨日资金回报，对应订阅请求ReqSubPreRiskAccount
	virtual void OnRtnSeqPreRiskAccount(CShfeFtdcSeqPreRiskAccountField *pSeqPreRiskAccount) {};

	///有序的业务通知回报
	virtual void OnRtnSeqBizNotice(CShfeFtdcSeqBizNoticeField *pSeqBizNotice) {};

	///查询席位资金应答
	virtual void OnRspRiskQryBrokerDeposit(CShfeFtdcQueryBrokerDepositField *pQueryBrokerDeposit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///有序的风险通知回报版本B，对应订阅请求ReqSubSeqRiskNotifyB
	virtual void OnRtnSeqRiskNotifyB(CShfeFtdcSeqRiskNotifyBField *pSeqRiskNotifyB) {};

	///查询持仓排名应答
	virtual void OnRspQryPositionStat(CShfeFtdcPositionStatField *pPositionStat, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///查询成交排名应答
	virtual void OnRspQryTradeStat(CShfeFtdcTradeStatField *pTradeStat, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///投资者及联系人信息哈希值查询应答
	virtual void OnRspInvestorLinkManHash(CShfeFtdcInvestorLinkManHashField *pInvestorLinkManHash, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
};

class RISKUSER_API_EXPORT CShfeFtdcRiskUserApi
{
public:
	///创建RiskUserApi
	///@param pszFlowPath 存贮订阅信息文件的目录，默认为当前目录
	///@return 创建出的UserApi
	static CShfeFtdcRiskUserApi *CreateFtdcRiskUserApi(const char *pszFlowPath = "");
	
	///删除接口对象本身
	///@remark 不再使用本接口对象时,调用该函数删除接口对象
	virtual void Release() = 0;
	
	///初始化
	///@remark 初始化运行环境,只有调用后,接口才开始工作
	virtual void Init() = 0;
	
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
	virtual void RegisterSpi(CShfeFtdcRiskUserSpi *pSpi) = 0;
	
	///订阅市场行情。
	///@param nTopicID 市场行情主题  
	///@param nResumeType 市场行情重传方式  
	///        TERT_RESTART:从本交易日开始重传
	///        TERT_RESUME:从上次收到的续传
	///        TERT_QUICK:先传送当前行情快照,再传送登录后市场行情的内容
	///@remark 该方法要在Init方法前调用。若不调用则不会收到私有流的数据。
	//virtual void SubscribeMarketDataTopic(int nTopicID, TE_RESUME_TYPE nResumeType) = 0;
	
	///登录请求
		// changelog
		// v4.3之前 ReqRiskUserLogin.Version=0
		//	投资者信息接口: RtnInvestorSumInfo,ReqInvestorRangeSumInfo,RspInvestorRangeSumInfo,ReqInvestorRangeInfo,RspInvestorRangeInfo,RtnRiskInvestorInfo
		//	投资者组织架构接口: RtnInvestorDepartment
		//	资金接口: RtnInvestorAccount
		//
		// v4.3	ReqRiskUserLogin.Version=1
		//	投资者信息接口: RtnInvestorLinkManHash,ReqQryInvestorLinkMan,RspQryInvestorLinkMan
		//	投资者组织架构接口: RtnInvestorDepartmentHash,ReqQryInvestorDepartment,RspQryInvestorDepartment
		//
		// v5.0 ReqRiskUserLogin.Version=2
		//	资金接口: 昨日资金(ReqSubPreRiskAccount,RtnSeqPreRiskAccount),当日资金RtnRiskSyncAccount
		//
		// v5.4.0.1 不再使用字段ReqRiskUserLogin.Version，填任何值对程序都没有影响
		//	登录成功不自动返回RtnInvestorLinkManHash，InvestorLinkMan的MD5值通过接口ReqInvestorLinkManHash查询
	virtual int ReqRiskUserLogin(CShfeFtdcReqRiskUserLoginField *pReqRiskUserLogin, int nRequestID) = 0;

	///查询报单排名请求
	virtual int ReqQryOrderStat(CShfeFtdcQryStatField *pQryStat, int nRequestID) = 0;

	///订阅风控实时行情
	virtual int ReqSubRiskMarketData(CShfeFtdcSubMarketDataField *pSubMarketData, int SubMarketDataCnt, 
		int nRequestID) = 0;

	///退订风控实时行情
	virtual int ReqUnSubRiskMarketData(CShfeFtdcSubMarketDataField *pSubMarketData, int nRequestID) = 0;

	///合约持仓比例查询
	virtual int ReqQryInstPositionRate(CShfeFtdcQryInstPositionRateField *pQryInstPositionRate, int QryInstPositionRateCnt, 
		int nRequestID) = 0;

	///产品持仓比例查询
	virtual int ReqQryProductPositionRate(CShfeFtdcQryProductPositionRateField *pQryProductPositionRate, int nRequestID) = 0;

	///订阅有序的成交，可根据已接收的RtnSequencialTrade中最大的UniqSequenceNo来实现续订
	virtual int ReqSubscribeTrade(CShfeFtdcNotifySequenceField *pNotifySequence, int nRequestID) = 0;

	///订阅有序的成交，可根据已接收的RtnSequencialOrder中最大的UniqSequenceNo来实现续订
	virtual int ReqSubscribeOrder(CShfeFtdcNotifySequenceField *pNotifySequence, int nRequestID) = 0;

	///订阅有序的经纪公司用户事件，可根据已接收的RtnSequencialBrokerUserEvent中最大的UniqSequenceNo来实现续订
	virtual int ReqSubBrokerUserEvent(CShfeFtdcNotifySequenceField *pNotifySequence, int nRequestID) = 0;

	///风控报单录入请求
	virtual int ReqRiskOrderInsert(CShfeFtdcRiskForceCloseOrderField *pRiskForceCloseOrder, int nRequestID) = 0;

	///风控报单操作请求
	virtual int ReqRiskOrderAction(CShfeFtdcInputOrderActionField *pInputOrderAction, int nRequestID) = 0;

	///订阅有序的持仓，可根据已接收的RtnSequencialPosition中最大的UniqSequenceNo来实现续订
	virtual int ReqSubscribePosition(CShfeFtdcNotifySequenceField *pNotifySequence, int nRequestID) = 0;

	///风控预埋单录入请求
	virtual int ReqRiskParkedOrderInsert(CShfeFtdcRiskParkedOrderField *pRiskParkedOrder, int nRequestID) = 0;

	///请求删除预埋单
	virtual int ReqRemoveRiskParkedOrder(CShfeFtdcRemoveRiskParkedOrderField *pRemoveRiskParkedOrder, int nRequestID) = 0;

	///订阅有序的风控预埋单
	virtual int ReqSubRiskParkedOrder(CShfeFtdcNotifySequenceField *pNotifySequence, int nRequestID) = 0;

	///风控用户密码修改请求
	virtual int ReqRiskUserPasswordUpd(CShfeFtdcUserPasswordUpdateField *pUserPasswordUpdate, int nRequestID) = 0;

	///订阅有序的出入金，可根据已接收的RtnSeqDeposit中最大的UniqSequenceNo来实现续订
	virtual int ReqSubSeqDeposit(CShfeFtdcRiskNtfSequenceField *pRiskNtfSequence, int nRequestID) = 0;

	///订阅有序的交易编码，可根据已接收的RtnSeqTradingCode中最大的UniqSequenceNo来实现续订
	virtual int ReqSubSeqTradingCode(CShfeFtdcRiskNtfSequenceField *pRiskNtfSequence, int nRequestID) = 0;

	///查询投资者和联系人信息请求
		// 投资者信息数据量很大，请尽量避免一次查询大量投资者的投资者信息。
		// 如确实需要所有投资者信息数据，则强烈建议在本地保存数据，然后每天只查询有变化的投资者信息，方法如下：
		// 登录成功发送请求ReqInvestorLinkManHash(具体见函数注释)，RspInvestorLinkManHash会将投资者信息的MD5值分多个投资者区间[InvestorIDBeg,InvestorIDEnd]返回，
		// 对每个区间，与本地相同区间的投资者信息的MD5值进行比较，如果不一致，再请求该区间的投资者信息。
		// 建议将所有需要请求的投资者区间放在一个请求发送。
		// 将一个投资者信息field更新到md5的顺序：
		// md5.update((const char *)field.Address, strlen((const char *)field.Address));
		// md5.update((const char *)field.BrokerID, strlen((const char *)field.BrokerID));
		// md5.update((const char *)field.IdentifiedCardNo, strlen((const char *)field.IdentifiedCardNo));
		// md5.update((const char *)field.InvestorGroupID, strlen((const char *)field.InvestorGroupID));
		// md5.update((const char *)field.InvestorID, strlen((const char *)field.InvestorID));
		// md5.update((const char *)field.InvestorName, strlen((const char *)field.InvestorName));
		// md5.update((const char *)field.Telephone, strlen((const char *)field.Telephone));
		// md5.update((const char *)field.OrderManIdentifiedCardNo, strlen((const char *)field.OrderManIdentifiedCardNo));
		// md5.update((const char *)field.OrderManPersonName, strlen((const char *)field.OrderManPersonName));
		// md5.update((const char *)field.OrderManTelephone, strlen((const char *)field.OrderManTelephone));
		// md5.update((const char *)field.OrderManAddress, strlen((const char *)field.OrderManAddress));
		// md5.update((const char *)field.OrderManZipCode, strlen((const char *)field.OrderManZipCode));
		// md5.update((const char *)field.FundManIdentifiedCardNo, strlen((const char *)field.FundManIdentifiedCardNo));
		// md5.update((const char *)field.FundManPersonName, strlen((const char *)field.FundManPersonName));
		// md5.update((const char *)field.FundManTelephone, strlen((const char *)field.FundManTelephone));
		// md5.update((const char *)field.FundManAddress, strlen((const char *)field.FundManAddress));
		// md5.update((const char *)field.FundManZipCode, strlen((const char *)field.FundManZipCode));
		// md5.update((const char *)field.OpenManIdentifiedCardNo, strlen((const char *)field.OpenManIdentifiedCardNo));
		// md5.update((const char *)field.OpenManPersonName, strlen((const char *)field.OpenManPersonName));
		// md5.update((const char *)field.OpenManTelephone, strlen((const char *)field.OpenManTelephone));
		// md5.update((const char *)field.OpenManAddress, strlen((const char *)field.OpenManAddress));
		// md5.update((const char *)field.OpenManZipCode, strlen((const char *)field.OpenManZipCode));
		// md5.update((const char *)field.SettlementManIdentifiedCardNo, strlen((const char *)field.SettlementManIdentifiedCardNo));
		// md5.update((const char *)field.SettlementManPersonName, strlen((const char *)field.SettlementManPersonName));
		// md5.update((const char *)field.SettlementManTelephone, strlen((const char *)field.SettlementManTelephone));
		// md5.update((const char *)field.SettlementManAddress, strlen((const char *)field.SettlementManAddress));
		// md5.update((const char *)field.SettlementManZipCode, strlen((const char *)field.SettlementManZipCode));
		// md5.update((const char *)field.OpenDate, strlen((const char *)field.OpenDate));
		// md5.update((const char *)field.Mobile, strlen((const char *)field.Mobile));
		// md5.update((const char *)field.EMail, strlen((const char *)field.EMail));
		// if (field.IsActive == 0) md5.update(字符0);
		// else md5.update(字符1);
		// md5.update((const char *)field.PhoneCountryCode, strlen((const char *)field.PhoneCountryCode));
		// md5.update((const char *)field.PhoneAreaCode, strlen((const char *)field.PhoneAreaCode));
		// md5.update((const char *)field.OpenPhoneCountryCode, strlen((const char *)field.OpenPhoneCountryCode));
		// md5.update((const char *)field.OpenPhoneAreaCode, strlen((const char *)field.OpenPhoneAreaCode));
		// md5.update((const char *)field.OrderPhoneCountryCode, strlen((const char *)field.OrderPhoneCountryCode));
		// md5.update((const char *)field.OrderPhoneAreaCode, strlen((const char *)field.OrderPhoneAreaCode));
		// md5.update((const char *)field.FundPhoneCountryCode, strlen((const char *)field.FundPhoneCountryCode));
		// md5.update((const char *)field.FundPhoneAreaCode, strlen((const char *)field.FundPhoneAreaCode));
		// md5.update((const char *)field.SettlePhoneCountryCode, strlen((const char *)field.SettlePhoneCountryCode));
		// md5.update((const char *)field.SettlePhoneAreaCode, strlen((const char *)field.SettlePhoneAreaCode));
	virtual int ReqQryInvestorLinkMan(CShfeFtdcInvestorIDRangeField *pInvestorIDRange, int InvestorIDRangeCnt, 
		int nRequestID) = 0;
	
	///查询组织架构投资者对应关系请求，使用方法类似ReqQryInvestorLinkMan
	virtual int ReqQryInvestorDepartment(CShfeFtdcInvestorIDRangeField *pInvestorIDRange, int InvestorIDRangeCnt, 
		int nRequestID) = 0;

	///订阅有序的昨日资金，可根据已接收的RtnSeqPreRiskAccount中最大的UniqSequenceNo来实现续订；当日资金使用RtnRiskSyncAccount
	virtual int ReqSubPreRiskAccount(CShfeFtdcRiskNtfSequenceField *pRiskNtfSequence, int nRequestID) = 0;

	///订阅有序数据请求
	virtual int ReqSubSeqData(CShfeFtdcRiskNtfSequenceField *pRiskNtfSequence, int nRequestID) = 0;

	///查询席位资金请求
	virtual int ReqRiskQryBrokerDeposit(CShfeFtdcQueryBrokerDepositField *pQueryBrokerDeposit, int nRequestID) = 0;

	///订阅有序的风险通知版本B，可根据已接收的RtnSeqRiskNotifyB中最大的UniqSequenceNo来实现续订
	virtual int ReqSubSeqRiskNotifyB(CShfeFtdcRiskNtfSequenceField *pRiskNtfSequence, int nRequestID) = 0;

	///查询持仓排名请求
	virtual int ReqQryPositionStat(CShfeFtdcQryStatField *pQryStat, int nRequestID) = 0;

	///查询成交排名请求
	virtual int ReqQryTradeStat(CShfeFtdcQryStatField *pQryStat, int nRequestID) = 0;

	///投资者及联系人信息哈希值查询请求
		// InvestorIDBeg    起始投资者代码，为空表示用户权限下的最小投资者代码
		// InvestorIdEnd    结束投资者代码，为空表示用户权限下的最大投资者代码
		// 如果InvestorIDBeg和InvestorIDEnd都为空，则服务器会自动分多个区间返回哈希值；否则只计算请求区间一个哈希值
	virtual int ReqInvestorLinkManHash(CShfeFtdcInvestorIDRangeField *pInvestorIDRange, int nRequestID) = 0;

protected:
	~CShfeFtdcRiskUserApi(){};
};

#endif

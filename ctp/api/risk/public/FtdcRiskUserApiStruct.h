
/////////////////////////////////////////////////////////////////////////
///@system 新一代交易所系统
///@company 上海期货信息技术有限公司
///@file FtdcStruct.h
///@brief 定义了客户端接口使用的业务数据结构
///@history 
///20070227	zhangjie		创建该文件
/////////////////////////////////////////////////////////////////////////

#if !defined(_FTDCRISKSTRUCT_H)
#define _FTDCRISKSTRUCT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "string.h"
#include "math.h"
#include "FtdcRiskUserApiDataType.h"

#ifndef SMALL_DOUBLE
#define SMALL_DOUBLE	0.0000001
#endif

#ifndef EQUALDOUBLE
#define EQUALDOUBLE(x,y)	(fabs((x)-(y)) < SMALL_DOUBLE)
#endif


///信息分发
struct CShfeFtdcDisseminationField
{
  ///序列系列号
  TShfeFtdcSequenceSeriesType	SequenceSeries;
  ///序列号
  TShfeFtdcSequenceNoType	SequenceNo;

  bool operator==(const CShfeFtdcDisseminationField &ct) const
  {
    bool ret = true;
    ret = ret && (SequenceSeries == ct.SequenceSeries);
    if (!ret) return ret;
    ret = ret && (SequenceNo == ct.SequenceNo);
    if (!ret) return ret;

    return ret;
  }
};

///用户登录请求
struct CShfeFtdcReqUserLoginField
{
  ///交易日
  TShfeFtdcDateType	TradingDay;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///密码
  TShfeFtdcPasswordType	Password;
  ///用户端产品信息
  TShfeFtdcProductInfoType	UserProductInfo;
  ///接口端产品信息
  TShfeFtdcProductInfoType	InterfaceProductInfo;
  ///协议信息
  TShfeFtdcProtocolInfoType	ProtocolInfo;

  bool operator==(const CShfeFtdcReqUserLoginField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(TradingDay, ct.TradingDay) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(Password, ct.Password) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserProductInfo, ct.UserProductInfo) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InterfaceProductInfo, ct.InterfaceProductInfo) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ProtocolInfo, ct.ProtocolInfo) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///用户登录应答
struct CShfeFtdcRspUserLoginField
{
  ///交易日
  TShfeFtdcDateType	TradingDay;
  ///登录成功时间
  TShfeFtdcTimeType	LoginTime;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///交易系统名称
  TShfeFtdcSystemNameType	SystemName;
  ///前置编号
  TShfeFtdcFrontIDType	FrontID;
  ///会话编号
  TShfeFtdcSessionIDType	SessionID;
  ///最大报单引用
  TShfeFtdcOrderRefType	MaxOrderRef;
  ///上期所时间
  TShfeFtdcTimeType	SHFETime;
  ///大商所时间
  TShfeFtdcTimeType	DCETime;
  ///郑商所时间
  TShfeFtdcTimeType	CZCETime;
  ///中金所时间
  TShfeFtdcTimeType	FFEXTime;

  bool operator==(const CShfeFtdcRspUserLoginField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(TradingDay, ct.TradingDay) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(LoginTime, ct.LoginTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(SystemName, ct.SystemName) == 0);
    if (!ret) return ret;
    ret = ret && (FrontID == ct.FrontID);
    if (!ret) return ret;
    ret = ret && (SessionID == ct.SessionID);
    if (!ret) return ret;
    ret = ret && (strcmp(MaxOrderRef, ct.MaxOrderRef) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(SHFETime, ct.SHFETime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(DCETime, ct.DCETime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(CZCETime, ct.CZCETime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(FFEXTime, ct.FFEXTime) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///用户登出请求
struct CShfeFtdcUserLogoutField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///用户代码
  TShfeFtdcUserIDType	UserID;

  bool operator==(const CShfeFtdcUserLogoutField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///强制交易员退出
struct CShfeFtdcForceUserLogoutField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///用户代码
  TShfeFtdcUserIDType	UserID;

  bool operator==(const CShfeFtdcForceUserLogoutField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///银期转帐报文头
struct CShfeFtdcTransferHeaderField
{
  ///版本号，常量，1.0
  TShfeFtdcVersionType	Version;
  ///交易代码，必填
  TShfeFtdcTradeCodeType	TradeCode;
  ///交易日期，必填，格式：yyyymmdd
  TShfeFtdcTradeDateType	TradeDate;
  ///交易时间，必填，格式：hhmmss
  TShfeFtdcTradeTimeType	TradeTime;
  ///发起方流水号，N/A
  TShfeFtdcTradeSerialType	TradeSerial;
  ///期货公司代码，必填
  TShfeFtdcFutureIDType	FutureID;
  ///银行代码，根据查询银行得到，必填
  TShfeFtdcBankIDType	BankID;
  ///银行分中心代码，根据查询银行得到，必填
  TShfeFtdcBankBrchIDType	BankBrchID;
  ///操作员，N/A
  TShfeFtdcOperNoType	OperNo;
  ///交易设备类型，N/A
  TShfeFtdcDeviceIDType	DeviceID;
  ///记录数，N/A
  TShfeFtdcRecordNumType	RecordNum;
  ///会话编号，N/A
  TShfeFtdcSessionIDType	SessionID;
  ///请求编号，N/A
  TShfeFtdcRequestIDType	RequestID;

  bool operator==(const CShfeFtdcTransferHeaderField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(Version, ct.Version) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TradeCode, ct.TradeCode) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TradeDate, ct.TradeDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TradeTime, ct.TradeTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TradeSerial, ct.TradeSerial) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(FutureID, ct.FutureID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BankID, ct.BankID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BankBrchID, ct.BankBrchID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OperNo, ct.OperNo) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(DeviceID, ct.DeviceID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(RecordNum, ct.RecordNum) == 0);
    if (!ret) return ret;
    ret = ret && (SessionID == ct.SessionID);
    if (!ret) return ret;
    ret = ret && (RequestID == ct.RequestID);
    if (!ret) return ret;

    return ret;
  }
};

///银行资金转期货请求，TradeCode=202001
struct CShfeFtdcTransferBankToFutureReqField
{
  ///期货资金账户
  TShfeFtdcAccountIDType	FutureAccount;
  ///密码标志
  TShfeFtdcFuturePwdFlagType	FuturePwdFlag;
  ///密码
  TShfeFtdcFutureAccPwdType	FutureAccPwd;
  ///转账金额
  TShfeFtdcMoneyType	TradeAmt;
  ///客户手续费
  TShfeFtdcMoneyType	CustFee;
  ///币种：RMB-人民币 USD-美圆 HKD-港元
  TShfeFtdcCurrencyCodeType	CurrencyCode;

  bool operator==(const CShfeFtdcTransferBankToFutureReqField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(FutureAccount, ct.FutureAccount) == 0);
    if (!ret) return ret;
    ret = ret && (FuturePwdFlag == ct.FuturePwdFlag);
    if (!ret) return ret;
    ret = ret && (strcmp(FutureAccPwd, ct.FutureAccPwd) == 0);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(TradeAmt, ct.TradeAmt));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CustFee, ct.CustFee));
    if (!ret) return ret;
    ret = ret && (strcmp(CurrencyCode, ct.CurrencyCode) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///银行资金转期货请求响应
struct CShfeFtdcTransferBankToFutureRspField
{
  ///响应代码
  TShfeFtdcRetCodeType	RetCode;
  ///响应信息
  TShfeFtdcRetInfoType	RetInfo;
  ///资金账户
  TShfeFtdcAccountIDType	FutureAccount;
  ///转帐金额
  TShfeFtdcMoneyType	TradeAmt;
  ///应收客户手续费
  TShfeFtdcMoneyType	CustFee;
  ///币种
  TShfeFtdcCurrencyCodeType	CurrencyCode;

  bool operator==(const CShfeFtdcTransferBankToFutureRspField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(RetCode, ct.RetCode) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(RetInfo, ct.RetInfo) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(FutureAccount, ct.FutureAccount) == 0);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(TradeAmt, ct.TradeAmt));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CustFee, ct.CustFee));
    if (!ret) return ret;
    ret = ret && (strcmp(CurrencyCode, ct.CurrencyCode) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///期货资金转银行请求，TradeCode=202002
struct CShfeFtdcTransferFutureToBankReqField
{
  ///期货资金账户
  TShfeFtdcAccountIDType	FutureAccount;
  ///密码标志
  TShfeFtdcFuturePwdFlagType	FuturePwdFlag;
  ///密码
  TShfeFtdcFutureAccPwdType	FutureAccPwd;
  ///转账金额
  TShfeFtdcMoneyType	TradeAmt;
  ///客户手续费
  TShfeFtdcMoneyType	CustFee;
  ///币种：RMB-人民币 USD-美圆 HKD-港元
  TShfeFtdcCurrencyCodeType	CurrencyCode;

  bool operator==(const CShfeFtdcTransferFutureToBankReqField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(FutureAccount, ct.FutureAccount) == 0);
    if (!ret) return ret;
    ret = ret && (FuturePwdFlag == ct.FuturePwdFlag);
    if (!ret) return ret;
    ret = ret && (strcmp(FutureAccPwd, ct.FutureAccPwd) == 0);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(TradeAmt, ct.TradeAmt));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CustFee, ct.CustFee));
    if (!ret) return ret;
    ret = ret && (strcmp(CurrencyCode, ct.CurrencyCode) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///期货资金转银行请求响应
struct CShfeFtdcTransferFutureToBankRspField
{
  ///响应代码
  TShfeFtdcRetCodeType	RetCode;
  ///响应信息
  TShfeFtdcRetInfoType	RetInfo;
  ///资金账户
  TShfeFtdcAccountIDType	FutureAccount;
  ///转帐金额
  TShfeFtdcMoneyType	TradeAmt;
  ///应收客户手续费
  TShfeFtdcMoneyType	CustFee;
  ///币种
  TShfeFtdcCurrencyCodeType	CurrencyCode;

  bool operator==(const CShfeFtdcTransferFutureToBankRspField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(RetCode, ct.RetCode) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(RetInfo, ct.RetInfo) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(FutureAccount, ct.FutureAccount) == 0);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(TradeAmt, ct.TradeAmt));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CustFee, ct.CustFee));
    if (!ret) return ret;
    ret = ret && (strcmp(CurrencyCode, ct.CurrencyCode) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询银行资金请求，TradeCode=204002
struct CShfeFtdcTransferQryBankReqField
{
  ///期货资金账户
  TShfeFtdcAccountIDType	FutureAccount;
  ///密码标志
  TShfeFtdcFuturePwdFlagType	FuturePwdFlag;
  ///密码
  TShfeFtdcFutureAccPwdType	FutureAccPwd;
  ///币种：RMB-人民币 USD-美圆 HKD-港元
  TShfeFtdcCurrencyCodeType	CurrencyCode;

  bool operator==(const CShfeFtdcTransferQryBankReqField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(FutureAccount, ct.FutureAccount) == 0);
    if (!ret) return ret;
    ret = ret && (FuturePwdFlag == ct.FuturePwdFlag);
    if (!ret) return ret;
    ret = ret && (strcmp(FutureAccPwd, ct.FutureAccPwd) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(CurrencyCode, ct.CurrencyCode) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询银行资金请求响应
struct CShfeFtdcTransferQryBankRspField
{
  ///响应代码
  TShfeFtdcRetCodeType	RetCode;
  ///响应信息
  TShfeFtdcRetInfoType	RetInfo;
  ///资金账户
  TShfeFtdcAccountIDType	FutureAccount;
  ///银行余额
  TShfeFtdcMoneyType	TradeAmt;
  ///银行可用余额
  TShfeFtdcMoneyType	UseAmt;
  ///银行可取余额
  TShfeFtdcMoneyType	FetchAmt;
  ///币种
  TShfeFtdcCurrencyCodeType	CurrencyCode;

  bool operator==(const CShfeFtdcTransferQryBankRspField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(RetCode, ct.RetCode) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(RetInfo, ct.RetInfo) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(FutureAccount, ct.FutureAccount) == 0);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(TradeAmt, ct.TradeAmt));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(UseAmt, ct.UseAmt));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(FetchAmt, ct.FetchAmt));
    if (!ret) return ret;
    ret = ret && (strcmp(CurrencyCode, ct.CurrencyCode) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询银行交易明细请求，TradeCode=204999
struct CShfeFtdcTransferQryDetailReqField
{
  ///期货资金账户
  TShfeFtdcAccountIDType	FutureAccount;

  bool operator==(const CShfeFtdcTransferQryDetailReqField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(FutureAccount, ct.FutureAccount) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询银行交易明细请求响应
struct CShfeFtdcTransferQryDetailRspField
{
  ///交易日期
  TShfeFtdcDateType	TradeDate;
  ///交易时间
  TShfeFtdcTradeTimeType	TradeTime;
  ///交易代码
  TShfeFtdcTradeCodeType	TradeCode;
  ///期货流水号
  TShfeFtdcTradeSerialNoType	FutureSerial;
  ///期货公司代码
  TShfeFtdcFutureIDType	FutureID;
  ///资金帐号
  TShfeFtdcFutureAccountType	FutureAccount;
  ///银行流水号
  TShfeFtdcTradeSerialNoType	BankSerial;
  ///银行代码
  TShfeFtdcBankIDType	BankID;
  ///银行分中心代码
  TShfeFtdcBankBrchIDType	BankBrchID;
  ///银行账号
  TShfeFtdcBankAccountType	BankAccount;
  ///证件号码
  TShfeFtdcCertCodeType	CertCode;
  ///货币代码
  TShfeFtdcCurrencyCodeType	CurrencyCode;
  ///发生金额
  TShfeFtdcMoneyType	TxAmount;
  ///有效标志
  TShfeFtdcTransferValidFlagType	Flag;

  bool operator==(const CShfeFtdcTransferQryDetailRspField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(TradeDate, ct.TradeDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TradeTime, ct.TradeTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TradeCode, ct.TradeCode) == 0);
    if (!ret) return ret;
    ret = ret && (FutureSerial == ct.FutureSerial);
    if (!ret) return ret;
    ret = ret && (strcmp(FutureID, ct.FutureID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(FutureAccount, ct.FutureAccount) == 0);
    if (!ret) return ret;
    ret = ret && (BankSerial == ct.BankSerial);
    if (!ret) return ret;
    ret = ret && (strcmp(BankID, ct.BankID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BankBrchID, ct.BankBrchID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BankAccount, ct.BankAccount) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(CertCode, ct.CertCode) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(CurrencyCode, ct.CurrencyCode) == 0);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(TxAmount, ct.TxAmount));
    if (!ret) return ret;
    ret = ret && (Flag == ct.Flag);
    if (!ret) return ret;

    return ret;
  }
};

///响应信息
struct CShfeFtdcRspInfoField
{
  ///错误代码
  TShfeFtdcErrorIDType	ErrorID;
  ///错误信息
  TShfeFtdcErrorMsgType	ErrorMsg;

  bool operator==(const CShfeFtdcRspInfoField &ct) const
  {
    bool ret = true;
    ret = ret && (ErrorID == ct.ErrorID);
    if (!ret) return ret;
    ret = ret && (strcmp(ErrorMsg, ct.ErrorMsg) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///交易所
struct CShfeFtdcExchangeField
{
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///交易所名称
  TShfeFtdcExchangeNameType	ExchangeName;
  ///交易所属性
  TShfeFtdcExchangePropertyType	ExchangeProperty;

  bool operator==(const CShfeFtdcExchangeField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeName, ct.ExchangeName) == 0);
    if (!ret) return ret;
    ret = ret && (ExchangeProperty == ct.ExchangeProperty);
    if (!ret) return ret;

    return ret;
  }
};

///产品
struct CShfeFtdcProductField
{
  ///产品代码
  TShfeFtdcInstrumentIDType	ProductID;
  ///产品名称
  TShfeFtdcProductNameType	ProductName;
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///产品类型
  TShfeFtdcProductClassType	ProductClass;
  ///合约数量乘数
  TShfeFtdcVolumeMultipleType	VolumeMultiple;
  ///最小变动价位
  TShfeFtdcPriceType	PriceTick;
  ///市价单最大下单量
  TShfeFtdcVolumeType	MaxMarketOrderVolume;
  ///市价单最小下单量
  TShfeFtdcVolumeType	MinMarketOrderVolume;
  ///限价单最大下单量
  TShfeFtdcVolumeType	MaxLimitOrderVolume;
  ///限价单最小下单量
  TShfeFtdcVolumeType	MinLimitOrderVolume;
  ///持仓类型
  TShfeFtdcPositionTypeType	PositionType;
  ///持仓日期类型
  TShfeFtdcPositionDateTypeType	PositionDateType;

  bool operator==(const CShfeFtdcProductField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(ProductID, ct.ProductID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ProductName, ct.ProductName) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (ProductClass == ct.ProductClass);
    if (!ret) return ret;
    ret = ret && (VolumeMultiple == ct.VolumeMultiple);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PriceTick, ct.PriceTick));
    if (!ret) return ret;
    ret = ret && (MaxMarketOrderVolume == ct.MaxMarketOrderVolume);
    if (!ret) return ret;
    ret = ret && (MinMarketOrderVolume == ct.MinMarketOrderVolume);
    if (!ret) return ret;
    ret = ret && (MaxLimitOrderVolume == ct.MaxLimitOrderVolume);
    if (!ret) return ret;
    ret = ret && (MinLimitOrderVolume == ct.MinLimitOrderVolume);
    if (!ret) return ret;
    ret = ret && (PositionType == ct.PositionType);
    if (!ret) return ret;
    ret = ret && (PositionDateType == ct.PositionDateType);
    if (!ret) return ret;

    return ret;
  }
};

///合约
struct CShfeFtdcInstrumentField
{
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///合约名称
  TShfeFtdcInstrumentNameType	InstrumentName;
  ///合约在交易所的代码
  TShfeFtdcExchangeInstIDType	ExchangeInstID;
  ///产品代码
  TShfeFtdcInstrumentIDType	ProductID;
  ///产品类型
  TShfeFtdcProductClassType	ProductClass;
  ///交割年份
  TShfeFtdcYearType	DeliveryYear;
  ///交割月
  TShfeFtdcMonthType	DeliveryMonth;
  ///市价单最大下单量
  TShfeFtdcVolumeType	MaxMarketOrderVolume;
  ///市价单最小下单量
  TShfeFtdcVolumeType	MinMarketOrderVolume;
  ///限价单最大下单量
  TShfeFtdcVolumeType	MaxLimitOrderVolume;
  ///限价单最小下单量
  TShfeFtdcVolumeType	MinLimitOrderVolume;
  ///合约数量乘数
  TShfeFtdcVolumeMultipleType	VolumeMultiple;
  ///最小变动价位
  TShfeFtdcPriceType	PriceTick;
  ///创建日
  TShfeFtdcDateType	CreateDate;
  ///上市日
  TShfeFtdcDateType	OpenDate;
  ///到期日
  TShfeFtdcDateType	ExpireDate;
  ///开始交割日
  TShfeFtdcDateType	StartDelivDate;
  ///结束交割日
  TShfeFtdcDateType	EndDelivDate;
  ///合约生命周期状态
  TShfeFtdcInstLifePhaseType	InstLifePhase;
  ///当前是否交易
  TShfeFtdcBoolType	IsTrading;
  ///持仓类型
  TShfeFtdcPositionTypeType	PositionType;
  ///持仓日期类型
  TShfeFtdcPositionDateTypeType	PositionDateType;
  ///多头保证金率
  TShfeFtdcRatioType	LongMarginRatio;
  ///空头保证金率
  TShfeFtdcRatioType	ShortMarginRatio;

  bool operator==(const CShfeFtdcInstrumentField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentName, ct.InstrumentName) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeInstID, ct.ExchangeInstID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ProductID, ct.ProductID) == 0);
    if (!ret) return ret;
    ret = ret && (ProductClass == ct.ProductClass);
    if (!ret) return ret;
    ret = ret && (DeliveryYear == ct.DeliveryYear);
    if (!ret) return ret;
    ret = ret && (DeliveryMonth == ct.DeliveryMonth);
    if (!ret) return ret;
    ret = ret && (MaxMarketOrderVolume == ct.MaxMarketOrderVolume);
    if (!ret) return ret;
    ret = ret && (MinMarketOrderVolume == ct.MinMarketOrderVolume);
    if (!ret) return ret;
    ret = ret && (MaxLimitOrderVolume == ct.MaxLimitOrderVolume);
    if (!ret) return ret;
    ret = ret && (MinLimitOrderVolume == ct.MinLimitOrderVolume);
    if (!ret) return ret;
    ret = ret && (VolumeMultiple == ct.VolumeMultiple);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PriceTick, ct.PriceTick));
    if (!ret) return ret;
    ret = ret && (strcmp(CreateDate, ct.CreateDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OpenDate, ct.OpenDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExpireDate, ct.ExpireDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(StartDelivDate, ct.StartDelivDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(EndDelivDate, ct.EndDelivDate) == 0);
    if (!ret) return ret;
    ret = ret && (InstLifePhase == ct.InstLifePhase);
    if (!ret) return ret;
    ret = ret && (IsTrading == ct.IsTrading);
    if (!ret) return ret;
    ret = ret && (PositionType == ct.PositionType);
    if (!ret) return ret;
    ret = ret && (PositionDateType == ct.PositionDateType);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(LongMarginRatio, ct.LongMarginRatio));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ShortMarginRatio, ct.ShortMarginRatio));
    if (!ret) return ret;

    return ret;
  }
};

///经纪公司
struct CShfeFtdcBrokerField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///经纪公司简称
  TShfeFtdcBrokerAbbrType	BrokerAbbr;
  ///经纪公司名称
  TShfeFtdcBrokerNameType	BrokerName;
  ///是否活跃
  TShfeFtdcBoolType	IsActive;

  bool operator==(const CShfeFtdcBrokerField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerAbbr, ct.BrokerAbbr) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerName, ct.BrokerName) == 0);
    if (!ret) return ret;
    ret = ret && (IsActive == ct.IsActive);
    if (!ret) return ret;

    return ret;
  }
};

///交易所交易员
struct CShfeFtdcTraderField
{
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///交易所交易员代码
  TShfeFtdcTraderIDType	TraderID;
  ///会员代码
  TShfeFtdcParticipantIDType	ParticipantID;
  ///密码
  TShfeFtdcPasswordType	Password;
  ///安装数量
  TShfeFtdcInstallCountType	InstallCount;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;

  bool operator==(const CShfeFtdcTraderField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TraderID, ct.TraderID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ParticipantID, ct.ParticipantID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(Password, ct.Password) == 0);
    if (!ret) return ret;
    ret = ret && (InstallCount == ct.InstallCount);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///投资者
struct CShfeFtdcInvestorField
{
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者分组代码
  TShfeFtdcInvestorIDType	InvestorGroupID;
  ///投资者名称
  TShfeFtdcPartyNameType	InvestorName;
  ///证件类型
  TShfeFtdcIdCardTypeType	IdentifiedCardType;
  ///证件号码
  TShfeFtdcIdentifiedCardNoType	IdentifiedCardNo;
  ///是否活跃
  TShfeFtdcBoolType	IsActive;
  ///联系电话
  TShfeFtdcTelephoneType	Telephone;
  ///通讯地址
  TShfeFtdcAddressType	Address;
  ///开户日期
  TShfeFtdcDateType	OpenDate;
  ///手机
  TShfeFtdcMobileType	Mobile;
  ///手续费率模板代码
  TShfeFtdcInvestorIDType	CommModelID;

  bool operator==(const CShfeFtdcInvestorField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorGroupID, ct.InvestorGroupID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorName, ct.InvestorName) == 0);
    if (!ret) return ret;
    ret = ret && (IdentifiedCardType == ct.IdentifiedCardType);
    if (!ret) return ret;
    ret = ret && (strcmp(IdentifiedCardNo, ct.IdentifiedCardNo) == 0);
    if (!ret) return ret;
    ret = ret && (IsActive == ct.IsActive);
    if (!ret) return ret;
    ret = ret && (strcmp(Telephone, ct.Telephone) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(Address, ct.Address) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OpenDate, ct.OpenDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(Mobile, ct.Mobile) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(CommModelID, ct.CommModelID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///交易编码
struct CShfeFtdcTradingCodeField
{
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///客户代码
  TShfeFtdcClientIDType	ClientID;
  ///是否活跃
  TShfeFtdcBoolType	IsActive;
  ///交易编码类型
  TShfeFtdcClientIDTypeType	ClientIDType;

  bool operator==(const CShfeFtdcTradingCodeField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ClientID, ct.ClientID) == 0);
    if (!ret) return ret;
    ret = ret && (IsActive == ct.IsActive);
    if (!ret) return ret;
    ret = ret && (ClientIDType == ct.ClientIDType);
    if (!ret) return ret;

    return ret;
  }
};

///会员编码和经纪公司编码对照表
struct CShfeFtdcPartBrokerField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///会员代码
  TShfeFtdcParticipantIDType	ParticipantID;
  ///是否活跃
  TShfeFtdcBoolType	IsActive;

  bool operator==(const CShfeFtdcPartBrokerField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ParticipantID, ct.ParticipantID) == 0);
    if (!ret) return ret;
    ret = ret && (IsActive == ct.IsActive);
    if (!ret) return ret;

    return ret;
  }
};

///管理用户
struct CShfeFtdcSuperUserField
{
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///用户名称
  TShfeFtdcUserNameType	UserName;
  ///密码
  TShfeFtdcPasswordType	Password;
  ///是否活跃
  TShfeFtdcBoolType	IsActive;

  bool operator==(const CShfeFtdcSuperUserField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserName, ct.UserName) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(Password, ct.Password) == 0);
    if (!ret) return ret;
    ret = ret && (IsActive == ct.IsActive);
    if (!ret) return ret;

    return ret;
  }
};

///管理用户功能权限
struct CShfeFtdcSuperUserFunctionField
{
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///功能代码
  TShfeFtdcFunctionCodeType	FunctionCode;

  bool operator==(const CShfeFtdcSuperUserFunctionField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (FunctionCode == ct.FunctionCode);
    if (!ret) return ret;

    return ret;
  }
};

///投资者组
struct CShfeFtdcInvestorGroupField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者分组代码
  TShfeFtdcInvestorIDType	InvestorGroupID;
  ///投资者分组名称
  TShfeFtdcInvestorGroupNameType	InvestorGroupName;

  bool operator==(const CShfeFtdcInvestorGroupField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorGroupID, ct.InvestorGroupID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorGroupName, ct.InvestorGroupName) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///资金账户
struct CShfeFtdcTradingAccountField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者帐号
  TShfeFtdcAccountIDType	AccountID;
  ///上次质押金额
  TShfeFtdcMoneyType	PreMortgage;
  ///上次信用额度
  TShfeFtdcMoneyType	PreCredit;
  ///上次存款额
  TShfeFtdcMoneyType	PreDeposit;
  ///上次结算准备金
  TShfeFtdcMoneyType	PreBalance;
  ///上次占用的保证金
  TShfeFtdcMoneyType	PreMargin;
  ///利息基数
  TShfeFtdcMoneyType	InterestBase;
  ///利息收入
  TShfeFtdcMoneyType	Interest;
  ///入金金额
  TShfeFtdcMoneyType	Deposit;
  ///出金金额
  TShfeFtdcMoneyType	Withdraw;
  ///冻结的保证金
  TShfeFtdcMoneyType	FrozenMargin;
  ///冻结的资金
  TShfeFtdcMoneyType	FrozenCash;
  ///冻结的手续费
  TShfeFtdcMoneyType	FrozenCommission;
  ///当前保证金总额
  TShfeFtdcMoneyType	CurrMargin;
  ///资金差额
  TShfeFtdcMoneyType	CashIn;
  ///手续费
  TShfeFtdcMoneyType	Commission;
  ///平仓盈亏
  TShfeFtdcMoneyType	CloseProfit;
  ///持仓盈亏
  TShfeFtdcMoneyType	PositionProfit;
  ///期货结算准备金
  TShfeFtdcMoneyType	Balance;
  ///可用资金
  TShfeFtdcMoneyType	Available;
  ///可取资金
  TShfeFtdcMoneyType	WithdrawQuota;
  ///基本准备金
  TShfeFtdcMoneyType	Reserve;
  ///交易日
  TShfeFtdcDateType	TradingDay;
  ///结算编号
  TShfeFtdcSettlementIDType	SettlementID;
  ///信用额度
  TShfeFtdcMoneyType	Credit;
  ///质押金额
  TShfeFtdcMoneyType	Mortgage;
  ///交易所保证金
  TShfeFtdcMoneyType	ExchangeMargin;
  ///投资者交割保证金
  TShfeFtdcMoneyType	DeliveryMargin;
  ///交易所交割保证金
  TShfeFtdcMoneyType	ExchangeDeliveryMargin;

  bool operator==(const CShfeFtdcTradingAccountField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(AccountID, ct.AccountID) == 0);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreMortgage, ct.PreMortgage));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreCredit, ct.PreCredit));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreDeposit, ct.PreDeposit));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreBalance, ct.PreBalance));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreMargin, ct.PreMargin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(InterestBase, ct.InterestBase));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Interest, ct.Interest));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Deposit, ct.Deposit));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Withdraw, ct.Withdraw));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(FrozenMargin, ct.FrozenMargin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(FrozenCash, ct.FrozenCash));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(FrozenCommission, ct.FrozenCommission));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CurrMargin, ct.CurrMargin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CashIn, ct.CashIn));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Commission, ct.Commission));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CloseProfit, ct.CloseProfit));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PositionProfit, ct.PositionProfit));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Balance, ct.Balance));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Available, ct.Available));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(WithdrawQuota, ct.WithdrawQuota));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Reserve, ct.Reserve));
    if (!ret) return ret;
    ret = ret && (strcmp(TradingDay, ct.TradingDay) == 0);
    if (!ret) return ret;
    ret = ret && (SettlementID == ct.SettlementID);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Credit, ct.Credit));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Mortgage, ct.Mortgage));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ExchangeMargin, ct.ExchangeMargin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(DeliveryMargin, ct.DeliveryMargin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ExchangeDeliveryMargin, ct.ExchangeDeliveryMargin));
    if (!ret) return ret;

    return ret;
  }
};

///投资者持仓
struct CShfeFtdcInvestorPositionField
{
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///持仓多空方向
  TShfeFtdcPosiDirectionType	PosiDirection;
  ///投机套保标志
  TShfeFtdcHedgeFlagType	HedgeFlag;
  ///持仓日期
  TShfeFtdcPositionDateType	PositionDate;
  ///上日持仓
  TShfeFtdcVolumeType	YdPosition;
  ///今日持仓
  TShfeFtdcVolumeType	Position;
  ///多头冻结
  TShfeFtdcVolumeType	LongFrozen;
  ///空头冻结
  TShfeFtdcVolumeType	ShortFrozen;
  ///开仓冻结金额
  TShfeFtdcMoneyType	LongFrozenAmount;
  ///开仓冻结金额
  TShfeFtdcMoneyType	ShortFrozenAmount;
  ///开仓量
  TShfeFtdcVolumeType	OpenVolume;
  ///平仓量
  TShfeFtdcVolumeType	CloseVolume;
  ///开仓金额
  TShfeFtdcMoneyType	OpenAmount;
  ///平仓金额
  TShfeFtdcMoneyType	CloseAmount;
  ///持仓成本
  TShfeFtdcMoneyType	PositionCost;
  ///上次占用的保证金
  TShfeFtdcMoneyType	PreMargin;
  ///占用的保证金
  TShfeFtdcMoneyType	UseMargin;
  ///冻结的保证金
  TShfeFtdcMoneyType	FrozenMargin;
  ///冻结的资金
  TShfeFtdcMoneyType	FrozenCash;
  ///冻结的手续费
  TShfeFtdcMoneyType	FrozenCommission;
  ///资金差额
  TShfeFtdcMoneyType	CashIn;
  ///手续费
  TShfeFtdcMoneyType	Commission;
  ///平仓盈亏
  TShfeFtdcMoneyType	CloseProfit;
  ///持仓盈亏
  TShfeFtdcMoneyType	PositionProfit;
  ///上次结算价
  TShfeFtdcPriceType	PreSettlementPrice;
  ///本次结算价
  TShfeFtdcPriceType	SettlementPrice;
  ///交易日
  TShfeFtdcDateType	TradingDay;
  ///结算编号
  TShfeFtdcSettlementIDType	SettlementID;
  ///开仓成本
  TShfeFtdcMoneyType	OpenCost;
  ///交易所保证金
  TShfeFtdcMoneyType	ExchangeMargin;
  ///组合成交形成的持仓
  TShfeFtdcVolumeType	CombPosition;
  ///组合多头冻结
  TShfeFtdcVolumeType	CombLongFrozen;
  ///组合空头冻结
  TShfeFtdcVolumeType	CombShortFrozen;
  ///逐日盯市平仓盈亏
  TShfeFtdcMoneyType	CloseProfitByDate;
  ///逐笔对冲平仓盈亏
  TShfeFtdcMoneyType	CloseProfitByTrade;
  ///今日持仓
  TShfeFtdcVolumeType	TodayPosition;
  ///保证金率
  TShfeFtdcRatioType	MarginRateByMoney;
  ///保证金率(按手数)
  TShfeFtdcRatioType	MarginRateByVolume;

  bool operator==(const CShfeFtdcInvestorPositionField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (PosiDirection == ct.PosiDirection);
    if (!ret) return ret;
    ret = ret && (HedgeFlag == ct.HedgeFlag);
    if (!ret) return ret;
    ret = ret && (PositionDate == ct.PositionDate);
    if (!ret) return ret;
    ret = ret && (YdPosition == ct.YdPosition);
    if (!ret) return ret;
    ret = ret && (Position == ct.Position);
    if (!ret) return ret;
    ret = ret && (LongFrozen == ct.LongFrozen);
    if (!ret) return ret;
    ret = ret && (ShortFrozen == ct.ShortFrozen);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(LongFrozenAmount, ct.LongFrozenAmount));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ShortFrozenAmount, ct.ShortFrozenAmount));
    if (!ret) return ret;
    ret = ret && (OpenVolume == ct.OpenVolume);
    if (!ret) return ret;
    ret = ret && (CloseVolume == ct.CloseVolume);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(OpenAmount, ct.OpenAmount));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CloseAmount, ct.CloseAmount));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PositionCost, ct.PositionCost));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreMargin, ct.PreMargin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(UseMargin, ct.UseMargin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(FrozenMargin, ct.FrozenMargin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(FrozenCash, ct.FrozenCash));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(FrozenCommission, ct.FrozenCommission));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CashIn, ct.CashIn));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Commission, ct.Commission));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CloseProfit, ct.CloseProfit));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PositionProfit, ct.PositionProfit));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreSettlementPrice, ct.PreSettlementPrice));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(SettlementPrice, ct.SettlementPrice));
    if (!ret) return ret;
    ret = ret && (strcmp(TradingDay, ct.TradingDay) == 0);
    if (!ret) return ret;
    ret = ret && (SettlementID == ct.SettlementID);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(OpenCost, ct.OpenCost));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ExchangeMargin, ct.ExchangeMargin));
    if (!ret) return ret;
    ret = ret && (CombPosition == ct.CombPosition);
    if (!ret) return ret;
    ret = ret && (CombLongFrozen == ct.CombLongFrozen);
    if (!ret) return ret;
    ret = ret && (CombShortFrozen == ct.CombShortFrozen);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CloseProfitByDate, ct.CloseProfitByDate));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CloseProfitByTrade, ct.CloseProfitByTrade));
    if (!ret) return ret;
    ret = ret && (TodayPosition == ct.TodayPosition);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(MarginRateByMoney, ct.MarginRateByMoney));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(MarginRateByVolume, ct.MarginRateByVolume));
    if (!ret) return ret;

    return ret;
  }
};

///合约保证金率
struct CShfeFtdcInstrumentMarginRateField
{
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///投资者范围
  TShfeFtdcInvestorRangeType	InvestorRange;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///投机套保标志
  TShfeFtdcHedgeFlagType	HedgeFlag;
  ///多头保证金率
  TShfeFtdcRatioType	LongMarginRatioByMoney;
  ///多头保证金费
  TShfeFtdcMoneyType	LongMarginRatioByVolume;
  ///空头保证金率
  TShfeFtdcRatioType	ShortMarginRatioByMoney;
  ///空头保证金费
  TShfeFtdcMoneyType	ShortMarginRatioByVolume;
  ///是否相对交易所收取
  TShfeFtdcBoolType	IsRelative;

  bool operator==(const CShfeFtdcInstrumentMarginRateField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (InvestorRange == ct.InvestorRange);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (HedgeFlag == ct.HedgeFlag);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(LongMarginRatioByMoney, ct.LongMarginRatioByMoney));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(LongMarginRatioByVolume, ct.LongMarginRatioByVolume));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ShortMarginRatioByMoney, ct.ShortMarginRatioByMoney));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ShortMarginRatioByVolume, ct.ShortMarginRatioByVolume));
    if (!ret) return ret;
    ret = ret && (IsRelative == ct.IsRelative);
    if (!ret) return ret;

    return ret;
  }
};

///合约手续费率
struct CShfeFtdcInstrumentCommissionRateField
{
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///投资者范围
  TShfeFtdcInvestorRangeType	InvestorRange;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///开仓手续费率
  TShfeFtdcRatioType	OpenRatioByMoney;
  ///开仓手续费
  TShfeFtdcRatioType	OpenRatioByVolume;
  ///平仓手续费率
  TShfeFtdcRatioType	CloseRatioByMoney;
  ///平仓手续费
  TShfeFtdcRatioType	CloseRatioByVolume;
  ///平今手续费率
  TShfeFtdcRatioType	CloseTodayRatioByMoney;
  ///平今手续费
  TShfeFtdcRatioType	CloseTodayRatioByVolume;

  bool operator==(const CShfeFtdcInstrumentCommissionRateField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (InvestorRange == ct.InvestorRange);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(OpenRatioByMoney, ct.OpenRatioByMoney));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(OpenRatioByVolume, ct.OpenRatioByVolume));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CloseRatioByMoney, ct.CloseRatioByMoney));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CloseRatioByVolume, ct.CloseRatioByVolume));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CloseTodayRatioByMoney, ct.CloseTodayRatioByMoney));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CloseTodayRatioByVolume, ct.CloseTodayRatioByVolume));
    if (!ret) return ret;

    return ret;
  }
};

///深度行情
struct CShfeFtdcDepthMarketDataField
{
  ///交易日
  TShfeFtdcDateType	TradingDay;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///合约在交易所的代码
  TShfeFtdcExchangeInstIDType	ExchangeInstID;
  ///最新价
  TShfeFtdcPriceType	LastPrice;
  ///上次结算价
  TShfeFtdcPriceType	PreSettlementPrice;
  ///昨收盘
  TShfeFtdcPriceType	PreClosePrice;
  ///昨持仓量
  TShfeFtdcLargeVolumeType	PreOpenInterest;
  ///今开盘
  TShfeFtdcPriceType	OpenPrice;
  ///最高价
  TShfeFtdcPriceType	HighestPrice;
  ///最低价
  TShfeFtdcPriceType	LowestPrice;
  ///数量
  TShfeFtdcVolumeType	Volume;
  ///成交金额
  TShfeFtdcMoneyType	Turnover;
  ///持仓量
  TShfeFtdcLargeVolumeType	OpenInterest;
  ///今收盘
  TShfeFtdcPriceType	ClosePrice;
  ///本次结算价
  TShfeFtdcPriceType	SettlementPrice;
  ///涨停板价
  TShfeFtdcPriceType	UpperLimitPrice;
  ///跌停板价
  TShfeFtdcPriceType	LowerLimitPrice;
  ///昨虚实度
  TShfeFtdcRatioType	PreDelta;
  ///今虚实度
  TShfeFtdcRatioType	CurrDelta;
  ///最后修改时间
  TShfeFtdcTimeType	UpdateTime;
  ///最后修改毫秒
  TShfeFtdcMillisecType	UpdateMillisec;
  ///申买价一
  TShfeFtdcPriceType	BidPrice1;
  ///申买量一
  TShfeFtdcVolumeType	BidVolume1;
  ///申卖价一
  TShfeFtdcPriceType	AskPrice1;
  ///申卖量一
  TShfeFtdcVolumeType	AskVolume1;
  ///申买价二
  TShfeFtdcPriceType	BidPrice2;
  ///申买量二
  TShfeFtdcVolumeType	BidVolume2;
  ///申卖价二
  TShfeFtdcPriceType	AskPrice2;
  ///申卖量二
  TShfeFtdcVolumeType	AskVolume2;
  ///申买价三
  TShfeFtdcPriceType	BidPrice3;
  ///申买量三
  TShfeFtdcVolumeType	BidVolume3;
  ///申卖价三
  TShfeFtdcPriceType	AskPrice3;
  ///申卖量三
  TShfeFtdcVolumeType	AskVolume3;
  ///申买价四
  TShfeFtdcPriceType	BidPrice4;
  ///申买量四
  TShfeFtdcVolumeType	BidVolume4;
  ///申卖价四
  TShfeFtdcPriceType	AskPrice4;
  ///申卖量四
  TShfeFtdcVolumeType	AskVolume4;
  ///申买价五
  TShfeFtdcPriceType	BidPrice5;
  ///申买量五
  TShfeFtdcVolumeType	BidVolume5;
  ///申卖价五
  TShfeFtdcPriceType	AskPrice5;
  ///申卖量五
  TShfeFtdcVolumeType	AskVolume5;
  ///当日均价
  TShfeFtdcPriceType	AveragePrice;

  bool operator==(const CShfeFtdcDepthMarketDataField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(TradingDay, ct.TradingDay) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeInstID, ct.ExchangeInstID) == 0);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(LastPrice, ct.LastPrice));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreSettlementPrice, ct.PreSettlementPrice));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreClosePrice, ct.PreClosePrice));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreOpenInterest, ct.PreOpenInterest));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(OpenPrice, ct.OpenPrice));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(HighestPrice, ct.HighestPrice));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(LowestPrice, ct.LowestPrice));
    if (!ret) return ret;
    ret = ret && (Volume == ct.Volume);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Turnover, ct.Turnover));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(OpenInterest, ct.OpenInterest));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ClosePrice, ct.ClosePrice));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(SettlementPrice, ct.SettlementPrice));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(UpperLimitPrice, ct.UpperLimitPrice));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(LowerLimitPrice, ct.LowerLimitPrice));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreDelta, ct.PreDelta));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CurrDelta, ct.CurrDelta));
    if (!ret) return ret;
    ret = ret && (strcmp(UpdateTime, ct.UpdateTime) == 0);
    if (!ret) return ret;
    ret = ret && (UpdateMillisec == ct.UpdateMillisec);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(BidPrice1, ct.BidPrice1));
    if (!ret) return ret;
    ret = ret && (BidVolume1 == ct.BidVolume1);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(AskPrice1, ct.AskPrice1));
    if (!ret) return ret;
    ret = ret && (AskVolume1 == ct.AskVolume1);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(BidPrice2, ct.BidPrice2));
    if (!ret) return ret;
    ret = ret && (BidVolume2 == ct.BidVolume2);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(AskPrice2, ct.AskPrice2));
    if (!ret) return ret;
    ret = ret && (AskVolume2 == ct.AskVolume2);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(BidPrice3, ct.BidPrice3));
    if (!ret) return ret;
    ret = ret && (BidVolume3 == ct.BidVolume3);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(AskPrice3, ct.AskPrice3));
    if (!ret) return ret;
    ret = ret && (AskVolume3 == ct.AskVolume3);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(BidPrice4, ct.BidPrice4));
    if (!ret) return ret;
    ret = ret && (BidVolume4 == ct.BidVolume4);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(AskPrice4, ct.AskPrice4));
    if (!ret) return ret;
    ret = ret && (AskVolume4 == ct.AskVolume4);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(BidPrice5, ct.BidPrice5));
    if (!ret) return ret;
    ret = ret && (BidVolume5 == ct.BidVolume5);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(AskPrice5, ct.AskPrice5));
    if (!ret) return ret;
    ret = ret && (AskVolume5 == ct.AskVolume5);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(AveragePrice, ct.AveragePrice));
    if (!ret) return ret;

    return ret;
  }
};

///投资者合约交易权限
struct CShfeFtdcInstrumentTradingRightField
{
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///投资者范围
  TShfeFtdcInvestorRangeType	InvestorRange;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///交易权限
  TShfeFtdcTradingRightType	TradingRight;

  bool operator==(const CShfeFtdcInstrumentTradingRightField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (InvestorRange == ct.InvestorRange);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (TradingRight == ct.TradingRight);
    if (!ret) return ret;

    return ret;
  }
};

///经纪公司用户
struct CShfeFtdcBrokerUserField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///用户名称
  TShfeFtdcUserNameType	UserName;
  ///用户类型
  TShfeFtdcUserTypeType	UserType;
  ///是否活跃
  TShfeFtdcBoolType	IsActive;
  ///是否使用令牌
  TShfeFtdcBoolType	IsUsingOTP;

  bool operator==(const CShfeFtdcBrokerUserField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserName, ct.UserName) == 0);
    if (!ret) return ret;
    ret = ret && (UserType == ct.UserType);
    if (!ret) return ret;
    ret = ret && (IsActive == ct.IsActive);
    if (!ret) return ret;
    ret = ret && (IsUsingOTP == ct.IsUsingOTP);
    if (!ret) return ret;

    return ret;
  }
};

///经纪公司用户口令
struct CShfeFtdcBrokerUserPasswordField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///密码
  TShfeFtdcPasswordType	Password;

  bool operator==(const CShfeFtdcBrokerUserPasswordField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(Password, ct.Password) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///经纪公司用户功能权限
struct CShfeFtdcBrokerUserFunctionField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///经纪公司功能代码
  TShfeFtdcBrokerFunctionCodeType	BrokerFunctionCode;

  bool operator==(const CShfeFtdcBrokerUserFunctionField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (BrokerFunctionCode == ct.BrokerFunctionCode);
    if (!ret) return ret;

    return ret;
  }
};

///交易所交易员报盘机
struct CShfeFtdcTraderOfferField
{
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///交易所交易员代码
  TShfeFtdcTraderIDType	TraderID;
  ///会员代码
  TShfeFtdcParticipantIDType	ParticipantID;
  ///密码
  TShfeFtdcPasswordType	Password;
  ///安装编号
  TShfeFtdcInstallIDType	InstallID;
  ///本地报单编号
  TShfeFtdcOrderLocalIDType	OrderLocalID;
  ///交易所交易员连接状态
  TShfeFtdcTraderConnectStatusType	TraderConnectStatus;
  ///发出连接请求的日期
  TShfeFtdcDateType	ConnectRequestDate;
  ///发出连接请求的时间
  TShfeFtdcTimeType	ConnectRequestTime;
  ///上次报告日期
  TShfeFtdcDateType	LastReportDate;
  ///上次报告时间
  TShfeFtdcTimeType	LastReportTime;
  ///完成连接日期
  TShfeFtdcDateType	ConnectDate;
  ///完成连接时间
  TShfeFtdcTimeType	ConnectTime;
  ///启动日期
  TShfeFtdcDateType	StartDate;
  ///启动时间
  TShfeFtdcTimeType	StartTime;
  ///交易日
  TShfeFtdcDateType	TradingDay;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///本席位最大成交编号
  TShfeFtdcTradeIDType	MaxTradeID;
  ///本席位最大报单备拷
  TShfeFtdcReturnCodeType	MaxOrderMessageReference;

  bool operator==(const CShfeFtdcTraderOfferField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TraderID, ct.TraderID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ParticipantID, ct.ParticipantID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(Password, ct.Password) == 0);
    if (!ret) return ret;
    ret = ret && (InstallID == ct.InstallID);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderLocalID, ct.OrderLocalID) == 0);
    if (!ret) return ret;
    ret = ret && (TraderConnectStatus == ct.TraderConnectStatus);
    if (!ret) return ret;
    ret = ret && (strcmp(ConnectRequestDate, ct.ConnectRequestDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ConnectRequestTime, ct.ConnectRequestTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(LastReportDate, ct.LastReportDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(LastReportTime, ct.LastReportTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ConnectDate, ct.ConnectDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ConnectTime, ct.ConnectTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(StartDate, ct.StartDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(StartTime, ct.StartTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TradingDay, ct.TradingDay) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(MaxTradeID, ct.MaxTradeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(MaxOrderMessageReference, ct.MaxOrderMessageReference) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///投资者结算结果
struct CShfeFtdcSettlementInfoField
{
  ///交易日
  TShfeFtdcDateType	TradingDay;
  ///结算编号
  TShfeFtdcSettlementIDType	SettlementID;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///序号
  TShfeFtdcSequenceNoType	SequenceNo;
  ///消息正文
  TShfeFtdcContentType	Content;

  bool operator==(const CShfeFtdcSettlementInfoField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(TradingDay, ct.TradingDay) == 0);
    if (!ret) return ret;
    ret = ret && (SettlementID == ct.SettlementID);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (SequenceNo == ct.SequenceNo);
    if (!ret) return ret;
    ret = ret && (strcmp(Content, ct.Content) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///合约保证金率调整
struct CShfeFtdcInstrumentMarginRateAdjustField
{
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///投资者范围
  TShfeFtdcInvestorRangeType	InvestorRange;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///投机套保标志
  TShfeFtdcHedgeFlagType	HedgeFlag;
  ///多头保证金率
  TShfeFtdcRatioType	LongMarginRatioByMoney;
  ///多头保证金费
  TShfeFtdcMoneyType	LongMarginRatioByVolume;
  ///空头保证金率
  TShfeFtdcRatioType	ShortMarginRatioByMoney;
  ///空头保证金费
  TShfeFtdcMoneyType	ShortMarginRatioByVolume;
  ///是否相对交易所收取
  TShfeFtdcBoolType	IsRelative;

  bool operator==(const CShfeFtdcInstrumentMarginRateAdjustField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (InvestorRange == ct.InvestorRange);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (HedgeFlag == ct.HedgeFlag);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(LongMarginRatioByMoney, ct.LongMarginRatioByMoney));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(LongMarginRatioByVolume, ct.LongMarginRatioByVolume));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ShortMarginRatioByMoney, ct.ShortMarginRatioByMoney));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ShortMarginRatioByVolume, ct.ShortMarginRatioByVolume));
    if (!ret) return ret;
    ret = ret && (IsRelative == ct.IsRelative);
    if (!ret) return ret;

    return ret;
  }
};

///交易所保证金率
struct CShfeFtdcExchangeMarginRateField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///投机套保标志
  TShfeFtdcHedgeFlagType	HedgeFlag;
  ///多头保证金率
  TShfeFtdcRatioType	LongMarginRatioByMoney;
  ///多头保证金费
  TShfeFtdcMoneyType	LongMarginRatioByVolume;
  ///空头保证金率
  TShfeFtdcRatioType	ShortMarginRatioByMoney;
  ///空头保证金费
  TShfeFtdcMoneyType	ShortMarginRatioByVolume;

  bool operator==(const CShfeFtdcExchangeMarginRateField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (HedgeFlag == ct.HedgeFlag);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(LongMarginRatioByMoney, ct.LongMarginRatioByMoney));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(LongMarginRatioByVolume, ct.LongMarginRatioByVolume));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ShortMarginRatioByMoney, ct.ShortMarginRatioByMoney));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ShortMarginRatioByVolume, ct.ShortMarginRatioByVolume));
    if (!ret) return ret;

    return ret;
  }
};

///交易所保证金率调整
struct CShfeFtdcExchangeMarginRateAdjustField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///投机套保标志
  TShfeFtdcHedgeFlagType	HedgeFlag;
  ///跟随交易所投资者多头保证金率
  TShfeFtdcRatioType	LongMarginRatioByMoney;
  ///跟随交易所投资者多头保证金费
  TShfeFtdcMoneyType	LongMarginRatioByVolume;
  ///跟随交易所投资者空头保证金率
  TShfeFtdcRatioType	ShortMarginRatioByMoney;
  ///跟随交易所投资者空头保证金费
  TShfeFtdcMoneyType	ShortMarginRatioByVolume;
  ///交易所多头保证金率
  TShfeFtdcRatioType	ExchLongMarginRatioByMoney;
  ///交易所多头保证金费
  TShfeFtdcMoneyType	ExchLongMarginRatioByVolume;
  ///交易所空头保证金率
  TShfeFtdcRatioType	ExchShortMarginRatioByMoney;
  ///交易所空头保证金费
  TShfeFtdcMoneyType	ExchShortMarginRatioByVolume;
  ///不跟随交易所投资者多头保证金率
  TShfeFtdcRatioType	NoLongMarginRatioByMoney;
  ///不跟随交易所投资者多头保证金费
  TShfeFtdcMoneyType	NoLongMarginRatioByVolume;
  ///不跟随交易所投资者空头保证金率
  TShfeFtdcRatioType	NoShortMarginRatioByMoney;
  ///不跟随交易所投资者空头保证金费
  TShfeFtdcMoneyType	NoShortMarginRatioByVolume;

  bool operator==(const CShfeFtdcExchangeMarginRateAdjustField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (HedgeFlag == ct.HedgeFlag);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(LongMarginRatioByMoney, ct.LongMarginRatioByMoney));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(LongMarginRatioByVolume, ct.LongMarginRatioByVolume));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ShortMarginRatioByMoney, ct.ShortMarginRatioByMoney));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ShortMarginRatioByVolume, ct.ShortMarginRatioByVolume));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ExchLongMarginRatioByMoney, ct.ExchLongMarginRatioByMoney));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ExchLongMarginRatioByVolume, ct.ExchLongMarginRatioByVolume));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ExchShortMarginRatioByMoney, ct.ExchShortMarginRatioByMoney));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ExchShortMarginRatioByVolume, ct.ExchShortMarginRatioByVolume));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(NoLongMarginRatioByMoney, ct.NoLongMarginRatioByMoney));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(NoLongMarginRatioByVolume, ct.NoLongMarginRatioByVolume));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(NoShortMarginRatioByMoney, ct.NoShortMarginRatioByMoney));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(NoShortMarginRatioByVolume, ct.NoShortMarginRatioByVolume));
    if (!ret) return ret;

    return ret;
  }
};

///结算引用
struct CShfeFtdcSettlementRefField
{
  ///交易日
  TShfeFtdcDateType	TradingDay;
  ///结算编号
  TShfeFtdcSettlementIDType	SettlementID;

  bool operator==(const CShfeFtdcSettlementRefField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(TradingDay, ct.TradingDay) == 0);
    if (!ret) return ret;
    ret = ret && (SettlementID == ct.SettlementID);
    if (!ret) return ret;

    return ret;
  }
};

///当前时间
struct CShfeFtdcCurrentTimeField
{
  ///当前日期
  TShfeFtdcDateType	CurrDate;
  ///当前时间
  TShfeFtdcTimeType	CurrTime;
  ///当前时间（毫秒）
  TShfeFtdcMillisecType	CurrMillisec;

  bool operator==(const CShfeFtdcCurrentTimeField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(CurrDate, ct.CurrDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(CurrTime, ct.CurrTime) == 0);
    if (!ret) return ret;
    ret = ret && (CurrMillisec == ct.CurrMillisec);
    if (!ret) return ret;

    return ret;
  }
};

///通讯阶段
struct CShfeFtdcCommPhaseField
{
  ///交易日
  TShfeFtdcDateType	TradingDay;
  ///通讯时段编号
  TShfeFtdcCommPhaseNoType	CommPhaseNo;

  bool operator==(const CShfeFtdcCommPhaseField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(TradingDay, ct.TradingDay) == 0);
    if (!ret) return ret;
    ret = ret && (CommPhaseNo == ct.CommPhaseNo);
    if (!ret) return ret;

    return ret;
  }
};

///登录信息
struct CShfeFtdcLoginInfoField
{
  ///前置编号
  TShfeFtdcFrontIDType	FrontID;
  ///会话编号
  TShfeFtdcSessionIDType	SessionID;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///登录日期
  TShfeFtdcDateType	LoginDate;
  ///登录时间
  TShfeFtdcTimeType	LoginTime;
  ///IP地址
  TShfeFtdcIPAddressType	IPAddress;
  ///用户端产品信息
  TShfeFtdcProductInfoType	UserProductInfo;
  ///接口端产品信息
  TShfeFtdcProductInfoType	InterfaceProductInfo;
  ///协议信息
  TShfeFtdcProtocolInfoType	ProtocolInfo;
  ///系统名称
  TShfeFtdcSystemNameType	SystemName;
  ///密码
  TShfeFtdcPasswordType	Password;
  ///最大报单引用
  TShfeFtdcOrderRefType	MaxOrderRef;
  ///上期所时间
  TShfeFtdcTimeType	SHFETime;
  ///大商所时间
  TShfeFtdcTimeType	DCETime;
  ///郑商所时间
  TShfeFtdcTimeType	CZCETime;
  ///中金所时间
  TShfeFtdcTimeType	FFEXTime;
  ///Mac地址
  TShfeFtdcMacAddressType	MacAddress;
  ///动态密码
  TShfeFtdcPasswordType	OneTimePassword;

  bool operator==(const CShfeFtdcLoginInfoField &ct) const
  {
    bool ret = true;
    ret = ret && (FrontID == ct.FrontID);
    if (!ret) return ret;
    ret = ret && (SessionID == ct.SessionID);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(LoginDate, ct.LoginDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(LoginTime, ct.LoginTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(IPAddress, ct.IPAddress) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserProductInfo, ct.UserProductInfo) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InterfaceProductInfo, ct.InterfaceProductInfo) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ProtocolInfo, ct.ProtocolInfo) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(SystemName, ct.SystemName) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(Password, ct.Password) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(MaxOrderRef, ct.MaxOrderRef) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(SHFETime, ct.SHFETime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(DCETime, ct.DCETime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(CZCETime, ct.CZCETime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(FFEXTime, ct.FFEXTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(MacAddress, ct.MacAddress) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OneTimePassword, ct.OneTimePassword) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///登录信息
struct CShfeFtdcLogoutAllField
{
  ///前置编号
  TShfeFtdcFrontIDType	FrontID;
  ///会话编号
  TShfeFtdcSessionIDType	SessionID;
  ///系统名称
  TShfeFtdcSystemNameType	SystemName;

  bool operator==(const CShfeFtdcLogoutAllField &ct) const
  {
    bool ret = true;
    ret = ret && (FrontID == ct.FrontID);
    if (!ret) return ret;
    ret = ret && (SessionID == ct.SessionID);
    if (!ret) return ret;
    ret = ret && (strcmp(SystemName, ct.SystemName) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///前置状态
struct CShfeFtdcFrontStatusField
{
  ///前置编号
  TShfeFtdcFrontIDType	FrontID;
  ///上次报告日期
  TShfeFtdcDateType	LastReportDate;
  ///上次报告时间
  TShfeFtdcTimeType	LastReportTime;
  ///是否活跃
  TShfeFtdcBoolType	IsActive;

  bool operator==(const CShfeFtdcFrontStatusField &ct) const
  {
    bool ret = true;
    ret = ret && (FrontID == ct.FrontID);
    if (!ret) return ret;
    ret = ret && (strcmp(LastReportDate, ct.LastReportDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(LastReportTime, ct.LastReportTime) == 0);
    if (!ret) return ret;
    ret = ret && (IsActive == ct.IsActive);
    if (!ret) return ret;

    return ret;
  }
};

///用户口令变更
struct CShfeFtdcUserPasswordUpdateField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///原来的口令
  TShfeFtdcPasswordType	OldPassword;
  ///新的口令
  TShfeFtdcPasswordType	NewPassword;

  bool operator==(const CShfeFtdcUserPasswordUpdateField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OldPassword, ct.OldPassword) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(NewPassword, ct.NewPassword) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///输入报单
struct CShfeFtdcInputOrderField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///报单引用
  TShfeFtdcOrderRefType	OrderRef;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///报单价格条件
  TShfeFtdcOrderPriceTypeType	OrderPriceType;
  ///买卖方向
  TShfeFtdcDirectionType	Direction;
  ///组合开平标志
  TShfeFtdcCombOffsetFlagType	CombOffsetFlag;
  ///组合投机套保标志
  TShfeFtdcCombHedgeFlagType	CombHedgeFlag;
  ///价格
  TShfeFtdcPriceType	LimitPrice;
  ///数量
  TShfeFtdcVolumeType	VolumeTotalOriginal;
  ///有效期类型
  TShfeFtdcTimeConditionType	TimeCondition;
  ///GTD日期
  TShfeFtdcDateType	GTDDate;
  ///成交量类型
  TShfeFtdcVolumeConditionType	VolumeCondition;
  ///最小成交量
  TShfeFtdcVolumeType	MinVolume;
  ///触发条件
  TShfeFtdcContingentConditionType	ContingentCondition;
  ///止损价
  TShfeFtdcPriceType	StopPrice;
  ///强平原因
  TShfeFtdcForceCloseReasonType	ForceCloseReason;
  ///自动挂起标志
  TShfeFtdcBoolType	IsAutoSuspend;
  ///业务单元
  TShfeFtdcBusinessUnitType	BusinessUnit;
  ///请求编号
  TShfeFtdcRequestIDType	RequestID;
  ///用户强评标志
  TShfeFtdcBoolType	UserForceClose;

  bool operator==(const CShfeFtdcInputOrderField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderRef, ct.OrderRef) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (OrderPriceType == ct.OrderPriceType);
    if (!ret) return ret;
    ret = ret && (Direction == ct.Direction);
    if (!ret) return ret;
    for (int i = 0; i < 4; ++i) {
      ret = ret && (CombOffsetFlag[i] == ct.CombOffsetFlag[i]);
      if (!ret) return ret;
    }
    for (int i = 0; i < 4; ++i) {
      ret = ret && (CombHedgeFlag[i] == ct.CombHedgeFlag[i]);
      if (!ret) return ret;
    }
    ret = ret && (EQUALDOUBLE(LimitPrice, ct.LimitPrice));
    if (!ret) return ret;
    ret = ret && (VolumeTotalOriginal == ct.VolumeTotalOriginal);
    if (!ret) return ret;
    ret = ret && (TimeCondition == ct.TimeCondition);
    if (!ret) return ret;
    ret = ret && (strcmp(GTDDate, ct.GTDDate) == 0);
    if (!ret) return ret;
    ret = ret && (VolumeCondition == ct.VolumeCondition);
    if (!ret) return ret;
    ret = ret && (MinVolume == ct.MinVolume);
    if (!ret) return ret;
    ret = ret && (ContingentCondition == ct.ContingentCondition);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(StopPrice, ct.StopPrice));
    if (!ret) return ret;
    ret = ret && (ForceCloseReason == ct.ForceCloseReason);
    if (!ret) return ret;
    ret = ret && (IsAutoSuspend == ct.IsAutoSuspend);
    if (!ret) return ret;
    ret = ret && (strcmp(BusinessUnit, ct.BusinessUnit) == 0);
    if (!ret) return ret;
    ret = ret && (RequestID == ct.RequestID);
    if (!ret) return ret;
    ret = ret && (UserForceClose == ct.UserForceClose);
    if (!ret) return ret;

    return ret;
  }
};

///报单
struct CShfeFtdcOrderField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///报单引用
  TShfeFtdcOrderRefType	OrderRef;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///报单价格条件
  TShfeFtdcOrderPriceTypeType	OrderPriceType;
  ///买卖方向
  TShfeFtdcDirectionType	Direction;
  ///组合开平标志
  TShfeFtdcCombOffsetFlagType	CombOffsetFlag;
  ///组合投机套保标志
  TShfeFtdcCombHedgeFlagType	CombHedgeFlag;
  ///价格
  TShfeFtdcPriceType	LimitPrice;
  ///数量
  TShfeFtdcVolumeType	VolumeTotalOriginal;
  ///有效期类型
  TShfeFtdcTimeConditionType	TimeCondition;
  ///GTD日期
  TShfeFtdcDateType	GTDDate;
  ///成交量类型
  TShfeFtdcVolumeConditionType	VolumeCondition;
  ///最小成交量
  TShfeFtdcVolumeType	MinVolume;
  ///触发条件
  TShfeFtdcContingentConditionType	ContingentCondition;
  ///止损价
  TShfeFtdcPriceType	StopPrice;
  ///强平原因
  TShfeFtdcForceCloseReasonType	ForceCloseReason;
  ///自动挂起标志
  TShfeFtdcBoolType	IsAutoSuspend;
  ///业务单元
  TShfeFtdcBusinessUnitType	BusinessUnit;
  ///请求编号
  TShfeFtdcRequestIDType	RequestID;
  ///本地报单编号
  TShfeFtdcOrderLocalIDType	OrderLocalID;
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///会员代码
  TShfeFtdcParticipantIDType	ParticipantID;
  ///客户代码
  TShfeFtdcClientIDType	ClientID;
  ///合约在交易所的代码
  TShfeFtdcExchangeInstIDType	ExchangeInstID;
  ///交易所交易员代码
  TShfeFtdcTraderIDType	TraderID;
  ///安装编号
  TShfeFtdcInstallIDType	InstallID;
  ///报单提交状态
  TShfeFtdcOrderSubmitStatusType	OrderSubmitStatus;
  ///报单提示序号
  TShfeFtdcSequenceNoType	NotifySequence;
  ///交易日
  TShfeFtdcDateType	TradingDay;
  ///结算编号
  TShfeFtdcSettlementIDType	SettlementID;
  ///报单编号
  TShfeFtdcOrderSysIDType	OrderSysID;
  ///报单来源
  TShfeFtdcOrderSourceType	OrderSource;
  ///报单状态
  TShfeFtdcOrderStatusType	OrderStatus;
  ///报单类型
  TShfeFtdcOrderTypeType	OrderType;
  ///今成交数量
  TShfeFtdcVolumeType	VolumeTraded;
  ///剩余数量
  TShfeFtdcVolumeType	VolumeTotal;
  ///报单日期
  TShfeFtdcDateType	InsertDate;
  ///委托时间
  TShfeFtdcTimeType	InsertTime;
  ///激活时间
  TShfeFtdcTimeType	ActiveTime;
  ///挂起时间
  TShfeFtdcTimeType	SuspendTime;
  ///最后修改时间
  TShfeFtdcTimeType	UpdateTime;
  ///撤销时间
  TShfeFtdcTimeType	CancelTime;
  ///最后修改交易所交易员代码
  TShfeFtdcTraderIDType	ActiveTraderID;
  ///结算会员编号
  TShfeFtdcParticipantIDType	ClearingPartID;
  ///序号
  TShfeFtdcSequenceNoType	SequenceNo;
  ///前置编号
  TShfeFtdcFrontIDType	FrontID;
  ///会话编号
  TShfeFtdcSessionIDType	SessionID;
  ///用户端产品信息
  TShfeFtdcProductInfoType	UserProductInfo;
  ///状态信息
  TShfeFtdcErrorMsgType	StatusMsg;
  ///用户强评标志
  TShfeFtdcBoolType	UserForceClose;
  ///操作用户代码
  TShfeFtdcUserIDType	ActiveUserID;
  ///经纪公司报单编号
  TShfeFtdcSequenceNoType	BrokerOrderSeq;
  ///相关报单
  TShfeFtdcOrderSysIDType	RelativeOrderSysID;
  ///郑商所成交数量
  TShfeFtdcVolumeType	ZCETotalTradedVolume;

  bool operator==(const CShfeFtdcOrderField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderRef, ct.OrderRef) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (OrderPriceType == ct.OrderPriceType);
    if (!ret) return ret;
    ret = ret && (Direction == ct.Direction);
    if (!ret) return ret;
    for (int i = 0; i < 4; ++i) {
      ret = ret && (CombOffsetFlag[i] == ct.CombOffsetFlag[i]);
      if (!ret) return ret;
    }
    for (int i = 0; i < 4; ++i) {
      ret = ret && (CombHedgeFlag[i] == ct.CombHedgeFlag[i]);
      if (!ret) return ret;
    }
    ret = ret && (EQUALDOUBLE(LimitPrice, ct.LimitPrice));
    if (!ret) return ret;
    ret = ret && (VolumeTotalOriginal == ct.VolumeTotalOriginal);
    if (!ret) return ret;
    ret = ret && (TimeCondition == ct.TimeCondition);
    if (!ret) return ret;
    ret = ret && (strcmp(GTDDate, ct.GTDDate) == 0);
    if (!ret) return ret;
    ret = ret && (VolumeCondition == ct.VolumeCondition);
    if (!ret) return ret;
    ret = ret && (MinVolume == ct.MinVolume);
    if (!ret) return ret;
    ret = ret && (ContingentCondition == ct.ContingentCondition);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(StopPrice, ct.StopPrice));
    if (!ret) return ret;
    ret = ret && (ForceCloseReason == ct.ForceCloseReason);
    if (!ret) return ret;
    ret = ret && (IsAutoSuspend == ct.IsAutoSuspend);
    if (!ret) return ret;
    ret = ret && (strcmp(BusinessUnit, ct.BusinessUnit) == 0);
    if (!ret) return ret;
    ret = ret && (RequestID == ct.RequestID);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderLocalID, ct.OrderLocalID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ParticipantID, ct.ParticipantID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ClientID, ct.ClientID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeInstID, ct.ExchangeInstID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TraderID, ct.TraderID) == 0);
    if (!ret) return ret;
    ret = ret && (InstallID == ct.InstallID);
    if (!ret) return ret;
    ret = ret && (OrderSubmitStatus == ct.OrderSubmitStatus);
    if (!ret) return ret;
    ret = ret && (NotifySequence == ct.NotifySequence);
    if (!ret) return ret;
    ret = ret && (strcmp(TradingDay, ct.TradingDay) == 0);
    if (!ret) return ret;
    ret = ret && (SettlementID == ct.SettlementID);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderSysID, ct.OrderSysID) == 0);
    if (!ret) return ret;
    ret = ret && (OrderSource == ct.OrderSource);
    if (!ret) return ret;
    ret = ret && (OrderStatus == ct.OrderStatus);
    if (!ret) return ret;
    ret = ret && (OrderType == ct.OrderType);
    if (!ret) return ret;
    ret = ret && (VolumeTraded == ct.VolumeTraded);
    if (!ret) return ret;
    ret = ret && (VolumeTotal == ct.VolumeTotal);
    if (!ret) return ret;
    ret = ret && (strcmp(InsertDate, ct.InsertDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InsertTime, ct.InsertTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ActiveTime, ct.ActiveTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(SuspendTime, ct.SuspendTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UpdateTime, ct.UpdateTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(CancelTime, ct.CancelTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ActiveTraderID, ct.ActiveTraderID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ClearingPartID, ct.ClearingPartID) == 0);
    if (!ret) return ret;
    ret = ret && (SequenceNo == ct.SequenceNo);
    if (!ret) return ret;
    ret = ret && (FrontID == ct.FrontID);
    if (!ret) return ret;
    ret = ret && (SessionID == ct.SessionID);
    if (!ret) return ret;
    ret = ret && (strcmp(UserProductInfo, ct.UserProductInfo) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(StatusMsg, ct.StatusMsg) == 0);
    if (!ret) return ret;
    ret = ret && (UserForceClose == ct.UserForceClose);
    if (!ret) return ret;
    ret = ret && (strcmp(ActiveUserID, ct.ActiveUserID) == 0);
    if (!ret) return ret;
    ret = ret && (BrokerOrderSeq == ct.BrokerOrderSeq);
    if (!ret) return ret;
    ret = ret && (strcmp(RelativeOrderSysID, ct.RelativeOrderSysID) == 0);
    if (!ret) return ret;
    ret = ret && (ZCETotalTradedVolume == ct.ZCETotalTradedVolume);
    if (!ret) return ret;

    return ret;
  }
};

///交易所报单
struct CShfeFtdcExchangeOrderField
{
  ///报单价格条件
  TShfeFtdcOrderPriceTypeType	OrderPriceType;
  ///买卖方向
  TShfeFtdcDirectionType	Direction;
  ///组合开平标志
  TShfeFtdcCombOffsetFlagType	CombOffsetFlag;
  ///组合投机套保标志
  TShfeFtdcCombHedgeFlagType	CombHedgeFlag;
  ///价格
  TShfeFtdcPriceType	LimitPrice;
  ///数量
  TShfeFtdcVolumeType	VolumeTotalOriginal;
  ///有效期类型
  TShfeFtdcTimeConditionType	TimeCondition;
  ///GTD日期
  TShfeFtdcDateType	GTDDate;
  ///成交量类型
  TShfeFtdcVolumeConditionType	VolumeCondition;
  ///最小成交量
  TShfeFtdcVolumeType	MinVolume;
  ///触发条件
  TShfeFtdcContingentConditionType	ContingentCondition;
  ///止损价
  TShfeFtdcPriceType	StopPrice;
  ///强平原因
  TShfeFtdcForceCloseReasonType	ForceCloseReason;
  ///自动挂起标志
  TShfeFtdcBoolType	IsAutoSuspend;
  ///业务单元
  TShfeFtdcBusinessUnitType	BusinessUnit;
  ///请求编号
  TShfeFtdcRequestIDType	RequestID;
  ///本地报单编号
  TShfeFtdcOrderLocalIDType	OrderLocalID;
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///会员代码
  TShfeFtdcParticipantIDType	ParticipantID;
  ///客户代码
  TShfeFtdcClientIDType	ClientID;
  ///合约在交易所的代码
  TShfeFtdcExchangeInstIDType	ExchangeInstID;
  ///交易所交易员代码
  TShfeFtdcTraderIDType	TraderID;
  ///安装编号
  TShfeFtdcInstallIDType	InstallID;
  ///报单提交状态
  TShfeFtdcOrderSubmitStatusType	OrderSubmitStatus;
  ///报单提示序号
  TShfeFtdcSequenceNoType	NotifySequence;
  ///交易日
  TShfeFtdcDateType	TradingDay;
  ///结算编号
  TShfeFtdcSettlementIDType	SettlementID;
  ///报单编号
  TShfeFtdcOrderSysIDType	OrderSysID;
  ///报单来源
  TShfeFtdcOrderSourceType	OrderSource;
  ///报单状态
  TShfeFtdcOrderStatusType	OrderStatus;
  ///报单类型
  TShfeFtdcOrderTypeType	OrderType;
  ///今成交数量
  TShfeFtdcVolumeType	VolumeTraded;
  ///剩余数量
  TShfeFtdcVolumeType	VolumeTotal;
  ///报单日期
  TShfeFtdcDateType	InsertDate;
  ///委托时间
  TShfeFtdcTimeType	InsertTime;
  ///激活时间
  TShfeFtdcTimeType	ActiveTime;
  ///挂起时间
  TShfeFtdcTimeType	SuspendTime;
  ///最后修改时间
  TShfeFtdcTimeType	UpdateTime;
  ///撤销时间
  TShfeFtdcTimeType	CancelTime;
  ///最后修改交易所交易员代码
  TShfeFtdcTraderIDType	ActiveTraderID;
  ///结算会员编号
  TShfeFtdcParticipantIDType	ClearingPartID;
  ///序号
  TShfeFtdcSequenceNoType	SequenceNo;

  bool operator==(const CShfeFtdcExchangeOrderField &ct) const
  {
    bool ret = true;
    ret = ret && (OrderPriceType == ct.OrderPriceType);
    if (!ret) return ret;
    ret = ret && (Direction == ct.Direction);
    if (!ret) return ret;
    for (int i = 0; i < 4; ++i) {
      ret = ret && (CombOffsetFlag[i] == ct.CombOffsetFlag[i]);
      if (!ret) return ret;
    }
    for (int i = 0; i < 4; ++i) {
      ret = ret && (CombHedgeFlag[i] == ct.CombHedgeFlag[i]);
      if (!ret) return ret;
    }
    ret = ret && (EQUALDOUBLE(LimitPrice, ct.LimitPrice));
    if (!ret) return ret;
    ret = ret && (VolumeTotalOriginal == ct.VolumeTotalOriginal);
    if (!ret) return ret;
    ret = ret && (TimeCondition == ct.TimeCondition);
    if (!ret) return ret;
    ret = ret && (strcmp(GTDDate, ct.GTDDate) == 0);
    if (!ret) return ret;
    ret = ret && (VolumeCondition == ct.VolumeCondition);
    if (!ret) return ret;
    ret = ret && (MinVolume == ct.MinVolume);
    if (!ret) return ret;
    ret = ret && (ContingentCondition == ct.ContingentCondition);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(StopPrice, ct.StopPrice));
    if (!ret) return ret;
    ret = ret && (ForceCloseReason == ct.ForceCloseReason);
    if (!ret) return ret;
    ret = ret && (IsAutoSuspend == ct.IsAutoSuspend);
    if (!ret) return ret;
    ret = ret && (strcmp(BusinessUnit, ct.BusinessUnit) == 0);
    if (!ret) return ret;
    ret = ret && (RequestID == ct.RequestID);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderLocalID, ct.OrderLocalID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ParticipantID, ct.ParticipantID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ClientID, ct.ClientID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeInstID, ct.ExchangeInstID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TraderID, ct.TraderID) == 0);
    if (!ret) return ret;
    ret = ret && (InstallID == ct.InstallID);
    if (!ret) return ret;
    ret = ret && (OrderSubmitStatus == ct.OrderSubmitStatus);
    if (!ret) return ret;
    ret = ret && (NotifySequence == ct.NotifySequence);
    if (!ret) return ret;
    ret = ret && (strcmp(TradingDay, ct.TradingDay) == 0);
    if (!ret) return ret;
    ret = ret && (SettlementID == ct.SettlementID);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderSysID, ct.OrderSysID) == 0);
    if (!ret) return ret;
    ret = ret && (OrderSource == ct.OrderSource);
    if (!ret) return ret;
    ret = ret && (OrderStatus == ct.OrderStatus);
    if (!ret) return ret;
    ret = ret && (OrderType == ct.OrderType);
    if (!ret) return ret;
    ret = ret && (VolumeTraded == ct.VolumeTraded);
    if (!ret) return ret;
    ret = ret && (VolumeTotal == ct.VolumeTotal);
    if (!ret) return ret;
    ret = ret && (strcmp(InsertDate, ct.InsertDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InsertTime, ct.InsertTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ActiveTime, ct.ActiveTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(SuspendTime, ct.SuspendTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UpdateTime, ct.UpdateTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(CancelTime, ct.CancelTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ActiveTraderID, ct.ActiveTraderID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ClearingPartID, ct.ClearingPartID) == 0);
    if (!ret) return ret;
    ret = ret && (SequenceNo == ct.SequenceNo);
    if (!ret) return ret;

    return ret;
  }
};

///交易所报单插入失败
struct CShfeFtdcExchangeOrderInsertErrorField
{
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///会员代码
  TShfeFtdcParticipantIDType	ParticipantID;
  ///交易所交易员代码
  TShfeFtdcTraderIDType	TraderID;
  ///安装编号
  TShfeFtdcInstallIDType	InstallID;
  ///本地报单编号
  TShfeFtdcOrderLocalIDType	OrderLocalID;
  ///错误代码
  TShfeFtdcErrorIDType	ErrorID;
  ///错误信息
  TShfeFtdcErrorMsgType	ErrorMsg;

  bool operator==(const CShfeFtdcExchangeOrderInsertErrorField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ParticipantID, ct.ParticipantID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TraderID, ct.TraderID) == 0);
    if (!ret) return ret;
    ret = ret && (InstallID == ct.InstallID);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderLocalID, ct.OrderLocalID) == 0);
    if (!ret) return ret;
    ret = ret && (ErrorID == ct.ErrorID);
    if (!ret) return ret;
    ret = ret && (strcmp(ErrorMsg, ct.ErrorMsg) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///输入报单操作
struct CShfeFtdcInputOrderActionField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///报单操作引用
  TShfeFtdcOrderActionRefType	OrderActionRef;
  ///报单引用
  TShfeFtdcOrderRefType	OrderRef;
  ///请求编号
  TShfeFtdcRequestIDType	RequestID;
  ///前置编号
  TShfeFtdcFrontIDType	FrontID;
  ///会话编号
  TShfeFtdcSessionIDType	SessionID;
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///报单编号
  TShfeFtdcOrderSysIDType	OrderSysID;
  ///操作标志
  TShfeFtdcActionFlagType	ActionFlag;
  ///价格
  TShfeFtdcPriceType	LimitPrice;
  ///数量变化
  TShfeFtdcVolumeType	VolumeChange;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;

  bool operator==(const CShfeFtdcInputOrderActionField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (OrderActionRef == ct.OrderActionRef);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderRef, ct.OrderRef) == 0);
    if (!ret) return ret;
    ret = ret && (RequestID == ct.RequestID);
    if (!ret) return ret;
    ret = ret && (FrontID == ct.FrontID);
    if (!ret) return ret;
    ret = ret && (SessionID == ct.SessionID);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderSysID, ct.OrderSysID) == 0);
    if (!ret) return ret;
    ret = ret && (ActionFlag == ct.ActionFlag);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(LimitPrice, ct.LimitPrice));
    if (!ret) return ret;
    ret = ret && (VolumeChange == ct.VolumeChange);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///报单操作
struct CShfeFtdcOrderActionField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///报单操作引用
  TShfeFtdcOrderActionRefType	OrderActionRef;
  ///报单引用
  TShfeFtdcOrderRefType	OrderRef;
  ///请求编号
  TShfeFtdcRequestIDType	RequestID;
  ///前置编号
  TShfeFtdcFrontIDType	FrontID;
  ///会话编号
  TShfeFtdcSessionIDType	SessionID;
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///报单编号
  TShfeFtdcOrderSysIDType	OrderSysID;
  ///操作标志
  TShfeFtdcActionFlagType	ActionFlag;
  ///价格
  TShfeFtdcPriceType	LimitPrice;
  ///数量变化
  TShfeFtdcVolumeType	VolumeChange;
  ///操作日期
  TShfeFtdcDateType	ActionDate;
  ///操作时间
  TShfeFtdcTimeType	ActionTime;
  ///交易所交易员代码
  TShfeFtdcTraderIDType	TraderID;
  ///安装编号
  TShfeFtdcInstallIDType	InstallID;
  ///本地报单编号
  TShfeFtdcOrderLocalIDType	OrderLocalID;
  ///操作本地编号
  TShfeFtdcOrderLocalIDType	ActionLocalID;
  ///会员代码
  TShfeFtdcParticipantIDType	ParticipantID;
  ///客户代码
  TShfeFtdcClientIDType	ClientID;
  ///业务单元
  TShfeFtdcBusinessUnitType	BusinessUnit;
  ///报单操作状态
  TShfeFtdcOrderActionStatusType	OrderActionStatus;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///状态信息
  TShfeFtdcErrorMsgType	StatusMsg;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;

  bool operator==(const CShfeFtdcOrderActionField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (OrderActionRef == ct.OrderActionRef);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderRef, ct.OrderRef) == 0);
    if (!ret) return ret;
    ret = ret && (RequestID == ct.RequestID);
    if (!ret) return ret;
    ret = ret && (FrontID == ct.FrontID);
    if (!ret) return ret;
    ret = ret && (SessionID == ct.SessionID);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderSysID, ct.OrderSysID) == 0);
    if (!ret) return ret;
    ret = ret && (ActionFlag == ct.ActionFlag);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(LimitPrice, ct.LimitPrice));
    if (!ret) return ret;
    ret = ret && (VolumeChange == ct.VolumeChange);
    if (!ret) return ret;
    ret = ret && (strcmp(ActionDate, ct.ActionDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ActionTime, ct.ActionTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TraderID, ct.TraderID) == 0);
    if (!ret) return ret;
    ret = ret && (InstallID == ct.InstallID);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderLocalID, ct.OrderLocalID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ActionLocalID, ct.ActionLocalID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ParticipantID, ct.ParticipantID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ClientID, ct.ClientID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BusinessUnit, ct.BusinessUnit) == 0);
    if (!ret) return ret;
    ret = ret && (OrderActionStatus == ct.OrderActionStatus);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(StatusMsg, ct.StatusMsg) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///交易所报单操作
struct CShfeFtdcExchangeOrderActionField
{
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///报单编号
  TShfeFtdcOrderSysIDType	OrderSysID;
  ///操作标志
  TShfeFtdcActionFlagType	ActionFlag;
  ///价格
  TShfeFtdcPriceType	LimitPrice;
  ///数量变化
  TShfeFtdcVolumeType	VolumeChange;
  ///操作日期
  TShfeFtdcDateType	ActionDate;
  ///操作时间
  TShfeFtdcTimeType	ActionTime;
  ///交易所交易员代码
  TShfeFtdcTraderIDType	TraderID;
  ///安装编号
  TShfeFtdcInstallIDType	InstallID;
  ///本地报单编号
  TShfeFtdcOrderLocalIDType	OrderLocalID;
  ///操作本地编号
  TShfeFtdcOrderLocalIDType	ActionLocalID;
  ///会员代码
  TShfeFtdcParticipantIDType	ParticipantID;
  ///客户代码
  TShfeFtdcClientIDType	ClientID;
  ///业务单元
  TShfeFtdcBusinessUnitType	BusinessUnit;
  ///报单操作状态
  TShfeFtdcOrderActionStatusType	OrderActionStatus;
  ///用户代码
  TShfeFtdcUserIDType	UserID;

  bool operator==(const CShfeFtdcExchangeOrderActionField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderSysID, ct.OrderSysID) == 0);
    if (!ret) return ret;
    ret = ret && (ActionFlag == ct.ActionFlag);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(LimitPrice, ct.LimitPrice));
    if (!ret) return ret;
    ret = ret && (VolumeChange == ct.VolumeChange);
    if (!ret) return ret;
    ret = ret && (strcmp(ActionDate, ct.ActionDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ActionTime, ct.ActionTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TraderID, ct.TraderID) == 0);
    if (!ret) return ret;
    ret = ret && (InstallID == ct.InstallID);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderLocalID, ct.OrderLocalID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ActionLocalID, ct.ActionLocalID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ParticipantID, ct.ParticipantID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ClientID, ct.ClientID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BusinessUnit, ct.BusinessUnit) == 0);
    if (!ret) return ret;
    ret = ret && (OrderActionStatus == ct.OrderActionStatus);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///交易所报单操作失败
struct CShfeFtdcExchangeOrderActionErrorField
{
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///报单编号
  TShfeFtdcOrderSysIDType	OrderSysID;
  ///交易所交易员代码
  TShfeFtdcTraderIDType	TraderID;
  ///安装编号
  TShfeFtdcInstallIDType	InstallID;
  ///本地报单编号
  TShfeFtdcOrderLocalIDType	OrderLocalID;
  ///操作本地编号
  TShfeFtdcOrderLocalIDType	ActionLocalID;
  ///错误代码
  TShfeFtdcErrorIDType	ErrorID;
  ///错误信息
  TShfeFtdcErrorMsgType	ErrorMsg;

  bool operator==(const CShfeFtdcExchangeOrderActionErrorField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderSysID, ct.OrderSysID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TraderID, ct.TraderID) == 0);
    if (!ret) return ret;
    ret = ret && (InstallID == ct.InstallID);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderLocalID, ct.OrderLocalID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ActionLocalID, ct.ActionLocalID) == 0);
    if (!ret) return ret;
    ret = ret && (ErrorID == ct.ErrorID);
    if (!ret) return ret;
    ret = ret && (strcmp(ErrorMsg, ct.ErrorMsg) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///交易所成交
struct CShfeFtdcExchangeTradeField
{
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///成交编号
  TShfeFtdcTradeIDType	TradeID;
  ///买卖方向
  TShfeFtdcDirectionType	Direction;
  ///报单编号
  TShfeFtdcOrderSysIDType	OrderSysID;
  ///会员代码
  TShfeFtdcParticipantIDType	ParticipantID;
  ///客户代码
  TShfeFtdcClientIDType	ClientID;
  ///交易角色
  TShfeFtdcTradingRoleType	TradingRole;
  ///合约在交易所的代码
  TShfeFtdcExchangeInstIDType	ExchangeInstID;
  ///开平标志
  TShfeFtdcOffsetFlagType	OffsetFlag;
  ///投机套保标志
  TShfeFtdcHedgeFlagType	HedgeFlag;
  ///价格
  TShfeFtdcPriceType	Price;
  ///数量
  TShfeFtdcVolumeType	Volume;
  ///成交时期
  TShfeFtdcDateType	TradeDate;
  ///成交时间
  TShfeFtdcTimeType	TradeTime;
  ///成交类型
  TShfeFtdcTradeTypeType	TradeType;
  ///成交价来源
  TShfeFtdcPriceSourceType	PriceSource;
  ///交易所交易员代码
  TShfeFtdcTraderIDType	TraderID;
  ///本地报单编号
  TShfeFtdcOrderLocalIDType	OrderLocalID;
  ///结算会员编号
  TShfeFtdcParticipantIDType	ClearingPartID;
  ///业务单元
  TShfeFtdcBusinessUnitType	BusinessUnit;
  ///序号
  TShfeFtdcSequenceNoType	SequenceNo;
  ///成交来源
  TShfeFtdcTradeSourceType	TradeSource;

  bool operator==(const CShfeFtdcExchangeTradeField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TradeID, ct.TradeID) == 0);
    if (!ret) return ret;
    ret = ret && (Direction == ct.Direction);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderSysID, ct.OrderSysID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ParticipantID, ct.ParticipantID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ClientID, ct.ClientID) == 0);
    if (!ret) return ret;
    ret = ret && (TradingRole == ct.TradingRole);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeInstID, ct.ExchangeInstID) == 0);
    if (!ret) return ret;
    ret = ret && (OffsetFlag == ct.OffsetFlag);
    if (!ret) return ret;
    ret = ret && (HedgeFlag == ct.HedgeFlag);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Price, ct.Price));
    if (!ret) return ret;
    ret = ret && (Volume == ct.Volume);
    if (!ret) return ret;
    ret = ret && (strcmp(TradeDate, ct.TradeDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TradeTime, ct.TradeTime) == 0);
    if (!ret) return ret;
    ret = ret && (TradeType == ct.TradeType);
    if (!ret) return ret;
    ret = ret && (PriceSource == ct.PriceSource);
    if (!ret) return ret;
    ret = ret && (strcmp(TraderID, ct.TraderID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderLocalID, ct.OrderLocalID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ClearingPartID, ct.ClearingPartID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BusinessUnit, ct.BusinessUnit) == 0);
    if (!ret) return ret;
    ret = ret && (SequenceNo == ct.SequenceNo);
    if (!ret) return ret;
    ret = ret && (TradeSource == ct.TradeSource);
    if (!ret) return ret;

    return ret;
  }
};

///成交
struct CShfeFtdcTradeField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///报单引用
  TShfeFtdcOrderRefType	OrderRef;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///成交编号
  TShfeFtdcTradeIDType	TradeID;
  ///买卖方向
  TShfeFtdcDirectionType	Direction;
  ///报单编号
  TShfeFtdcOrderSysIDType	OrderSysID;
  ///会员代码
  TShfeFtdcParticipantIDType	ParticipantID;
  ///客户代码
  TShfeFtdcClientIDType	ClientID;
  ///交易角色
  TShfeFtdcTradingRoleType	TradingRole;
  ///合约在交易所的代码
  TShfeFtdcExchangeInstIDType	ExchangeInstID;
  ///开平标志
  TShfeFtdcOffsetFlagType	OffsetFlag;
  ///投机套保标志
  TShfeFtdcHedgeFlagType	HedgeFlag;
  ///价格
  TShfeFtdcPriceType	Price;
  ///数量
  TShfeFtdcVolumeType	Volume;
  ///成交时期
  TShfeFtdcDateType	TradeDate;
  ///成交时间
  TShfeFtdcTimeType	TradeTime;
  ///成交类型
  TShfeFtdcTradeTypeType	TradeType;
  ///成交价来源
  TShfeFtdcPriceSourceType	PriceSource;
  ///交易所交易员代码
  TShfeFtdcTraderIDType	TraderID;
  ///本地报单编号
  TShfeFtdcOrderLocalIDType	OrderLocalID;
  ///结算会员编号
  TShfeFtdcParticipantIDType	ClearingPartID;
  ///业务单元
  TShfeFtdcBusinessUnitType	BusinessUnit;
  ///序号
  TShfeFtdcSequenceNoType	SequenceNo;
  ///交易日
  TShfeFtdcDateType	TradingDay;
  ///结算编号
  TShfeFtdcSettlementIDType	SettlementID;
  ///经纪公司报单编号
  TShfeFtdcSequenceNoType	BrokerOrderSeq;
  ///成交来源
  TShfeFtdcTradeSourceType	TradeSource;

  bool operator==(const CShfeFtdcTradeField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderRef, ct.OrderRef) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TradeID, ct.TradeID) == 0);
    if (!ret) return ret;
    ret = ret && (Direction == ct.Direction);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderSysID, ct.OrderSysID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ParticipantID, ct.ParticipantID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ClientID, ct.ClientID) == 0);
    if (!ret) return ret;
    ret = ret && (TradingRole == ct.TradingRole);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeInstID, ct.ExchangeInstID) == 0);
    if (!ret) return ret;
    ret = ret && (OffsetFlag == ct.OffsetFlag);
    if (!ret) return ret;
    ret = ret && (HedgeFlag == ct.HedgeFlag);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Price, ct.Price));
    if (!ret) return ret;
    ret = ret && (Volume == ct.Volume);
    if (!ret) return ret;
    ret = ret && (strcmp(TradeDate, ct.TradeDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TradeTime, ct.TradeTime) == 0);
    if (!ret) return ret;
    ret = ret && (TradeType == ct.TradeType);
    if (!ret) return ret;
    ret = ret && (PriceSource == ct.PriceSource);
    if (!ret) return ret;
    ret = ret && (strcmp(TraderID, ct.TraderID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderLocalID, ct.OrderLocalID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ClearingPartID, ct.ClearingPartID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BusinessUnit, ct.BusinessUnit) == 0);
    if (!ret) return ret;
    ret = ret && (SequenceNo == ct.SequenceNo);
    if (!ret) return ret;
    ret = ret && (strcmp(TradingDay, ct.TradingDay) == 0);
    if (!ret) return ret;
    ret = ret && (SettlementID == ct.SettlementID);
    if (!ret) return ret;
    ret = ret && (BrokerOrderSeq == ct.BrokerOrderSeq);
    if (!ret) return ret;
    ret = ret && (TradeSource == ct.TradeSource);
    if (!ret) return ret;

    return ret;
  }
};

///用户会话
struct CShfeFtdcUserSessionField
{
  ///前置编号
  TShfeFtdcFrontIDType	FrontID;
  ///会话编号
  TShfeFtdcSessionIDType	SessionID;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///登录日期
  TShfeFtdcDateType	LoginDate;
  ///登录时间
  TShfeFtdcTimeType	LoginTime;
  ///IP地址
  TShfeFtdcIPAddressType	IPAddress;
  ///用户端产品信息
  TShfeFtdcProductInfoType	UserProductInfo;
  ///接口端产品信息
  TShfeFtdcProductInfoType	InterfaceProductInfo;
  ///协议信息
  TShfeFtdcProtocolInfoType	ProtocolInfo;
  ///Mac地址
  TShfeFtdcMacAddressType	MacAddress;

  bool operator==(const CShfeFtdcUserSessionField &ct) const
  {
    bool ret = true;
    ret = ret && (FrontID == ct.FrontID);
    if (!ret) return ret;
    ret = ret && (SessionID == ct.SessionID);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(LoginDate, ct.LoginDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(LoginTime, ct.LoginTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(IPAddress, ct.IPAddress) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserProductInfo, ct.UserProductInfo) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InterfaceProductInfo, ct.InterfaceProductInfo) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ProtocolInfo, ct.ProtocolInfo) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(MacAddress, ct.MacAddress) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询最大报单数量
struct CShfeFtdcQueryMaxOrderVolumeField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///买卖方向
  TShfeFtdcDirectionType	Direction;
  ///开平标志
  TShfeFtdcOffsetFlagType	OffsetFlag;
  ///投机套保标志
  TShfeFtdcHedgeFlagType	HedgeFlag;
  ///最大允许报单数量
  TShfeFtdcVolumeType	MaxVolume;

  bool operator==(const CShfeFtdcQueryMaxOrderVolumeField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (Direction == ct.Direction);
    if (!ret) return ret;
    ret = ret && (OffsetFlag == ct.OffsetFlag);
    if (!ret) return ret;
    ret = ret && (HedgeFlag == ct.HedgeFlag);
    if (!ret) return ret;
    ret = ret && (MaxVolume == ct.MaxVolume);
    if (!ret) return ret;

    return ret;
  }
};

///投资者结算结果确认信息
struct CShfeFtdcSettlementInfoConfirmField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///确认日期
  TShfeFtdcDateType	ConfirmDate;
  ///确认时间
  TShfeFtdcTimeType	ConfirmTime;

  bool operator==(const CShfeFtdcSettlementInfoConfirmField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ConfirmDate, ct.ConfirmDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ConfirmTime, ct.ConfirmTime) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///出入金同步
struct CShfeFtdcSyncDepositField
{
  ///出入金流水号
  TShfeFtdcDepositSeqNoType	DepositSeqNo;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///入金金额
  TShfeFtdcMoneyType	Deposit;
  ///是否强制进行
  TShfeFtdcBoolType	IsForce;

  bool operator==(const CShfeFtdcSyncDepositField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(DepositSeqNo, ct.DepositSeqNo) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Deposit, ct.Deposit));
    if (!ret) return ret;
    ret = ret && (IsForce == ct.IsForce);
    if (!ret) return ret;

    return ret;
  }
};

///经纪公司同步
struct CShfeFtdcBrokerSyncField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;

  bool operator==(const CShfeFtdcBrokerSyncField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///正在同步中的投资者
struct CShfeFtdcSyncingInvestorField
{
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者分组代码
  TShfeFtdcInvestorIDType	InvestorGroupID;
  ///投资者名称
  TShfeFtdcPartyNameType	InvestorName;
  ///证件类型
  TShfeFtdcIdCardTypeType	IdentifiedCardType;
  ///证件号码
  TShfeFtdcIdentifiedCardNoType	IdentifiedCardNo;
  ///是否活跃
  TShfeFtdcBoolType	IsActive;
  ///联系电话
  TShfeFtdcTelephoneType	Telephone;
  ///通讯地址
  TShfeFtdcAddressType	Address;
  ///开户日期
  TShfeFtdcDateType	OpenDate;
  ///手机
  TShfeFtdcMobileType	Mobile;
  ///手续费率模板代码
  TShfeFtdcInvestorIDType	CommModelID;

  bool operator==(const CShfeFtdcSyncingInvestorField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorGroupID, ct.InvestorGroupID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorName, ct.InvestorName) == 0);
    if (!ret) return ret;
    ret = ret && (IdentifiedCardType == ct.IdentifiedCardType);
    if (!ret) return ret;
    ret = ret && (strcmp(IdentifiedCardNo, ct.IdentifiedCardNo) == 0);
    if (!ret) return ret;
    ret = ret && (IsActive == ct.IsActive);
    if (!ret) return ret;
    ret = ret && (strcmp(Telephone, ct.Telephone) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(Address, ct.Address) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OpenDate, ct.OpenDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(Mobile, ct.Mobile) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(CommModelID, ct.CommModelID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///正在同步中的交易代码
struct CShfeFtdcSyncingTradingCodeField
{
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///客户代码
  TShfeFtdcClientIDType	ClientID;
  ///是否活跃
  TShfeFtdcBoolType	IsActive;
  ///交易编码类型
  TShfeFtdcClientIDTypeType	ClientIDType;

  bool operator==(const CShfeFtdcSyncingTradingCodeField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ClientID, ct.ClientID) == 0);
    if (!ret) return ret;
    ret = ret && (IsActive == ct.IsActive);
    if (!ret) return ret;
    ret = ret && (ClientIDType == ct.ClientIDType);
    if (!ret) return ret;

    return ret;
  }
};

///正在同步中的投资者分组
struct CShfeFtdcSyncingInvestorGroupField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者分组代码
  TShfeFtdcInvestorIDType	InvestorGroupID;
  ///投资者分组名称
  TShfeFtdcInvestorGroupNameType	InvestorGroupName;

  bool operator==(const CShfeFtdcSyncingInvestorGroupField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorGroupID, ct.InvestorGroupID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorGroupName, ct.InvestorGroupName) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///正在同步中的交易账号
struct CShfeFtdcSyncingTradingAccountField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者帐号
  TShfeFtdcAccountIDType	AccountID;
  ///上次质押金额
  TShfeFtdcMoneyType	PreMortgage;
  ///上次信用额度
  TShfeFtdcMoneyType	PreCredit;
  ///上次存款额
  TShfeFtdcMoneyType	PreDeposit;
  ///上次结算准备金
  TShfeFtdcMoneyType	PreBalance;
  ///上次占用的保证金
  TShfeFtdcMoneyType	PreMargin;
  ///利息基数
  TShfeFtdcMoneyType	InterestBase;
  ///利息收入
  TShfeFtdcMoneyType	Interest;
  ///入金金额
  TShfeFtdcMoneyType	Deposit;
  ///出金金额
  TShfeFtdcMoneyType	Withdraw;
  ///冻结的保证金
  TShfeFtdcMoneyType	FrozenMargin;
  ///冻结的资金
  TShfeFtdcMoneyType	FrozenCash;
  ///冻结的手续费
  TShfeFtdcMoneyType	FrozenCommission;
  ///当前保证金总额
  TShfeFtdcMoneyType	CurrMargin;
  ///资金差额
  TShfeFtdcMoneyType	CashIn;
  ///手续费
  TShfeFtdcMoneyType	Commission;
  ///平仓盈亏
  TShfeFtdcMoneyType	CloseProfit;
  ///持仓盈亏
  TShfeFtdcMoneyType	PositionProfit;
  ///期货结算准备金
  TShfeFtdcMoneyType	Balance;
  ///可用资金
  TShfeFtdcMoneyType	Available;
  ///可取资金
  TShfeFtdcMoneyType	WithdrawQuota;
  ///基本准备金
  TShfeFtdcMoneyType	Reserve;
  ///交易日
  TShfeFtdcDateType	TradingDay;
  ///结算编号
  TShfeFtdcSettlementIDType	SettlementID;
  ///信用额度
  TShfeFtdcMoneyType	Credit;
  ///质押金额
  TShfeFtdcMoneyType	Mortgage;
  ///交易所保证金
  TShfeFtdcMoneyType	ExchangeMargin;
  ///投资者交割保证金
  TShfeFtdcMoneyType	DeliveryMargin;
  ///交易所交割保证金
  TShfeFtdcMoneyType	ExchangeDeliveryMargin;

  bool operator==(const CShfeFtdcSyncingTradingAccountField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(AccountID, ct.AccountID) == 0);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreMortgage, ct.PreMortgage));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreCredit, ct.PreCredit));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreDeposit, ct.PreDeposit));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreBalance, ct.PreBalance));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreMargin, ct.PreMargin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(InterestBase, ct.InterestBase));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Interest, ct.Interest));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Deposit, ct.Deposit));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Withdraw, ct.Withdraw));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(FrozenMargin, ct.FrozenMargin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(FrozenCash, ct.FrozenCash));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(FrozenCommission, ct.FrozenCommission));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CurrMargin, ct.CurrMargin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CashIn, ct.CashIn));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Commission, ct.Commission));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CloseProfit, ct.CloseProfit));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PositionProfit, ct.PositionProfit));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Balance, ct.Balance));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Available, ct.Available));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(WithdrawQuota, ct.WithdrawQuota));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Reserve, ct.Reserve));
    if (!ret) return ret;
    ret = ret && (strcmp(TradingDay, ct.TradingDay) == 0);
    if (!ret) return ret;
    ret = ret && (SettlementID == ct.SettlementID);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Credit, ct.Credit));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Mortgage, ct.Mortgage));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ExchangeMargin, ct.ExchangeMargin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(DeliveryMargin, ct.DeliveryMargin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ExchangeDeliveryMargin, ct.ExchangeDeliveryMargin));
    if (!ret) return ret;

    return ret;
  }
};

///正在同步中的投资者持仓
struct CShfeFtdcSyncingInvestorPositionField
{
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///持仓多空方向
  TShfeFtdcPosiDirectionType	PosiDirection;
  ///投机套保标志
  TShfeFtdcHedgeFlagType	HedgeFlag;
  ///持仓日期
  TShfeFtdcPositionDateType	PositionDate;
  ///上日持仓
  TShfeFtdcVolumeType	YdPosition;
  ///今日持仓
  TShfeFtdcVolumeType	Position;
  ///多头冻结
  TShfeFtdcVolumeType	LongFrozen;
  ///空头冻结
  TShfeFtdcVolumeType	ShortFrozen;
  ///开仓冻结金额
  TShfeFtdcMoneyType	LongFrozenAmount;
  ///开仓冻结金额
  TShfeFtdcMoneyType	ShortFrozenAmount;
  ///开仓量
  TShfeFtdcVolumeType	OpenVolume;
  ///平仓量
  TShfeFtdcVolumeType	CloseVolume;
  ///开仓金额
  TShfeFtdcMoneyType	OpenAmount;
  ///平仓金额
  TShfeFtdcMoneyType	CloseAmount;
  ///持仓成本
  TShfeFtdcMoneyType	PositionCost;
  ///上次占用的保证金
  TShfeFtdcMoneyType	PreMargin;
  ///占用的保证金
  TShfeFtdcMoneyType	UseMargin;
  ///冻结的保证金
  TShfeFtdcMoneyType	FrozenMargin;
  ///冻结的资金
  TShfeFtdcMoneyType	FrozenCash;
  ///冻结的手续费
  TShfeFtdcMoneyType	FrozenCommission;
  ///资金差额
  TShfeFtdcMoneyType	CashIn;
  ///手续费
  TShfeFtdcMoneyType	Commission;
  ///平仓盈亏
  TShfeFtdcMoneyType	CloseProfit;
  ///持仓盈亏
  TShfeFtdcMoneyType	PositionProfit;
  ///上次结算价
  TShfeFtdcPriceType	PreSettlementPrice;
  ///本次结算价
  TShfeFtdcPriceType	SettlementPrice;
  ///交易日
  TShfeFtdcDateType	TradingDay;
  ///结算编号
  TShfeFtdcSettlementIDType	SettlementID;
  ///开仓成本
  TShfeFtdcMoneyType	OpenCost;
  ///交易所保证金
  TShfeFtdcMoneyType	ExchangeMargin;
  ///组合成交形成的持仓
  TShfeFtdcVolumeType	CombPosition;
  ///组合多头冻结
  TShfeFtdcVolumeType	CombLongFrozen;
  ///组合空头冻结
  TShfeFtdcVolumeType	CombShortFrozen;
  ///逐日盯市平仓盈亏
  TShfeFtdcMoneyType	CloseProfitByDate;
  ///逐笔对冲平仓盈亏
  TShfeFtdcMoneyType	CloseProfitByTrade;
  ///今日持仓
  TShfeFtdcVolumeType	TodayPosition;
  ///保证金率
  TShfeFtdcRatioType	MarginRateByMoney;
  ///保证金率(按手数)
  TShfeFtdcRatioType	MarginRateByVolume;

  bool operator==(const CShfeFtdcSyncingInvestorPositionField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (PosiDirection == ct.PosiDirection);
    if (!ret) return ret;
    ret = ret && (HedgeFlag == ct.HedgeFlag);
    if (!ret) return ret;
    ret = ret && (PositionDate == ct.PositionDate);
    if (!ret) return ret;
    ret = ret && (YdPosition == ct.YdPosition);
    if (!ret) return ret;
    ret = ret && (Position == ct.Position);
    if (!ret) return ret;
    ret = ret && (LongFrozen == ct.LongFrozen);
    if (!ret) return ret;
    ret = ret && (ShortFrozen == ct.ShortFrozen);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(LongFrozenAmount, ct.LongFrozenAmount));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ShortFrozenAmount, ct.ShortFrozenAmount));
    if (!ret) return ret;
    ret = ret && (OpenVolume == ct.OpenVolume);
    if (!ret) return ret;
    ret = ret && (CloseVolume == ct.CloseVolume);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(OpenAmount, ct.OpenAmount));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CloseAmount, ct.CloseAmount));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PositionCost, ct.PositionCost));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreMargin, ct.PreMargin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(UseMargin, ct.UseMargin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(FrozenMargin, ct.FrozenMargin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(FrozenCash, ct.FrozenCash));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(FrozenCommission, ct.FrozenCommission));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CashIn, ct.CashIn));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Commission, ct.Commission));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CloseProfit, ct.CloseProfit));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PositionProfit, ct.PositionProfit));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreSettlementPrice, ct.PreSettlementPrice));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(SettlementPrice, ct.SettlementPrice));
    if (!ret) return ret;
    ret = ret && (strcmp(TradingDay, ct.TradingDay) == 0);
    if (!ret) return ret;
    ret = ret && (SettlementID == ct.SettlementID);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(OpenCost, ct.OpenCost));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ExchangeMargin, ct.ExchangeMargin));
    if (!ret) return ret;
    ret = ret && (CombPosition == ct.CombPosition);
    if (!ret) return ret;
    ret = ret && (CombLongFrozen == ct.CombLongFrozen);
    if (!ret) return ret;
    ret = ret && (CombShortFrozen == ct.CombShortFrozen);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CloseProfitByDate, ct.CloseProfitByDate));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CloseProfitByTrade, ct.CloseProfitByTrade));
    if (!ret) return ret;
    ret = ret && (TodayPosition == ct.TodayPosition);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(MarginRateByMoney, ct.MarginRateByMoney));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(MarginRateByVolume, ct.MarginRateByVolume));
    if (!ret) return ret;

    return ret;
  }
};

///正在同步中的合约保证金率
struct CShfeFtdcSyncingInstrumentMarginRateField
{
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///投资者范围
  TShfeFtdcInvestorRangeType	InvestorRange;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///投机套保标志
  TShfeFtdcHedgeFlagType	HedgeFlag;
  ///多头保证金率
  TShfeFtdcRatioType	LongMarginRatioByMoney;
  ///多头保证金费
  TShfeFtdcMoneyType	LongMarginRatioByVolume;
  ///空头保证金率
  TShfeFtdcRatioType	ShortMarginRatioByMoney;
  ///空头保证金费
  TShfeFtdcMoneyType	ShortMarginRatioByVolume;
  ///是否相对交易所收取
  TShfeFtdcBoolType	IsRelative;

  bool operator==(const CShfeFtdcSyncingInstrumentMarginRateField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (InvestorRange == ct.InvestorRange);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (HedgeFlag == ct.HedgeFlag);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(LongMarginRatioByMoney, ct.LongMarginRatioByMoney));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(LongMarginRatioByVolume, ct.LongMarginRatioByVolume));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ShortMarginRatioByMoney, ct.ShortMarginRatioByMoney));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ShortMarginRatioByVolume, ct.ShortMarginRatioByVolume));
    if (!ret) return ret;
    ret = ret && (IsRelative == ct.IsRelative);
    if (!ret) return ret;

    return ret;
  }
};

///正在同步中的合约手续费率
struct CShfeFtdcSyncingInstrumentCommissionRateField
{
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///投资者范围
  TShfeFtdcInvestorRangeType	InvestorRange;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///开仓手续费率
  TShfeFtdcRatioType	OpenRatioByMoney;
  ///开仓手续费
  TShfeFtdcRatioType	OpenRatioByVolume;
  ///平仓手续费率
  TShfeFtdcRatioType	CloseRatioByMoney;
  ///平仓手续费
  TShfeFtdcRatioType	CloseRatioByVolume;
  ///平今手续费率
  TShfeFtdcRatioType	CloseTodayRatioByMoney;
  ///平今手续费
  TShfeFtdcRatioType	CloseTodayRatioByVolume;

  bool operator==(const CShfeFtdcSyncingInstrumentCommissionRateField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (InvestorRange == ct.InvestorRange);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(OpenRatioByMoney, ct.OpenRatioByMoney));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(OpenRatioByVolume, ct.OpenRatioByVolume));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CloseRatioByMoney, ct.CloseRatioByMoney));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CloseRatioByVolume, ct.CloseRatioByVolume));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CloseTodayRatioByMoney, ct.CloseTodayRatioByMoney));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CloseTodayRatioByVolume, ct.CloseTodayRatioByVolume));
    if (!ret) return ret;

    return ret;
  }
};

///正在同步中的合约交易权限
struct CShfeFtdcSyncingInstrumentTradingRightField
{
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///投资者范围
  TShfeFtdcInvestorRangeType	InvestorRange;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///交易权限
  TShfeFtdcTradingRightType	TradingRight;

  bool operator==(const CShfeFtdcSyncingInstrumentTradingRightField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (InvestorRange == ct.InvestorRange);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (TradingRight == ct.TradingRight);
    if (!ret) return ret;

    return ret;
  }
};

///查询报单
struct CShfeFtdcQryOrderField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///报单编号
  TShfeFtdcOrderSysIDType	OrderSysID;
  ///开始时间
  TShfeFtdcTimeType	InsertTimeStart;
  ///结束时间
  TShfeFtdcTimeType	InsertTimeEnd;

  bool operator==(const CShfeFtdcQryOrderField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderSysID, ct.OrderSysID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InsertTimeStart, ct.InsertTimeStart) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InsertTimeEnd, ct.InsertTimeEnd) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询成交
struct CShfeFtdcQryTradeField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///成交编号
  TShfeFtdcTradeIDType	TradeID;
  ///开始时间
  TShfeFtdcTimeType	TradeTimeStart;
  ///结束时间
  TShfeFtdcTimeType	TradeTimeEnd;

  bool operator==(const CShfeFtdcQryTradeField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TradeID, ct.TradeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TradeTimeStart, ct.TradeTimeStart) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TradeTimeEnd, ct.TradeTimeEnd) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询投资者持仓
struct CShfeFtdcQryInvestorPositionField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;

  bool operator==(const CShfeFtdcQryInvestorPositionField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询资金账户
struct CShfeFtdcQryTradingAccountField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;

  bool operator==(const CShfeFtdcQryTradingAccountField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询投资者
struct CShfeFtdcQryInvestorField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;

  bool operator==(const CShfeFtdcQryInvestorField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询交易编码
struct CShfeFtdcQryTradingCodeField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///客户代码
  TShfeFtdcClientIDType	ClientID;
  ///交易编码类型
  TShfeFtdcClientIDTypeType	ClientIDType;

  bool operator==(const CShfeFtdcQryTradingCodeField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ClientID, ct.ClientID) == 0);
    if (!ret) return ret;
    ret = ret && (ClientIDType == ct.ClientIDType);
    if (!ret) return ret;

    return ret;
  }
};

///查询交易编码
struct CShfeFtdcQryInvestorGroupField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;

  bool operator==(const CShfeFtdcQryInvestorGroupField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询交易编码
struct CShfeFtdcQryInstrumentMarginRateField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///投机套保标志
  TShfeFtdcHedgeFlagType	HedgeFlag;

  bool operator==(const CShfeFtdcQryInstrumentMarginRateField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (HedgeFlag == ct.HedgeFlag);
    if (!ret) return ret;

    return ret;
  }
};

///查询交易编码
struct CShfeFtdcQryInstrumentCommissionRateField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;

  bool operator==(const CShfeFtdcQryInstrumentCommissionRateField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询交易编码
struct CShfeFtdcQryInstrumentTradingRightField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;

  bool operator==(const CShfeFtdcQryInstrumentTradingRightField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询经纪公司
struct CShfeFtdcQryBrokerField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;

  bool operator==(const CShfeFtdcQryBrokerField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询交易员
struct CShfeFtdcQryTraderField
{
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///会员代码
  TShfeFtdcParticipantIDType	ParticipantID;
  ///交易所交易员代码
  TShfeFtdcTraderIDType	TraderID;

  bool operator==(const CShfeFtdcQryTraderField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ParticipantID, ct.ParticipantID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TraderID, ct.TraderID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询经纪公司会员代码
struct CShfeFtdcQryPartBrokerField
{
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///会员代码
  TShfeFtdcParticipantIDType	ParticipantID;

  bool operator==(const CShfeFtdcQryPartBrokerField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ParticipantID, ct.ParticipantID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询管理用户功能权限
struct CShfeFtdcQrySuperUserFunctionField
{
  ///用户代码
  TShfeFtdcUserIDType	UserID;

  bool operator==(const CShfeFtdcQrySuperUserFunctionField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询用户会话
struct CShfeFtdcQryUserSessionField
{
  ///前置编号
  TShfeFtdcFrontIDType	FrontID;
  ///会话编号
  TShfeFtdcSessionIDType	SessionID;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///用户代码
  TShfeFtdcUserIDType	UserID;

  bool operator==(const CShfeFtdcQryUserSessionField &ct) const
  {
    bool ret = true;
    ret = ret && (FrontID == ct.FrontID);
    if (!ret) return ret;
    ret = ret && (SessionID == ct.SessionID);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询前置状态
struct CShfeFtdcQryFrontStatusField
{
  ///前置编号
  TShfeFtdcFrontIDType	FrontID;

  bool operator==(const CShfeFtdcQryFrontStatusField &ct) const
  {
    bool ret = true;
    ret = ret && (FrontID == ct.FrontID);
    if (!ret) return ret;

    return ret;
  }
};

///查询交易所报单
struct CShfeFtdcQryExchangeOrderField
{
  ///会员代码
  TShfeFtdcParticipantIDType	ParticipantID;
  ///客户代码
  TShfeFtdcClientIDType	ClientID;
  ///合约在交易所的代码
  TShfeFtdcExchangeInstIDType	ExchangeInstID;
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///交易所交易员代码
  TShfeFtdcTraderIDType	TraderID;

  bool operator==(const CShfeFtdcQryExchangeOrderField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(ParticipantID, ct.ParticipantID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ClientID, ct.ClientID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeInstID, ct.ExchangeInstID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TraderID, ct.TraderID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询报单操作
struct CShfeFtdcQryOrderActionField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;

  bool operator==(const CShfeFtdcQryOrderActionField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询交易所报单操作
struct CShfeFtdcQryExchangeOrderActionField
{
  ///会员代码
  TShfeFtdcParticipantIDType	ParticipantID;
  ///客户代码
  TShfeFtdcClientIDType	ClientID;
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///交易所交易员代码
  TShfeFtdcTraderIDType	TraderID;

  bool operator==(const CShfeFtdcQryExchangeOrderActionField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(ParticipantID, ct.ParticipantID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ClientID, ct.ClientID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TraderID, ct.TraderID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询管理用户
struct CShfeFtdcQrySuperUserField
{
  ///用户代码
  TShfeFtdcUserIDType	UserID;

  bool operator==(const CShfeFtdcQrySuperUserField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询交易所
struct CShfeFtdcQryExchangeField
{
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;

  bool operator==(const CShfeFtdcQryExchangeField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询产品
struct CShfeFtdcQryProductField
{
  ///产品代码
  TShfeFtdcInstrumentIDType	ProductID;

  bool operator==(const CShfeFtdcQryProductField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(ProductID, ct.ProductID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询合约
struct CShfeFtdcQryInstrumentField
{
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///合约在交易所的代码
  TShfeFtdcExchangeInstIDType	ExchangeInstID;
  ///产品代码
  TShfeFtdcInstrumentIDType	ProductID;

  bool operator==(const CShfeFtdcQryInstrumentField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeInstID, ct.ExchangeInstID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ProductID, ct.ProductID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询行情
struct CShfeFtdcQryDepthMarketDataField
{
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;

  bool operator==(const CShfeFtdcQryDepthMarketDataField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询经纪公司用户
struct CShfeFtdcQryBrokerUserField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///用户代码
  TShfeFtdcUserIDType	UserID;

  bool operator==(const CShfeFtdcQryBrokerUserField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询经纪公司用户权限
struct CShfeFtdcQryBrokerUserFunctionField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///用户代码
  TShfeFtdcUserIDType	UserID;

  bool operator==(const CShfeFtdcQryBrokerUserFunctionField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询交易员报盘机
struct CShfeFtdcQryTraderOfferField
{
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///会员代码
  TShfeFtdcParticipantIDType	ParticipantID;
  ///交易所交易员代码
  TShfeFtdcTraderIDType	TraderID;

  bool operator==(const CShfeFtdcQryTraderOfferField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ParticipantID, ct.ParticipantID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TraderID, ct.TraderID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询出入金流水
struct CShfeFtdcQrySyncDepositField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///出入金流水号
  TShfeFtdcDepositSeqNoType	DepositSeqNo;

  bool operator==(const CShfeFtdcQrySyncDepositField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(DepositSeqNo, ct.DepositSeqNo) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询投资者结算结果
struct CShfeFtdcQrySettlementInfoField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///交易日
  TShfeFtdcDateType	TradingDay;

  bool operator==(const CShfeFtdcQrySettlementInfoField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TradingDay, ct.TradingDay) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询报单
struct CShfeFtdcQryHisOrderField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///报单编号
  TShfeFtdcOrderSysIDType	OrderSysID;
  ///开始时间
  TShfeFtdcTimeType	InsertTimeStart;
  ///结束时间
  TShfeFtdcTimeType	InsertTimeEnd;
  ///交易日
  TShfeFtdcDateType	TradingDay;
  ///结算编号
  TShfeFtdcSettlementIDType	SettlementID;

  bool operator==(const CShfeFtdcQryHisOrderField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderSysID, ct.OrderSysID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InsertTimeStart, ct.InsertTimeStart) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InsertTimeEnd, ct.InsertTimeEnd) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TradingDay, ct.TradingDay) == 0);
    if (!ret) return ret;
    ret = ret && (SettlementID == ct.SettlementID);
    if (!ret) return ret;

    return ret;
  }
};

///组织架构投资者对应关系扁平表
struct CShfeFtdcInvestorDepartmentFlatField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///组织架构代码
  TShfeFtdcInvestorIDType	DepartmentID;

  bool operator==(const CShfeFtdcInvestorDepartmentFlatField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(DepartmentID, ct.DepartmentID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///操作员组织架构关系
struct CShfeFtdcDepartmentUserField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///投资者范围
  TShfeFtdcDepartmentRangeType	InvestorRange;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;

  bool operator==(const CShfeFtdcDepartmentUserField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (InvestorRange == ct.InvestorRange);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///组织架构
struct CShfeFtdcDepartmentField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///组织架构代码
  TShfeFtdcInvestorIDType	DepartmentID;
  ///组织架构名称
  TShfeFtdcPartyNameType	DepartmentName;

  bool operator==(const CShfeFtdcDepartmentField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(DepartmentID, ct.DepartmentID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(DepartmentName, ct.DepartmentName) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询经纪公司资金
struct CShfeFtdcQueryBrokerDepositField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;

  bool operator==(const CShfeFtdcQueryBrokerDepositField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///经纪公司资金
struct CShfeFtdcBrokerDepositField
{
  ///交易日期
  TShfeFtdcTradeDateType	TradingDay;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///会员代码
  TShfeFtdcParticipantIDType	ParticipantID;
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///上次结算准备金
  TShfeFtdcMoneyType	PreBalance;
  ///当前保证金总额
  TShfeFtdcMoneyType	CurrMargin;
  ///平仓盈亏
  TShfeFtdcMoneyType	CloseProfit;
  ///期货结算准备金
  TShfeFtdcMoneyType	Balance;
  ///入金金额
  TShfeFtdcMoneyType	Deposit;
  ///出金金额
  TShfeFtdcMoneyType	Withdraw;
  ///可提资金
  TShfeFtdcMoneyType	Available;
  ///基本准备金
  TShfeFtdcMoneyType	Reserve;
  ///冻结的保证金
  TShfeFtdcMoneyType	FrozenMargin;

  bool operator==(const CShfeFtdcBrokerDepositField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(TradingDay, ct.TradingDay) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ParticipantID, ct.ParticipantID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreBalance, ct.PreBalance));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CurrMargin, ct.CurrMargin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CloseProfit, ct.CloseProfit));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Balance, ct.Balance));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Deposit, ct.Deposit));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Withdraw, ct.Withdraw));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Available, ct.Available));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Reserve, ct.Reserve));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(FrozenMargin, ct.FrozenMargin));
    if (!ret) return ret;

    return ret;
  }
};

///市场行情
struct CShfeFtdcMarketDataField
{
  ///交易日
  TShfeFtdcDateType	TradingDay;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///合约在交易所的代码
  TShfeFtdcExchangeInstIDType	ExchangeInstID;
  ///最新价
  TShfeFtdcPriceType	LastPrice;
  ///上次结算价
  TShfeFtdcPriceType	PreSettlementPrice;
  ///昨收盘
  TShfeFtdcPriceType	PreClosePrice;
  ///昨持仓量
  TShfeFtdcLargeVolumeType	PreOpenInterest;
  ///今开盘
  TShfeFtdcPriceType	OpenPrice;
  ///最高价
  TShfeFtdcPriceType	HighestPrice;
  ///最低价
  TShfeFtdcPriceType	LowestPrice;
  ///数量
  TShfeFtdcVolumeType	Volume;
  ///成交金额
  TShfeFtdcMoneyType	Turnover;
  ///持仓量
  TShfeFtdcLargeVolumeType	OpenInterest;
  ///今收盘
  TShfeFtdcPriceType	ClosePrice;
  ///本次结算价
  TShfeFtdcPriceType	SettlementPrice;
  ///涨停板价
  TShfeFtdcPriceType	UpperLimitPrice;
  ///跌停板价
  TShfeFtdcPriceType	LowerLimitPrice;
  ///昨虚实度
  TShfeFtdcRatioType	PreDelta;
  ///今虚实度
  TShfeFtdcRatioType	CurrDelta;
  ///最后修改时间
  TShfeFtdcTimeType	UpdateTime;
  ///最后修改毫秒
  TShfeFtdcMillisecType	UpdateMillisec;

  bool operator==(const CShfeFtdcMarketDataField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(TradingDay, ct.TradingDay) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeInstID, ct.ExchangeInstID) == 0);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(LastPrice, ct.LastPrice));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreSettlementPrice, ct.PreSettlementPrice));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreClosePrice, ct.PreClosePrice));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreOpenInterest, ct.PreOpenInterest));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(OpenPrice, ct.OpenPrice));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(HighestPrice, ct.HighestPrice));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(LowestPrice, ct.LowestPrice));
    if (!ret) return ret;
    ret = ret && (Volume == ct.Volume);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Turnover, ct.Turnover));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(OpenInterest, ct.OpenInterest));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ClosePrice, ct.ClosePrice));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(SettlementPrice, ct.SettlementPrice));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(UpperLimitPrice, ct.UpperLimitPrice));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(LowerLimitPrice, ct.LowerLimitPrice));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreDelta, ct.PreDelta));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CurrDelta, ct.CurrDelta));
    if (!ret) return ret;
    ret = ret && (strcmp(UpdateTime, ct.UpdateTime) == 0);
    if (!ret) return ret;
    ret = ret && (UpdateMillisec == ct.UpdateMillisec);
    if (!ret) return ret;

    return ret;
  }
};

///行情基础属性
struct CShfeFtdcMarketDataBaseField
{
  ///交易日
  TShfeFtdcDateType	TradingDay;
  ///上次结算价
  TShfeFtdcPriceType	PreSettlementPrice;
  ///昨收盘
  TShfeFtdcPriceType	PreClosePrice;
  ///昨持仓量
  TShfeFtdcLargeVolumeType	PreOpenInterest;
  ///昨虚实度
  TShfeFtdcRatioType	PreDelta;

  bool operator==(const CShfeFtdcMarketDataBaseField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(TradingDay, ct.TradingDay) == 0);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreSettlementPrice, ct.PreSettlementPrice));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreClosePrice, ct.PreClosePrice));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreOpenInterest, ct.PreOpenInterest));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreDelta, ct.PreDelta));
    if (!ret) return ret;

    return ret;
  }
};

///行情静态属性
struct CShfeFtdcMarketDataStaticField
{
  ///今开盘
  TShfeFtdcPriceType	OpenPrice;
  ///最高价
  TShfeFtdcPriceType	HighestPrice;
  ///最低价
  TShfeFtdcPriceType	LowestPrice;
  ///今收盘
  TShfeFtdcPriceType	ClosePrice;
  ///涨停板价
  TShfeFtdcPriceType	UpperLimitPrice;
  ///跌停板价
  TShfeFtdcPriceType	LowerLimitPrice;
  ///本次结算价
  TShfeFtdcPriceType	SettlementPrice;
  ///今虚实度
  TShfeFtdcRatioType	CurrDelta;

  bool operator==(const CShfeFtdcMarketDataStaticField &ct) const
  {
    bool ret = true;
    ret = ret && (EQUALDOUBLE(OpenPrice, ct.OpenPrice));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(HighestPrice, ct.HighestPrice));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(LowestPrice, ct.LowestPrice));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ClosePrice, ct.ClosePrice));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(UpperLimitPrice, ct.UpperLimitPrice));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(LowerLimitPrice, ct.LowerLimitPrice));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(SettlementPrice, ct.SettlementPrice));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CurrDelta, ct.CurrDelta));
    if (!ret) return ret;

    return ret;
  }
};

///行情最新成交属性
struct CShfeFtdcMarketDataLastMatchField
{
  ///最新价
  TShfeFtdcPriceType	LastPrice;
  ///数量
  TShfeFtdcVolumeType	Volume;
  ///成交金额
  TShfeFtdcMoneyType	Turnover;
  ///持仓量
  TShfeFtdcLargeVolumeType	OpenInterest;

  bool operator==(const CShfeFtdcMarketDataLastMatchField &ct) const
  {
    bool ret = true;
    ret = ret && (EQUALDOUBLE(LastPrice, ct.LastPrice));
    if (!ret) return ret;
    ret = ret && (Volume == ct.Volume);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Turnover, ct.Turnover));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(OpenInterest, ct.OpenInterest));
    if (!ret) return ret;

    return ret;
  }
};

///行情最优价属性
struct CShfeFtdcMarketDataBestPriceField
{
  ///申买价一
  TShfeFtdcPriceType	BidPrice1;
  ///申买量一
  TShfeFtdcVolumeType	BidVolume1;
  ///申卖价一
  TShfeFtdcPriceType	AskPrice1;
  ///申卖量一
  TShfeFtdcVolumeType	AskVolume1;

  bool operator==(const CShfeFtdcMarketDataBestPriceField &ct) const
  {
    bool ret = true;
    ret = ret && (EQUALDOUBLE(BidPrice1, ct.BidPrice1));
    if (!ret) return ret;
    ret = ret && (BidVolume1 == ct.BidVolume1);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(AskPrice1, ct.AskPrice1));
    if (!ret) return ret;
    ret = ret && (AskVolume1 == ct.AskVolume1);
    if (!ret) return ret;

    return ret;
  }
};

///行情申买二、三属性
struct CShfeFtdcMarketDataBid23Field
{
  ///申买价二
  TShfeFtdcPriceType	BidPrice2;
  ///申买量二
  TShfeFtdcVolumeType	BidVolume2;
  ///申买价三
  TShfeFtdcPriceType	BidPrice3;
  ///申买量三
  TShfeFtdcVolumeType	BidVolume3;

  bool operator==(const CShfeFtdcMarketDataBid23Field &ct) const
  {
    bool ret = true;
    ret = ret && (EQUALDOUBLE(BidPrice2, ct.BidPrice2));
    if (!ret) return ret;
    ret = ret && (BidVolume2 == ct.BidVolume2);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(BidPrice3, ct.BidPrice3));
    if (!ret) return ret;
    ret = ret && (BidVolume3 == ct.BidVolume3);
    if (!ret) return ret;

    return ret;
  }
};

///行情申卖二、三属性
struct CShfeFtdcMarketDataAsk23Field
{
  ///申卖价二
  TShfeFtdcPriceType	AskPrice2;
  ///申卖量二
  TShfeFtdcVolumeType	AskVolume2;
  ///申卖价三
  TShfeFtdcPriceType	AskPrice3;
  ///申卖量三
  TShfeFtdcVolumeType	AskVolume3;

  bool operator==(const CShfeFtdcMarketDataAsk23Field &ct) const
  {
    bool ret = true;
    ret = ret && (EQUALDOUBLE(AskPrice2, ct.AskPrice2));
    if (!ret) return ret;
    ret = ret && (AskVolume2 == ct.AskVolume2);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(AskPrice3, ct.AskPrice3));
    if (!ret) return ret;
    ret = ret && (AskVolume3 == ct.AskVolume3);
    if (!ret) return ret;

    return ret;
  }
};

///行情申买四、五属性
struct CShfeFtdcMarketDataBid45Field
{
  ///申买价四
  TShfeFtdcPriceType	BidPrice4;
  ///申买量四
  TShfeFtdcVolumeType	BidVolume4;
  ///申买价五
  TShfeFtdcPriceType	BidPrice5;
  ///申买量五
  TShfeFtdcVolumeType	BidVolume5;

  bool operator==(const CShfeFtdcMarketDataBid45Field &ct) const
  {
    bool ret = true;
    ret = ret && (EQUALDOUBLE(BidPrice4, ct.BidPrice4));
    if (!ret) return ret;
    ret = ret && (BidVolume4 == ct.BidVolume4);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(BidPrice5, ct.BidPrice5));
    if (!ret) return ret;
    ret = ret && (BidVolume5 == ct.BidVolume5);
    if (!ret) return ret;

    return ret;
  }
};

///行情申卖四、五属性
struct CShfeFtdcMarketDataAsk45Field
{
  ///申卖价四
  TShfeFtdcPriceType	AskPrice4;
  ///申卖量四
  TShfeFtdcVolumeType	AskVolume4;
  ///申卖价五
  TShfeFtdcPriceType	AskPrice5;
  ///申卖量五
  TShfeFtdcVolumeType	AskVolume5;

  bool operator==(const CShfeFtdcMarketDataAsk45Field &ct) const
  {
    bool ret = true;
    ret = ret && (EQUALDOUBLE(AskPrice4, ct.AskPrice4));
    if (!ret) return ret;
    ret = ret && (AskVolume4 == ct.AskVolume4);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(AskPrice5, ct.AskPrice5));
    if (!ret) return ret;
    ret = ret && (AskVolume5 == ct.AskVolume5);
    if (!ret) return ret;

    return ret;
  }
};

///行情更新时间属性
struct CShfeFtdcMarketDataUpdateTimeField
{
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///最后修改时间
  TShfeFtdcTimeType	UpdateTime;
  ///最后修改毫秒
  TShfeFtdcMillisecType	UpdateMillisec;

  bool operator==(const CShfeFtdcMarketDataUpdateTimeField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UpdateTime, ct.UpdateTime) == 0);
    if (!ret) return ret;
    ret = ret && (UpdateMillisec == ct.UpdateMillisec);
    if (!ret) return ret;

    return ret;
  }
};

///指定的合约
struct CShfeFtdcSpecificInstrumentField
{
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;

  bool operator==(const CShfeFtdcSpecificInstrumentField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///合约状态
struct CShfeFtdcInstrumentStatusField
{
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///合约在交易所的代码
  TShfeFtdcExchangeInstIDType	ExchangeInstID;
  ///结算组代码
  TShfeFtdcSettlementGroupIDType	SettlementGroupID;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///合约交易状态
  TShfeFtdcInstrumentStatusType	InstrumentStatus;
  ///交易阶段编号
  TShfeFtdcTradingSegmentSNType	TradingSegmentSN;
  ///进入本状态时间
  TShfeFtdcTimeType	EnterTime;
  ///进入本状态原因
  TShfeFtdcInstStatusEnterReasonType	EnterReason;

  bool operator==(const CShfeFtdcInstrumentStatusField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeInstID, ct.ExchangeInstID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(SettlementGroupID, ct.SettlementGroupID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (InstrumentStatus == ct.InstrumentStatus);
    if (!ret) return ret;
    ret = ret && (TradingSegmentSN == ct.TradingSegmentSN);
    if (!ret) return ret;
    ret = ret && (strcmp(EnterTime, ct.EnterTime) == 0);
    if (!ret) return ret;
    ret = ret && (EnterReason == ct.EnterReason);
    if (!ret) return ret;

    return ret;
  }
};

///查询合约状态
struct CShfeFtdcQryInstrumentStatusField
{
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///合约在交易所的代码
  TShfeFtdcExchangeInstIDType	ExchangeInstID;

  bool operator==(const CShfeFtdcQryInstrumentStatusField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeInstID, ct.ExchangeInstID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///投资者账户
struct CShfeFtdcInvestorAccountField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///投资者帐号
  TShfeFtdcAccountIDType	AccountID;

  bool operator==(const CShfeFtdcInvestorAccountField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(AccountID, ct.AccountID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///浮动盈亏算法
struct CShfeFtdcPositionProfitAlgorithmField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者帐号
  TShfeFtdcAccountIDType	AccountID;
  ///盈亏算法
  TShfeFtdcAlgorithmType	Algorithm;
  ///备注
  TShfeFtdcMemoType	Memo;

  bool operator==(const CShfeFtdcPositionProfitAlgorithmField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(AccountID, ct.AccountID) == 0);
    if (!ret) return ret;
    ret = ret && (Algorithm == ct.Algorithm);
    if (!ret) return ret;
    ret = ret && (strcmp(Memo, ct.Memo) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///会员资金折扣
struct CShfeFtdcDiscountField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者范围
  TShfeFtdcInvestorRangeType	InvestorRange;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///资金折扣比例
  TShfeFtdcRatioType	Discount;

  bool operator==(const CShfeFtdcDiscountField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (InvestorRange == ct.InvestorRange);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Discount, ct.Discount));
    if (!ret) return ret;

    return ret;
  }
};

///查询转帐银行
struct CShfeFtdcQryTransferBankField
{
  ///银行代码
  TShfeFtdcBankIDType	BankID;
  ///银行分中心代码
  TShfeFtdcBankBrchIDType	BankBrchID;

  bool operator==(const CShfeFtdcQryTransferBankField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BankID, ct.BankID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BankBrchID, ct.BankBrchID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///转帐银行
struct CShfeFtdcTransferBankField
{
  ///银行代码
  TShfeFtdcBankIDType	BankID;
  ///银行分中心代码
  TShfeFtdcBankBrchIDType	BankBrchID;
  ///银行名称
  TShfeFtdcBankNameType	BankName;
  ///是否活跃
  TShfeFtdcBoolType	IsActive;

  bool operator==(const CShfeFtdcTransferBankField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BankID, ct.BankID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BankBrchID, ct.BankBrchID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BankName, ct.BankName) == 0);
    if (!ret) return ret;
    ret = ret && (IsActive == ct.IsActive);
    if (!ret) return ret;

    return ret;
  }
};

///查询投资者持仓明细
struct CShfeFtdcQryInvestorPositionDetailField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;

  bool operator==(const CShfeFtdcQryInvestorPositionDetailField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///投资者持仓明细
struct CShfeFtdcInvestorPositionDetailField
{
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///投机套保标志
  TShfeFtdcHedgeFlagType	HedgeFlag;
  ///买卖
  TShfeFtdcDirectionType	Direction;
  ///开仓日期
  TShfeFtdcDateType	OpenDate;
  ///成交编号
  TShfeFtdcTradeIDType	TradeID;
  ///数量
  TShfeFtdcVolumeType	Volume;
  ///开仓价
  TShfeFtdcPriceType	OpenPrice;
  ///交易日
  TShfeFtdcDateType	TradingDay;
  ///结算编号
  TShfeFtdcSettlementIDType	SettlementID;
  ///成交类型
  TShfeFtdcTradeTypeType	TradeType;
  ///组合合约代码
  TShfeFtdcInstrumentIDType	CombInstrumentID;
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///逐日盯市平仓盈亏
  TShfeFtdcMoneyType	CloseProfitByDate;
  ///逐笔对冲平仓盈亏
  TShfeFtdcMoneyType	CloseProfitByTrade;
  ///逐日盯市持仓盈亏
  TShfeFtdcMoneyType	PositionProfitByDate;
  ///逐笔对冲持仓盈亏
  TShfeFtdcMoneyType	PositionProfitByTrade;
  ///投资者保证金
  TShfeFtdcMoneyType	Margin;
  ///交易所保证金
  TShfeFtdcMoneyType	ExchMargin;
  ///保证金率
  TShfeFtdcRatioType	MarginRateByMoney;
  ///保证金率(按手数)
  TShfeFtdcRatioType	MarginRateByVolume;
  ///昨结算价
  TShfeFtdcPriceType	LastSettlementPrice;
  ///结算价
  TShfeFtdcPriceType	SettlementPrice;
  ///平仓量
  TShfeFtdcVolumeType	CloseVolume;
  ///平仓金额
  TShfeFtdcMoneyType	CloseAmount;

  bool operator==(const CShfeFtdcInvestorPositionDetailField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (HedgeFlag == ct.HedgeFlag);
    if (!ret) return ret;
    ret = ret && (Direction == ct.Direction);
    if (!ret) return ret;
    ret = ret && (strcmp(OpenDate, ct.OpenDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TradeID, ct.TradeID) == 0);
    if (!ret) return ret;
    ret = ret && (Volume == ct.Volume);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(OpenPrice, ct.OpenPrice));
    if (!ret) return ret;
    ret = ret && (strcmp(TradingDay, ct.TradingDay) == 0);
    if (!ret) return ret;
    ret = ret && (SettlementID == ct.SettlementID);
    if (!ret) return ret;
    ret = ret && (TradeType == ct.TradeType);
    if (!ret) return ret;
    ret = ret && (strcmp(CombInstrumentID, ct.CombInstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CloseProfitByDate, ct.CloseProfitByDate));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CloseProfitByTrade, ct.CloseProfitByTrade));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PositionProfitByDate, ct.PositionProfitByDate));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PositionProfitByTrade, ct.PositionProfitByTrade));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Margin, ct.Margin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ExchMargin, ct.ExchMargin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(MarginRateByMoney, ct.MarginRateByMoney));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(MarginRateByVolume, ct.MarginRateByVolume));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(LastSettlementPrice, ct.LastSettlementPrice));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(SettlementPrice, ct.SettlementPrice));
    if (!ret) return ret;
    ret = ret && (CloseVolume == ct.CloseVolume);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CloseAmount, ct.CloseAmount));
    if (!ret) return ret;

    return ret;
  }
};

///资金账户口令域
struct CShfeFtdcTradingAccountPasswordField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者帐号
  TShfeFtdcAccountIDType	AccountID;
  ///密码
  TShfeFtdcPasswordType	Password;

  bool operator==(const CShfeFtdcTradingAccountPasswordField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(AccountID, ct.AccountID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(Password, ct.Password) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///交易所行情报盘机
struct CShfeFtdcMDTraderOfferField
{
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///交易所交易员代码
  TShfeFtdcTraderIDType	TraderID;
  ///会员代码
  TShfeFtdcParticipantIDType	ParticipantID;
  ///密码
  TShfeFtdcPasswordType	Password;
  ///安装编号
  TShfeFtdcInstallIDType	InstallID;
  ///本地报单编号
  TShfeFtdcOrderLocalIDType	OrderLocalID;
  ///交易所交易员连接状态
  TShfeFtdcTraderConnectStatusType	TraderConnectStatus;
  ///发出连接请求的日期
  TShfeFtdcDateType	ConnectRequestDate;
  ///发出连接请求的时间
  TShfeFtdcTimeType	ConnectRequestTime;
  ///上次报告日期
  TShfeFtdcDateType	LastReportDate;
  ///上次报告时间
  TShfeFtdcTimeType	LastReportTime;
  ///完成连接日期
  TShfeFtdcDateType	ConnectDate;
  ///完成连接时间
  TShfeFtdcTimeType	ConnectTime;
  ///启动日期
  TShfeFtdcDateType	StartDate;
  ///启动时间
  TShfeFtdcTimeType	StartTime;
  ///交易日
  TShfeFtdcDateType	TradingDay;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///本席位最大成交编号
  TShfeFtdcTradeIDType	MaxTradeID;
  ///本席位最大报单备拷
  TShfeFtdcReturnCodeType	MaxOrderMessageReference;

  bool operator==(const CShfeFtdcMDTraderOfferField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TraderID, ct.TraderID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ParticipantID, ct.ParticipantID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(Password, ct.Password) == 0);
    if (!ret) return ret;
    ret = ret && (InstallID == ct.InstallID);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderLocalID, ct.OrderLocalID) == 0);
    if (!ret) return ret;
    ret = ret && (TraderConnectStatus == ct.TraderConnectStatus);
    if (!ret) return ret;
    ret = ret && (strcmp(ConnectRequestDate, ct.ConnectRequestDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ConnectRequestTime, ct.ConnectRequestTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(LastReportDate, ct.LastReportDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(LastReportTime, ct.LastReportTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ConnectDate, ct.ConnectDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ConnectTime, ct.ConnectTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(StartDate, ct.StartDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(StartTime, ct.StartTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TradingDay, ct.TradingDay) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(MaxTradeID, ct.MaxTradeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(MaxOrderMessageReference, ct.MaxOrderMessageReference) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询行情报盘机
struct CShfeFtdcQryMDTraderOfferField
{
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///会员代码
  TShfeFtdcParticipantIDType	ParticipantID;
  ///交易所交易员代码
  TShfeFtdcTraderIDType	TraderID;

  bool operator==(const CShfeFtdcQryMDTraderOfferField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ParticipantID, ct.ParticipantID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TraderID, ct.TraderID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询客户通知
struct CShfeFtdcQryNoticeField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;

  bool operator==(const CShfeFtdcQryNoticeField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///客户通知
struct CShfeFtdcNoticeField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///消息正文
  TShfeFtdcContentType	Content;
  ///经纪公司通知内容序列号
  TShfeFtdcSequenceLabelType	SequenceLabel;

  bool operator==(const CShfeFtdcNoticeField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(Content, ct.Content) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(SequenceLabel, ct.SequenceLabel) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///用户权限
struct CShfeFtdcUserRightField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///客户权限类型
  TShfeFtdcUserRightTypeType	UserRightType;
  ///是否禁止
  TShfeFtdcBoolType	IsForbidden;

  bool operator==(const CShfeFtdcUserRightField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (UserRightType == ct.UserRightType);
    if (!ret) return ret;
    ret = ret && (IsForbidden == ct.IsForbidden);
    if (!ret) return ret;

    return ret;
  }
};

///查询结算信息确认域
struct CShfeFtdcQrySettlementInfoConfirmField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;

  bool operator==(const CShfeFtdcQrySettlementInfoConfirmField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///装载结算信息
struct CShfeFtdcLoadSettlementInfoField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;

  bool operator==(const CShfeFtdcLoadSettlementInfoField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///经纪公司可提资金算法表
struct CShfeFtdcBrokerWithdrawAlgorithmField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///可提资金算法
  TShfeFtdcAlgorithmType	WithdrawAlgorithm;
  ///资金使用率
  TShfeFtdcRatioType	UsingRatio;
  ///可提是否包含平仓盈利
  TShfeFtdcIncludeCloseProfitType	IncludeCloseProfit;
  ///本日无仓且无成交客户是否受可提比例限制
  TShfeFtdcAllWithoutTradeType	AllWithoutTrade;
  ///可用是否包含平仓盈利
  TShfeFtdcIncludeCloseProfitType	AvailIncludeCloseProfit;
  ///是否启用用户事件
  TShfeFtdcBoolType	IsBrokerUserEvent;

  bool operator==(const CShfeFtdcBrokerWithdrawAlgorithmField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (WithdrawAlgorithm == ct.WithdrawAlgorithm);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(UsingRatio, ct.UsingRatio));
    if (!ret) return ret;
    ret = ret && (IncludeCloseProfit == ct.IncludeCloseProfit);
    if (!ret) return ret;
    ret = ret && (AllWithoutTrade == ct.AllWithoutTrade);
    if (!ret) return ret;
    ret = ret && (AvailIncludeCloseProfit == ct.AvailIncludeCloseProfit);
    if (!ret) return ret;
    ret = ret && (IsBrokerUserEvent == ct.IsBrokerUserEvent);
    if (!ret) return ret;

    return ret;
  }
};

///资金账户口令变更域
struct CShfeFtdcTradingAccountPasswordUpdateV1Field
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///原来的口令
  TShfeFtdcPasswordType	OldPassword;
  ///新的口令
  TShfeFtdcPasswordType	NewPassword;

  bool operator==(const CShfeFtdcTradingAccountPasswordUpdateV1Field &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OldPassword, ct.OldPassword) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(NewPassword, ct.NewPassword) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///资金账户口令变更域
struct CShfeFtdcTradingAccountPasswordUpdateField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者帐号
  TShfeFtdcAccountIDType	AccountID;
  ///原来的口令
  TShfeFtdcPasswordType	OldPassword;
  ///新的口令
  TShfeFtdcPasswordType	NewPassword;

  bool operator==(const CShfeFtdcTradingAccountPasswordUpdateField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(AccountID, ct.AccountID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OldPassword, ct.OldPassword) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(NewPassword, ct.NewPassword) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询组合合约分腿
struct CShfeFtdcQryCombinationLegField
{
  ///组合合约代码
  TShfeFtdcInstrumentIDType	CombInstrumentID;
  ///单腿编号
  TShfeFtdcLegIDType	LegID;
  ///单腿合约代码
  TShfeFtdcInstrumentIDType	LegInstrumentID;

  bool operator==(const CShfeFtdcQryCombinationLegField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(CombInstrumentID, ct.CombInstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (LegID == ct.LegID);
    if (!ret) return ret;
    ret = ret && (strcmp(LegInstrumentID, ct.LegInstrumentID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询组合合约分腿
struct CShfeFtdcQrySyncStatusField
{
  ///交易日
  TShfeFtdcDateType	TradingDay;

  bool operator==(const CShfeFtdcQrySyncStatusField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(TradingDay, ct.TradingDay) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///组合交易合约的单腿
struct CShfeFtdcCombinationLegField
{
  ///组合合约代码
  TShfeFtdcInstrumentIDType	CombInstrumentID;
  ///单腿编号
  TShfeFtdcLegIDType	LegID;
  ///单腿合约代码
  TShfeFtdcInstrumentIDType	LegInstrumentID;
  ///买卖方向
  TShfeFtdcDirectionType	Direction;
  ///单腿乘数
  TShfeFtdcLegMultipleType	LegMultiple;
  ///派生层数
  TShfeFtdcImplyLevelType	ImplyLevel;

  bool operator==(const CShfeFtdcCombinationLegField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(CombInstrumentID, ct.CombInstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (LegID == ct.LegID);
    if (!ret) return ret;
    ret = ret && (strcmp(LegInstrumentID, ct.LegInstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (Direction == ct.Direction);
    if (!ret) return ret;
    ret = ret && (LegMultiple == ct.LegMultiple);
    if (!ret) return ret;
    ret = ret && (ImplyLevel == ct.ImplyLevel);
    if (!ret) return ret;

    return ret;
  }
};

///数据同步状态
struct CShfeFtdcSyncStatusField
{
  ///交易日
  TShfeFtdcDateType	TradingDay;
  ///数据同步状态
  TShfeFtdcDataSyncStatusType	DataSyncStatus;

  bool operator==(const CShfeFtdcSyncStatusField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(TradingDay, ct.TradingDay) == 0);
    if (!ret) return ret;
    ret = ret && (DataSyncStatus == ct.DataSyncStatus);
    if (!ret) return ret;

    return ret;
  }
};

///查询联系人
struct CShfeFtdcQryLinkManField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;

  bool operator==(const CShfeFtdcQryLinkManField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///联系人
struct CShfeFtdcLinkManField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///联系人类型
  TShfeFtdcPersonTypeType	PersonType;
  ///证件类型
  TShfeFtdcIdCardTypeType	IdentifiedCardType;
  ///证件号码
  TShfeFtdcIdentifiedCardNoType	IdentifiedCardNo;
  ///名称
  TShfeFtdcPartyNameType	PersonName;
  ///联系电话
  TShfeFtdcTelephoneType	Telephone;
  ///通讯地址
  TShfeFtdcAddressType	Address;
  ///邮政编码
  TShfeFtdcZipCodeType	ZipCode;
  ///优先级
  TShfeFtdcPriorityType	Priority;

  bool operator==(const CShfeFtdcLinkManField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (PersonType == ct.PersonType);
    if (!ret) return ret;
    ret = ret && (IdentifiedCardType == ct.IdentifiedCardType);
    if (!ret) return ret;
    ret = ret && (strcmp(IdentifiedCardNo, ct.IdentifiedCardNo) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(PersonName, ct.PersonName) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(Telephone, ct.Telephone) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(Address, ct.Address) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ZipCode, ct.ZipCode) == 0);
    if (!ret) return ret;
    ret = ret && (Priority == ct.Priority);
    if (!ret) return ret;

    return ret;
  }
};

///查询经纪公司用户事件
struct CShfeFtdcQryBrokerUserEventField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///用户事件类型
  TShfeFtdcUserEventTypeType	UserEventType;

  bool operator==(const CShfeFtdcQryBrokerUserEventField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (UserEventType == ct.UserEventType);
    if (!ret) return ret;

    return ret;
  }
};

///查询经纪公司用户事件
struct CShfeFtdcBrokerUserEventField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///用户事件类型
  TShfeFtdcUserEventTypeType	UserEventType;
  ///用户事件序号
  TShfeFtdcSequenceNoType	EventSequenceNo;
  ///事件发生日期
  TShfeFtdcDateType	EventDate;
  ///事件发生时间
  TShfeFtdcTimeType	EventTime;
  ///用户事件信息
  TShfeFtdcUserEventInfoType	UserEventInfo;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;

  bool operator==(const CShfeFtdcBrokerUserEventField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (UserEventType == ct.UserEventType);
    if (!ret) return ret;
    ret = ret && (EventSequenceNo == ct.EventSequenceNo);
    if (!ret) return ret;
    ret = ret && (strcmp(EventDate, ct.EventDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(EventTime, ct.EventTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserEventInfo, ct.UserEventInfo) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询签约银行请求
struct CShfeFtdcQryContractBankField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///银行代码
  TShfeFtdcBankIDType	BankID;
  ///银行分中心代码
  TShfeFtdcBankBrchIDType	BankBrchID;

  bool operator==(const CShfeFtdcQryContractBankField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BankID, ct.BankID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BankBrchID, ct.BankBrchID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询签约银行响应
struct CShfeFtdcContractBankField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///银行代码
  TShfeFtdcBankIDType	BankID;
  ///银行分中心代码
  TShfeFtdcBankBrchIDType	BankBrchID;
  ///银行名称
  TShfeFtdcBankNameType	BankName;

  bool operator==(const CShfeFtdcContractBankField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BankID, ct.BankID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BankBrchID, ct.BankBrchID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BankName, ct.BankName) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///投资者组合持仓明细
struct CShfeFtdcInvestorPositionCombineDetailField
{
  ///交易日
  TShfeFtdcDateType	TradingDay;
  ///开仓日期
  TShfeFtdcDateType	OpenDate;
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///结算编号
  TShfeFtdcSettlementIDType	SettlementID;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///组合编号
  TShfeFtdcTradeIDType	ComTradeID;
  ///撮合编号
  TShfeFtdcTradeIDType	TradeID;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///投机套保标志
  TShfeFtdcHedgeFlagType	HedgeFlag;
  ///买卖
  TShfeFtdcDirectionType	Direction;
  ///持仓量
  TShfeFtdcVolumeType	TotalAmt;
  ///投资者保证金
  TShfeFtdcMoneyType	Margin;
  ///交易所保证金
  TShfeFtdcMoneyType	ExchMargin;
  ///保证金率
  TShfeFtdcRatioType	MarginRateByMoney;
  ///保证金率(按手数)
  TShfeFtdcRatioType	MarginRateByVolume;
  ///单腿编号
  TShfeFtdcLegIDType	LegID;
  ///单腿乘数
  TShfeFtdcLegMultipleType	LegMultiple;
  ///组合持仓合约编码
  TShfeFtdcInstrumentIDType	CombInstrumentID;

  bool operator==(const CShfeFtdcInvestorPositionCombineDetailField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(TradingDay, ct.TradingDay) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OpenDate, ct.OpenDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (SettlementID == ct.SettlementID);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ComTradeID, ct.ComTradeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TradeID, ct.TradeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (HedgeFlag == ct.HedgeFlag);
    if (!ret) return ret;
    ret = ret && (Direction == ct.Direction);
    if (!ret) return ret;
    ret = ret && (TotalAmt == ct.TotalAmt);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Margin, ct.Margin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ExchMargin, ct.ExchMargin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(MarginRateByMoney, ct.MarginRateByMoney));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(MarginRateByVolume, ct.MarginRateByVolume));
    if (!ret) return ret;
    ret = ret && (LegID == ct.LegID);
    if (!ret) return ret;
    ret = ret && (LegMultiple == ct.LegMultiple);
    if (!ret) return ret;
    ret = ret && (strcmp(CombInstrumentID, ct.CombInstrumentID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///预埋单
struct CShfeFtdcParkedOrderField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///报单引用
  TShfeFtdcOrderRefType	OrderRef;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///报单价格条件
  TShfeFtdcOrderPriceTypeType	OrderPriceType;
  ///买卖方向
  TShfeFtdcDirectionType	Direction;
  ///组合开平标志
  TShfeFtdcCombOffsetFlagType	CombOffsetFlag;
  ///组合投机套保标志
  TShfeFtdcCombHedgeFlagType	CombHedgeFlag;
  ///价格
  TShfeFtdcPriceType	LimitPrice;
  ///数量
  TShfeFtdcVolumeType	VolumeTotalOriginal;
  ///有效期类型
  TShfeFtdcTimeConditionType	TimeCondition;
  ///GTD日期
  TShfeFtdcDateType	GTDDate;
  ///成交量类型
  TShfeFtdcVolumeConditionType	VolumeCondition;
  ///最小成交量
  TShfeFtdcVolumeType	MinVolume;
  ///触发条件
  TShfeFtdcContingentConditionType	ContingentCondition;
  ///止损价
  TShfeFtdcPriceType	StopPrice;
  ///强平原因
  TShfeFtdcForceCloseReasonType	ForceCloseReason;
  ///自动挂起标志
  TShfeFtdcBoolType	IsAutoSuspend;
  ///业务单元
  TShfeFtdcBusinessUnitType	BusinessUnit;
  ///请求编号
  TShfeFtdcRequestIDType	RequestID;
  ///用户强评标志
  TShfeFtdcBoolType	UserForceClose;
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///预埋报单编号
  TShfeFtdcParkedOrderIDType	ParkedOrderID;
  ///用户类型
  TShfeFtdcUserTypeType	UserType;
  ///预埋单状态
  TShfeFtdcParkedOrderStatusType	Status;
  ///错误代码
  TShfeFtdcErrorIDType	ErrorID;
  ///错误信息
  TShfeFtdcErrorMsgType	ErrorMsg;

  bool operator==(const CShfeFtdcParkedOrderField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderRef, ct.OrderRef) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (OrderPriceType == ct.OrderPriceType);
    if (!ret) return ret;
    ret = ret && (Direction == ct.Direction);
    if (!ret) return ret;
    for (int i = 0; i < 4; ++i) {
      ret = ret && (CombOffsetFlag[i] == ct.CombOffsetFlag[i]);
      if (!ret) return ret;
    }
    for (int i = 0; i < 4; ++i) {
      ret = ret && (CombHedgeFlag[i] == ct.CombHedgeFlag[i]);
      if (!ret) return ret;
    }
    ret = ret && (EQUALDOUBLE(LimitPrice, ct.LimitPrice));
    if (!ret) return ret;
    ret = ret && (VolumeTotalOriginal == ct.VolumeTotalOriginal);
    if (!ret) return ret;
    ret = ret && (TimeCondition == ct.TimeCondition);
    if (!ret) return ret;
    ret = ret && (strcmp(GTDDate, ct.GTDDate) == 0);
    if (!ret) return ret;
    ret = ret && (VolumeCondition == ct.VolumeCondition);
    if (!ret) return ret;
    ret = ret && (MinVolume == ct.MinVolume);
    if (!ret) return ret;
    ret = ret && (ContingentCondition == ct.ContingentCondition);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(StopPrice, ct.StopPrice));
    if (!ret) return ret;
    ret = ret && (ForceCloseReason == ct.ForceCloseReason);
    if (!ret) return ret;
    ret = ret && (IsAutoSuspend == ct.IsAutoSuspend);
    if (!ret) return ret;
    ret = ret && (strcmp(BusinessUnit, ct.BusinessUnit) == 0);
    if (!ret) return ret;
    ret = ret && (RequestID == ct.RequestID);
    if (!ret) return ret;
    ret = ret && (UserForceClose == ct.UserForceClose);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ParkedOrderID, ct.ParkedOrderID) == 0);
    if (!ret) return ret;
    ret = ret && (UserType == ct.UserType);
    if (!ret) return ret;
    ret = ret && (Status == ct.Status);
    if (!ret) return ret;
    ret = ret && (ErrorID == ct.ErrorID);
    if (!ret) return ret;
    ret = ret && (strcmp(ErrorMsg, ct.ErrorMsg) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///输入预埋单操作
struct CShfeFtdcParkedOrderActionField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///报单操作引用
  TShfeFtdcOrderActionRefType	OrderActionRef;
  ///报单引用
  TShfeFtdcOrderRefType	OrderRef;
  ///请求编号
  TShfeFtdcRequestIDType	RequestID;
  ///前置编号
  TShfeFtdcFrontIDType	FrontID;
  ///会话编号
  TShfeFtdcSessionIDType	SessionID;
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///报单编号
  TShfeFtdcOrderSysIDType	OrderSysID;
  ///操作标志
  TShfeFtdcActionFlagType	ActionFlag;
  ///价格
  TShfeFtdcPriceType	LimitPrice;
  ///数量变化
  TShfeFtdcVolumeType	VolumeChange;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///预埋撤单单编号
  TShfeFtdcParkedOrderActionIDType	ParkedOrderActionID;
  ///用户类型
  TShfeFtdcUserTypeType	UserType;
  ///预埋撤单状态
  TShfeFtdcParkedOrderStatusType	Status;
  ///错误代码
  TShfeFtdcErrorIDType	ErrorID;
  ///错误信息
  TShfeFtdcErrorMsgType	ErrorMsg;

  bool operator==(const CShfeFtdcParkedOrderActionField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (OrderActionRef == ct.OrderActionRef);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderRef, ct.OrderRef) == 0);
    if (!ret) return ret;
    ret = ret && (RequestID == ct.RequestID);
    if (!ret) return ret;
    ret = ret && (FrontID == ct.FrontID);
    if (!ret) return ret;
    ret = ret && (SessionID == ct.SessionID);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderSysID, ct.OrderSysID) == 0);
    if (!ret) return ret;
    ret = ret && (ActionFlag == ct.ActionFlag);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(LimitPrice, ct.LimitPrice));
    if (!ret) return ret;
    ret = ret && (VolumeChange == ct.VolumeChange);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ParkedOrderActionID, ct.ParkedOrderActionID) == 0);
    if (!ret) return ret;
    ret = ret && (UserType == ct.UserType);
    if (!ret) return ret;
    ret = ret && (Status == ct.Status);
    if (!ret) return ret;
    ret = ret && (ErrorID == ct.ErrorID);
    if (!ret) return ret;
    ret = ret && (strcmp(ErrorMsg, ct.ErrorMsg) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询预埋单
struct CShfeFtdcQryParkedOrderField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;

  bool operator==(const CShfeFtdcQryParkedOrderField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询预埋撤单
struct CShfeFtdcQryParkedOrderActionField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;

  bool operator==(const CShfeFtdcQryParkedOrderActionField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///删除预埋单
struct CShfeFtdcRemoveParkedOrderField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///预埋报单编号
  TShfeFtdcParkedOrderIDType	ParkedOrderID;

  bool operator==(const CShfeFtdcRemoveParkedOrderField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ParkedOrderID, ct.ParkedOrderID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///删除预埋撤单
struct CShfeFtdcRemoveParkedOrderActionField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///预埋撤单编号
  TShfeFtdcParkedOrderActionIDType	ParkedOrderActionID;

  bool operator==(const CShfeFtdcRemoveParkedOrderActionField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ParkedOrderActionID, ct.ParkedOrderActionID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///经纪公司可提资金算法表
struct CShfeFtdcInvestorWithdrawAlgorithmField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者范围
  TShfeFtdcInvestorRangeType	InvestorRange;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///可提资金比例
  TShfeFtdcRatioType	UsingRatio;

  bool operator==(const CShfeFtdcInvestorWithdrawAlgorithmField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (InvestorRange == ct.InvestorRange);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(UsingRatio, ct.UsingRatio));
    if (!ret) return ret;

    return ret;
  }
};

///查询组合持仓明细
struct CShfeFtdcQryInvestorPositionCombineDetailField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///组合持仓合约编码
  TShfeFtdcInstrumentIDType	CombInstrumentID;

  bool operator==(const CShfeFtdcQryInvestorPositionCombineDetailField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(CombInstrumentID, ct.CombInstrumentID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///成交均价
struct CShfeFtdcMarketDataAveragePriceField
{
  ///当日均价
  TShfeFtdcPriceType	AveragePrice;

  bool operator==(const CShfeFtdcMarketDataAveragePriceField &ct) const
  {
    bool ret = true;
    ret = ret && (EQUALDOUBLE(AveragePrice, ct.AveragePrice));
    if (!ret) return ret;

    return ret;
  }
};

///校验投资者密码
struct CShfeFtdcVerifyInvestorPasswordField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///密码
  TShfeFtdcPasswordType	Password;

  bool operator==(const CShfeFtdcVerifyInvestorPasswordField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(Password, ct.Password) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///用户IP
struct CShfeFtdcUserIPField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///IP地址
  TShfeFtdcIPAddressType	IPAddress;
  ///IP地址掩码
  TShfeFtdcIPAddressType	IPMask;
  ///Mac地址
  TShfeFtdcMacAddressType	MacAddress;

  bool operator==(const CShfeFtdcUserIPField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(IPAddress, ct.IPAddress) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(IPMask, ct.IPMask) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(MacAddress, ct.MacAddress) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///用户事件通知信息
struct CShfeFtdcTradingNoticeInfoField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///发送时间
  TShfeFtdcTimeType	SendTime;
  ///消息正文
  TShfeFtdcContentType	FieldContent;
  ///序列系列号
  TShfeFtdcSequenceSeriesType	SequenceSeries;
  ///序列号
  TShfeFtdcSequenceNoType	SequenceNo;

  bool operator==(const CShfeFtdcTradingNoticeInfoField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(SendTime, ct.SendTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(FieldContent, ct.FieldContent) == 0);
    if (!ret) return ret;
    ret = ret && (SequenceSeries == ct.SequenceSeries);
    if (!ret) return ret;
    ret = ret && (SequenceNo == ct.SequenceNo);
    if (!ret) return ret;

    return ret;
  }
};

///用户事件通知
struct CShfeFtdcTradingNoticeField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者范围
  TShfeFtdcInvestorRangeType	InvestorRange;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///序列系列号
  TShfeFtdcSequenceSeriesType	SequenceSeries;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///发送时间
  TShfeFtdcTimeType	SendTime;
  ///序列号
  TShfeFtdcSequenceNoType	SequenceNo;
  ///消息正文
  TShfeFtdcContentType	FieldContent;

  bool operator==(const CShfeFtdcTradingNoticeField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (InvestorRange == ct.InvestorRange);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (SequenceSeries == ct.SequenceSeries);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(SendTime, ct.SendTime) == 0);
    if (!ret) return ret;
    ret = ret && (SequenceNo == ct.SequenceNo);
    if (!ret) return ret;
    ret = ret && (strcmp(FieldContent, ct.FieldContent) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询交易事件通知
struct CShfeFtdcQryTradingNoticeField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;

  bool operator==(const CShfeFtdcQryTradingNoticeField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询错误报单
struct CShfeFtdcQryErrOrderField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;

  bool operator==(const CShfeFtdcQryErrOrderField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///错误报单
struct CShfeFtdcErrOrderField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///报单引用
  TShfeFtdcOrderRefType	OrderRef;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///报单价格条件
  TShfeFtdcOrderPriceTypeType	OrderPriceType;
  ///买卖方向
  TShfeFtdcDirectionType	Direction;
  ///组合开平标志
  TShfeFtdcCombOffsetFlagType	CombOffsetFlag;
  ///组合投机套保标志
  TShfeFtdcCombHedgeFlagType	CombHedgeFlag;
  ///价格
  TShfeFtdcPriceType	LimitPrice;
  ///数量
  TShfeFtdcVolumeType	VolumeTotalOriginal;
  ///有效期类型
  TShfeFtdcTimeConditionType	TimeCondition;
  ///GTD日期
  TShfeFtdcDateType	GTDDate;
  ///成交量类型
  TShfeFtdcVolumeConditionType	VolumeCondition;
  ///最小成交量
  TShfeFtdcVolumeType	MinVolume;
  ///触发条件
  TShfeFtdcContingentConditionType	ContingentCondition;
  ///止损价
  TShfeFtdcPriceType	StopPrice;
  ///强平原因
  TShfeFtdcForceCloseReasonType	ForceCloseReason;
  ///自动挂起标志
  TShfeFtdcBoolType	IsAutoSuspend;
  ///业务单元
  TShfeFtdcBusinessUnitType	BusinessUnit;
  ///请求编号
  TShfeFtdcRequestIDType	RequestID;
  ///用户强评标志
  TShfeFtdcBoolType	UserForceClose;
  ///错误代码
  TShfeFtdcErrorIDType	ErrorID;
  ///错误信息
  TShfeFtdcErrorMsgType	ErrorMsg;

  bool operator==(const CShfeFtdcErrOrderField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderRef, ct.OrderRef) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (OrderPriceType == ct.OrderPriceType);
    if (!ret) return ret;
    ret = ret && (Direction == ct.Direction);
    if (!ret) return ret;
    for (int i = 0; i < 4; ++i) {
      ret = ret && (CombOffsetFlag[i] == ct.CombOffsetFlag[i]);
      if (!ret) return ret;
    }
    for (int i = 0; i < 4; ++i) {
      ret = ret && (CombHedgeFlag[i] == ct.CombHedgeFlag[i]);
      if (!ret) return ret;
    }
    ret = ret && (EQUALDOUBLE(LimitPrice, ct.LimitPrice));
    if (!ret) return ret;
    ret = ret && (VolumeTotalOriginal == ct.VolumeTotalOriginal);
    if (!ret) return ret;
    ret = ret && (TimeCondition == ct.TimeCondition);
    if (!ret) return ret;
    ret = ret && (strcmp(GTDDate, ct.GTDDate) == 0);
    if (!ret) return ret;
    ret = ret && (VolumeCondition == ct.VolumeCondition);
    if (!ret) return ret;
    ret = ret && (MinVolume == ct.MinVolume);
    if (!ret) return ret;
    ret = ret && (ContingentCondition == ct.ContingentCondition);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(StopPrice, ct.StopPrice));
    if (!ret) return ret;
    ret = ret && (ForceCloseReason == ct.ForceCloseReason);
    if (!ret) return ret;
    ret = ret && (IsAutoSuspend == ct.IsAutoSuspend);
    if (!ret) return ret;
    ret = ret && (strcmp(BusinessUnit, ct.BusinessUnit) == 0);
    if (!ret) return ret;
    ret = ret && (RequestID == ct.RequestID);
    if (!ret) return ret;
    ret = ret && (UserForceClose == ct.UserForceClose);
    if (!ret) return ret;
    ret = ret && (ErrorID == ct.ErrorID);
    if (!ret) return ret;
    ret = ret && (strcmp(ErrorMsg, ct.ErrorMsg) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询错误报单操作
struct CShfeFtdcQryErrOrderActionField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;

  bool operator==(const CShfeFtdcQryErrOrderActionField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///错误报单操作
struct CShfeFtdcErrOrderActionField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///报单操作引用
  TShfeFtdcOrderActionRefType	OrderActionRef;
  ///报单引用
  TShfeFtdcOrderRefType	OrderRef;
  ///请求编号
  TShfeFtdcRequestIDType	RequestID;
  ///前置编号
  TShfeFtdcFrontIDType	FrontID;
  ///会话编号
  TShfeFtdcSessionIDType	SessionID;
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///报单编号
  TShfeFtdcOrderSysIDType	OrderSysID;
  ///操作标志
  TShfeFtdcActionFlagType	ActionFlag;
  ///价格
  TShfeFtdcPriceType	LimitPrice;
  ///数量变化
  TShfeFtdcVolumeType	VolumeChange;
  ///操作日期
  TShfeFtdcDateType	ActionDate;
  ///操作时间
  TShfeFtdcTimeType	ActionTime;
  ///交易所交易员代码
  TShfeFtdcTraderIDType	TraderID;
  ///安装编号
  TShfeFtdcInstallIDType	InstallID;
  ///本地报单编号
  TShfeFtdcOrderLocalIDType	OrderLocalID;
  ///操作本地编号
  TShfeFtdcOrderLocalIDType	ActionLocalID;
  ///会员代码
  TShfeFtdcParticipantIDType	ParticipantID;
  ///客户代码
  TShfeFtdcClientIDType	ClientID;
  ///业务单元
  TShfeFtdcBusinessUnitType	BusinessUnit;
  ///报单操作状态
  TShfeFtdcOrderActionStatusType	OrderActionStatus;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///状态信息
  TShfeFtdcErrorMsgType	StatusMsg;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///错误代码
  TShfeFtdcErrorIDType	ErrorID;
  ///错误信息
  TShfeFtdcErrorMsgType	ErrorMsg;

  bool operator==(const CShfeFtdcErrOrderActionField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (OrderActionRef == ct.OrderActionRef);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderRef, ct.OrderRef) == 0);
    if (!ret) return ret;
    ret = ret && (RequestID == ct.RequestID);
    if (!ret) return ret;
    ret = ret && (FrontID == ct.FrontID);
    if (!ret) return ret;
    ret = ret && (SessionID == ct.SessionID);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderSysID, ct.OrderSysID) == 0);
    if (!ret) return ret;
    ret = ret && (ActionFlag == ct.ActionFlag);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(LimitPrice, ct.LimitPrice));
    if (!ret) return ret;
    ret = ret && (VolumeChange == ct.VolumeChange);
    if (!ret) return ret;
    ret = ret && (strcmp(ActionDate, ct.ActionDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ActionTime, ct.ActionTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TraderID, ct.TraderID) == 0);
    if (!ret) return ret;
    ret = ret && (InstallID == ct.InstallID);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderLocalID, ct.OrderLocalID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ActionLocalID, ct.ActionLocalID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ParticipantID, ct.ParticipantID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ClientID, ct.ClientID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BusinessUnit, ct.BusinessUnit) == 0);
    if (!ret) return ret;
    ret = ret && (OrderActionStatus == ct.OrderActionStatus);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(StatusMsg, ct.StatusMsg) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (ErrorID == ct.ErrorID);
    if (!ret) return ret;
    ret = ret && (strcmp(ErrorMsg, ct.ErrorMsg) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///投资者信息摘要
struct CShfeFtdcInvestorSumInfoField
{
  ///投资者人数
  TShfeFtdcVolumeType	Count;
  ///MD5校验码1
  TShfeFtdcMD5Type	md5_1;
  ///MD5校验码2
  TShfeFtdcMD5Type	md5_2;
  ///MD5校验码3
  TShfeFtdcMD5Type	md5_3;
  ///MD5校验码4
  TShfeFtdcMD5Type	md5_4;
  ///MD5校验码5
  TShfeFtdcMD5Type	md5_5;
  ///MD5校验码6
  TShfeFtdcMD5Type	md5_6;
  ///MD5校验码7
  TShfeFtdcMD5Type	md5_7;
  ///MD5校验码8
  TShfeFtdcMD5Type	md5_8;
  ///MD5校验码9
  TShfeFtdcMD5Type	md5_9;
  ///MD5校验码10
  TShfeFtdcMD5Type	md5_10;
  ///MD5校验码11
  TShfeFtdcMD5Type	md5_11;
  ///MD5校验码12
  TShfeFtdcMD5Type	md5_12;
  ///MD5校验码13
  TShfeFtdcMD5Type	md5_13;
  ///MD5校验码14
  TShfeFtdcMD5Type	md5_14;
  ///MD5校验码15
  TShfeFtdcMD5Type	md5_15;
  ///MD5校验码16
  TShfeFtdcMD5Type	md5_16;

  bool operator==(const CShfeFtdcInvestorSumInfoField &ct) const
  {
    bool ret = true;
    ret = ret && (Count == ct.Count);
    if (!ret) return ret;
    ret = ret && (md5_1 == ct.md5_1);
    if (!ret) return ret;
    ret = ret && (md5_2 == ct.md5_2);
    if (!ret) return ret;
    ret = ret && (md5_3 == ct.md5_3);
    if (!ret) return ret;
    ret = ret && (md5_4 == ct.md5_4);
    if (!ret) return ret;
    ret = ret && (md5_5 == ct.md5_5);
    if (!ret) return ret;
    ret = ret && (md5_6 == ct.md5_6);
    if (!ret) return ret;
    ret = ret && (md5_7 == ct.md5_7);
    if (!ret) return ret;
    ret = ret && (md5_8 == ct.md5_8);
    if (!ret) return ret;
    ret = ret && (md5_9 == ct.md5_9);
    if (!ret) return ret;
    ret = ret && (md5_10 == ct.md5_10);
    if (!ret) return ret;
    ret = ret && (md5_11 == ct.md5_11);
    if (!ret) return ret;
    ret = ret && (md5_12 == ct.md5_12);
    if (!ret) return ret;
    ret = ret && (md5_13 == ct.md5_13);
    if (!ret) return ret;
    ret = ret && (md5_14 == ct.md5_14);
    if (!ret) return ret;
    ret = ret && (md5_15 == ct.md5_15);
    if (!ret) return ret;
    ret = ret && (md5_16 == ct.md5_16);
    if (!ret) return ret;

    return ret;
  }
};

///结算会话
struct CShfeFtdcSettlementSessionField
{
  ///交易日
  TShfeFtdcDateType	TradingDay;
  ///结算编号
  TShfeFtdcSettlementIDType	SettlementID;

  bool operator==(const CShfeFtdcSettlementSessionField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(TradingDay, ct.TradingDay) == 0);
    if (!ret) return ret;
    ret = ret && (SettlementID == ct.SettlementID);
    if (!ret) return ret;

    return ret;
  }
};

///用户登录请求
struct CShfeFtdcReqRiskUserLoginField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///密码
  TShfeFtdcPasswordType	Password;
  ///客户端版本,20091230版Version=1,之前版本Version=0
  TShfeFtdcVolumeType	Version;
  ///本地前置中客户端连接的SessionID
  TShfeFtdcSessionIDType	LocalSessionID;

  bool operator==(const CShfeFtdcReqRiskUserLoginField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(Password, ct.Password) == 0);
    if (!ret) return ret;
    ret = ret && (Version == ct.Version);
    if (!ret) return ret;
    ret = ret && (LocalSessionID == ct.LocalSessionID);
    if (!ret) return ret;

    return ret;
  }
};

///用户登录应答
struct CShfeFtdcRspRiskUserLoginField
{
  ///交易日
  TShfeFtdcDateType	TradingDay;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///客户端版本,20091230版Version=1,之前版本Version=0
  TShfeFtdcVolumeType	Version;
  ///前置类型
  TShfeFtdcFrontTypeType	FrontType;

  bool operator==(const CShfeFtdcRspRiskUserLoginField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(TradingDay, ct.TradingDay) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (Version == ct.Version);
    if (!ret) return ret;
    ret = ret && (FrontType == ct.FrontType);
    if (!ret) return ret;

    return ret;
  }
};

///特定范围投资者信息摘要请求
struct CShfeFtdcInvestorRangeSumInfoField
{
  ///投资者起始下标
  TShfeFtdcVolumeType	startindex;
  ///投资者结束下标
  TShfeFtdcVolumeType	endindex;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;

  bool operator==(const CShfeFtdcInvestorRangeSumInfoField &ct) const
  {
    bool ret = true;
    ret = ret && (startindex == ct.startindex);
    if (!ret) return ret;
    ret = ret && (endindex == ct.endindex);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///投资者资金查询请求
struct CShfeFtdcReqInvestorAccountField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///起始交易日期
  TShfeFtdcDateType	TradingDayStart;
  ///结束交易日期
  TShfeFtdcDateType	TradingDayEnd;
  ///起始投资者代码
  TShfeFtdcInvestorIDType	InvestorIDStart;
  ///结束投资者代码
  TShfeFtdcInvestorIDType	InvestorIDEnd;
  ///资金排序方法
  TShfeFtdcAccountSortTypeType	SortType;
  ///按排名数返回结果
  TShfeFtdcVolumeType	ResultCount;
  ///按比例返回结果
  TShfeFtdcRatioType	ResultRatio;

  bool operator==(const CShfeFtdcReqInvestorAccountField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TradingDayStart, ct.TradingDayStart) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TradingDayEnd, ct.TradingDayEnd) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorIDStart, ct.InvestorIDStart) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorIDEnd, ct.InvestorIDEnd) == 0);
    if (!ret) return ret;
    ret = ret && (SortType == ct.SortType);
    if (!ret) return ret;
    ret = ret && (ResultCount == ct.ResultCount);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ResultRatio, ct.ResultRatio));
    if (!ret) return ret;

    return ret;
  }
};

///投资者资金查询响应
struct CShfeFtdcInvestorRiskAccountField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///投资者帐号
  TShfeFtdcAccountIDType	AccountID;
  ///上次质押金额
  TShfeFtdcMoneyType	PreMortgage;
  ///上次信用额度
  TShfeFtdcMoneyType	PreCredit;
  ///上次存款额
  TShfeFtdcMoneyType	PreDeposit;
  ///上次总权益
  TShfeFtdcMoneyType	PreBalance;
  ///上次占用的保证金
  TShfeFtdcMoneyType	PreMargin;
  ///出入金金额
  TShfeFtdcMoneyType	Withdraw;
  ///当前保证金总额
  TShfeFtdcMoneyType	CurrMargin;
  ///手续费
  TShfeFtdcMoneyType	Commission;
  ///平仓盈亏
  TShfeFtdcMoneyType	CloseProfit;
  ///持仓盈亏
  TShfeFtdcMoneyType	PositionProfit;
  ///总权益
  TShfeFtdcMoneyType	Balance;
  ///可用资金
  TShfeFtdcMoneyType	Available;
  ///质押金额
  TShfeFtdcMoneyType	Mortgage;
  ///交易所保证金
  TShfeFtdcMoneyType	ExchangeMargin;
  ///基本准备金
  TShfeFtdcMoneyType	Reserve;
  ///可取资金
  TShfeFtdcMoneyType	WithdrawQuota;
  ///信用额度
  TShfeFtdcMoneyType	Credit;
  ///上次交易所保证金
  TShfeFtdcMoneyType	PreExchMargin;
  ///历史强平次数
  TShfeFtdcVolumeType	ForceCloseStat;
  ///投资者交割保证金
  TShfeFtdcMoneyType	DeliveryMargin;
  ///交易所交割保证金
  TShfeFtdcMoneyType	ExchangeDeliveryMargin;
  ///保证金冻结
  TShfeFtdcMoneyType	FrozenMargin;
  ///手续费冻结
  TShfeFtdcMoneyType	FrozenCommission;

  bool operator==(const CShfeFtdcInvestorRiskAccountField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(AccountID, ct.AccountID) == 0);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreMortgage, ct.PreMortgage));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreCredit, ct.PreCredit));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreDeposit, ct.PreDeposit));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreBalance, ct.PreBalance));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreMargin, ct.PreMargin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Withdraw, ct.Withdraw));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CurrMargin, ct.CurrMargin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Commission, ct.Commission));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CloseProfit, ct.CloseProfit));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PositionProfit, ct.PositionProfit));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Balance, ct.Balance));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Available, ct.Available));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Mortgage, ct.Mortgage));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ExchangeMargin, ct.ExchangeMargin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Reserve, ct.Reserve));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(WithdrawQuota, ct.WithdrawQuota));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Credit, ct.Credit));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreExchMargin, ct.PreExchMargin));
    if (!ret) return ret;
    ret = ret && (ForceCloseStat == ct.ForceCloseStat);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(DeliveryMargin, ct.DeliveryMargin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ExchangeDeliveryMargin, ct.ExchangeDeliveryMargin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(FrozenMargin, ct.FrozenMargin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(FrozenCommission, ct.FrozenCommission));
    if (!ret) return ret;

    return ret;
  }
};

///投资者持仓查询请求
struct CShfeFtdcReqInvestorPositionField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///起始交易日期
  TShfeFtdcDateType	TradingDayStart;
  ///结束交易日期
  TShfeFtdcDateType	TradingDayEnd;
  ///起始投资者代码
  TShfeFtdcInvestorIDType	InvestorIDStart;
  ///结束投资者代码
  TShfeFtdcInvestorIDType	InvestorIDEnd;
  ///起始合约代码
  TShfeFtdcInstrumentIDType	InstIDStart;
  ///结束合约代码
  TShfeFtdcInstrumentIDType	InstIDEnd;
  ///起始产品代码
  TShfeFtdcInstrumentIDType	ProductIDStart;
  ///结束产品代码
  TShfeFtdcInstrumentIDType	ProductIDEnd;
  ///持仓排序方法
  TShfeFtdcPositionSortTypeType	SortType;
  ///按排名数返回结果
  TShfeFtdcVolumeType	ResultCount;
  ///按比例返回结果
  TShfeFtdcRatioType	ResultRatio;

  bool operator==(const CShfeFtdcReqInvestorPositionField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TradingDayStart, ct.TradingDayStart) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TradingDayEnd, ct.TradingDayEnd) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorIDStart, ct.InvestorIDStart) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorIDEnd, ct.InvestorIDEnd) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstIDStart, ct.InstIDStart) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstIDEnd, ct.InstIDEnd) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ProductIDStart, ct.ProductIDStart) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ProductIDEnd, ct.ProductIDEnd) == 0);
    if (!ret) return ret;
    ret = ret && (SortType == ct.SortType);
    if (!ret) return ret;
    ret = ret && (ResultCount == ct.ResultCount);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ResultRatio, ct.ResultRatio));
    if (!ret) return ret;

    return ret;
  }
};

///投资者持仓查询响应
struct CShfeFtdcRspInvestorPositionField
{
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///持仓多空方向
  TShfeFtdcPosiDirectionType	PosiDirection;
  ///投机套保标志
  TShfeFtdcHedgeFlagType	HedgeFlag;
  ///持仓日期
  TShfeFtdcPositionDateType	PositionDate;
  ///上日持仓
  TShfeFtdcVolumeType	YdPosition;
  ///今日持仓
  TShfeFtdcVolumeType	Position;
  ///多头冻结
  TShfeFtdcVolumeType	LongFrozen;
  ///空头冻结
  TShfeFtdcVolumeType	ShortFrozen;
  ///开仓冻结金额
  TShfeFtdcMoneyType	LongFrozenAmount;
  ///开仓冻结金额
  TShfeFtdcMoneyType	ShortFrozenAmount;
  ///开仓量
  TShfeFtdcVolumeType	OpenVolume;
  ///平仓量
  TShfeFtdcVolumeType	CloseVolume;
  ///开仓金额
  TShfeFtdcMoneyType	OpenAmount;
  ///平仓金额
  TShfeFtdcMoneyType	CloseAmount;
  ///持仓成本
  TShfeFtdcMoneyType	PositionCost;
  ///上次占用的保证金
  TShfeFtdcMoneyType	PreMargin;
  ///占用的保证金
  TShfeFtdcMoneyType	UseMargin;
  ///冻结的保证金
  TShfeFtdcMoneyType	FrozenMargin;
  ///冻结的资金
  TShfeFtdcMoneyType	FrozenCash;
  ///冻结的手续费
  TShfeFtdcMoneyType	FrozenCommission;
  ///资金差额
  TShfeFtdcMoneyType	CashIn;
  ///手续费
  TShfeFtdcMoneyType	Commission;
  ///平仓盈亏
  TShfeFtdcMoneyType	CloseProfit;
  ///持仓盈亏
  TShfeFtdcMoneyType	PositionProfit;
  ///上次结算价
  TShfeFtdcPriceType	PreSettlementPrice;
  ///本次结算价
  TShfeFtdcPriceType	SettlementPrice;
  ///交易日
  TShfeFtdcDateType	TradingDay;
  ///结算编号
  TShfeFtdcSettlementIDType	SettlementID;
  ///开仓成本
  TShfeFtdcMoneyType	OpenCost;
  ///交易所保证金
  TShfeFtdcMoneyType	ExchangeMargin;
  ///组合成交形成的持仓
  TShfeFtdcVolumeType	CombPosition;
  ///组合多头冻结
  TShfeFtdcVolumeType	CombLongFrozen;
  ///组合空头冻结
  TShfeFtdcVolumeType	CombShortFrozen;
  ///逐日盯市平仓盈亏
  TShfeFtdcMoneyType	CloseProfitByDate;
  ///逐笔对冲平仓盈亏
  TShfeFtdcMoneyType	CloseProfitByTrade;
  ///今日持仓
  TShfeFtdcVolumeType	TodayPosition;
  ///保证金率
  TShfeFtdcRatioType	MarginRateByMoney;
  ///保证金率(按手数)
  TShfeFtdcRatioType	MarginRateByVolume;

  bool operator==(const CShfeFtdcRspInvestorPositionField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (PosiDirection == ct.PosiDirection);
    if (!ret) return ret;
    ret = ret && (HedgeFlag == ct.HedgeFlag);
    if (!ret) return ret;
    ret = ret && (PositionDate == ct.PositionDate);
    if (!ret) return ret;
    ret = ret && (YdPosition == ct.YdPosition);
    if (!ret) return ret;
    ret = ret && (Position == ct.Position);
    if (!ret) return ret;
    ret = ret && (LongFrozen == ct.LongFrozen);
    if (!ret) return ret;
    ret = ret && (ShortFrozen == ct.ShortFrozen);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(LongFrozenAmount, ct.LongFrozenAmount));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ShortFrozenAmount, ct.ShortFrozenAmount));
    if (!ret) return ret;
    ret = ret && (OpenVolume == ct.OpenVolume);
    if (!ret) return ret;
    ret = ret && (CloseVolume == ct.CloseVolume);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(OpenAmount, ct.OpenAmount));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CloseAmount, ct.CloseAmount));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PositionCost, ct.PositionCost));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreMargin, ct.PreMargin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(UseMargin, ct.UseMargin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(FrozenMargin, ct.FrozenMargin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(FrozenCash, ct.FrozenCash));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(FrozenCommission, ct.FrozenCommission));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CashIn, ct.CashIn));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Commission, ct.Commission));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CloseProfit, ct.CloseProfit));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PositionProfit, ct.PositionProfit));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreSettlementPrice, ct.PreSettlementPrice));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(SettlementPrice, ct.SettlementPrice));
    if (!ret) return ret;
    ret = ret && (strcmp(TradingDay, ct.TradingDay) == 0);
    if (!ret) return ret;
    ret = ret && (SettlementID == ct.SettlementID);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(OpenCost, ct.OpenCost));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ExchangeMargin, ct.ExchangeMargin));
    if (!ret) return ret;
    ret = ret && (CombPosition == ct.CombPosition);
    if (!ret) return ret;
    ret = ret && (CombLongFrozen == ct.CombLongFrozen);
    if (!ret) return ret;
    ret = ret && (CombShortFrozen == ct.CombShortFrozen);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CloseProfitByDate, ct.CloseProfitByDate));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CloseProfitByTrade, ct.CloseProfitByTrade));
    if (!ret) return ret;
    ret = ret && (TodayPosition == ct.TodayPosition);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(MarginRateByMoney, ct.MarginRateByMoney));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(MarginRateByVolume, ct.MarginRateByVolume));
    if (!ret) return ret;

    return ret;
  }
};

///投资者交易查询请求
struct CShfeFtdcReqInvestorTradeField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///起始交易日期
  TShfeFtdcDateType	TradingDayStart;
  ///结束交易日期
  TShfeFtdcDateType	TradingDayEnd;
  ///起始投资者代码
  TShfeFtdcInvestorIDType	InvestorIDStart;
  ///结束投资者代码
  TShfeFtdcInvestorIDType	InvestorIDEnd;
  ///起始合约代码
  TShfeFtdcInstrumentIDType	InstIDStart;
  ///结束合约代码
  TShfeFtdcInstrumentIDType	InstIDEnd;
  ///起始产品代码
  TShfeFtdcInstrumentIDType	ProductIDStart;
  ///结束产品代码
  TShfeFtdcInstrumentIDType	ProductIDEnd;
  ///交易排序方法
  TShfeFtdcTradeSortTypeType	SortType;
  ///按排名数返回结果
  TShfeFtdcVolumeType	ResultCount;
  ///按比例返回结果
  TShfeFtdcRatioType	ResultRatio;

  bool operator==(const CShfeFtdcReqInvestorTradeField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TradingDayStart, ct.TradingDayStart) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TradingDayEnd, ct.TradingDayEnd) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorIDStart, ct.InvestorIDStart) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorIDEnd, ct.InvestorIDEnd) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstIDStart, ct.InstIDStart) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstIDEnd, ct.InstIDEnd) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ProductIDStart, ct.ProductIDStart) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ProductIDEnd, ct.ProductIDEnd) == 0);
    if (!ret) return ret;
    ret = ret && (SortType == ct.SortType);
    if (!ret) return ret;
    ret = ret && (ResultCount == ct.ResultCount);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ResultRatio, ct.ResultRatio));
    if (!ret) return ret;

    return ret;
  }
};

///投资者交易查询响应
struct CShfeFtdcRspInvestorTradeField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///报单引用
  TShfeFtdcOrderRefType	OrderRef;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///成交编号
  TShfeFtdcTradeIDType	TradeID;
  ///买卖方向
  TShfeFtdcDirectionType	Direction;
  ///报单编号
  TShfeFtdcOrderSysIDType	OrderSysID;
  ///会员代码
  TShfeFtdcParticipantIDType	ParticipantID;
  ///客户代码
  TShfeFtdcClientIDType	ClientID;
  ///交易角色
  TShfeFtdcTradingRoleType	TradingRole;
  ///合约在交易所的代码
  TShfeFtdcExchangeInstIDType	ExchangeInstID;
  ///开平标志
  TShfeFtdcOffsetFlagType	OffsetFlag;
  ///投机套保标志
  TShfeFtdcHedgeFlagType	HedgeFlag;
  ///价格
  TShfeFtdcPriceType	Price;
  ///数量
  TShfeFtdcVolumeType	Volume;
  ///成交时期
  TShfeFtdcDateType	TradeDate;
  ///成交时间
  TShfeFtdcTimeType	TradeTime;
  ///成交类型
  TShfeFtdcTradeTypeType	TradeType;
  ///成交价来源
  TShfeFtdcPriceSourceType	PriceSource;
  ///交易所交易员代码
  TShfeFtdcTraderIDType	TraderID;
  ///本地报单编号
  TShfeFtdcOrderLocalIDType	OrderLocalID;
  ///结算会员编号
  TShfeFtdcParticipantIDType	ClearingPartID;
  ///业务单元
  TShfeFtdcBusinessUnitType	BusinessUnit;
  ///序号
  TShfeFtdcSequenceNoType	SequenceNo;
  ///交易日
  TShfeFtdcDateType	TradingDay;
  ///结算编号
  TShfeFtdcSettlementIDType	SettlementID;
  ///经纪公司报单编号
  TShfeFtdcSequenceNoType	BrokerOrderSeq;
  ///成交来源
  TShfeFtdcTradeSourceType	TradeSource;

  bool operator==(const CShfeFtdcRspInvestorTradeField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderRef, ct.OrderRef) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TradeID, ct.TradeID) == 0);
    if (!ret) return ret;
    ret = ret && (Direction == ct.Direction);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderSysID, ct.OrderSysID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ParticipantID, ct.ParticipantID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ClientID, ct.ClientID) == 0);
    if (!ret) return ret;
    ret = ret && (TradingRole == ct.TradingRole);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeInstID, ct.ExchangeInstID) == 0);
    if (!ret) return ret;
    ret = ret && (OffsetFlag == ct.OffsetFlag);
    if (!ret) return ret;
    ret = ret && (HedgeFlag == ct.HedgeFlag);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Price, ct.Price));
    if (!ret) return ret;
    ret = ret && (Volume == ct.Volume);
    if (!ret) return ret;
    ret = ret && (strcmp(TradeDate, ct.TradeDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TradeTime, ct.TradeTime) == 0);
    if (!ret) return ret;
    ret = ret && (TradeType == ct.TradeType);
    if (!ret) return ret;
    ret = ret && (PriceSource == ct.PriceSource);
    if (!ret) return ret;
    ret = ret && (strcmp(TraderID, ct.TraderID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderLocalID, ct.OrderLocalID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ClearingPartID, ct.ClearingPartID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BusinessUnit, ct.BusinessUnit) == 0);
    if (!ret) return ret;
    ret = ret && (SequenceNo == ct.SequenceNo);
    if (!ret) return ret;
    ret = ret && (strcmp(TradingDay, ct.TradingDay) == 0);
    if (!ret) return ret;
    ret = ret && (SettlementID == ct.SettlementID);
    if (!ret) return ret;
    ret = ret && (BrokerOrderSeq == ct.BrokerOrderSeq);
    if (!ret) return ret;
    ret = ret && (TradeSource == ct.TradeSource);
    if (!ret) return ret;

    return ret;
  }
};

///投资者报单查询请求
struct CShfeFtdcReqInvestorOrderField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///交易日期
  TShfeFtdcDateType	TradingDay;
  ///起始投资者代码
  TShfeFtdcInvestorIDType	InvestorIDStart;
  ///结束投资者代码
  TShfeFtdcInvestorIDType	InvestorIDEnd;
  ///起始合约代码
  TShfeFtdcInstrumentIDType	InstIDStart;
  ///结束合约代码
  TShfeFtdcInstrumentIDType	InstIDEnd;
  ///起始产品代码
  TShfeFtdcInstrumentIDType	ProductIDStart;
  ///结束产品代码
  TShfeFtdcInstrumentIDType	ProductIDEnd;

  bool operator==(const CShfeFtdcReqInvestorOrderField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TradingDay, ct.TradingDay) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorIDStart, ct.InvestorIDStart) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorIDEnd, ct.InvestorIDEnd) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstIDStart, ct.InstIDStart) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstIDEnd, ct.InstIDEnd) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ProductIDStart, ct.ProductIDStart) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ProductIDEnd, ct.ProductIDEnd) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///投资者报单查询响应
struct CShfeFtdcRspInvestorOrderField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///报单引用
  TShfeFtdcOrderRefType	OrderRef;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///报单价格条件
  TShfeFtdcOrderPriceTypeType	OrderPriceType;
  ///买卖方向
  TShfeFtdcDirectionType	Direction;
  ///组合开平标志
  TShfeFtdcCombOffsetFlagType	CombOffsetFlag;
  ///组合投机套保标志
  TShfeFtdcCombHedgeFlagType	CombHedgeFlag;
  ///价格
  TShfeFtdcPriceType	LimitPrice;
  ///数量
  TShfeFtdcVolumeType	VolumeTotalOriginal;
  ///有效期类型
  TShfeFtdcTimeConditionType	TimeCondition;
  ///GTD日期
  TShfeFtdcDateType	GTDDate;
  ///成交量类型
  TShfeFtdcVolumeConditionType	VolumeCondition;
  ///最小成交量
  TShfeFtdcVolumeType	MinVolume;
  ///触发条件
  TShfeFtdcContingentConditionType	ContingentCondition;
  ///止损价
  TShfeFtdcPriceType	StopPrice;
  ///强平原因
  TShfeFtdcForceCloseReasonType	ForceCloseReason;
  ///自动挂起标志
  TShfeFtdcBoolType	IsAutoSuspend;
  ///业务单元
  TShfeFtdcBusinessUnitType	BusinessUnit;
  ///请求编号
  TShfeFtdcRequestIDType	RequestID;
  ///本地报单编号
  TShfeFtdcOrderLocalIDType	OrderLocalID;
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///会员代码
  TShfeFtdcParticipantIDType	ParticipantID;
  ///客户代码
  TShfeFtdcClientIDType	ClientID;
  ///合约在交易所的代码
  TShfeFtdcExchangeInstIDType	ExchangeInstID;
  ///交易所交易员代码
  TShfeFtdcTraderIDType	TraderID;
  ///安装编号
  TShfeFtdcInstallIDType	InstallID;
  ///报单提交状态
  TShfeFtdcOrderSubmitStatusType	OrderSubmitStatus;
  ///报单提示序号
  TShfeFtdcSequenceNoType	NotifySequence;
  ///交易日
  TShfeFtdcDateType	TradingDay;
  ///结算编号
  TShfeFtdcSettlementIDType	SettlementID;
  ///报单编号
  TShfeFtdcOrderSysIDType	OrderSysID;
  ///报单来源
  TShfeFtdcOrderSourceType	OrderSource;
  ///报单状态
  TShfeFtdcOrderStatusType	OrderStatus;
  ///报单类型
  TShfeFtdcOrderTypeType	OrderType;
  ///今成交数量
  TShfeFtdcVolumeType	VolumeTraded;
  ///剩余数量
  TShfeFtdcVolumeType	VolumeTotal;
  ///报单日期
  TShfeFtdcDateType	InsertDate;
  ///委托时间
  TShfeFtdcTimeType	InsertTime;
  ///激活时间
  TShfeFtdcTimeType	ActiveTime;
  ///挂起时间
  TShfeFtdcTimeType	SuspendTime;
  ///最后修改时间
  TShfeFtdcTimeType	UpdateTime;
  ///撤销时间
  TShfeFtdcTimeType	CancelTime;
  ///最后修改交易所交易员代码
  TShfeFtdcTraderIDType	ActiveTraderID;
  ///结算会员编号
  TShfeFtdcParticipantIDType	ClearingPartID;
  ///序号
  TShfeFtdcSequenceNoType	SequenceNo;
  ///前置编号
  TShfeFtdcFrontIDType	FrontID;
  ///会话编号
  TShfeFtdcSessionIDType	SessionID;
  ///用户端产品信息
  TShfeFtdcProductInfoType	UserProductInfo;
  ///状态信息
  TShfeFtdcErrorMsgType	StatusMsg;
  ///用户强评标志
  TShfeFtdcBoolType	UserForceClose;
  ///操作用户代码
  TShfeFtdcUserIDType	ActiveUserID;
  ///经纪公司报单编号
  TShfeFtdcSequenceNoType	BrokerOrderSeq;
  ///相关报单
  TShfeFtdcOrderSysIDType	RelativeOrderSysID;
  ///郑商所成交数量
  TShfeFtdcVolumeType	ZCETotalTradedVolume;

  bool operator==(const CShfeFtdcRspInvestorOrderField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderRef, ct.OrderRef) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (OrderPriceType == ct.OrderPriceType);
    if (!ret) return ret;
    ret = ret && (Direction == ct.Direction);
    if (!ret) return ret;
    for (int i = 0; i < 4; ++i) {
      ret = ret && (CombOffsetFlag[i] == ct.CombOffsetFlag[i]);
      if (!ret) return ret;
    }
    for (int i = 0; i < 4; ++i) {
      ret = ret && (CombHedgeFlag[i] == ct.CombHedgeFlag[i]);
      if (!ret) return ret;
    }
    ret = ret && (EQUALDOUBLE(LimitPrice, ct.LimitPrice));
    if (!ret) return ret;
    ret = ret && (VolumeTotalOriginal == ct.VolumeTotalOriginal);
    if (!ret) return ret;
    ret = ret && (TimeCondition == ct.TimeCondition);
    if (!ret) return ret;
    ret = ret && (strcmp(GTDDate, ct.GTDDate) == 0);
    if (!ret) return ret;
    ret = ret && (VolumeCondition == ct.VolumeCondition);
    if (!ret) return ret;
    ret = ret && (MinVolume == ct.MinVolume);
    if (!ret) return ret;
    ret = ret && (ContingentCondition == ct.ContingentCondition);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(StopPrice, ct.StopPrice));
    if (!ret) return ret;
    ret = ret && (ForceCloseReason == ct.ForceCloseReason);
    if (!ret) return ret;
    ret = ret && (IsAutoSuspend == ct.IsAutoSuspend);
    if (!ret) return ret;
    ret = ret && (strcmp(BusinessUnit, ct.BusinessUnit) == 0);
    if (!ret) return ret;
    ret = ret && (RequestID == ct.RequestID);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderLocalID, ct.OrderLocalID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ParticipantID, ct.ParticipantID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ClientID, ct.ClientID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeInstID, ct.ExchangeInstID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TraderID, ct.TraderID) == 0);
    if (!ret) return ret;
    ret = ret && (InstallID == ct.InstallID);
    if (!ret) return ret;
    ret = ret && (OrderSubmitStatus == ct.OrderSubmitStatus);
    if (!ret) return ret;
    ret = ret && (NotifySequence == ct.NotifySequence);
    if (!ret) return ret;
    ret = ret && (strcmp(TradingDay, ct.TradingDay) == 0);
    if (!ret) return ret;
    ret = ret && (SettlementID == ct.SettlementID);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderSysID, ct.OrderSysID) == 0);
    if (!ret) return ret;
    ret = ret && (OrderSource == ct.OrderSource);
    if (!ret) return ret;
    ret = ret && (OrderStatus == ct.OrderStatus);
    if (!ret) return ret;
    ret = ret && (OrderType == ct.OrderType);
    if (!ret) return ret;
    ret = ret && (VolumeTraded == ct.VolumeTraded);
    if (!ret) return ret;
    ret = ret && (VolumeTotal == ct.VolumeTotal);
    if (!ret) return ret;
    ret = ret && (strcmp(InsertDate, ct.InsertDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InsertTime, ct.InsertTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ActiveTime, ct.ActiveTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(SuspendTime, ct.SuspendTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UpdateTime, ct.UpdateTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(CancelTime, ct.CancelTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ActiveTraderID, ct.ActiveTraderID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ClearingPartID, ct.ClearingPartID) == 0);
    if (!ret) return ret;
    ret = ret && (SequenceNo == ct.SequenceNo);
    if (!ret) return ret;
    ret = ret && (FrontID == ct.FrontID);
    if (!ret) return ret;
    ret = ret && (SessionID == ct.SessionID);
    if (!ret) return ret;
    ret = ret && (strcmp(UserProductInfo, ct.UserProductInfo) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(StatusMsg, ct.StatusMsg) == 0);
    if (!ret) return ret;
    ret = ret && (UserForceClose == ct.UserForceClose);
    if (!ret) return ret;
    ret = ret && (strcmp(ActiveUserID, ct.ActiveUserID) == 0);
    if (!ret) return ret;
    ret = ret && (BrokerOrderSeq == ct.BrokerOrderSeq);
    if (!ret) return ret;
    ret = ret && (strcmp(RelativeOrderSysID, ct.RelativeOrderSysID) == 0);
    if (!ret) return ret;
    ret = ret && (ZCETotalTradedVolume == ct.ZCETotalTradedVolume);
    if (!ret) return ret;

    return ret;
  }
};

///投资者持仓统计查询响应
struct CShfeFtdcInvestorPositionStaticField
{
  ///产品代码
  TShfeFtdcInstrumentIDType	ProductID;
  ///合约编号
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///昨持仓
  TShfeFtdcVolumeType	YdPosition;
  ///总持仓
  TShfeFtdcVolumeType	Position;
  ///多头持仓
  TShfeFtdcVolumeType	LongPosition;
  ///空头持仓
  TShfeFtdcVolumeType	ShortPosition;
  ///净持仓
  TShfeFtdcVolumeType	NetPosition;
  ///投机多头持仓
  TShfeFtdcVolumeType	SpecuLongPosi;
  ///投机空头持仓
  TShfeFtdcVolumeType	SpecuShortPosi;
  ///保值多头持仓
  TShfeFtdcVolumeType	HedgeLongPosi;
  ///保值空头持仓
  TShfeFtdcVolumeType	HedgeShortPosi;
  ///今仓
  TShfeFtdcVolumeType	TodayPosition;
  ///总持仓成本
  TShfeFtdcMoneyType	PositionCost;

  bool operator==(const CShfeFtdcInvestorPositionStaticField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(ProductID, ct.ProductID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (YdPosition == ct.YdPosition);
    if (!ret) return ret;
    ret = ret && (Position == ct.Position);
    if (!ret) return ret;
    ret = ret && (LongPosition == ct.LongPosition);
    if (!ret) return ret;
    ret = ret && (ShortPosition == ct.ShortPosition);
    if (!ret) return ret;
    ret = ret && (NetPosition == ct.NetPosition);
    if (!ret) return ret;
    ret = ret && (SpecuLongPosi == ct.SpecuLongPosi);
    if (!ret) return ret;
    ret = ret && (SpecuShortPosi == ct.SpecuShortPosi);
    if (!ret) return ret;
    ret = ret && (HedgeLongPosi == ct.HedgeLongPosi);
    if (!ret) return ret;
    ret = ret && (HedgeShortPosi == ct.HedgeShortPosi);
    if (!ret) return ret;
    ret = ret && (TodayPosition == ct.TodayPosition);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PositionCost, ct.PositionCost));
    if (!ret) return ret;

    return ret;
  }
};

///投资者成交统计查询响应
struct CShfeFtdcInvestorTradeStaticField
{
  ///产品代码
  TShfeFtdcInstrumentIDType	ProductID;
  ///合约编号
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///总成交量
  TShfeFtdcVolumeType	TotalVol;
  ///总成交额
  TShfeFtdcMoneyType	TotalAmt;
  ///买成交量
  TShfeFtdcVolumeType	BuyVol;
  ///买成交额
  TShfeFtdcMoneyType	BuyAmt;
  ///卖成交量
  TShfeFtdcVolumeType	SellVol;
  ///卖成交额
  TShfeFtdcMoneyType	SellAmt;
  ///净买入成交量
  TShfeFtdcVolumeType	NetVol;
  ///净买入成交额
  TShfeFtdcMoneyType	NetAmt;

  bool operator==(const CShfeFtdcInvestorTradeStaticField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(ProductID, ct.ProductID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (TotalVol == ct.TotalVol);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(TotalAmt, ct.TotalAmt));
    if (!ret) return ret;
    ret = ret && (BuyVol == ct.BuyVol);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(BuyAmt, ct.BuyAmt));
    if (!ret) return ret;
    ret = ret && (SellVol == ct.SellVol);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(SellAmt, ct.SellAmt));
    if (!ret) return ret;
    ret = ret && (NetVol == ct.NetVol);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(NetAmt, ct.NetAmt));
    if (!ret) return ret;

    return ret;
  }
};

///订阅实时行情
struct CShfeFtdcSubMarketDataField
{
  ///合约编号
  TShfeFtdcInstrumentIDType	InstrumentID;

  bool operator==(const CShfeFtdcSubMarketDataField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///合约持仓比例查询
struct CShfeFtdcQryInstPositionRateField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///起始合约代码
  TShfeFtdcInstrumentIDType	InstIDStart;
  ///结束合约代码
  TShfeFtdcInstrumentIDType	InstIDEnd;
  ///散户保值买入持仓量定义
  TShfeFtdcLargeVolumeType	hbtotal_little;
  ///中户保值买入持仓量定义
  TShfeFtdcLargeVolumeType	hbtotal_medium;
  ///散户保值卖出持仓量定义
  TShfeFtdcLargeVolumeType	hstotal_little;
  ///中户保值卖出持仓量定义
  TShfeFtdcLargeVolumeType	hstotal_medium;
  ///散户保值持仓量定义
  TShfeFtdcLargeVolumeType	htotal_little;
  ///中户保值持仓量定义
  TShfeFtdcLargeVolumeType	htotal_medium;
  ///散户投机买入持仓量定义
  TShfeFtdcLargeVolumeType	sbtotal_little;
  ///中户投机买入持仓量定义
  TShfeFtdcLargeVolumeType	sbtotal_medium;
  ///散户投机卖出持仓量定义
  TShfeFtdcLargeVolumeType	sstotal_little;
  ///中户投机卖出持仓量定义
  TShfeFtdcLargeVolumeType	sstotal_medium;
  ///散户投机持仓量定义
  TShfeFtdcLargeVolumeType	stotal_little;
  ///中户投机持仓量定义
  TShfeFtdcLargeVolumeType	stotal_medium;
  ///散户买入持仓量定义
  TShfeFtdcLargeVolumeType	buytotal_little;
  ///中户买入持仓量定义
  TShfeFtdcLargeVolumeType	buytotal_medium;
  ///散户卖出持仓量定义
  TShfeFtdcLargeVolumeType	selltotal_little;
  ///中户卖出持仓量定义
  TShfeFtdcLargeVolumeType	selltotal_medium;
  ///散户总持仓量定义
  TShfeFtdcLargeVolumeType	total_little;
  ///中户总持仓量定义
  TShfeFtdcLargeVolumeType	total_medium;
  ///取值方式
  TShfeFtdcValueModeType	ValueMode;

  bool operator==(const CShfeFtdcQryInstPositionRateField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstIDStart, ct.InstIDStart) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstIDEnd, ct.InstIDEnd) == 0);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(hbtotal_little, ct.hbtotal_little));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(hbtotal_medium, ct.hbtotal_medium));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(hstotal_little, ct.hstotal_little));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(hstotal_medium, ct.hstotal_medium));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(htotal_little, ct.htotal_little));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(htotal_medium, ct.htotal_medium));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(sbtotal_little, ct.sbtotal_little));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(sbtotal_medium, ct.sbtotal_medium));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(sstotal_little, ct.sstotal_little));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(sstotal_medium, ct.sstotal_medium));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(stotal_little, ct.stotal_little));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(stotal_medium, ct.stotal_medium));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(buytotal_little, ct.buytotal_little));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(buytotal_medium, ct.buytotal_medium));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(selltotal_little, ct.selltotal_little));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(selltotal_medium, ct.selltotal_medium));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(total_little, ct.total_little));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(total_medium, ct.total_medium));
    if (!ret) return ret;
    ret = ret && (ValueMode == ct.ValueMode);
    if (!ret) return ret;

    return ret;
  }
};

///合约持仓比例应答
struct CShfeFtdcRspInstPositionRateField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///散户保值买入持仓量
  TShfeFtdcVolumeType	hbtotal_amt_little;
  ///中户保值买入持仓量
  TShfeFtdcVolumeType	hbtotal_amt_medium;
  ///大户保值买入持仓量
  TShfeFtdcVolumeType	hbtotal_amt_large;
  ///散户保值卖出持仓量
  TShfeFtdcVolumeType	hstotal_amt_little;
  ///中户保值卖出持仓量
  TShfeFtdcVolumeType	hstotal_amt_medium;
  ///大户保值卖出持仓量
  TShfeFtdcVolumeType	hstotal_amt_large;
  ///散户保值持仓量
  TShfeFtdcVolumeType	htotal_amt_little;
  ///中户保值持仓量
  TShfeFtdcVolumeType	htotal_amt_medium;
  ///大户保值持仓量
  TShfeFtdcVolumeType	htotal_amt_large;
  ///散户投机买入持仓量
  TShfeFtdcVolumeType	sbtotal_amt_little;
  ///中户投机买入持仓量
  TShfeFtdcVolumeType	sbtotal_amt_medium;
  ///大户投机买入持仓量
  TShfeFtdcVolumeType	sbtotal_amt_large;
  ///散户投机卖出持仓量
  TShfeFtdcVolumeType	sstotal_amt_little;
  ///中户投机卖出持仓量
  TShfeFtdcVolumeType	sstotal_amt_medium;
  ///大户投机卖出持仓量
  TShfeFtdcVolumeType	sstotal_amt_large;
  ///散户投机持仓量
  TShfeFtdcVolumeType	stotal_amt_little;
  ///中户投机持仓量
  TShfeFtdcVolumeType	stotal_amt_medium;
  ///大户投机持仓量
  TShfeFtdcVolumeType	stotal_amt_large;
  ///散户买入持仓量
  TShfeFtdcVolumeType	buytotal_amt_little;
  ///中户买入持仓量
  TShfeFtdcVolumeType	buytotal_amt_medium;
  ///大户买入持仓量
  TShfeFtdcVolumeType	buytotal_amt_large;
  ///散户卖出持仓量
  TShfeFtdcVolumeType	selltotal_amt_little;
  ///中户卖出持仓量
  TShfeFtdcVolumeType	selltotal_amt_medium;
  ///大户卖出持仓量
  TShfeFtdcVolumeType	selltotal_amt_large;
  ///散户总持仓量
  TShfeFtdcVolumeType	total_amt_little;
  ///中户总持仓量
  TShfeFtdcVolumeType	total_amt_medium;
  ///大户总持仓量
  TShfeFtdcVolumeType	total_amt_large;

  bool operator==(const CShfeFtdcRspInstPositionRateField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (hbtotal_amt_little == ct.hbtotal_amt_little);
    if (!ret) return ret;
    ret = ret && (hbtotal_amt_medium == ct.hbtotal_amt_medium);
    if (!ret) return ret;
    ret = ret && (hbtotal_amt_large == ct.hbtotal_amt_large);
    if (!ret) return ret;
    ret = ret && (hstotal_amt_little == ct.hstotal_amt_little);
    if (!ret) return ret;
    ret = ret && (hstotal_amt_medium == ct.hstotal_amt_medium);
    if (!ret) return ret;
    ret = ret && (hstotal_amt_large == ct.hstotal_amt_large);
    if (!ret) return ret;
    ret = ret && (htotal_amt_little == ct.htotal_amt_little);
    if (!ret) return ret;
    ret = ret && (htotal_amt_medium == ct.htotal_amt_medium);
    if (!ret) return ret;
    ret = ret && (htotal_amt_large == ct.htotal_amt_large);
    if (!ret) return ret;
    ret = ret && (sbtotal_amt_little == ct.sbtotal_amt_little);
    if (!ret) return ret;
    ret = ret && (sbtotal_amt_medium == ct.sbtotal_amt_medium);
    if (!ret) return ret;
    ret = ret && (sbtotal_amt_large == ct.sbtotal_amt_large);
    if (!ret) return ret;
    ret = ret && (sstotal_amt_little == ct.sstotal_amt_little);
    if (!ret) return ret;
    ret = ret && (sstotal_amt_medium == ct.sstotal_amt_medium);
    if (!ret) return ret;
    ret = ret && (sstotal_amt_large == ct.sstotal_amt_large);
    if (!ret) return ret;
    ret = ret && (stotal_amt_little == ct.stotal_amt_little);
    if (!ret) return ret;
    ret = ret && (stotal_amt_medium == ct.stotal_amt_medium);
    if (!ret) return ret;
    ret = ret && (stotal_amt_large == ct.stotal_amt_large);
    if (!ret) return ret;
    ret = ret && (buytotal_amt_little == ct.buytotal_amt_little);
    if (!ret) return ret;
    ret = ret && (buytotal_amt_medium == ct.buytotal_amt_medium);
    if (!ret) return ret;
    ret = ret && (buytotal_amt_large == ct.buytotal_amt_large);
    if (!ret) return ret;
    ret = ret && (selltotal_amt_little == ct.selltotal_amt_little);
    if (!ret) return ret;
    ret = ret && (selltotal_amt_medium == ct.selltotal_amt_medium);
    if (!ret) return ret;
    ret = ret && (selltotal_amt_large == ct.selltotal_amt_large);
    if (!ret) return ret;
    ret = ret && (total_amt_little == ct.total_amt_little);
    if (!ret) return ret;
    ret = ret && (total_amt_medium == ct.total_amt_medium);
    if (!ret) return ret;
    ret = ret && (total_amt_large == ct.total_amt_large);
    if (!ret) return ret;

    return ret;
  }
};

///产品持仓比例查询
struct CShfeFtdcQryProductPositionRateField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///产品代码
  TShfeFtdcInstrumentIDType	ProductID;
  ///散户保值买入持仓量定义
  TShfeFtdcLargeVolumeType	hbtotal_little;
  ///中户保值买入持仓量定义
  TShfeFtdcLargeVolumeType	hbtotal_medium;
  ///散户保值卖出持仓量定义
  TShfeFtdcLargeVolumeType	hstotal_little;
  ///中户保值卖出持仓量定义
  TShfeFtdcLargeVolumeType	hstotal_medium;
  ///散户保值持仓量定义
  TShfeFtdcLargeVolumeType	htotal_little;
  ///中户保值持仓量定义
  TShfeFtdcLargeVolumeType	htotal_medium;
  ///散户投机买入持仓量定义
  TShfeFtdcLargeVolumeType	sbtotal_little;
  ///中户投机买入持仓量定义
  TShfeFtdcLargeVolumeType	sbtotal_medium;
  ///散户投机卖出持仓量定义
  TShfeFtdcLargeVolumeType	sstotal_little;
  ///中户投机卖出持仓量定义
  TShfeFtdcLargeVolumeType	sstotal_medium;
  ///散户投机持仓量定义
  TShfeFtdcLargeVolumeType	stotal_little;
  ///中户投机持仓量定义
  TShfeFtdcLargeVolumeType	stotal_medium;
  ///散户买入持仓量定义
  TShfeFtdcLargeVolumeType	buytotal_little;
  ///中户买入持仓量定义
  TShfeFtdcLargeVolumeType	buytotal_medium;
  ///散户卖出持仓量定义
  TShfeFtdcLargeVolumeType	selltotal_little;
  ///中户卖出持仓量定义
  TShfeFtdcLargeVolumeType	selltotal_medium;
  ///散户总持仓量定义
  TShfeFtdcLargeVolumeType	total_little;
  ///中户总持仓量定义
  TShfeFtdcLargeVolumeType	total_medium;
  ///取值方式
  TShfeFtdcValueModeType	ValueMode;

  bool operator==(const CShfeFtdcQryProductPositionRateField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ProductID, ct.ProductID) == 0);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(hbtotal_little, ct.hbtotal_little));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(hbtotal_medium, ct.hbtotal_medium));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(hstotal_little, ct.hstotal_little));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(hstotal_medium, ct.hstotal_medium));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(htotal_little, ct.htotal_little));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(htotal_medium, ct.htotal_medium));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(sbtotal_little, ct.sbtotal_little));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(sbtotal_medium, ct.sbtotal_medium));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(sstotal_little, ct.sstotal_little));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(sstotal_medium, ct.sstotal_medium));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(stotal_little, ct.stotal_little));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(stotal_medium, ct.stotal_medium));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(buytotal_little, ct.buytotal_little));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(buytotal_medium, ct.buytotal_medium));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(selltotal_little, ct.selltotal_little));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(selltotal_medium, ct.selltotal_medium));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(total_little, ct.total_little));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(total_medium, ct.total_medium));
    if (!ret) return ret;
    ret = ret && (ValueMode == ct.ValueMode);
    if (!ret) return ret;

    return ret;
  }
};

///产品持仓比例
struct CShfeFtdcRspProductPositionRateField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///产品代码
  TShfeFtdcInstrumentIDType	ProductID;
  ///散户保值买入持仓量
  TShfeFtdcVolumeType	hbtotal_amt_little;
  ///中户保值买入持仓量
  TShfeFtdcVolumeType	hbtotal_amt_medium;
  ///大户保值买入持仓量
  TShfeFtdcVolumeType	hbtotal_amt_large;
  ///散户保值卖出持仓量
  TShfeFtdcVolumeType	hstotal_amt_little;
  ///中户保值卖出持仓量
  TShfeFtdcVolumeType	hstotal_amt_medium;
  ///大户保值卖出持仓量
  TShfeFtdcVolumeType	hstotal_amt_large;
  ///散户保值持仓量
  TShfeFtdcVolumeType	htotal_amt_little;
  ///中户保值持仓量
  TShfeFtdcVolumeType	htotal_amt_medium;
  ///大户保值持仓量
  TShfeFtdcVolumeType	htotal_amt_large;
  ///散户投机买入持仓量
  TShfeFtdcVolumeType	sbtotal_amt_little;
  ///中户投机买入持仓量
  TShfeFtdcVolumeType	sbtotal_amt_medium;
  ///大户投机买入持仓量
  TShfeFtdcVolumeType	sbtotal_amt_large;
  ///散户投机卖出持仓量
  TShfeFtdcVolumeType	sstotal_amt_little;
  ///中户投机卖出持仓量
  TShfeFtdcVolumeType	sstotal_amt_medium;
  ///大户投机卖出持仓量
  TShfeFtdcVolumeType	sstotal_amt_large;
  ///散户投机持仓量
  TShfeFtdcVolumeType	stotal_amt_little;
  ///中户投机持仓量
  TShfeFtdcVolumeType	stotal_amt_medium;
  ///大户投机持仓量
  TShfeFtdcVolumeType	stotal_amt_large;
  ///散户买入持仓量
  TShfeFtdcVolumeType	buytotal_amt_little;
  ///中户买入持仓量
  TShfeFtdcVolumeType	buytotal_amt_medium;
  ///大户买入持仓量
  TShfeFtdcVolumeType	buytotal_amt_large;
  ///散户卖出持仓量
  TShfeFtdcVolumeType	selltotal_amt_little;
  ///中户卖出持仓量
  TShfeFtdcVolumeType	selltotal_amt_medium;
  ///大户卖出持仓量
  TShfeFtdcVolumeType	selltotal_amt_large;
  ///散户总持仓量
  TShfeFtdcVolumeType	total_amt_little;
  ///中户总持仓量
  TShfeFtdcVolumeType	total_amt_medium;
  ///大户总持仓量
  TShfeFtdcVolumeType	total_amt_large;

  bool operator==(const CShfeFtdcRspProductPositionRateField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ProductID, ct.ProductID) == 0);
    if (!ret) return ret;
    ret = ret && (hbtotal_amt_little == ct.hbtotal_amt_little);
    if (!ret) return ret;
    ret = ret && (hbtotal_amt_medium == ct.hbtotal_amt_medium);
    if (!ret) return ret;
    ret = ret && (hbtotal_amt_large == ct.hbtotal_amt_large);
    if (!ret) return ret;
    ret = ret && (hstotal_amt_little == ct.hstotal_amt_little);
    if (!ret) return ret;
    ret = ret && (hstotal_amt_medium == ct.hstotal_amt_medium);
    if (!ret) return ret;
    ret = ret && (hstotal_amt_large == ct.hstotal_amt_large);
    if (!ret) return ret;
    ret = ret && (htotal_amt_little == ct.htotal_amt_little);
    if (!ret) return ret;
    ret = ret && (htotal_amt_medium == ct.htotal_amt_medium);
    if (!ret) return ret;
    ret = ret && (htotal_amt_large == ct.htotal_amt_large);
    if (!ret) return ret;
    ret = ret && (sbtotal_amt_little == ct.sbtotal_amt_little);
    if (!ret) return ret;
    ret = ret && (sbtotal_amt_medium == ct.sbtotal_amt_medium);
    if (!ret) return ret;
    ret = ret && (sbtotal_amt_large == ct.sbtotal_amt_large);
    if (!ret) return ret;
    ret = ret && (sstotal_amt_little == ct.sstotal_amt_little);
    if (!ret) return ret;
    ret = ret && (sstotal_amt_medium == ct.sstotal_amt_medium);
    if (!ret) return ret;
    ret = ret && (sstotal_amt_large == ct.sstotal_amt_large);
    if (!ret) return ret;
    ret = ret && (stotal_amt_little == ct.stotal_amt_little);
    if (!ret) return ret;
    ret = ret && (stotal_amt_medium == ct.stotal_amt_medium);
    if (!ret) return ret;
    ret = ret && (stotal_amt_large == ct.stotal_amt_large);
    if (!ret) return ret;
    ret = ret && (buytotal_amt_little == ct.buytotal_amt_little);
    if (!ret) return ret;
    ret = ret && (buytotal_amt_medium == ct.buytotal_amt_medium);
    if (!ret) return ret;
    ret = ret && (buytotal_amt_large == ct.buytotal_amt_large);
    if (!ret) return ret;
    ret = ret && (selltotal_amt_little == ct.selltotal_amt_little);
    if (!ret) return ret;
    ret = ret && (selltotal_amt_medium == ct.selltotal_amt_medium);
    if (!ret) return ret;
    ret = ret && (selltotal_amt_large == ct.selltotal_amt_large);
    if (!ret) return ret;
    ret = ret && (total_amt_little == ct.total_amt_little);
    if (!ret) return ret;
    ret = ret && (total_amt_medium == ct.total_amt_medium);
    if (!ret) return ret;
    ret = ret && (total_amt_large == ct.total_amt_large);
    if (!ret) return ret;

    return ret;
  }
};

///历史模拟法压力测试只返回一次结果
struct CShfeFtdcIsWriteOnceField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///是否只返回一次结果
  TShfeFtdcBoolType	IsWriteOnce;

  bool operator==(const CShfeFtdcIsWriteOnceField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (IsWriteOnce == ct.IsWriteOnce);
    if (!ret) return ret;

    return ret;
  }
};

///压力测试结算价格(或浮动)
struct CShfeFtdcSTSettlePriceField
{
  ///第几天
  TShfeFtdcDayNumberType	Day;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///结算价格类型(Day=1时有效)
  TShfeFtdcSTPriceTypeType	PriceType;
  ///结算价格(或浮动)
  TShfeFtdcPriceType	Price;

  bool operator==(const CShfeFtdcSTSettlePriceField &ct) const
  {
    bool ret = true;
    ret = ret && (Day == ct.Day);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (PriceType == ct.PriceType);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Price, ct.Price));
    if (!ret) return ret;

    return ret;
  }
};

///压力测试投资者保证金率
struct CShfeFtdcSTInstrumentMarginRateField
{
  ///第几天
  TShfeFtdcDayNumberType	Day;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///投资者范围
  TShfeFtdcInvestorRangeType	InvestorRange;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///投机套保标志
  TShfeFtdcHedgeFlagType	HedgeFlag;
  ///多头保证金率
  TShfeFtdcRatioType	LongMarginRatioByMoney;
  ///多头保证金费
  TShfeFtdcMoneyType	LongMarginRatioByVolume;
  ///空头保证金率
  TShfeFtdcRatioType	ShortMarginRatioByMoney;
  ///空头保证金费
  TShfeFtdcMoneyType	ShortMarginRatioByVolume;
  ///是否相对交易所收取
  TShfeFtdcBoolType	IsRelative;

  bool operator==(const CShfeFtdcSTInstrumentMarginRateField &ct) const
  {
    bool ret = true;
    ret = ret && (Day == ct.Day);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (InvestorRange == ct.InvestorRange);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (HedgeFlag == ct.HedgeFlag);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(LongMarginRatioByMoney, ct.LongMarginRatioByMoney));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(LongMarginRatioByVolume, ct.LongMarginRatioByVolume));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ShortMarginRatioByMoney, ct.ShortMarginRatioByMoney));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ShortMarginRatioByVolume, ct.ShortMarginRatioByVolume));
    if (!ret) return ret;
    ret = ret && (IsRelative == ct.IsRelative);
    if (!ret) return ret;

    return ret;
  }
};

///压力测试投资者保证金率调整
struct CShfeFtdcSTInstrumentMarginRateAdjustField
{
  ///第几天
  TShfeFtdcDayNumberType	Day;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///投资者范围
  TShfeFtdcInvestorRangeType	InvestorRange;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///投机套保标志
  TShfeFtdcHedgeFlagType	HedgeFlag;
  ///多头保证金率
  TShfeFtdcRatioType	LongMarginRatioByMoney;
  ///多头保证金费
  TShfeFtdcMoneyType	LongMarginRatioByVolume;
  ///空头保证金率
  TShfeFtdcRatioType	ShortMarginRatioByMoney;
  ///空头保证金费
  TShfeFtdcMoneyType	ShortMarginRatioByVolume;
  ///是否相对交易所收取
  TShfeFtdcBoolType	IsRelative;

  bool operator==(const CShfeFtdcSTInstrumentMarginRateAdjustField &ct) const
  {
    bool ret = true;
    ret = ret && (Day == ct.Day);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (InvestorRange == ct.InvestorRange);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (HedgeFlag == ct.HedgeFlag);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(LongMarginRatioByMoney, ct.LongMarginRatioByMoney));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(LongMarginRatioByVolume, ct.LongMarginRatioByVolume));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ShortMarginRatioByMoney, ct.ShortMarginRatioByMoney));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ShortMarginRatioByVolume, ct.ShortMarginRatioByVolume));
    if (!ret) return ret;
    ret = ret && (IsRelative == ct.IsRelative);
    if (!ret) return ret;

    return ret;
  }
};

///压力测试交易所保证金率
struct CShfeFtdcSTExchangeMarginRateField
{
  ///第几天
  TShfeFtdcDayNumberType	Day;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///投机套保标志
  TShfeFtdcHedgeFlagType	HedgeFlag;
  ///多头保证金率
  TShfeFtdcRatioType	LongMarginRatioByMoney;
  ///多头保证金费
  TShfeFtdcMoneyType	LongMarginRatioByVolume;
  ///空头保证金率
  TShfeFtdcRatioType	ShortMarginRatioByMoney;
  ///空头保证金费
  TShfeFtdcMoneyType	ShortMarginRatioByVolume;

  bool operator==(const CShfeFtdcSTExchangeMarginRateField &ct) const
  {
    bool ret = true;
    ret = ret && (Day == ct.Day);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (HedgeFlag == ct.HedgeFlag);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(LongMarginRatioByMoney, ct.LongMarginRatioByMoney));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(LongMarginRatioByVolume, ct.LongMarginRatioByVolume));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ShortMarginRatioByMoney, ct.ShortMarginRatioByMoney));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ShortMarginRatioByVolume, ct.ShortMarginRatioByVolume));
    if (!ret) return ret;

    return ret;
  }
};

///压力测试交易所保证金率调整
struct CShfeFtdcSTExchangeMarginRateAdjustField
{
  ///第几天
  TShfeFtdcDayNumberType	Day;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///投机套保标志
  TShfeFtdcHedgeFlagType	HedgeFlag;
  ///跟随交易所投资者多头保证金率
  TShfeFtdcRatioType	LongMarginRatioByMoney;
  ///跟随交易所投资者多头保证金费
  TShfeFtdcMoneyType	LongMarginRatioByVolume;
  ///跟随交易所投资者空头保证金率
  TShfeFtdcRatioType	ShortMarginRatioByMoney;
  ///跟随交易所投资者空头保证金费
  TShfeFtdcMoneyType	ShortMarginRatioByVolume;
  ///交易所多头保证金率
  TShfeFtdcRatioType	ExchLongMarginRatioByMoney;
  ///交易所多头保证金费
  TShfeFtdcMoneyType	ExchLongMarginRatioByVolume;
  ///交易所空头保证金率
  TShfeFtdcRatioType	ExchShortMarginRatioByMoney;
  ///交易所空头保证金费
  TShfeFtdcMoneyType	ExchShortMarginRatioByVolume;
  ///不跟随交易所投资者多头保证金率
  TShfeFtdcRatioType	NoLongMarginRatioByMoney;
  ///不跟随交易所投资者多头保证金费
  TShfeFtdcMoneyType	NoLongMarginRatioByVolume;
  ///不跟随交易所投资者空头保证金率
  TShfeFtdcRatioType	NoShortMarginRatioByMoney;
  ///不跟随交易所投资者空头保证金费
  TShfeFtdcMoneyType	NoShortMarginRatioByVolume;

  bool operator==(const CShfeFtdcSTExchangeMarginRateAdjustField &ct) const
  {
    bool ret = true;
    ret = ret && (Day == ct.Day);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (HedgeFlag == ct.HedgeFlag);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(LongMarginRatioByMoney, ct.LongMarginRatioByMoney));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(LongMarginRatioByVolume, ct.LongMarginRatioByVolume));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ShortMarginRatioByMoney, ct.ShortMarginRatioByMoney));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ShortMarginRatioByVolume, ct.ShortMarginRatioByVolume));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ExchLongMarginRatioByMoney, ct.ExchLongMarginRatioByMoney));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ExchLongMarginRatioByVolume, ct.ExchLongMarginRatioByVolume));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ExchShortMarginRatioByMoney, ct.ExchShortMarginRatioByMoney));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ExchShortMarginRatioByVolume, ct.ExchShortMarginRatioByVolume));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(NoLongMarginRatioByMoney, ct.NoLongMarginRatioByMoney));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(NoLongMarginRatioByVolume, ct.NoLongMarginRatioByVolume));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(NoShortMarginRatioByMoney, ct.NoShortMarginRatioByMoney));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(NoShortMarginRatioByVolume, ct.NoShortMarginRatioByVolume));
    if (!ret) return ret;

    return ret;
  }
};

///投资者与联系人信息
struct CShfeFtdcInvestorLinkManField
{
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者分组代码
  TShfeFtdcInvestorIDType	InvestorGroupID;
  ///投资者名称
  TShfeFtdcPartyNameType	InvestorName;
  ///证件类型
  TShfeFtdcIdCardTypeType	IdentifiedCardType;
  ///证件号码
  TShfeFtdcIdentifiedCardNoType	IdentifiedCardNo;
  ///是否活跃
  TShfeFtdcBoolType	IsActive;
  ///联系电话
  TShfeFtdcTelephoneType	Telephone;
  ///通讯地址
  TShfeFtdcAddressType	Address;
  ///指定下单人证件类型
  TShfeFtdcIdCardTypeType	OrderManIdentifiedCardType;
  ///指定下单人证件号码
  TShfeFtdcIdentifiedCardNoType	OrderManIdentifiedCardNo;
  ///指定下单人名称
  TShfeFtdcPartyNameType	OrderManPersonName;
  ///指定下单人联系电话
  TShfeFtdcTelephoneType	OrderManTelephone;
  ///指定下单人通讯地址
  TShfeFtdcAddressType	OrderManAddress;
  ///指定下单人邮政编码
  TShfeFtdcZipCodeType	OrderManZipCode;
  ///资金调拨人证件类型
  TShfeFtdcIdCardTypeType	FundManIdentifiedCardType;
  ///资金调拨人证件号码
  TShfeFtdcIdentifiedCardNoType	FundManIdentifiedCardNo;
  ///资金调拨人名称
  TShfeFtdcPartyNameType	FundManPersonName;
  ///资金调拨人联系电话
  TShfeFtdcTelephoneType	FundManTelephone;
  ///资金调拨人通讯地址
  TShfeFtdcAddressType	FundManAddress;
  ///资金调拨人邮政编码
  TShfeFtdcZipCodeType	FundManZipCode;
  ///开户授权人证件类型
  TShfeFtdcIdCardTypeType	OpenManIdentifiedCardType;
  ///开户授权人证件号码
  TShfeFtdcIdentifiedCardNoType	OpenManIdentifiedCardNo;
  ///开户授权人名称
  TShfeFtdcPartyNameType	OpenManPersonName;
  ///开户授权人联系电话
  TShfeFtdcTelephoneType	OpenManTelephone;
  ///开户授权人通讯地址
  TShfeFtdcAddressType	OpenManAddress;
  ///开户授权人邮政编码
  TShfeFtdcZipCodeType	OpenManZipCode;
  ///结算单确认人证件类型
  TShfeFtdcIdCardTypeType	SettlementManIdentifiedCardType;
  ///结算单确认人证件号码
  TShfeFtdcIdentifiedCardNoType	SettlementManIdentifiedCardNo;
  ///结算单确认人名称
  TShfeFtdcPartyNameType	SettlementManPersonName;
  ///结算单确认人联系电话
  TShfeFtdcTelephoneType	SettlementManTelephone;
  ///结算单确认人通讯地址
  TShfeFtdcAddressType	SettlementManAddress;
  ///结算单确认人邮政编码
  TShfeFtdcZipCodeType	SettlementManZipCode;
  ///开户日期
  TShfeFtdcDateType	OpenDate;
  ///手机
  TShfeFtdcMobileType	Mobile;
  ///电子邮件
  TShfeFtdcEMailType	EMail;
  ///投资者类型
  TShfeFtdcInvestorTypeType	InvestorType;
  ///国家代码
  TShfeFtdcUOACountryCodeType	PhoneCountryCode;
  ///区号
  TShfeFtdcAreaCodeType	PhoneAreaCode;
  ///开户授权人国家代码
  TShfeFtdcUOACountryCodeType	OpenPhoneCountryCode;
  ///开户授权人区号
  TShfeFtdcAreaCodeType	OpenPhoneAreaCode;
  ///指定下单人国家代码
  TShfeFtdcUOACountryCodeType	OrderPhoneCountryCode;
  ///指定下单人区号
  TShfeFtdcAreaCodeType	OrderPhoneAreaCode;
  ///资金调拨人国家代码
  TShfeFtdcUOACountryCodeType	FundPhoneCountryCode;
  ///资金调拨人区号
  TShfeFtdcAreaCodeType	FundPhoneAreaCode;
  ///结算单确认人国家代码
  TShfeFtdcUOACountryCodeType	SettlePhoneCountryCode;
  ///结算单确认人区号
  TShfeFtdcAreaCodeType	SettlePhoneAreaCode;

  bool operator==(const CShfeFtdcInvestorLinkManField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorGroupID, ct.InvestorGroupID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorName, ct.InvestorName) == 0);
    if (!ret) return ret;
    ret = ret && (IdentifiedCardType == ct.IdentifiedCardType);
    if (!ret) return ret;
    ret = ret && (strcmp(IdentifiedCardNo, ct.IdentifiedCardNo) == 0);
    if (!ret) return ret;
    ret = ret && (IsActive == ct.IsActive);
    if (!ret) return ret;
    ret = ret && (strcmp(Telephone, ct.Telephone) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(Address, ct.Address) == 0);
    if (!ret) return ret;
    ret = ret && (OrderManIdentifiedCardType == ct.OrderManIdentifiedCardType);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderManIdentifiedCardNo, ct.OrderManIdentifiedCardNo) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderManPersonName, ct.OrderManPersonName) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderManTelephone, ct.OrderManTelephone) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderManAddress, ct.OrderManAddress) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderManZipCode, ct.OrderManZipCode) == 0);
    if (!ret) return ret;
    ret = ret && (FundManIdentifiedCardType == ct.FundManIdentifiedCardType);
    if (!ret) return ret;
    ret = ret && (strcmp(FundManIdentifiedCardNo, ct.FundManIdentifiedCardNo) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(FundManPersonName, ct.FundManPersonName) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(FundManTelephone, ct.FundManTelephone) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(FundManAddress, ct.FundManAddress) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(FundManZipCode, ct.FundManZipCode) == 0);
    if (!ret) return ret;
    ret = ret && (OpenManIdentifiedCardType == ct.OpenManIdentifiedCardType);
    if (!ret) return ret;
    ret = ret && (strcmp(OpenManIdentifiedCardNo, ct.OpenManIdentifiedCardNo) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OpenManPersonName, ct.OpenManPersonName) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OpenManTelephone, ct.OpenManTelephone) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OpenManAddress, ct.OpenManAddress) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OpenManZipCode, ct.OpenManZipCode) == 0);
    if (!ret) return ret;
    ret = ret && (SettlementManIdentifiedCardType == ct.SettlementManIdentifiedCardType);
    if (!ret) return ret;
    ret = ret && (strcmp(SettlementManIdentifiedCardNo, ct.SettlementManIdentifiedCardNo) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(SettlementManPersonName, ct.SettlementManPersonName) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(SettlementManTelephone, ct.SettlementManTelephone) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(SettlementManAddress, ct.SettlementManAddress) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(SettlementManZipCode, ct.SettlementManZipCode) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OpenDate, ct.OpenDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(Mobile, ct.Mobile) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(EMail, ct.EMail) == 0);
    if (!ret) return ret;
    ret = ret && (InvestorType == ct.InvestorType);
    if (!ret) return ret;
    ret = ret && (strcmp(PhoneCountryCode, ct.PhoneCountryCode) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(PhoneAreaCode, ct.PhoneAreaCode) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OpenPhoneCountryCode, ct.OpenPhoneCountryCode) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OpenPhoneAreaCode, ct.OpenPhoneAreaCode) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderPhoneCountryCode, ct.OrderPhoneCountryCode) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderPhoneAreaCode, ct.OrderPhoneAreaCode) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(FundPhoneCountryCode, ct.FundPhoneCountryCode) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(FundPhoneAreaCode, ct.FundPhoneAreaCode) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(SettlePhoneCountryCode, ct.SettlePhoneCountryCode) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(SettlePhoneAreaCode, ct.SettlePhoneAreaCode) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///订阅投资者成交
struct CShfeFtdcSubInvestorTradeField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;

  bool operator==(const CShfeFtdcSubInvestorTradeField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///订阅投资者持仓
struct CShfeFtdcSubInvestorPositionField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;

  bool operator==(const CShfeFtdcSubInvestorPositionField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///序列号
struct CShfeFtdcNotifySequenceField
{
  ///序号
  TShfeFtdcSequenceNoType	SequenceNo;

  bool operator==(const CShfeFtdcNotifySequenceField &ct) const
  {
    bool ret = true;
    ret = ret && (SequenceNo == ct.SequenceNo);
    if (!ret) return ret;

    return ret;
  }
};

///有序的成交
struct CShfeFtdcSequencialTradeField
{
  ///流中唯一的序列号
  TShfeFtdcSequenceNoType	UniqSequenceNo;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///报单引用
  TShfeFtdcOrderRefType	OrderRef;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///成交编号
  TShfeFtdcTradeIDType	TradeID;
  ///买卖方向
  TShfeFtdcDirectionType	Direction;
  ///报单编号
  TShfeFtdcOrderSysIDType	OrderSysID;
  ///会员代码
  TShfeFtdcParticipantIDType	ParticipantID;
  ///客户代码
  TShfeFtdcClientIDType	ClientID;
  ///交易角色
  TShfeFtdcTradingRoleType	TradingRole;
  ///合约在交易所的代码
  TShfeFtdcExchangeInstIDType	ExchangeInstID;
  ///开平标志
  TShfeFtdcOffsetFlagType	OffsetFlag;
  ///投机套保标志
  TShfeFtdcHedgeFlagType	HedgeFlag;
  ///价格
  TShfeFtdcPriceType	Price;
  ///数量
  TShfeFtdcVolumeType	Volume;
  ///成交时期
  TShfeFtdcDateType	TradeDate;
  ///成交时间
  TShfeFtdcTimeType	TradeTime;
  ///成交类型
  TShfeFtdcTradeTypeType	TradeType;
  ///成交价来源
  TShfeFtdcPriceSourceType	PriceSource;
  ///交易所交易员代码
  TShfeFtdcTraderIDType	TraderID;
  ///本地报单编号
  TShfeFtdcOrderLocalIDType	OrderLocalID;
  ///结算会员编号
  TShfeFtdcParticipantIDType	ClearingPartID;
  ///业务单元
  TShfeFtdcBusinessUnitType	BusinessUnit;
  ///序号
  TShfeFtdcSequenceNoType	SequenceNo;
  ///交易日
  TShfeFtdcDateType	TradingDay;
  ///结算编号
  TShfeFtdcSettlementIDType	SettlementID;
  ///经纪公司报单编号
  TShfeFtdcSequenceNoType	BrokerOrderSeq;
  ///成交来源
  TShfeFtdcTradeSourceType	TradeSource;

  bool operator==(const CShfeFtdcSequencialTradeField &ct) const
  {
    bool ret = true;
    ret = ret && (UniqSequenceNo == ct.UniqSequenceNo);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderRef, ct.OrderRef) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TradeID, ct.TradeID) == 0);
    if (!ret) return ret;
    ret = ret && (Direction == ct.Direction);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderSysID, ct.OrderSysID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ParticipantID, ct.ParticipantID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ClientID, ct.ClientID) == 0);
    if (!ret) return ret;
    ret = ret && (TradingRole == ct.TradingRole);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeInstID, ct.ExchangeInstID) == 0);
    if (!ret) return ret;
    ret = ret && (OffsetFlag == ct.OffsetFlag);
    if (!ret) return ret;
    ret = ret && (HedgeFlag == ct.HedgeFlag);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Price, ct.Price));
    if (!ret) return ret;
    ret = ret && (Volume == ct.Volume);
    if (!ret) return ret;
    ret = ret && (strcmp(TradeDate, ct.TradeDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TradeTime, ct.TradeTime) == 0);
    if (!ret) return ret;
    ret = ret && (TradeType == ct.TradeType);
    if (!ret) return ret;
    ret = ret && (PriceSource == ct.PriceSource);
    if (!ret) return ret;
    ret = ret && (strcmp(TraderID, ct.TraderID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderLocalID, ct.OrderLocalID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ClearingPartID, ct.ClearingPartID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BusinessUnit, ct.BusinessUnit) == 0);
    if (!ret) return ret;
    ret = ret && (SequenceNo == ct.SequenceNo);
    if (!ret) return ret;
    ret = ret && (strcmp(TradingDay, ct.TradingDay) == 0);
    if (!ret) return ret;
    ret = ret && (SettlementID == ct.SettlementID);
    if (!ret) return ret;
    ret = ret && (BrokerOrderSeq == ct.BrokerOrderSeq);
    if (!ret) return ret;
    ret = ret && (TradeSource == ct.TradeSource);
    if (!ret) return ret;

    return ret;
  }
};

///有序的报单
struct CShfeFtdcSequencialOrderField
{
  ///流中唯一的序列号
  TShfeFtdcSequenceNoType	UniqSequenceNo;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///报单引用
  TShfeFtdcOrderRefType	OrderRef;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///报单价格条件
  TShfeFtdcOrderPriceTypeType	OrderPriceType;
  ///买卖方向
  TShfeFtdcDirectionType	Direction;
  ///组合开平标志
  TShfeFtdcCombOffsetFlagType	CombOffsetFlag;
  ///组合投机套保标志
  TShfeFtdcCombHedgeFlagType	CombHedgeFlag;
  ///价格
  TShfeFtdcPriceType	LimitPrice;
  ///数量
  TShfeFtdcVolumeType	VolumeTotalOriginal;
  ///有效期类型
  TShfeFtdcTimeConditionType	TimeCondition;
  ///GTD日期
  TShfeFtdcDateType	GTDDate;
  ///成交量类型
  TShfeFtdcVolumeConditionType	VolumeCondition;
  ///最小成交量
  TShfeFtdcVolumeType	MinVolume;
  ///触发条件
  TShfeFtdcContingentConditionType	ContingentCondition;
  ///止损价
  TShfeFtdcPriceType	StopPrice;
  ///强平原因
  TShfeFtdcForceCloseReasonType	ForceCloseReason;
  ///自动挂起标志
  TShfeFtdcBoolType	IsAutoSuspend;
  ///业务单元
  TShfeFtdcBusinessUnitType	BusinessUnit;
  ///请求编号
  TShfeFtdcRequestIDType	RequestID;
  ///本地报单编号
  TShfeFtdcOrderLocalIDType	OrderLocalID;
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///会员代码
  TShfeFtdcParticipantIDType	ParticipantID;
  ///客户代码
  TShfeFtdcClientIDType	ClientID;
  ///合约在交易所的代码
  TShfeFtdcExchangeInstIDType	ExchangeInstID;
  ///交易所交易员代码
  TShfeFtdcTraderIDType	TraderID;
  ///安装编号
  TShfeFtdcInstallIDType	InstallID;
  ///报单提交状态
  TShfeFtdcOrderSubmitStatusType	OrderSubmitStatus;
  ///报单提示序号
  TShfeFtdcSequenceNoType	NotifySequence;
  ///交易日
  TShfeFtdcDateType	TradingDay;
  ///结算编号
  TShfeFtdcSettlementIDType	SettlementID;
  ///报单编号
  TShfeFtdcOrderSysIDType	OrderSysID;
  ///报单来源
  TShfeFtdcOrderSourceType	OrderSource;
  ///报单状态
  TShfeFtdcOrderStatusType	OrderStatus;
  ///报单类型
  TShfeFtdcOrderTypeType	OrderType;
  ///今成交数量
  TShfeFtdcVolumeType	VolumeTraded;
  ///剩余数量
  TShfeFtdcVolumeType	VolumeTotal;
  ///报单日期
  TShfeFtdcDateType	InsertDate;
  ///委托时间
  TShfeFtdcTimeType	InsertTime;
  ///激活时间
  TShfeFtdcTimeType	ActiveTime;
  ///挂起时间
  TShfeFtdcTimeType	SuspendTime;
  ///最后修改时间
  TShfeFtdcTimeType	UpdateTime;
  ///撤销时间
  TShfeFtdcTimeType	CancelTime;
  ///最后修改交易所交易员代码
  TShfeFtdcTraderIDType	ActiveTraderID;
  ///结算会员编号
  TShfeFtdcParticipantIDType	ClearingPartID;
  ///序号
  TShfeFtdcSequenceNoType	SequenceNo;
  ///前置编号
  TShfeFtdcFrontIDType	FrontID;
  ///会话编号
  TShfeFtdcSessionIDType	SessionID;
  ///用户端产品信息
  TShfeFtdcProductInfoType	UserProductInfo;
  ///状态信息
  TShfeFtdcErrorMsgType	StatusMsg;
  ///用户强评标志
  TShfeFtdcBoolType	UserForceClose;
  ///操作用户代码
  TShfeFtdcUserIDType	ActiveUserID;
  ///经纪公司报单编号
  TShfeFtdcSequenceNoType	BrokerOrderSeq;
  ///相关报单
  TShfeFtdcOrderSysIDType	RelativeOrderSysID;
  ///郑商所成交数量
  TShfeFtdcVolumeType	ZCETotalTradedVolume;

  bool operator==(const CShfeFtdcSequencialOrderField &ct) const
  {
    bool ret = true;
    ret = ret && (UniqSequenceNo == ct.UniqSequenceNo);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderRef, ct.OrderRef) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (OrderPriceType == ct.OrderPriceType);
    if (!ret) return ret;
    ret = ret && (Direction == ct.Direction);
    if (!ret) return ret;
    for (int i = 0; i < 4; ++i) {
      ret = ret && (CombOffsetFlag[i] == ct.CombOffsetFlag[i]);
      if (!ret) return ret;
    }
    for (int i = 0; i < 4; ++i) {
      ret = ret && (CombHedgeFlag[i] == ct.CombHedgeFlag[i]);
      if (!ret) return ret;
    }
    ret = ret && (EQUALDOUBLE(LimitPrice, ct.LimitPrice));
    if (!ret) return ret;
    ret = ret && (VolumeTotalOriginal == ct.VolumeTotalOriginal);
    if (!ret) return ret;
    ret = ret && (TimeCondition == ct.TimeCondition);
    if (!ret) return ret;
    ret = ret && (strcmp(GTDDate, ct.GTDDate) == 0);
    if (!ret) return ret;
    ret = ret && (VolumeCondition == ct.VolumeCondition);
    if (!ret) return ret;
    ret = ret && (MinVolume == ct.MinVolume);
    if (!ret) return ret;
    ret = ret && (ContingentCondition == ct.ContingentCondition);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(StopPrice, ct.StopPrice));
    if (!ret) return ret;
    ret = ret && (ForceCloseReason == ct.ForceCloseReason);
    if (!ret) return ret;
    ret = ret && (IsAutoSuspend == ct.IsAutoSuspend);
    if (!ret) return ret;
    ret = ret && (strcmp(BusinessUnit, ct.BusinessUnit) == 0);
    if (!ret) return ret;
    ret = ret && (RequestID == ct.RequestID);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderLocalID, ct.OrderLocalID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ParticipantID, ct.ParticipantID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ClientID, ct.ClientID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeInstID, ct.ExchangeInstID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(TraderID, ct.TraderID) == 0);
    if (!ret) return ret;
    ret = ret && (InstallID == ct.InstallID);
    if (!ret) return ret;
    ret = ret && (OrderSubmitStatus == ct.OrderSubmitStatus);
    if (!ret) return ret;
    ret = ret && (NotifySequence == ct.NotifySequence);
    if (!ret) return ret;
    ret = ret && (strcmp(TradingDay, ct.TradingDay) == 0);
    if (!ret) return ret;
    ret = ret && (SettlementID == ct.SettlementID);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderSysID, ct.OrderSysID) == 0);
    if (!ret) return ret;
    ret = ret && (OrderSource == ct.OrderSource);
    if (!ret) return ret;
    ret = ret && (OrderStatus == ct.OrderStatus);
    if (!ret) return ret;
    ret = ret && (OrderType == ct.OrderType);
    if (!ret) return ret;
    ret = ret && (VolumeTraded == ct.VolumeTraded);
    if (!ret) return ret;
    ret = ret && (VolumeTotal == ct.VolumeTotal);
    if (!ret) return ret;
    ret = ret && (strcmp(InsertDate, ct.InsertDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InsertTime, ct.InsertTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ActiveTime, ct.ActiveTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(SuspendTime, ct.SuspendTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UpdateTime, ct.UpdateTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(CancelTime, ct.CancelTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ActiveTraderID, ct.ActiveTraderID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ClearingPartID, ct.ClearingPartID) == 0);
    if (!ret) return ret;
    ret = ret && (SequenceNo == ct.SequenceNo);
    if (!ret) return ret;
    ret = ret && (FrontID == ct.FrontID);
    if (!ret) return ret;
    ret = ret && (SessionID == ct.SessionID);
    if (!ret) return ret;
    ret = ret && (strcmp(UserProductInfo, ct.UserProductInfo) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(StatusMsg, ct.StatusMsg) == 0);
    if (!ret) return ret;
    ret = ret && (UserForceClose == ct.UserForceClose);
    if (!ret) return ret;
    ret = ret && (strcmp(ActiveUserID, ct.ActiveUserID) == 0);
    if (!ret) return ret;
    ret = ret && (BrokerOrderSeq == ct.BrokerOrderSeq);
    if (!ret) return ret;
    ret = ret && (strcmp(RelativeOrderSysID, ct.RelativeOrderSysID) == 0);
    if (!ret) return ret;
    ret = ret && (ZCETotalTradedVolume == ct.ZCETotalTradedVolume);
    if (!ret) return ret;

    return ret;
  }
};

///有序的经纪公司用户事件
struct CShfeFtdcSequencialBrokerUserEventField
{
  ///流中唯一的序列号
  TShfeFtdcSequenceNoType	UniqSequenceNo;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///用户事件类型
  TShfeFtdcUserEventTypeType	UserEventType;
  ///用户事件序号
  TShfeFtdcSequenceNoType	EventSequenceNo;
  ///事件发生日期
  TShfeFtdcDateType	EventDate;
  ///事件发生时间
  TShfeFtdcTimeType	EventTime;
  ///用户事件信息
  TShfeFtdcUserEventInfoType	UserEventInfo;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;

  bool operator==(const CShfeFtdcSequencialBrokerUserEventField &ct) const
  {
    bool ret = true;
    ret = ret && (UniqSequenceNo == ct.UniqSequenceNo);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (UserEventType == ct.UserEventType);
    if (!ret) return ret;
    ret = ret && (EventSequenceNo == ct.EventSequenceNo);
    if (!ret) return ret;
    ret = ret && (strcmp(EventDate, ct.EventDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(EventTime, ct.EventTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserEventInfo, ct.UserEventInfo) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///有序的持仓
struct CShfeFtdcSequencialPositionField
{
  ///流中唯一的序列号
  TShfeFtdcSequenceNoType	UniqSequenceNo;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///持仓多空方向
  TShfeFtdcPosiDirectionType	PosiDirection;
  ///投机套保标志
  TShfeFtdcHedgeFlagType	HedgeFlag;
  ///持仓日期
  TShfeFtdcPositionDateType	PositionDate;
  ///上日持仓
  TShfeFtdcVolumeType	YdPosition;
  ///今日持仓
  TShfeFtdcVolumeType	Position;
  ///多头冻结
  TShfeFtdcVolumeType	LongFrozen;
  ///空头冻结
  TShfeFtdcVolumeType	ShortFrozen;
  ///开仓冻结金额
  TShfeFtdcMoneyType	LongFrozenAmount;
  ///开仓冻结金额
  TShfeFtdcMoneyType	ShortFrozenAmount;
  ///开仓量
  TShfeFtdcVolumeType	OpenVolume;
  ///平仓量
  TShfeFtdcVolumeType	CloseVolume;
  ///开仓金额
  TShfeFtdcMoneyType	OpenAmount;
  ///平仓金额
  TShfeFtdcMoneyType	CloseAmount;
  ///持仓成本
  TShfeFtdcMoneyType	PositionCost;
  ///上次占用的保证金
  TShfeFtdcMoneyType	PreMargin;
  ///占用的保证金
  TShfeFtdcMoneyType	UseMargin;
  ///冻结的保证金
  TShfeFtdcMoneyType	FrozenMargin;
  ///冻结的资金
  TShfeFtdcMoneyType	FrozenCash;
  ///冻结的手续费
  TShfeFtdcMoneyType	FrozenCommission;
  ///资金差额
  TShfeFtdcMoneyType	CashIn;
  ///手续费
  TShfeFtdcMoneyType	Commission;
  ///平仓盈亏
  TShfeFtdcMoneyType	CloseProfit;
  ///持仓盈亏
  TShfeFtdcMoneyType	PositionProfit;
  ///上次结算价
  TShfeFtdcPriceType	PreSettlementPrice;
  ///本次结算价
  TShfeFtdcPriceType	SettlementPrice;
  ///交易日
  TShfeFtdcDateType	TradingDay;
  ///结算编号
  TShfeFtdcSettlementIDType	SettlementID;
  ///开仓成本
  TShfeFtdcMoneyType	OpenCost;
  ///交易所保证金
  TShfeFtdcMoneyType	ExchangeMargin;
  ///组合成交形成的持仓
  TShfeFtdcVolumeType	CombPosition;
  ///组合多头冻结
  TShfeFtdcVolumeType	CombLongFrozen;
  ///组合空头冻结
  TShfeFtdcVolumeType	CombShortFrozen;
  ///逐日盯市平仓盈亏
  TShfeFtdcMoneyType	CloseProfitByDate;
  ///逐笔对冲平仓盈亏
  TShfeFtdcMoneyType	CloseProfitByTrade;
  ///今日持仓
  TShfeFtdcVolumeType	TodayPosition;
  ///保证金率
  TShfeFtdcRatioType	MarginRateByMoney;
  ///保证金率(按手数)
  TShfeFtdcRatioType	MarginRateByVolume;

  bool operator==(const CShfeFtdcSequencialPositionField &ct) const
  {
    bool ret = true;
    ret = ret && (UniqSequenceNo == ct.UniqSequenceNo);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (PosiDirection == ct.PosiDirection);
    if (!ret) return ret;
    ret = ret && (HedgeFlag == ct.HedgeFlag);
    if (!ret) return ret;
    ret = ret && (PositionDate == ct.PositionDate);
    if (!ret) return ret;
    ret = ret && (YdPosition == ct.YdPosition);
    if (!ret) return ret;
    ret = ret && (Position == ct.Position);
    if (!ret) return ret;
    ret = ret && (LongFrozen == ct.LongFrozen);
    if (!ret) return ret;
    ret = ret && (ShortFrozen == ct.ShortFrozen);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(LongFrozenAmount, ct.LongFrozenAmount));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ShortFrozenAmount, ct.ShortFrozenAmount));
    if (!ret) return ret;
    ret = ret && (OpenVolume == ct.OpenVolume);
    if (!ret) return ret;
    ret = ret && (CloseVolume == ct.CloseVolume);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(OpenAmount, ct.OpenAmount));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CloseAmount, ct.CloseAmount));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PositionCost, ct.PositionCost));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreMargin, ct.PreMargin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(UseMargin, ct.UseMargin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(FrozenMargin, ct.FrozenMargin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(FrozenCash, ct.FrozenCash));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(FrozenCommission, ct.FrozenCommission));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CashIn, ct.CashIn));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Commission, ct.Commission));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CloseProfit, ct.CloseProfit));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PositionProfit, ct.PositionProfit));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreSettlementPrice, ct.PreSettlementPrice));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(SettlementPrice, ct.SettlementPrice));
    if (!ret) return ret;
    ret = ret && (strcmp(TradingDay, ct.TradingDay) == 0);
    if (!ret) return ret;
    ret = ret && (SettlementID == ct.SettlementID);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(OpenCost, ct.OpenCost));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ExchangeMargin, ct.ExchangeMargin));
    if (!ret) return ret;
    ret = ret && (CombPosition == ct.CombPosition);
    if (!ret) return ret;
    ret = ret && (CombLongFrozen == ct.CombLongFrozen);
    if (!ret) return ret;
    ret = ret && (CombShortFrozen == ct.CombShortFrozen);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CloseProfitByDate, ct.CloseProfitByDate));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CloseProfitByTrade, ct.CloseProfitByTrade));
    if (!ret) return ret;
    ret = ret && (TodayPosition == ct.TodayPosition);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(MarginRateByMoney, ct.MarginRateByMoney));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(MarginRateByVolume, ct.MarginRateByVolume));
    if (!ret) return ret;

    return ret;
  }
};

///查询客户风险通知模版
struct CShfeFtdcQryRiskNotifyPatternField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///保留字段
  TShfeFtdcCommentType	Reserve;

  bool operator==(const CShfeFtdcQryRiskNotifyPatternField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(Reserve, ct.Reserve) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///客户风险通知模版
struct CShfeFtdcRiskNotifyPatternField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///用户代码，请求修改模版时有效
  TShfeFtdcUserIDType	UserID;
  ///通知类型
  TShfeFtdcNotifyClassType	NotifyClass;
  ///是否启用
  TShfeFtdcBoolType	IsActive;
  ///是否自动系统通知
  TShfeFtdcBoolType	IsAutoSystem;
  ///是否自动短信通知
  TShfeFtdcBoolType	IsAutoSMS;
  ///是否自动邮件通知
  TShfeFtdcBoolType	IsAutoEmail;
  ///系统通知模版内容
  TShfeFtdcRiskNofityInfoType	SystemPattern;
  ///短信通知模版内容
  TShfeFtdcRiskNofityInfoType	SMSPattern;
  ///邮件通知模版内容
  TShfeFtdcRiskNofityInfoType	EmailPattern;
  ///预留参数(暂时只用作warnlevel)
  TShfeFtdcAddressType	Reserve;

  bool operator==(const CShfeFtdcRiskNotifyPatternField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (NotifyClass == ct.NotifyClass);
    if (!ret) return ret;
    ret = ret && (IsActive == ct.IsActive);
    if (!ret) return ret;
    ret = ret && (IsAutoSystem == ct.IsAutoSystem);
    if (!ret) return ret;
    ret = ret && (IsAutoSMS == ct.IsAutoSMS);
    if (!ret) return ret;
    ret = ret && (IsAutoEmail == ct.IsAutoEmail);
    if (!ret) return ret;
    ret = ret && (strcmp(SystemPattern, ct.SystemPattern) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(SMSPattern, ct.SMSPattern) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(EmailPattern, ct.EmailPattern) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(Reserve, ct.Reserve) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询客户风险通知模版中自动替换字段
struct CShfeFtdcQryRiskNotifyTokenField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///用户代码
  TShfeFtdcUserIDType	UserID;

  bool operator==(const CShfeFtdcQryRiskNotifyTokenField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///客户风险通知模版中自动替换字段
struct CShfeFtdcRiskNotifyTokenField
{
  ///自动替换字段
  TShfeFtdcExchangeNameType	Token;
  ///自动替换字段的描述
  TShfeFtdcBrokerNameType	Description;

  bool operator==(const CShfeFtdcRiskNotifyTokenField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(Token, ct.Token) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(Description, ct.Description) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///请求发送客户风险通知的命令
struct CShfeFtdcRiskNotifyCommandField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///通知类型
  TShfeFtdcNotifyClassType	NotifyClass;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///是否发送系统通知
  TShfeFtdcBoolType	IsAutoSystem;
  ///是否发送短信通知
  TShfeFtdcBoolType	IsAutoSMS;
  ///是否发送邮件通知
  TShfeFtdcBoolType	IsAutoEmail;
  ///保留字段
  TShfeFtdcCommentType	Reserve;
  ///通知模版内容
  TShfeFtdcRiskNofityInfoType	Pattern;
  ///是否允许发送正常通知
  TShfeFtdcBoolType	IsNormal;
  ///是否允许发送警示通知
  TShfeFtdcBoolType	IsWarn;

  bool operator==(const CShfeFtdcRiskNotifyCommandField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (NotifyClass == ct.NotifyClass);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (IsAutoSystem == ct.IsAutoSystem);
    if (!ret) return ret;
    ret = ret && (IsAutoSMS == ct.IsAutoSMS);
    if (!ret) return ret;
    ret = ret && (IsAutoEmail == ct.IsAutoEmail);
    if (!ret) return ret;
    ret = ret && (strcmp(Reserve, ct.Reserve) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(Pattern, ct.Pattern) == 0);
    if (!ret) return ret;
    ret = ret && (IsNormal == ct.IsNormal);
    if (!ret) return ret;
    ret = ret && (IsWarn == ct.IsWarn);
    if (!ret) return ret;

    return ret;
  }
};

///有序的客户风险通知事件
struct CShfeFtdcSequencialRiskNotifyField
{
  ///流中唯一的序列号
  TShfeFtdcSequenceNoType	UniqSequenceNo;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///请求发送该风险通知的用户代码
  TShfeFtdcUserIDType	UserID;
  ///该用户代码的风险通知事件在当天的序号
  TShfeFtdcSequenceNoType	SequenceNo;
  ///事件发生日期
  TShfeFtdcDateType	EventDate;
  ///事件发生时间
  TShfeFtdcTimeType	EventTime;
  ///通知类型
  TShfeFtdcNotifyClassType	NotifyClass;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///是否发送系统通知
  TShfeFtdcBoolType	IsAutoSystem;
  ///是否发送短信通知
  TShfeFtdcBoolType	IsAutoSMS;
  ///是否发送邮件通知
  TShfeFtdcBoolType	IsAutoEmail;
  ///系统通知内容
  TShfeFtdcRiskNofityInfoType	SystemMsg;
  ///短信通知内容
  TShfeFtdcRiskNofityInfoType	SMSMsg;
  ///邮件通知内容
  TShfeFtdcRiskNofityInfoType	EmailMsg;

  bool operator==(const CShfeFtdcSequencialRiskNotifyField &ct) const
  {
    bool ret = true;
    ret = ret && (UniqSequenceNo == ct.UniqSequenceNo);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (SequenceNo == ct.SequenceNo);
    if (!ret) return ret;
    ret = ret && (strcmp(EventDate, ct.EventDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(EventTime, ct.EventTime) == 0);
    if (!ret) return ret;
    ret = ret && (NotifyClass == ct.NotifyClass);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (IsAutoSystem == ct.IsAutoSystem);
    if (!ret) return ret;
    ret = ret && (IsAutoSMS == ct.IsAutoSMS);
    if (!ret) return ret;
    ret = ret && (IsAutoEmail == ct.IsAutoEmail);
    if (!ret) return ret;
    ret = ret && (strcmp(SystemMsg, ct.SystemMsg) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(SMSMsg, ct.SMSMsg) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(EmailMsg, ct.EmailMsg) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///客户风险通知事件
struct CShfeFtdcRiskNotifyField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///请求发送该风险通知的用户代码
  TShfeFtdcUserIDType	UserID;
  ///该用户代码的风险通知事件在当天的序号
  TShfeFtdcSequenceNoType	SequenceNo;
  ///事件发生日期
  TShfeFtdcDateType	EventDate;
  ///事件发生时间
  TShfeFtdcTimeType	EventTime;
  ///通知类型
  TShfeFtdcNotifyClassType	NotifyClass;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///是否发送系统通知
  TShfeFtdcBoolType	IsAutoSystem;
  ///是否发送短信通知
  TShfeFtdcBoolType	IsAutoSMS;
  ///是否发送邮件通知
  TShfeFtdcBoolType	IsAutoEmail;
  ///系统通知内容
  TShfeFtdcRiskNofityInfoType	SystemMsg;
  ///短信通知内容
  TShfeFtdcRiskNofityInfoType	SMSMsg;
  ///邮件通知内容
  TShfeFtdcRiskNofityInfoType	EmailMsg;

  bool operator==(const CShfeFtdcRiskNotifyField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (SequenceNo == ct.SequenceNo);
    if (!ret) return ret;
    ret = ret && (strcmp(EventDate, ct.EventDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(EventTime, ct.EventTime) == 0);
    if (!ret) return ret;
    ret = ret && (NotifyClass == ct.NotifyClass);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (IsAutoSystem == ct.IsAutoSystem);
    if (!ret) return ret;
    ret = ret && (IsAutoSMS == ct.IsAutoSMS);
    if (!ret) return ret;
    ret = ret && (IsAutoEmail == ct.IsAutoEmail);
    if (!ret) return ret;
    ret = ret && (strcmp(SystemMsg, ct.SystemMsg) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(SMSMsg, ct.SMSMsg) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(EmailMsg, ct.EmailMsg) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///强平标准
struct CShfeFtdcForceCloseStandardField
{
  ///强平标准
  TShfeFtdcForceCloseLevelType	ForceCloseLevel;
  ///强平资金释放标准
  TShfeFtdcForceCloseReleaseType	ForceCloseRelease;
  ///非停板方向持仓优先
  TShfeFtdcBoolType	FCNonLimitFirst;

  bool operator==(const CShfeFtdcForceCloseStandardField &ct) const
  {
    bool ret = true;
    ret = ret && (ForceCloseLevel == ct.ForceCloseLevel);
    if (!ret) return ret;
    ret = ret && (ForceCloseRelease == ct.ForceCloseRelease);
    if (!ret) return ret;
    ret = ret && (FCNonLimitFirst == ct.FCNonLimitFirst);
    if (!ret) return ret;

    return ret;
  }
};

///强平持仓规则
struct CShfeFtdcForceClosePositionRuleField
{
  ///产品或合约代码
  TShfeFtdcInstrumentIDType	ProductInstrumentID;
  ///强平持仓方向
  TShfeFtdcForceClosePosiDirectionType	FCPosiDirection;
  ///强平投机套保标志
  TShfeFtdcForceCloseHedgeFlagType	FCHedgeFlag;
  ///强平组合持仓标志
  TShfeFtdcForceCloseCombPosiFlagType	FCCombPosiFlag;
  ///强平历史持仓顺序
  TShfeFtdcForceCloseHistoryPosiOrderType	FCHistoryPosiOrder;
  ///强平价格类型
  TShfeFtdcForceClosePriceTypeType	FCPrice;
  ///限价调整点数
  TShfeFtdcVolumeType	PriceTick;
  ///批量强平计算规则优先级
  TShfeFtdcFCRulePriorityType	FCRulePriority;

  bool operator==(const CShfeFtdcForceClosePositionRuleField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(ProductInstrumentID, ct.ProductInstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (FCPosiDirection == ct.FCPosiDirection);
    if (!ret) return ret;
    ret = ret && (FCHedgeFlag == ct.FCHedgeFlag);
    if (!ret) return ret;
    ret = ret && (FCCombPosiFlag == ct.FCCombPosiFlag);
    if (!ret) return ret;
    ret = ret && (FCHistoryPosiOrder == ct.FCHistoryPosiOrder);
    if (!ret) return ret;
    ret = ret && (FCPrice == ct.FCPrice);
    if (!ret) return ret;
    ret = ret && (PriceTick == ct.PriceTick);
    if (!ret) return ret;
    ret = ret && (strcmp(FCRulePriority, ct.FCRulePriority) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///强平名单
struct CShfeFtdcForceCloseListField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;

  bool operator==(const CShfeFtdcForceCloseListField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///投资者强平持仓
struct CShfeFtdcForceClosePositionField
{
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///持仓多空方向
  TShfeFtdcPosiDirectionType	PosiDirection;
  ///投机套保标志
  TShfeFtdcHedgeFlagType	HedgeFlag;
  ///持仓日期
  TShfeFtdcPositionDateType	PositionDate;
  ///当前持仓数量
  TShfeFtdcVolumeType	Position;
  ///需强平持仓数量
  TShfeFtdcVolumeType	FCPosition;
  ///强平价格类型
  TShfeFtdcForceClosePriceTypeType	FCPriceType;
  ///限价调整点数
  TShfeFtdcVolumeType	PriceTick;
  ///强平价格
  TShfeFtdcPriceType	FCPrice;
  ///平仓释放的保证金
  TShfeFtdcMoneyType	ReleaseMargin;
  ///平仓盈亏
  TShfeFtdcMoneyType	CloseProfit;
  ///平仓释放的交易所保证金
  TShfeFtdcMoneyType	ExchReleaseMargin;

  bool operator==(const CShfeFtdcForceClosePositionField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (PosiDirection == ct.PosiDirection);
    if (!ret) return ret;
    ret = ret && (HedgeFlag == ct.HedgeFlag);
    if (!ret) return ret;
    ret = ret && (PositionDate == ct.PositionDate);
    if (!ret) return ret;
    ret = ret && (Position == ct.Position);
    if (!ret) return ret;
    ret = ret && (FCPosition == ct.FCPosition);
    if (!ret) return ret;
    ret = ret && (FCPriceType == ct.FCPriceType);
    if (!ret) return ret;
    ret = ret && (PriceTick == ct.PriceTick);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(FCPrice, ct.FCPrice));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ReleaseMargin, ct.ReleaseMargin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CloseProfit, ct.CloseProfit));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ExchReleaseMargin, ct.ExchReleaseMargin));
    if (!ret) return ret;

    return ret;
  }
};

///强平应答
struct CShfeFtdcRspForceClosePositionField
{
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///持仓多空方向
  TShfeFtdcPosiDirectionType	PosiDirection;
  ///投机套保标志
  TShfeFtdcHedgeFlagType	HedgeFlag;
  ///持仓日期
  TShfeFtdcPositionDateType	PositionDate;
  ///当前持仓数量
  TShfeFtdcVolumeType	Position;
  ///需强平持仓数量
  TShfeFtdcVolumeType	FCPosition;
  ///强平价格类型
  TShfeFtdcForceClosePriceTypeType	FCPriceType;
  ///限价调整点数
  TShfeFtdcVolumeType	PriceTick;
  ///强平价格
  TShfeFtdcPriceType	FCPrice;
  ///平仓释放的保证金
  TShfeFtdcMoneyType	ReleaseMargin;
  ///平仓盈亏
  TShfeFtdcMoneyType	CloseProfit;
  ///强平场景编号
  TShfeFtdcForceCloseSceneIdType	FCID;
  ///辅助强平单的生成时间
  TShfeFtdcTimeType	Time;
  ///当前时间（毫秒）
  TShfeFtdcMillisecType	CurrMillisec;
  ///平仓释放的交易所保证金
  TShfeFtdcMoneyType	ExchReleaseMargin;

  bool operator==(const CShfeFtdcRspForceClosePositionField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (PosiDirection == ct.PosiDirection);
    if (!ret) return ret;
    ret = ret && (HedgeFlag == ct.HedgeFlag);
    if (!ret) return ret;
    ret = ret && (PositionDate == ct.PositionDate);
    if (!ret) return ret;
    ret = ret && (Position == ct.Position);
    if (!ret) return ret;
    ret = ret && (FCPosition == ct.FCPosition);
    if (!ret) return ret;
    ret = ret && (FCPriceType == ct.FCPriceType);
    if (!ret) return ret;
    ret = ret && (PriceTick == ct.PriceTick);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(FCPrice, ct.FCPrice));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ReleaseMargin, ct.ReleaseMargin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CloseProfit, ct.CloseProfit));
    if (!ret) return ret;
    ret = ret && (strcmp(FCID, ct.FCID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(Time, ct.Time) == 0);
    if (!ret) return ret;
    ret = ret && (CurrMillisec == ct.CurrMillisec);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ExchReleaseMargin, ct.ExchReleaseMargin));
    if (!ret) return ret;

    return ret;
  }
};

///风控强平报单输入
struct CShfeFtdcRiskForceCloseOrderField
{
  ///风控强平类型
  TShfeFtdcForceCloseTypeType	FCType;
  ///辅助强平单的生成时间
  TShfeFtdcTimeType	Time1;
  ///辅助强平单的生成时间（毫秒）
  TShfeFtdcMillisecType	Millisec1;
  ///强平单的提交时间
  TShfeFtdcTimeType	Time2;
  ///强平单的提交时间（毫秒）
  TShfeFtdcMillisecType	Millisec2;
  ///强平场景编号
  TShfeFtdcForceCloseSceneIdType	FCSceneId;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///报单引用
  TShfeFtdcOrderRefType	OrderRef;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///报单价格条件
  TShfeFtdcOrderPriceTypeType	OrderPriceType;
  ///买卖方向
  TShfeFtdcDirectionType	Direction;
  ///组合开平标志
  TShfeFtdcCombOffsetFlagType	CombOffsetFlag;
  ///组合投机套保标志
  TShfeFtdcCombHedgeFlagType	CombHedgeFlag;
  ///价格
  TShfeFtdcPriceType	LimitPrice;
  ///数量
  TShfeFtdcVolumeType	VolumeTotalOriginal;
  ///有效期类型
  TShfeFtdcTimeConditionType	TimeCondition;
  ///GTD日期
  TShfeFtdcDateType	GTDDate;
  ///成交量类型
  TShfeFtdcVolumeConditionType	VolumeCondition;
  ///最小成交量
  TShfeFtdcVolumeType	MinVolume;
  ///触发条件
  TShfeFtdcContingentConditionType	ContingentCondition;
  ///止损价
  TShfeFtdcPriceType	StopPrice;
  ///强平原因
  TShfeFtdcForceCloseReasonType	ForceCloseReason;
  ///自动挂起标志
  TShfeFtdcBoolType	IsAutoSuspend;
  ///业务单元
  TShfeFtdcBusinessUnitType	BusinessUnit;
  ///请求编号
  TShfeFtdcRequestIDType	RequestID;
  ///用户强评标志
  TShfeFtdcBoolType	UserForceClose;
  ///前置编号
  TShfeFtdcFrontIDType	FrontID;
  ///会话编号
  TShfeFtdcSessionIDType	SessionID;

  bool operator==(const CShfeFtdcRiskForceCloseOrderField &ct) const
  {
    bool ret = true;
    ret = ret && (FCType == ct.FCType);
    if (!ret) return ret;
    ret = ret && (strcmp(Time1, ct.Time1) == 0);
    if (!ret) return ret;
    ret = ret && (Millisec1 == ct.Millisec1);
    if (!ret) return ret;
    ret = ret && (strcmp(Time2, ct.Time2) == 0);
    if (!ret) return ret;
    ret = ret && (Millisec2 == ct.Millisec2);
    if (!ret) return ret;
    ret = ret && (strcmp(FCSceneId, ct.FCSceneId) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderRef, ct.OrderRef) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (OrderPriceType == ct.OrderPriceType);
    if (!ret) return ret;
    ret = ret && (Direction == ct.Direction);
    if (!ret) return ret;
    for (int i = 0; i < 4; ++i) {
      ret = ret && (CombOffsetFlag[i] == ct.CombOffsetFlag[i]);
      if (!ret) return ret;
    }
    for (int i = 0; i < 4; ++i) {
      ret = ret && (CombHedgeFlag[i] == ct.CombHedgeFlag[i]);
      if (!ret) return ret;
    }
    ret = ret && (EQUALDOUBLE(LimitPrice, ct.LimitPrice));
    if (!ret) return ret;
    ret = ret && (VolumeTotalOriginal == ct.VolumeTotalOriginal);
    if (!ret) return ret;
    ret = ret && (TimeCondition == ct.TimeCondition);
    if (!ret) return ret;
    ret = ret && (strcmp(GTDDate, ct.GTDDate) == 0);
    if (!ret) return ret;
    ret = ret && (VolumeCondition == ct.VolumeCondition);
    if (!ret) return ret;
    ret = ret && (MinVolume == ct.MinVolume);
    if (!ret) return ret;
    ret = ret && (ContingentCondition == ct.ContingentCondition);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(StopPrice, ct.StopPrice));
    if (!ret) return ret;
    ret = ret && (ForceCloseReason == ct.ForceCloseReason);
    if (!ret) return ret;
    ret = ret && (IsAutoSuspend == ct.IsAutoSuspend);
    if (!ret) return ret;
    ret = ret && (strcmp(BusinessUnit, ct.BusinessUnit) == 0);
    if (!ret) return ret;
    ret = ret && (RequestID == ct.RequestID);
    if (!ret) return ret;
    ret = ret && (UserForceClose == ct.UserForceClose);
    if (!ret) return ret;
    ret = ret && (FrontID == ct.FrontID);
    if (!ret) return ret;
    ret = ret && (SessionID == ct.SessionID);
    if (!ret) return ret;

    return ret;
  }
};

///前置状态报告
struct CShfeFtdcFrontStatusReportField
{
  ///前置time(NULL)
  TShfeFtdcSessionIDType	Seconds;

  bool operator==(const CShfeFtdcFrontStatusReportField &ct) const
  {
    bool ret = true;
    ret = ret && (Seconds == ct.Seconds);
    if (!ret) return ret;

    return ret;
  }
};

///净持仓保证金指标参数
struct CShfeFtdcIndexNPPField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///产品代码
  TShfeFtdcInstrumentIDsType	ProductIDs;
  ///报警值(在参数中是警示值,在指标FullIndexNPP中是指标值)
  TShfeFtdcRatioType	WarnLevel;

  bool operator==(const CShfeFtdcIndexNPPField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ProductIDs, ct.ProductIDs) == 0);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(WarnLevel, ct.WarnLevel));
    if (!ret) return ret;

    return ret;
  }
};

///净持仓保证金指标值
struct CShfeFtdcFullIndexNPPField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///产品代码
  TShfeFtdcInstrumentIDsType	ProductIDs;
  ///报警值(在参数中是警示值,在指标FullIndexNPP中是指标值)
  TShfeFtdcRatioType	WarnLevel;
  ///多头保证金
  TShfeFtdcMoneyType	LongMargin;
  ///空头保证金
  TShfeFtdcMoneyType	ShortMargin;
  ///总权益
  TShfeFtdcMoneyType	Balance;
  ///报警阈值
  TShfeFtdcRatioType	RealWarnLevel;

  bool operator==(const CShfeFtdcFullIndexNPPField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ProductIDs, ct.ProductIDs) == 0);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(WarnLevel, ct.WarnLevel));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(LongMargin, ct.LongMargin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ShortMargin, ct.ShortMargin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Balance, ct.Balance));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(RealWarnLevel, ct.RealWarnLevel));
    if (!ret) return ret;

    return ret;
  }
};

///一般查询请求
struct CShfeFtdcNormalRiskQueryField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///用户代码
  TShfeFtdcUserIDType	UserID;

  bool operator==(const CShfeFtdcNormalRiskQueryField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询安全价格波动范围请求
struct CShfeFtdcQrySafePriceRangeField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///合约价格波动方法
  TShfeFtdcPriceVaryAlgoType	PriceVaryAlgo;
  ///价格波动的基准价类型(v5.1.2之后废弃)
  TShfeFtdcPriceTypeType	BasePriceType;
  ///风险类型
  TShfeFtdcNotifyClassType	RiskLevel;
  ///按合约顺序波动时的最大允许停板个数
  TShfeFtdcVolumeType	MaxLimitDay;

  bool operator==(const CShfeFtdcQrySafePriceRangeField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (PriceVaryAlgo == ct.PriceVaryAlgo);
    if (!ret) return ret;
    ret = ret && (BasePriceType == ct.BasePriceType);
    if (!ret) return ret;
    ret = ret && (RiskLevel == ct.RiskLevel);
    if (!ret) return ret;
    ret = ret && (MaxLimitDay == ct.MaxLimitDay);
    if (!ret) return ret;

    return ret;
  }
};

///价格波动参数
struct CShfeFtdcPriceVaryParamField
{
  ///合约编号
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///价格波动方向
  TShfeFtdcPriceVaryDirType	Direction;
  ///价格波动幅度(>=0有效)
  TShfeFtdcRatioType	Pecent;
  ///价格波动的基准价类型
  TShfeFtdcPriceTypeType	BasePriceType;
  ///自定义基准价
  TShfeFtdcPriceType	BasePrice;

  bool operator==(const CShfeFtdcPriceVaryParamField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (Direction == ct.Direction);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Pecent, ct.Pecent));
    if (!ret) return ret;
    ret = ret && (BasePriceType == ct.BasePriceType);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(BasePrice, ct.BasePrice));
    if (!ret) return ret;

    return ret;
  }
};

///查询安全价格波动范围应答
struct CShfeFtdcRspSafePriceRangeField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///基准价格
  TShfeFtdcPriceType	BasePrice;
  ///波动价格
  TShfeFtdcPriceType	LimitPrice;
  ///总波动幅度
  TShfeFtdcRatioType	VaryPecent;
  ///停板个数
  TShfeFtdcVolumeType	LimitDayCnt;
  ///总波动点数
  TShfeFtdcVolumeType	VaryTickCnt;
  ///停板点数
  TShfeFtdcVolumeType	LimitTickCnt;
  ///是否有波动限制
  TShfeFtdcBoolType	HasLimit;
  ///涨跌停
  TShfeFtdcRatioType	PecentPerLimit;
  ///停板波动
  TShfeFtdcRatioType	InLimitVaryPct;
  ///停板外波动
  TShfeFtdcRatioType	OutLimitVaryPct;
  ///总买持
  TShfeFtdcVolumeType	LongVol;
  ///总卖持
  TShfeFtdcVolumeType	ShortVol;
  ///波动方向
  TShfeFtdcPriceVaryDirType	Direction;
  ///不利方向
  TShfeFtdcPriceVaryDirType	BadDir;

  bool operator==(const CShfeFtdcRspSafePriceRangeField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(BasePrice, ct.BasePrice));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(LimitPrice, ct.LimitPrice));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(VaryPecent, ct.VaryPecent));
    if (!ret) return ret;
    ret = ret && (LimitDayCnt == ct.LimitDayCnt);
    if (!ret) return ret;
    ret = ret && (VaryTickCnt == ct.VaryTickCnt);
    if (!ret) return ret;
    ret = ret && (LimitTickCnt == ct.LimitTickCnt);
    if (!ret) return ret;
    ret = ret && (HasLimit == ct.HasLimit);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PecentPerLimit, ct.PecentPerLimit));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(InLimitVaryPct, ct.InLimitVaryPct));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(OutLimitVaryPct, ct.OutLimitVaryPct));
    if (!ret) return ret;
    ret = ret && (LongVol == ct.LongVol);
    if (!ret) return ret;
    ret = ret && (ShortVol == ct.ShortVol);
    if (!ret) return ret;
    ret = ret && (Direction == ct.Direction);
    if (!ret) return ret;
    ret = ret && (BadDir == ct.BadDir);
    if (!ret) return ret;

    return ret;
  }
};

///投资者查分层
struct CShfeFtdcFullInvestorGroupField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者分组代码
  TShfeFtdcInvestorIDType	InvestorGroupID;
  ///投资者分组名称
  TShfeFtdcInvestorGroupNameType	InvestorGroupName;

  bool operator==(const CShfeFtdcFullInvestorGroupField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorGroupID, ct.InvestorGroupID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorGroupName, ct.InvestorGroupName) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///投资者查询分类
struct CShfeFtdcInvestorGroupMapField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者分组代码
  TShfeFtdcInvestorIDType	InvestorGroupID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;

  bool operator==(const CShfeFtdcInvestorGroupMapField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorGroupID, ct.InvestorGroupID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询价格波动对投资者风险的影响
struct CShfeFtdcQryPriceVaryEffectField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///风险类型
  TShfeFtdcNotifyClassType	RiskLevel;

  bool operator==(const CShfeFtdcQryPriceVaryEffectField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (RiskLevel == ct.RiskLevel);
    if (!ret) return ret;

    return ret;
  }
};

///经纪公司投资者
struct CShfeFtdcBrokerInvestorField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;

  bool operator==(const CShfeFtdcBrokerInvestorField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///交易系统参数
struct CShfeFtdcTradeParamField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///参数代码
  TShfeFtdcTradeParamIDType	TradeParamID;
  ///参数代码值
  TShfeFtdcSettlementParamValueType	TradeParamValue;
  ///备注
  TShfeFtdcMemoType	Memo;

  bool operator==(const CShfeFtdcTradeParamField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (TradeParamID == ct.TradeParamID);
    if (!ret) return ret;
    ret = ret && (strcmp(TradeParamValue, ct.TradeParamValue) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(Memo, ct.Memo) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///风控预埋单
struct CShfeFtdcRiskParkedOrderField
{
  ///预埋报单编号
  TShfeFtdcParkedOrderIDType	ParkedOrderID;
  ///预埋单本地编号
  TShfeFtdcParkedOrderIDType	LocalID;
  ///风控用户类型
  TShfeFtdcRiskUserTypeType	UserType;
  ///预埋单状态
  TShfeFtdcRiskParkedOrderStatusType	Status;
  ///预埋单状态信息
  TShfeFtdcErrorMsgType	StatusMsg;
  ///触发类型
  TShfeFtdcOrderTriggerTypeType	TriggerType;
  ///交易阶段
  TShfeFtdcVolumeType	TradeSegment;
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///风控强平类型
  TShfeFtdcForceCloseTypeType	FCType;
  ///辅助强平单的生成时间
  TShfeFtdcTimeType	Time1;
  ///辅助强平单的生成时间（毫秒）
  TShfeFtdcMillisecType	Millisec1;
  ///强平单的提交时间
  TShfeFtdcTimeType	Time2;
  ///强平单的提交时间（毫秒）
  TShfeFtdcMillisecType	Millisec2;
  ///强平场景编号
  TShfeFtdcForceCloseSceneIdType	FCSceneId;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///报单引用
  TShfeFtdcOrderRefType	OrderRef;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///报单价格条件
  TShfeFtdcOrderPriceTypeType	OrderPriceType;
  ///买卖方向
  TShfeFtdcDirectionType	Direction;
  ///组合开平标志
  TShfeFtdcCombOffsetFlagType	CombOffsetFlag;
  ///组合投机套保标志
  TShfeFtdcCombHedgeFlagType	CombHedgeFlag;
  ///价格
  TShfeFtdcPriceType	LimitPrice;
  ///数量
  TShfeFtdcVolumeType	VolumeTotalOriginal;
  ///有效期类型
  TShfeFtdcTimeConditionType	TimeCondition;
  ///GTD日期
  TShfeFtdcDateType	GTDDate;
  ///成交量类型
  TShfeFtdcVolumeConditionType	VolumeCondition;
  ///最小成交量
  TShfeFtdcVolumeType	MinVolume;
  ///触发条件
  TShfeFtdcContingentConditionType	ContingentCondition;
  ///止损价
  TShfeFtdcPriceType	StopPrice;
  ///强平原因
  TShfeFtdcForceCloseReasonType	ForceCloseReason;
  ///自动挂起标志
  TShfeFtdcBoolType	IsAutoSuspend;
  ///业务单元
  TShfeFtdcBusinessUnitType	BusinessUnit;
  ///请求编号
  TShfeFtdcRequestIDType	RequestID;
  ///用户强评标志
  TShfeFtdcBoolType	UserForceClose;
  ///报单提交状态
  TShfeFtdcOrderSubmitStatusType	OrderSubmitStatus;
  ///报单状态
  TShfeFtdcOrderStatusType	OrderStatus;
  ///报单状态信息
  TShfeFtdcErrorMsgType	OrderStatusMsg;
  ///错误代码
  TShfeFtdcErrorIDType	ErrorID;
  ///错误信息
  TShfeFtdcErrorMsgType	ErrorMsg;
  ///预埋时间
  TShfeFtdcTimeType	ParkedTime;
  ///预埋量
  TShfeFtdcVolumeType	OriginalParkedVol;
  ///预埋时可平量
  TShfeFtdcVolumeType	MaxCloseVol1;
  ///触发时可平量
  TShfeFtdcVolumeType	MaxCloseVol2;
  ///预埋时追保
  TShfeFtdcMoneyType	Call1;
  ///触发时追保
  TShfeFtdcMoneyType	Call2;
  ///预埋时出入金
  TShfeFtdcMoneyType	MoneyIO1;
  ///触发时出入金
  TShfeFtdcMoneyType	MoneyIO2;
  ///删除原因
  TShfeFtdcCommentType	DeleteReason;
  ///强平资金释放标准
  TShfeFtdcForceCloseReleaseType	ForceCloseRelease;

  bool operator==(const CShfeFtdcRiskParkedOrderField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(ParkedOrderID, ct.ParkedOrderID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(LocalID, ct.LocalID) == 0);
    if (!ret) return ret;
    ret = ret && (UserType == ct.UserType);
    if (!ret) return ret;
    ret = ret && (Status == ct.Status);
    if (!ret) return ret;
    ret = ret && (strcmp(StatusMsg, ct.StatusMsg) == 0);
    if (!ret) return ret;
    ret = ret && (TriggerType == ct.TriggerType);
    if (!ret) return ret;
    ret = ret && (TradeSegment == ct.TradeSegment);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (FCType == ct.FCType);
    if (!ret) return ret;
    ret = ret && (strcmp(Time1, ct.Time1) == 0);
    if (!ret) return ret;
    ret = ret && (Millisec1 == ct.Millisec1);
    if (!ret) return ret;
    ret = ret && (strcmp(Time2, ct.Time2) == 0);
    if (!ret) return ret;
    ret = ret && (Millisec2 == ct.Millisec2);
    if (!ret) return ret;
    ret = ret && (strcmp(FCSceneId, ct.FCSceneId) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderRef, ct.OrderRef) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (OrderPriceType == ct.OrderPriceType);
    if (!ret) return ret;
    ret = ret && (Direction == ct.Direction);
    if (!ret) return ret;
    for (int i = 0; i < 4; ++i) {
      ret = ret && (CombOffsetFlag[i] == ct.CombOffsetFlag[i]);
      if (!ret) return ret;
    }
    for (int i = 0; i < 4; ++i) {
      ret = ret && (CombHedgeFlag[i] == ct.CombHedgeFlag[i]);
      if (!ret) return ret;
    }
    ret = ret && (EQUALDOUBLE(LimitPrice, ct.LimitPrice));
    if (!ret) return ret;
    ret = ret && (VolumeTotalOriginal == ct.VolumeTotalOriginal);
    if (!ret) return ret;
    ret = ret && (TimeCondition == ct.TimeCondition);
    if (!ret) return ret;
    ret = ret && (strcmp(GTDDate, ct.GTDDate) == 0);
    if (!ret) return ret;
    ret = ret && (VolumeCondition == ct.VolumeCondition);
    if (!ret) return ret;
    ret = ret && (MinVolume == ct.MinVolume);
    if (!ret) return ret;
    ret = ret && (ContingentCondition == ct.ContingentCondition);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(StopPrice, ct.StopPrice));
    if (!ret) return ret;
    ret = ret && (ForceCloseReason == ct.ForceCloseReason);
    if (!ret) return ret;
    ret = ret && (IsAutoSuspend == ct.IsAutoSuspend);
    if (!ret) return ret;
    ret = ret && (strcmp(BusinessUnit, ct.BusinessUnit) == 0);
    if (!ret) return ret;
    ret = ret && (RequestID == ct.RequestID);
    if (!ret) return ret;
    ret = ret && (UserForceClose == ct.UserForceClose);
    if (!ret) return ret;
    ret = ret && (OrderSubmitStatus == ct.OrderSubmitStatus);
    if (!ret) return ret;
    ret = ret && (OrderStatus == ct.OrderStatus);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderStatusMsg, ct.OrderStatusMsg) == 0);
    if (!ret) return ret;
    ret = ret && (ErrorID == ct.ErrorID);
    if (!ret) return ret;
    ret = ret && (strcmp(ErrorMsg, ct.ErrorMsg) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ParkedTime, ct.ParkedTime) == 0);
    if (!ret) return ret;
    ret = ret && (OriginalParkedVol == ct.OriginalParkedVol);
    if (!ret) return ret;
    ret = ret && (MaxCloseVol1 == ct.MaxCloseVol1);
    if (!ret) return ret;
    ret = ret && (MaxCloseVol2 == ct.MaxCloseVol2);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Call1, ct.Call1));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Call2, ct.Call2));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(MoneyIO1, ct.MoneyIO1));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(MoneyIO2, ct.MoneyIO2));
    if (!ret) return ret;
    ret = ret && (strcmp(DeleteReason, ct.DeleteReason) == 0);
    if (!ret) return ret;
    ret = ret && (ForceCloseRelease == ct.ForceCloseRelease);
    if (!ret) return ret;

    return ret;
  }
};

///删除风控预埋单
struct CShfeFtdcRemoveRiskParkedOrderField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///预埋报单编号
  TShfeFtdcParkedOrderIDType	ParkedOrderID;

  bool operator==(const CShfeFtdcRemoveRiskParkedOrderField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ParkedOrderID, ct.ParkedOrderID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///有序的风控预埋单
struct CShfeFtdcSeqRiskParkedOrderField
{
  ///流中唯一的序列号
  TShfeFtdcSequenceNoType	UniqSequenceNo;
  ///预埋报单编号
  TShfeFtdcParkedOrderIDType	ParkedOrderID;
  ///预埋单本地编号
  TShfeFtdcParkedOrderIDType	LocalID;
  ///风控用户类型
  TShfeFtdcRiskUserTypeType	UserType;
  ///预埋单状态
  TShfeFtdcRiskParkedOrderStatusType	Status;
  ///预埋单状态信息
  TShfeFtdcErrorMsgType	StatusMsg;
  ///触发类型
  TShfeFtdcOrderTriggerTypeType	TriggerType;
  ///交易阶段
  TShfeFtdcVolumeType	TradeSegment;
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///风控强平类型
  TShfeFtdcForceCloseTypeType	FCType;
  ///辅助强平单的生成时间
  TShfeFtdcTimeType	Time1;
  ///辅助强平单的生成时间（毫秒）
  TShfeFtdcMillisecType	Millisec1;
  ///强平单的提交时间
  TShfeFtdcTimeType	Time2;
  ///强平单的提交时间（毫秒）
  TShfeFtdcMillisecType	Millisec2;
  ///强平场景编号
  TShfeFtdcForceCloseSceneIdType	FCSceneId;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///报单引用
  TShfeFtdcOrderRefType	OrderRef;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///报单价格条件
  TShfeFtdcOrderPriceTypeType	OrderPriceType;
  ///买卖方向
  TShfeFtdcDirectionType	Direction;
  ///组合开平标志
  TShfeFtdcCombOffsetFlagType	CombOffsetFlag;
  ///组合投机套保标志
  TShfeFtdcCombHedgeFlagType	CombHedgeFlag;
  ///价格
  TShfeFtdcPriceType	LimitPrice;
  ///数量
  TShfeFtdcVolumeType	VolumeTotalOriginal;
  ///有效期类型
  TShfeFtdcTimeConditionType	TimeCondition;
  ///GTD日期
  TShfeFtdcDateType	GTDDate;
  ///成交量类型
  TShfeFtdcVolumeConditionType	VolumeCondition;
  ///最小成交量
  TShfeFtdcVolumeType	MinVolume;
  ///触发条件
  TShfeFtdcContingentConditionType	ContingentCondition;
  ///止损价
  TShfeFtdcPriceType	StopPrice;
  ///强平原因
  TShfeFtdcForceCloseReasonType	ForceCloseReason;
  ///自动挂起标志
  TShfeFtdcBoolType	IsAutoSuspend;
  ///业务单元
  TShfeFtdcBusinessUnitType	BusinessUnit;
  ///请求编号
  TShfeFtdcRequestIDType	RequestID;
  ///用户强评标志
  TShfeFtdcBoolType	UserForceClose;
  ///报单提交状态
  TShfeFtdcOrderSubmitStatusType	OrderSubmitStatus;
  ///报单状态
  TShfeFtdcOrderStatusType	OrderStatus;
  ///报单状态信息
  TShfeFtdcErrorMsgType	OrderStatusMsg;
  ///错误代码
  TShfeFtdcErrorIDType	ErrorID;
  ///错误信息
  TShfeFtdcErrorMsgType	ErrorMsg;
  ///预埋时间
  TShfeFtdcTimeType	ParkedTime;
  ///预埋量
  TShfeFtdcVolumeType	OriginalParkedVol;
  ///预埋时可平量
  TShfeFtdcVolumeType	MaxCloseVol1;
  ///触发时可平量
  TShfeFtdcVolumeType	MaxCloseVol2;
  ///预埋时追保
  TShfeFtdcMoneyType	Call1;
  ///触发时追保
  TShfeFtdcMoneyType	Call2;
  ///预埋时出入金
  TShfeFtdcMoneyType	MoneyIO1;
  ///触发时出入金
  TShfeFtdcMoneyType	MoneyIO2;
  ///删除原因
  TShfeFtdcCommentType	DeleteReason;
  ///强平资金释放标准
  TShfeFtdcForceCloseReleaseType	ForceCloseRelease;

  bool operator==(const CShfeFtdcSeqRiskParkedOrderField &ct) const
  {
    bool ret = true;
    ret = ret && (UniqSequenceNo == ct.UniqSequenceNo);
    if (!ret) return ret;
    ret = ret && (strcmp(ParkedOrderID, ct.ParkedOrderID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(LocalID, ct.LocalID) == 0);
    if (!ret) return ret;
    ret = ret && (UserType == ct.UserType);
    if (!ret) return ret;
    ret = ret && (Status == ct.Status);
    if (!ret) return ret;
    ret = ret && (strcmp(StatusMsg, ct.StatusMsg) == 0);
    if (!ret) return ret;
    ret = ret && (TriggerType == ct.TriggerType);
    if (!ret) return ret;
    ret = ret && (TradeSegment == ct.TradeSegment);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (FCType == ct.FCType);
    if (!ret) return ret;
    ret = ret && (strcmp(Time1, ct.Time1) == 0);
    if (!ret) return ret;
    ret = ret && (Millisec1 == ct.Millisec1);
    if (!ret) return ret;
    ret = ret && (strcmp(Time2, ct.Time2) == 0);
    if (!ret) return ret;
    ret = ret && (Millisec2 == ct.Millisec2);
    if (!ret) return ret;
    ret = ret && (strcmp(FCSceneId, ct.FCSceneId) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderRef, ct.OrderRef) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (OrderPriceType == ct.OrderPriceType);
    if (!ret) return ret;
    ret = ret && (Direction == ct.Direction);
    if (!ret) return ret;
    for (int i = 0; i < 4; ++i) {
      ret = ret && (CombOffsetFlag[i] == ct.CombOffsetFlag[i]);
      if (!ret) return ret;
    }
    for (int i = 0; i < 4; ++i) {
      ret = ret && (CombHedgeFlag[i] == ct.CombHedgeFlag[i]);
      if (!ret) return ret;
    }
    ret = ret && (EQUALDOUBLE(LimitPrice, ct.LimitPrice));
    if (!ret) return ret;
    ret = ret && (VolumeTotalOriginal == ct.VolumeTotalOriginal);
    if (!ret) return ret;
    ret = ret && (TimeCondition == ct.TimeCondition);
    if (!ret) return ret;
    ret = ret && (strcmp(GTDDate, ct.GTDDate) == 0);
    if (!ret) return ret;
    ret = ret && (VolumeCondition == ct.VolumeCondition);
    if (!ret) return ret;
    ret = ret && (MinVolume == ct.MinVolume);
    if (!ret) return ret;
    ret = ret && (ContingentCondition == ct.ContingentCondition);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(StopPrice, ct.StopPrice));
    if (!ret) return ret;
    ret = ret && (ForceCloseReason == ct.ForceCloseReason);
    if (!ret) return ret;
    ret = ret && (IsAutoSuspend == ct.IsAutoSuspend);
    if (!ret) return ret;
    ret = ret && (strcmp(BusinessUnit, ct.BusinessUnit) == 0);
    if (!ret) return ret;
    ret = ret && (RequestID == ct.RequestID);
    if (!ret) return ret;
    ret = ret && (UserForceClose == ct.UserForceClose);
    if (!ret) return ret;
    ret = ret && (OrderSubmitStatus == ct.OrderSubmitStatus);
    if (!ret) return ret;
    ret = ret && (OrderStatus == ct.OrderStatus);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderStatusMsg, ct.OrderStatusMsg) == 0);
    if (!ret) return ret;
    ret = ret && (ErrorID == ct.ErrorID);
    if (!ret) return ret;
    ret = ret && (strcmp(ErrorMsg, ct.ErrorMsg) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ParkedTime, ct.ParkedTime) == 0);
    if (!ret) return ret;
    ret = ret && (OriginalParkedVol == ct.OriginalParkedVol);
    if (!ret) return ret;
    ret = ret && (MaxCloseVol1 == ct.MaxCloseVol1);
    if (!ret) return ret;
    ret = ret && (MaxCloseVol2 == ct.MaxCloseVol2);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Call1, ct.Call1));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Call2, ct.Call2));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(MoneyIO1, ct.MoneyIO1));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(MoneyIO2, ct.MoneyIO2));
    if (!ret) return ret;
    ret = ret && (strcmp(DeleteReason, ct.DeleteReason) == 0);
    if (!ret) return ret;
    ret = ret && (ForceCloseRelease == ct.ForceCloseRelease);
    if (!ret) return ret;

    return ret;
  }
};

///风控中投资者消息
struct CShfeFtdcRiskInvestorInfoField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///手机
  TShfeFtdcTelephoneType	Mobile;
  ///电子邮件
  TShfeFtdcEMailType	EMail;
  ///是否允许发送邮件
  TShfeFtdcBoolType	IsEMail;
  ///是否允许发送邮件
  TShfeFtdcBoolType	IsSMS;
  ///投资者类型
  TShfeFtdcInvestorTypeType	InvestorType;
  ///国家代码
  TShfeFtdcUOACountryCodeType	PhoneCountryCode;
  ///区号
  TShfeFtdcAreaCodeType	PhoneAreaCode;
  ///开户授权人国家代码
  TShfeFtdcUOACountryCodeType	OpenPhoneCountryCode;
  ///开户授权人区号
  TShfeFtdcAreaCodeType	OpenPhoneAreaCode;
  ///指定下单人国家代码
  TShfeFtdcUOACountryCodeType	OrderPhoneCountryCode;
  ///指定下单人区号
  TShfeFtdcAreaCodeType	OrderPhoneAreaCode;
  ///资金调拨人国家代码
  TShfeFtdcUOACountryCodeType	FundPhoneCountryCode;
  ///资金调拨人区号
  TShfeFtdcAreaCodeType	FundPhoneAreaCode;
  ///结算单确认人国家代码
  TShfeFtdcUOACountryCodeType	SettlePhoneCountryCode;
  ///结算单确认人区号
  TShfeFtdcAreaCodeType	SettlePhoneAreaCode;

  bool operator==(const CShfeFtdcRiskInvestorInfoField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(Mobile, ct.Mobile) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(EMail, ct.EMail) == 0);
    if (!ret) return ret;
    ret = ret && (IsEMail == ct.IsEMail);
    if (!ret) return ret;
    ret = ret && (IsSMS == ct.IsSMS);
    if (!ret) return ret;
    ret = ret && (InvestorType == ct.InvestorType);
    if (!ret) return ret;
    ret = ret && (strcmp(PhoneCountryCode, ct.PhoneCountryCode) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(PhoneAreaCode, ct.PhoneAreaCode) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OpenPhoneCountryCode, ct.OpenPhoneCountryCode) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OpenPhoneAreaCode, ct.OpenPhoneAreaCode) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderPhoneCountryCode, ct.OrderPhoneCountryCode) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OrderPhoneAreaCode, ct.OrderPhoneAreaCode) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(FundPhoneCountryCode, ct.FundPhoneCountryCode) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(FundPhoneAreaCode, ct.FundPhoneAreaCode) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(SettlePhoneCountryCode, ct.SettlePhoneCountryCode) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(SettlePhoneAreaCode, ct.SettlePhoneAreaCode) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///客户风险通知版本A
struct CShfeFtdcRiskNotifyAField
{
  ///风险通知事件在当天的序号
  TShfeFtdcSequenceNoType	SequenceNo;
  ///事件发生日期
  TShfeFtdcDateType	EventDate;
  ///事件发生时间
  TShfeFtdcTimeType	EventTime;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///请求发送该风险通知的用户代码
  TShfeFtdcUserIDType	UserID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///通知类型
  TShfeFtdcNotifyClassType	NotifyClass;
  ///风险通知途径
  TShfeFtdcRiskNotifyMethodType	NotifyMethod;
  ///风险通知状态
  TShfeFtdcRiskNotifyStatusType	NotifyStatus;
  ///通知内容
  TShfeFtdcRiskNofityInfoType	Message;
  ///预留字段(人工通知-通知操作员，否则为错误原因)
  TShfeFtdcCommentType	Reserve;

  bool operator==(const CShfeFtdcRiskNotifyAField &ct) const
  {
    bool ret = true;
    ret = ret && (SequenceNo == ct.SequenceNo);
    if (!ret) return ret;
    ret = ret && (strcmp(EventDate, ct.EventDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(EventTime, ct.EventTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (NotifyClass == ct.NotifyClass);
    if (!ret) return ret;
    ret = ret && (NotifyMethod == ct.NotifyMethod);
    if (!ret) return ret;
    ret = ret && (NotifyStatus == ct.NotifyStatus);
    if (!ret) return ret;
    ret = ret && (strcmp(Message, ct.Message) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(Reserve, ct.Reserve) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///有序的客户风险通知版本A
struct CShfeFtdcSeqRiskNotifyAField
{
  ///流中唯一的序列号
  TShfeFtdcSequenceNoType	UniqSequenceNo;
  ///风险通知事件在当天的序号
  TShfeFtdcSequenceNoType	SequenceNo;
  ///事件发生日期
  TShfeFtdcDateType	EventDate;
  ///事件发生时间
  TShfeFtdcTimeType	EventTime;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///请求发送该风险通知的用户代码
  TShfeFtdcUserIDType	UserID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///通知类型
  TShfeFtdcNotifyClassType	NotifyClass;
  ///风险通知途径
  TShfeFtdcRiskNotifyMethodType	NotifyMethod;
  ///风险通知状态
  TShfeFtdcRiskNotifyStatusType	NotifyStatus;
  ///通知内容
  TShfeFtdcRiskNofityInfoType	Message;
  ///预留字段(人工通知-通知操作员，否则为错误原因)
  TShfeFtdcCommentType	Reserve;

  bool operator==(const CShfeFtdcSeqRiskNotifyAField &ct) const
  {
    bool ret = true;
    ret = ret && (UniqSequenceNo == ct.UniqSequenceNo);
    if (!ret) return ret;
    ret = ret && (SequenceNo == ct.SequenceNo);
    if (!ret) return ret;
    ret = ret && (strcmp(EventDate, ct.EventDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(EventTime, ct.EventTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (NotifyClass == ct.NotifyClass);
    if (!ret) return ret;
    ret = ret && (NotifyMethod == ct.NotifyMethod);
    if (!ret) return ret;
    ret = ret && (NotifyStatus == ct.NotifyStatus);
    if (!ret) return ret;
    ret = ret && (strcmp(Message, ct.Message) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(Reserve, ct.Reserve) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///有序的出入金
struct CShfeFtdcSeqDepositField
{
  ///流中唯一的序列号
  TShfeFtdcSequenceNoType	UniqSequenceNo;
  ///出入金类型
  TShfeFtdcFundIOTypeType	Type;
  ///有效标志-有效或冲正
  TShfeFtdcAvailabilityFlagType	Flag;
  ///出入金方向
  TShfeFtdcFundDirectionType	Direction;
  ///交易日
  TShfeFtdcDateType	TradingDay;
  ///流水号
  TShfeFtdcDepositSeqNoType	SequenceNo;
  ///时间
  TShfeFtdcTimeType	Time;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///出入金金额
  TShfeFtdcMoneyType	Amount;

  bool operator==(const CShfeFtdcSeqDepositField &ct) const
  {
    bool ret = true;
    ret = ret && (UniqSequenceNo == ct.UniqSequenceNo);
    if (!ret) return ret;
    ret = ret && (Type == ct.Type);
    if (!ret) return ret;
    ret = ret && (Flag == ct.Flag);
    if (!ret) return ret;
    ret = ret && (Direction == ct.Direction);
    if (!ret) return ret;
    ret = ret && (strcmp(TradingDay, ct.TradingDay) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(SequenceNo, ct.SequenceNo) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(Time, ct.Time) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Amount, ct.Amount));
    if (!ret) return ret;

    return ret;
  }
};

///有序的交易编码
struct CShfeFtdcSeqTradingCodeField
{
  ///流中唯一的序列号
  TShfeFtdcSequenceNoType	UniqSequenceNo;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///交易所代码
  TShfeFtdcExchangeIDType	ExchangeID;
  ///客户代码
  TShfeFtdcClientIDType	ClientID;
  ///是否活跃
  TShfeFtdcBoolType	IsActive;
  ///操作标志(修改或删除)
  TShfeFtdcActionFlagType	Action;
  ///交易编码类型
  TShfeFtdcClientIDTypeType	ClientIDType;

  bool operator==(const CShfeFtdcSeqTradingCodeField &ct) const
  {
    bool ret = true;
    ret = ret && (UniqSequenceNo == ct.UniqSequenceNo);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeID, ct.ExchangeID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ClientID, ct.ClientID) == 0);
    if (!ret) return ret;
    ret = ret && (IsActive == ct.IsActive);
    if (!ret) return ret;
    ret = ret && (Action == ct.Action);
    if (!ret) return ret;
    ret = ret && (ClientIDType == ct.ClientIDType);
    if (!ret) return ret;

    return ret;
  }
};

///风控用户操作事件
struct CShfeFtdcRiskUserEventField
{
  ///用户事件当天的序号
  TShfeFtdcSequenceNoType	SequenceNo;
  ///事件发生日期
  TShfeFtdcDateType	EventDate;
  ///事件发生时间
  TShfeFtdcTimeType	EventTime;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///事件类型
  TShfeFtdcRiskUserEventType	EventType;
  ///事件信息
  TShfeFtdcUserEventInfoType	EventInfo;

  bool operator==(const CShfeFtdcRiskUserEventField &ct) const
  {
    bool ret = true;
    ret = ret && (SequenceNo == ct.SequenceNo);
    if (!ret) return ret;
    ret = ret && (strcmp(EventDate, ct.EventDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(EventTime, ct.EventTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (EventType == ct.EventType);
    if (!ret) return ret;
    ret = ret && (strcmp(EventInfo, ct.EventInfo) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///风控订阅序列号
struct CShfeFtdcRiskNtfSequenceField
{
  ///序号
  TShfeFtdcSequenceNoType	SequenceNo;
  ///业务数据类型
  TShfeFtdcBusinessUnitType	DataType;

  bool operator==(const CShfeFtdcRiskNtfSequenceField &ct) const
  {
    bool ret = true;
    ret = ret && (SequenceNo == ct.SequenceNo);
    if (!ret) return ret;
    ret = ret && (strcmp(DataType, ct.DataType) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///客户风险通知模版版本A
struct CShfeFtdcRiskNotifyPatternAField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///用户代码，请求修改模版时有效
  TShfeFtdcUserIDType	UserID;
  ///通知类型
  TShfeFtdcNotifyClassType	NotifyClass;
  ///风险通知途径
  TShfeFtdcRiskNotifyMethodType	NotifyMethod;
  ///是否启用
  TShfeFtdcBoolType	IsActive;
  ///通知模版内容
  TShfeFtdcRiskNofityInfoType	Pattern;
  ///预留参数(暂时只用作warnlevel)
  TShfeFtdcCommentType	Reserve;

  bool operator==(const CShfeFtdcRiskNotifyPatternAField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (NotifyClass == ct.NotifyClass);
    if (!ret) return ret;
    ret = ret && (NotifyMethod == ct.NotifyMethod);
    if (!ret) return ret;
    ret = ret && (IsActive == ct.IsActive);
    if (!ret) return ret;
    ret = ret && (strcmp(Pattern, ct.Pattern) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(Reserve, ct.Reserve) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///品种停板涨跌幅
struct CShfeFtdcProductLimitsField
{
  ///品种或合约代码
  TShfeFtdcInstrumentIDType	ProductID;
  ///D1涨跌幅
  TShfeFtdcRatioType	Limit1;
  ///D2涨跌幅
  TShfeFtdcRatioType	Limit2;
  ///D3涨跌幅
  TShfeFtdcRatioType	Limit3;
  ///D4涨跌幅
  TShfeFtdcRatioType	Limit4;
  ///最大保证金率
  TShfeFtdcRatioType	MaxMarginRate1;
  ///结算价
  TShfeFtdcPriceType	Price;

  bool operator==(const CShfeFtdcProductLimitsField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(ProductID, ct.ProductID) == 0);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Limit1, ct.Limit1));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Limit2, ct.Limit2));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Limit3, ct.Limit3));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Limit4, ct.Limit4));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(MaxMarginRate1, ct.MaxMarginRate1));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Price, ct.Price));
    if (!ret) return ret;

    return ret;
  }
};

///风险预算资金账户
struct CShfeFtdcPredictRiskAccountField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///初始权益
  TShfeFtdcMoneyType	Balance0;
  ///D1亏损
  TShfeFtdcMoneyType	Lose1;
  ///D1权益
  TShfeFtdcMoneyType	Balance1;
  ///D2亏损
  TShfeFtdcMoneyType	Lose2;
  ///D2权益
  TShfeFtdcMoneyType	Balance2;
  ///D3亏损
  TShfeFtdcMoneyType	Lose3;
  ///D3权益
  TShfeFtdcMoneyType	Balance3;
  ///D4亏损
  TShfeFtdcMoneyType	Lose4;
  ///D4权益
  TShfeFtdcMoneyType	Balance4;

  bool operator==(const CShfeFtdcPredictRiskAccountField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Balance0, ct.Balance0));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Lose1, ct.Lose1));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Balance1, ct.Balance1));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Lose2, ct.Lose2));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Balance2, ct.Balance2));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Lose3, ct.Lose3));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Balance3, ct.Balance3));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Lose4, ct.Lose4));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Balance4, ct.Balance4));
    if (!ret) return ret;

    return ret;
  }
};

///风险预算持仓
struct CShfeFtdcPredictRiskPositionField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///多头持仓
  TShfeFtdcVolumeType	LongVol;
  ///空头持仓
  TShfeFtdcVolumeType	ShortVol;
  ///净持仓
  TShfeFtdcVolumeType	NetVol;
  ///初始价格
  TShfeFtdcPriceType	Price0;
  ///D1结算价
  TShfeFtdcPriceType	Price1;
  ///D1涨跌幅
  TShfeFtdcRatioType	Limit1;
  ///D2涨跌幅
  TShfeFtdcRatioType	Limit2;
  ///D3涨跌幅
  TShfeFtdcRatioType	Limit3;
  ///D4涨跌幅
  TShfeFtdcRatioType	Limit4;
  ///合约乘数
  TShfeFtdcVolumeMultipleType	Multiple;
  ///D1亏损
  TShfeFtdcMoneyType	Lose1;
  ///D2亏损
  TShfeFtdcMoneyType	Lose2;
  ///D3亏损
  TShfeFtdcMoneyType	Lose3;
  ///D4亏损
  TShfeFtdcMoneyType	Lose4;
  ///可留手数
  TShfeFtdcVolumeType	LeftVol;
  ///D1应强平
  TShfeFtdcVolumeType	ShouldClose;
  ///调整后可强平
  TShfeFtdcVolumeType	CanClose;
  ///当前保证金率
  TShfeFtdcRatioType	CurrMarginRate;
  ///调整后保证金率
  TShfeFtdcRatioType	MarginRate1;
  ///净持仓保证金
  TShfeFtdcMoneyType	NetMargin1;
  ///D1可用
  TShfeFtdcMoneyType	Available1;
  ///1手保证金
  TShfeFtdcMoneyType	Margin1PerVol;

  bool operator==(const CShfeFtdcPredictRiskPositionField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (LongVol == ct.LongVol);
    if (!ret) return ret;
    ret = ret && (ShortVol == ct.ShortVol);
    if (!ret) return ret;
    ret = ret && (NetVol == ct.NetVol);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Price0, ct.Price0));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Price1, ct.Price1));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Limit1, ct.Limit1));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Limit2, ct.Limit2));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Limit3, ct.Limit3));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Limit4, ct.Limit4));
    if (!ret) return ret;
    ret = ret && (Multiple == ct.Multiple);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Lose1, ct.Lose1));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Lose2, ct.Lose2));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Lose3, ct.Lose3));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Lose4, ct.Lose4));
    if (!ret) return ret;
    ret = ret && (LeftVol == ct.LeftVol);
    if (!ret) return ret;
    ret = ret && (ShouldClose == ct.ShouldClose);
    if (!ret) return ret;
    ret = ret && (CanClose == ct.CanClose);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CurrMarginRate, ct.CurrMarginRate));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(MarginRate1, ct.MarginRate1));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(NetMargin1, ct.NetMargin1));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Available1, ct.Available1));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Margin1PerVol, ct.Margin1PerVol));
    if (!ret) return ret;

    return ret;
  }
};

///风险预算参数
struct CShfeFtdcPredictRiskParamField
{
  ///D1日期
  TShfeFtdcVolumeType	D1;
  ///是否过滤无效记录
  TShfeFtdcBoolType	IsFilter;

  bool operator==(const CShfeFtdcPredictRiskParamField &ct) const
  {
    bool ret = true;
    ret = ret && (D1 == ct.D1);
    if (!ret) return ret;
    ret = ret && (IsFilter == ct.IsFilter);
    if (!ret) return ret;

    return ret;
  }
};

///风控中同步投资者
struct CShfeFtdcRiskSyncInvestorField
{
  ///操作标志(修改或删除)
  TShfeFtdcActionFlagType	Action;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者分组代码
  TShfeFtdcInvestorIDType	InvestorGroupID;
  ///投资者名称
  TShfeFtdcPartyNameType	InvestorName;
  ///证件类型
  TShfeFtdcIdCardTypeType	IdentifiedCardType;
  ///证件号码
  TShfeFtdcIdentifiedCardNoType	IdentifiedCardNo;
  ///是否活跃
  TShfeFtdcBoolType	IsActive;
  ///联系电话
  TShfeFtdcTelephoneType	Telephone;
  ///通讯地址
  TShfeFtdcAddressType	Address;
  ///开户日期
  TShfeFtdcDateType	OpenDate;
  ///手机
  TShfeFtdcMobileType	Mobile;

  bool operator==(const CShfeFtdcRiskSyncInvestorField &ct) const
  {
    bool ret = true;
    ret = ret && (Action == ct.Action);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorGroupID, ct.InvestorGroupID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorName, ct.InvestorName) == 0);
    if (!ret) return ret;
    ret = ret && (IdentifiedCardType == ct.IdentifiedCardType);
    if (!ret) return ret;
    ret = ret && (strcmp(IdentifiedCardNo, ct.IdentifiedCardNo) == 0);
    if (!ret) return ret;
    ret = ret && (IsActive == ct.IsActive);
    if (!ret) return ret;
    ret = ret && (strcmp(Telephone, ct.Telephone) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(Address, ct.Address) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(OpenDate, ct.OpenDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(Mobile, ct.Mobile) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///合约价格
struct CShfeFtdcInstrumentPriceField
{
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///价格类型
  TShfeFtdcPriceTypeType	PriceType;
  ///价格
  TShfeFtdcPriceType	Price;

  bool operator==(const CShfeFtdcInstrumentPriceField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (PriceType == ct.PriceType);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Price, ct.Price));
    if (!ret) return ret;

    return ret;
  }
};

///投资者与联系人信息的Hash值
struct CShfeFtdcInvestorLinkManHashField
{
  ///请求中是业务类型，否则是数据MD5值
  TShfeFtdcFullMD5Type	MD5;
  ///投资者代码(为空代表所有投资者代码)
  TShfeFtdcInvestorIDType	InvestorIDBeg;
  ///投资者代码(为空代表所有投资者代码)
  TShfeFtdcInvestorIDType	InvestorIDEnd;

  bool operator==(const CShfeFtdcInvestorLinkManHashField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(MD5, ct.MD5) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorIDBeg, ct.InvestorIDBeg) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorIDEnd, ct.InvestorIDEnd) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///投资者代码
struct CShfeFtdcInvestorIDRangeField
{
  ///投资者代码(为空代表所有投资者代码)
  TShfeFtdcInvestorIDType	InvestorIDBeg;
  ///投资者代码(为空代表所有投资者代码)
  TShfeFtdcInvestorIDType	InvestorIDEnd;

  bool operator==(const CShfeFtdcInvestorIDRangeField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(InvestorIDBeg, ct.InvestorIDBeg) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorIDEnd, ct.InvestorIDEnd) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///带通讯时段编号的流序号
struct CShfeFtdcCommPhaseSequenceField
{
  ///通讯时段编号
  TShfeFtdcCommPhaseNoType	CommPhaseNo;
  ///序列系列号
  TShfeFtdcSequenceSeriesType	SequenceSeries;
  ///序号
  TShfeFtdcSequenceNoType	SequenceNo;

  bool operator==(const CShfeFtdcCommPhaseSequenceField &ct) const
  {
    bool ret = true;
    ret = ret && (CommPhaseNo == ct.CommPhaseNo);
    if (!ret) return ret;
    ret = ret && (SequenceSeries == ct.SequenceSeries);
    if (!ret) return ret;
    ret = ret && (SequenceNo == ct.SequenceNo);
    if (!ret) return ret;

    return ret;
  }
};

///风控用户权限
struct CShfeFtdcRiskUserFunctionField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///权限名称
  TShfeFtdcFunctionIDType	Function;

  bool operator==(const CShfeFtdcRiskUserFunctionField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(Function, ct.Function) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///连接状态
struct CShfeFtdcLinkStatusField
{
  ///连接状态
  TShfeFtdcLinkStatusType	LinkStatus;

  bool operator==(const CShfeFtdcLinkStatusField &ct) const
  {
    bool ret = true;
    ret = ret && (LinkStatus == ct.LinkStatus);
    if (!ret) return ret;

    return ret;
  }
};

///风控同步投资者资金账户
struct CShfeFtdcRiskSyncAccountField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///出入金金额
  TShfeFtdcMoneyType	Withdraw;
  ///当前保证金总额
  TShfeFtdcMoneyType	CurrMargin;
  ///手续费
  TShfeFtdcMoneyType	Commission;
  ///平仓盈亏
  TShfeFtdcMoneyType	CloseProfit;
  ///持仓盈亏
  TShfeFtdcMoneyType	PositionProfit;
  ///总权益
  TShfeFtdcMoneyType	Balance;
  ///可用资金
  TShfeFtdcMoneyType	Available;
  ///质押金额
  TShfeFtdcMoneyType	Mortgage;
  ///交易所保证金
  TShfeFtdcMoneyType	ExchangeMargin;
  ///可取资金
  TShfeFtdcMoneyType	WithdrawQuota;
  ///信用额度
  TShfeFtdcMoneyType	Credit;
  ///保证金冻结
  TShfeFtdcMoneyType	FrozenMargin;
  ///手续费冻结
  TShfeFtdcMoneyType	FrozenCommission;

  bool operator==(const CShfeFtdcRiskSyncAccountField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Withdraw, ct.Withdraw));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CurrMargin, ct.CurrMargin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Commission, ct.Commission));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(CloseProfit, ct.CloseProfit));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PositionProfit, ct.PositionProfit));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Balance, ct.Balance));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Available, ct.Available));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Mortgage, ct.Mortgage));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ExchangeMargin, ct.ExchangeMargin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(WithdrawQuota, ct.WithdrawQuota));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Credit, ct.Credit));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(FrozenMargin, ct.FrozenMargin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(FrozenCommission, ct.FrozenCommission));
    if (!ret) return ret;

    return ret;
  }
};

///风控资金账户昨日信息
struct CShfeFtdcSeqPreRiskAccountField
{
  ///流中唯一的序列号
  TShfeFtdcSequenceNoType	UniqSequenceNo;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///投资者帐号
  TShfeFtdcAccountIDType	AccountID;
  ///上次质押金额
  TShfeFtdcMoneyType	PreMortgage;
  ///上次信用额度
  TShfeFtdcMoneyType	PreCredit;
  ///上次存款额
  TShfeFtdcMoneyType	PreDeposit;
  ///上次总权益
  TShfeFtdcMoneyType	PreBalance;
  ///上次占用的保证金
  TShfeFtdcMoneyType	PreMargin;
  ///基本准备金
  TShfeFtdcMoneyType	Reserve;
  ///上次交易所保证金
  TShfeFtdcMoneyType	PreExchMargin;
  ///历史强平次数
  TShfeFtdcVolumeType	ForceCloseStat;
  ///投资者交割保证金
  TShfeFtdcMoneyType	DeliveryMargin;
  ///交易所交割保证金
  TShfeFtdcMoneyType	ExchangeDeliveryMargin;

  bool operator==(const CShfeFtdcSeqPreRiskAccountField &ct) const
  {
    bool ret = true;
    ret = ret && (UniqSequenceNo == ct.UniqSequenceNo);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(AccountID, ct.AccountID) == 0);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreMortgage, ct.PreMortgage));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreCredit, ct.PreCredit));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreDeposit, ct.PreDeposit));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreBalance, ct.PreBalance));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreMargin, ct.PreMargin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Reserve, ct.Reserve));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PreExchMargin, ct.PreExchMargin));
    if (!ret) return ret;
    ret = ret && (ForceCloseStat == ct.ForceCloseStat);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(DeliveryMargin, ct.DeliveryMargin));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ExchangeDeliveryMargin, ct.ExchangeDeliveryMargin));
    if (!ret) return ret;

    return ret;
  }
};

///查询服务器登录应答
struct CShfeFtdcRspLocalFrontLoginField
{
  ///通讯时段编号
  TShfeFtdcCommPhaseNoType	CommPhaseNo;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///前置编号
  TShfeFtdcFrontIDType	FrontID;
  ///风控前置中连接的SessionID
  TShfeFtdcSessionIDType	FrontSessionID;

  bool operator==(const CShfeFtdcRspLocalFrontLoginField &ct) const
  {
    bool ret = true;
    ret = ret && (CommPhaseNo == ct.CommPhaseNo);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (FrontID == ct.FrontID);
    if (!ret) return ret;
    ret = ret && (FrontSessionID == ct.FrontSessionID);
    if (!ret) return ret;

    return ret;
  }
};

///模板替换字段
struct CShfeFtdcNoticeTokenField
{
  ///自动替换字段
  TShfeFtdcExchangeNameType	Token;
  ///自动替换字段的描述
  TShfeFtdcBrokerNameType	Description;

  bool operator==(const CShfeFtdcNoticeTokenField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(Token, ct.Token) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(Description, ct.Description) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///通知模板
struct CShfeFtdcNoticePatternField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///业务类型
  TShfeFtdcParamNameType	BizType;
  ///通知途径
  TShfeFtdcRiskNotifyMethodType	Method;
  ///业务名称
  TShfeFtdcParamNameType	BizName;
  ///最近修改模版的用户代码
  TShfeFtdcUserIDType	UserID;
  ///是否启用
  TShfeFtdcBoolType	IsActive;
  ///通知模版内容
  TShfeFtdcContentType	Pattern;

  bool operator==(const CShfeFtdcNoticePatternField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BizType, ct.BizType) == 0);
    if (!ret) return ret;
    ret = ret && (Method == ct.Method);
    if (!ret) return ret;
    ret = ret && (strcmp(BizName, ct.BizName) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (IsActive == ct.IsActive);
    if (!ret) return ret;
    ret = ret && (strcmp(Pattern, ct.Pattern) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///业务通知
struct CShfeFtdcBizNoticeField
{
  ///事件发生日期
  TShfeFtdcDateType	TradingDay;
  ///通知事件在当天的序号
  TShfeFtdcSequenceNoType	SequenceNo;
  ///风险通知途径
  TShfeFtdcRiskNotifyMethodType	Method;
  ///事件发生时间
  TShfeFtdcTimeType	EventTime;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///业务类型
  TShfeFtdcParamNameType	BizType;
  ///通知状态
  TShfeFtdcRiskNotifyStatusType	Status;
  ///通知内容
  TShfeFtdcContentType	Message;
  ///错误信息
  TShfeFtdcErrorMsgType	ErrorMsg;

  bool operator==(const CShfeFtdcBizNoticeField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(TradingDay, ct.TradingDay) == 0);
    if (!ret) return ret;
    ret = ret && (SequenceNo == ct.SequenceNo);
    if (!ret) return ret;
    ret = ret && (Method == ct.Method);
    if (!ret) return ret;
    ret = ret && (strcmp(EventTime, ct.EventTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BizType, ct.BizType) == 0);
    if (!ret) return ret;
    ret = ret && (Status == ct.Status);
    if (!ret) return ret;
    ret = ret && (strcmp(Message, ct.Message) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ErrorMsg, ct.ErrorMsg) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///投资者参数
struct CShfeFtdcRiskInvestorParamField
{
  ///参数代码
  TShfeFtdcParamIDType	ParamID;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///参数值
  TShfeFtdcParamValueType	ParamValue;

  bool operator==(const CShfeFtdcRiskInvestorParamField &ct) const
  {
    bool ret = true;
    ret = ret && (ParamID == ct.ParamID);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ParamValue, ct.ParamValue) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///变化行情
struct CShfeFtdcVaryMarketDataField
{
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///最新价
  TShfeFtdcPriceType	LastPrice;

  bool operator==(const CShfeFtdcVaryMarketDataField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(LastPrice, ct.LastPrice));
    if (!ret) return ret;

    return ret;
  }
};

///合约价格区间
struct CShfeFtdcPriceRangeField
{
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///价格1
  TShfeFtdcPriceType	Price1;
  ///价格2
  TShfeFtdcPriceType	Price2;

  bool operator==(const CShfeFtdcPriceRangeField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Price1, ct.Price1));
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(Price2, ct.Price2));
    if (!ret) return ret;

    return ret;
  }
};

///有序的业务通知
struct CShfeFtdcSeqBizNoticeField
{
  ///流中唯一的序列号
  TShfeFtdcSequenceNoType	UniqSequenceNo;
  ///事件发生日期
  TShfeFtdcDateType	TradingDay;
  ///通知事件在当天的序号
  TShfeFtdcSequenceNoType	SequenceNo;
  ///风险通知途径
  TShfeFtdcRiskNotifyMethodType	Method;
  ///事件发生时间
  TShfeFtdcTimeType	EventTime;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///业务类型
  TShfeFtdcParamNameType	BizType;
  ///通知状态
  TShfeFtdcRiskNotifyStatusType	Status;
  ///通知内容
  TShfeFtdcContentType	Message;
  ///错误信息
  TShfeFtdcErrorMsgType	ErrorMsg;

  bool operator==(const CShfeFtdcSeqBizNoticeField &ct) const
  {
    bool ret = true;
    ret = ret && (UniqSequenceNo == ct.UniqSequenceNo);
    if (!ret) return ret;
    ret = ret && (strcmp(TradingDay, ct.TradingDay) == 0);
    if (!ret) return ret;
    ret = ret && (SequenceNo == ct.SequenceNo);
    if (!ret) return ret;
    ret = ret && (Method == ct.Method);
    if (!ret) return ret;
    ret = ret && (strcmp(EventTime, ct.EventTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BizType, ct.BizType) == 0);
    if (!ret) return ret;
    ret = ret && (Status == ct.Status);
    if (!ret) return ret;
    ret = ret && (strcmp(Message, ct.Message) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ErrorMsg, ct.ErrorMsg) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///风控参数信息
struct CShfeFtdcRiskParamInfoField
{
  ///参数代码
  TShfeFtdcParamIDType	ParamID;
  ///参数说明
  TShfeFtdcDescriptionType	Description;

  bool operator==(const CShfeFtdcRiskParamInfoField &ct) const
  {
    bool ret = true;
    ret = ret && (ParamID == ct.ParamID);
    if (!ret) return ret;
    ret = ret && (strcmp(Description, ct.Description) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///风控登录信息
struct CShfeFtdcRiskLoginInfoField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///用户代码
  TShfeFtdcUserIDType	UserID;
  ///本地前置会话编号
  TShfeFtdcSessionIDType	LocalSessionID;
  ///风控前置会话编号
  TShfeFtdcSessionIDType	SessionID;
  ///风控前置编号
  TShfeFtdcFrontIDType	FrontID;

  bool operator==(const CShfeFtdcRiskLoginInfoField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (LocalSessionID == ct.LocalSessionID);
    if (!ret) return ret;
    ret = ret && (SessionID == ct.SessionID);
    if (!ret) return ret;
    ret = ret && (FrontID == ct.FrontID);
    if (!ret) return ret;

    return ret;
  }
};

///风控通知模板
struct CShfeFtdcRiskPatternField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///业务类型
  TShfeFtdcParamNameType	BizType;
  ///模板代码
  TShfeFtdcParamIDType	PatternID;
  ///模板名称
  TShfeFtdcParamNameType	PatternName;
  ///通知模版内容
  TShfeFtdcContentType	Pattern;

  bool operator==(const CShfeFtdcRiskPatternField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BizType, ct.BizType) == 0);
    if (!ret) return ret;
    ret = ret && (PatternID == ct.PatternID);
    if (!ret) return ret;
    ret = ret && (strcmp(PatternName, ct.PatternName) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(Pattern, ct.Pattern) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///投资者通知模板
struct CShfeFtdcInvestorPatternField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///业务类型
  TShfeFtdcParamNameType	BizType;
  ///通知途径
  TShfeFtdcRiskNotifyMethodType	Method;
  ///模板代码
  TShfeFtdcParamIDType	PatternID;
  ///是否启用
  TShfeFtdcBoolType	IsActive;

  bool operator==(const CShfeFtdcInvestorPatternField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BizType, ct.BizType) == 0);
    if (!ret) return ret;
    ret = ret && (Method == ct.Method);
    if (!ret) return ret;
    ret = ret && (PatternID == ct.PatternID);
    if (!ret) return ret;
    ret = ret && (IsActive == ct.IsActive);
    if (!ret) return ret;

    return ret;
  }
};

///客户风险通知版本B
struct CShfeFtdcRiskNotifyBField
{
  ///风险通知事件在当天的序号
  TShfeFtdcSequenceNoType	SequenceNo;
  ///事件发生日期
  TShfeFtdcDateType	EventDate;
  ///事件发生时间
  TShfeFtdcTimeType	EventTime;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///请求发送该风险通知的用户代码
  TShfeFtdcUserIDType	UserID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///通知类型
  TShfeFtdcNotifyClassType	NotifyClass;
  ///风险通知途径
  TShfeFtdcRiskNotifyMethodType	NotifyMethod;
  ///风险通知状态
  TShfeFtdcRiskNotifyStatusType	NotifyStatus;
  ///通知内容
  TShfeFtdcContentType	Message;
  ///预留字段(人工通知-通知操作员，否则为错误原因)
  TShfeFtdcCommentType	Reserve;

  bool operator==(const CShfeFtdcRiskNotifyBField &ct) const
  {
    bool ret = true;
    ret = ret && (SequenceNo == ct.SequenceNo);
    if (!ret) return ret;
    ret = ret && (strcmp(EventDate, ct.EventDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(EventTime, ct.EventTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (NotifyClass == ct.NotifyClass);
    if (!ret) return ret;
    ret = ret && (NotifyMethod == ct.NotifyMethod);
    if (!ret) return ret;
    ret = ret && (NotifyStatus == ct.NotifyStatus);
    if (!ret) return ret;
    ret = ret && (strcmp(Message, ct.Message) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(Reserve, ct.Reserve) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///有序的客户风险通知版本B
struct CShfeFtdcSeqRiskNotifyBField
{
  ///流中唯一的序列号
  TShfeFtdcSequenceNoType	UniqSequenceNo;
  ///风险通知事件在当天的序号
  TShfeFtdcSequenceNoType	SequenceNo;
  ///事件发生日期
  TShfeFtdcDateType	EventDate;
  ///事件发生时间
  TShfeFtdcTimeType	EventTime;
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///请求发送该风险通知的用户代码
  TShfeFtdcUserIDType	UserID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///通知类型
  TShfeFtdcNotifyClassType	NotifyClass;
  ///风险通知途径
  TShfeFtdcRiskNotifyMethodType	NotifyMethod;
  ///风险通知状态
  TShfeFtdcRiskNotifyStatusType	NotifyStatus;
  ///通知内容
  TShfeFtdcContentType	Message;
  ///预留字段(人工通知-通知操作员，否则为错误原因)
  TShfeFtdcCommentType	Reserve;

  bool operator==(const CShfeFtdcSeqRiskNotifyBField &ct) const
  {
    bool ret = true;
    ret = ret && (UniqSequenceNo == ct.UniqSequenceNo);
    if (!ret) return ret;
    ret = ret && (SequenceNo == ct.SequenceNo);
    if (!ret) return ret;
    ret = ret && (strcmp(EventDate, ct.EventDate) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(EventTime, ct.EventTime) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(UserID, ct.UserID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (NotifyClass == ct.NotifyClass);
    if (!ret) return ret;
    ret = ret && (NotifyMethod == ct.NotifyMethod);
    if (!ret) return ret;
    ret = ret && (NotifyStatus == ct.NotifyStatus);
    if (!ret) return ret;
    ret = ret && (strcmp(Message, ct.Message) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(Reserve, ct.Reserve) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///查询持仓成交报排名的参数
struct CShfeFtdcQryStatField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///交易所品种合约代码组合(交易所代码使用前缀e:，格式如cu,e:SHFE,cu1105)
  TShfeFtdcString100Type	ExchangeProductInstID;
  ///排名类型
  TShfeFtdcStatSortTypeType	SortType;
  ///按排名数返回结果
  TShfeFtdcVolumeType	ResultCount;
  ///按比例返回结果
  TShfeFtdcRatioType	ResultRatio;

  bool operator==(const CShfeFtdcQryStatField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeProductInstID, ct.ExchangeProductInstID) == 0);
    if (!ret) return ret;
    ret = ret && (SortType == ct.SortType);
    if (!ret) return ret;
    ret = ret && (ResultCount == ct.ResultCount);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(ResultRatio, ct.ResultRatio));
    if (!ret) return ret;

    return ret;
  }
};

///持仓排名统计
struct CShfeFtdcPositionStatField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///交易所品种合约代码组合(交易所代码使用前缀e:，格式如cu,e:SHFE,cu1105)
  TShfeFtdcString100Type	ExchangeProductInstID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///昨持仓
  TShfeFtdcVolumeType	YdPosition;
  ///总持仓
  TShfeFtdcVolumeType	Position;
  ///多头持仓
  TShfeFtdcVolumeType	LongPosition;
  ///空头持仓
  TShfeFtdcVolumeType	ShortPosition;
  ///净持仓
  TShfeFtdcVolumeType	NetPosition;
  ///投机多头持仓
  TShfeFtdcVolumeType	SpecuLongPosi;
  ///投机空头持仓
  TShfeFtdcVolumeType	SpecuShortPosi;
  ///保值多头持仓
  TShfeFtdcVolumeType	HedgeLongPosi;
  ///保值空头持仓
  TShfeFtdcVolumeType	HedgeShortPosi;
  ///今仓
  TShfeFtdcVolumeType	TodayPosition;
  ///总持仓成本
  TShfeFtdcMoneyType	PositionCost;

  bool operator==(const CShfeFtdcPositionStatField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeProductInstID, ct.ExchangeProductInstID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (YdPosition == ct.YdPosition);
    if (!ret) return ret;
    ret = ret && (Position == ct.Position);
    if (!ret) return ret;
    ret = ret && (LongPosition == ct.LongPosition);
    if (!ret) return ret;
    ret = ret && (ShortPosition == ct.ShortPosition);
    if (!ret) return ret;
    ret = ret && (NetPosition == ct.NetPosition);
    if (!ret) return ret;
    ret = ret && (SpecuLongPosi == ct.SpecuLongPosi);
    if (!ret) return ret;
    ret = ret && (SpecuShortPosi == ct.SpecuShortPosi);
    if (!ret) return ret;
    ret = ret && (HedgeLongPosi == ct.HedgeLongPosi);
    if (!ret) return ret;
    ret = ret && (HedgeShortPosi == ct.HedgeShortPosi);
    if (!ret) return ret;
    ret = ret && (TodayPosition == ct.TodayPosition);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(PositionCost, ct.PositionCost));
    if (!ret) return ret;

    return ret;
  }
};

///成交排名统计
struct CShfeFtdcTradeStatField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///交易所品种合约代码组合(交易所代码使用前缀e:，格式如cu,e:SHFE,cu1105)
  TShfeFtdcString100Type	ExchangeProductInstID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///总成交量
  TShfeFtdcVolumeType	TotalVol;
  ///总成交额
  TShfeFtdcMoneyType	TotalAmt;
  ///买成交量
  TShfeFtdcVolumeType	BuyVol;
  ///买成交额
  TShfeFtdcMoneyType	BuyAmt;
  ///卖成交量
  TShfeFtdcVolumeType	SellVol;
  ///卖成交额
  TShfeFtdcMoneyType	SellAmt;
  ///净买入成交量
  TShfeFtdcVolumeType	NetVol;
  ///净买入成交额
  TShfeFtdcMoneyType	NetAmt;

  bool operator==(const CShfeFtdcTradeStatField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeProductInstID, ct.ExchangeProductInstID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (TotalVol == ct.TotalVol);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(TotalAmt, ct.TotalAmt));
    if (!ret) return ret;
    ret = ret && (BuyVol == ct.BuyVol);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(BuyAmt, ct.BuyAmt));
    if (!ret) return ret;
    ret = ret && (SellVol == ct.SellVol);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(SellAmt, ct.SellAmt));
    if (!ret) return ret;
    ret = ret && (NetVol == ct.NetVol);
    if (!ret) return ret;
    ret = ret && (EQUALDOUBLE(NetAmt, ct.NetAmt));
    if (!ret) return ret;

    return ret;
  }
};

///报单排名统计
struct CShfeFtdcOrderStatField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///交易所品种合约代码组合(交易所代码使用前缀e:，格式如cu,e:SHFE,cu1105)
  TShfeFtdcString100Type	ExchangeProductInstID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///总报单量
  TShfeFtdcVolumeType	TotalVol;
  ///买报单量
  TShfeFtdcVolumeType	BuyVol;
  ///卖报单量
  TShfeFtdcVolumeType	SellVol;
  ///净买入报单量
  TShfeFtdcVolumeType	NetVol;
  ///有成交报单数
  TShfeFtdcVolumeType	TradeCount;
  ///总报单数
  TShfeFtdcVolumeType	TotalCount;

  bool operator==(const CShfeFtdcOrderStatField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(ExchangeProductInstID, ct.ExchangeProductInstID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (TotalVol == ct.TotalVol);
    if (!ret) return ret;
    ret = ret && (BuyVol == ct.BuyVol);
    if (!ret) return ret;
    ret = ret && (SellVol == ct.SellVol);
    if (!ret) return ret;
    ret = ret && (NetVol == ct.NetVol);
    if (!ret) return ret;
    ret = ret && (TradeCount == ct.TradeCount);
    if (!ret) return ret;
    ret = ret && (TotalCount == ct.TotalCount);
    if (!ret) return ret;

    return ret;
  }
};

///灾备子系统编号
struct CShfeFtdcDRSysIDField
{
  ///灾备子系统编号(每个子系统中心一个编号)
  TShfeFtdcDRSysIDType	DRSysID;

  bool operator==(const CShfeFtdcDRSysIDField &ct) const
  {
    bool ret = true;
    ret = ret && (DRSysID == ct.DRSysID);
    if (!ret) return ret;

    return ret;
  }
};

///投资者手续费率模板代码
struct CShfeFtdcInvestorCommModelIDField
{
  ///经纪公司代码
  TShfeFtdcBrokerIDType	BrokerID;
  ///投资者代码
  TShfeFtdcInvestorIDType	InvestorID;
  ///手续费率模板代码，为空删除该记录
  TShfeFtdcInvestorIDType	CommModelID;

  bool operator==(const CShfeFtdcInvestorCommModelIDField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(BrokerID, ct.BrokerID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorID, ct.InvestorID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(CommModelID, ct.CommModelID) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///投资者代码范围加合约
struct CShfeFtdcInstInvestorRangeField
{
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///投资者代码(为空代表所有投资者代码)
  TShfeFtdcInvestorIDType	InvestorIDBeg;
  ///投资者代码(为空代表所有投资者代码)
  TShfeFtdcInvestorIDType	InvestorIDEnd;

  bool operator==(const CShfeFtdcInstInvestorRangeField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorIDBeg, ct.InvestorIDBeg) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorIDEnd, ct.InvestorIDEnd) == 0);
    if (!ret) return ret;

    return ret;
  }
};

///投资者代码范围加合约上的数据Hash值
struct CShfeFtdcInstInvestorRangeHashField
{
  ///合约代码
  TShfeFtdcInstrumentIDType	InstrumentID;
  ///请求中是业务类型，否则是数据MD5值
  TShfeFtdcFullMD5Type	MD5;
  ///投资者代码(为空代表所有投资者代码)
  TShfeFtdcInvestorIDType	InvestorIDBeg;
  ///投资者代码(为空代表所有投资者代码)
  TShfeFtdcInvestorIDType	InvestorIDEnd;

  bool operator==(const CShfeFtdcInstInvestorRangeHashField &ct) const
  {
    bool ret = true;
    ret = ret && (strcmp(InstrumentID, ct.InstrumentID) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(MD5, ct.MD5) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorIDBeg, ct.InvestorIDBeg) == 0);
    if (!ret) return ret;
    ret = ret && (strcmp(InvestorIDEnd, ct.InvestorIDEnd) == 0);
    if (!ret) return ret;

    return ret;
  }
};



#endif

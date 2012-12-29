%module(directors="1") Ctp

%include <typemaps.i>

//#ifdef SWIGJAVA

//#endif

%{
#include "ThostFtdcUserApiDataType.h"
#include "ThostFtdcUserApiStruct.h"
#include "ThostFtdcTraderApi.h"
#include "ThostFtdcMdApi.h"
%}

// These symbols are NEVER used in original files
%ignore TThostFtdcVirementTradeCodeType;
%ignore THOST_FTDC_VTC_BankBankToFuture;
%ignore THOST_FTDC_VTC_BankFutureToBank;
%ignore THOST_FTDC_VTC_FutureBankToFuture;
%ignore THOST_FTDC_VTC_FutureFutureToBank;

%ignore TThostFtdcFBTTradeCodeEnumType;
%ignore THOST_FTDC_FTC_BankLaunchBankToBroker;
%ignore THOST_FTDC_FTC_BrokerLaunchBankToBroker;
%ignore THOST_FTDC_FTC_BankLaunchBrokerToBank;
%ignore THOST_FTDC_FTC_BrokerLaunchBrokerToBank;

#ifdef SWIGJAVA
%include <various.i>
%rename(ThostTeResumeType) THOST_TE_RESUME_TYPE;
%javaconst(1);
%apply char **STRING_ARRAY { char *ppInstrumentID[] };
#endif

%include "ThostFtdcUserApiDataType.h"
%include "ThostFtdcUserApiStruct.h"
%feature("director") CThostFtdcMdSpi;
%include "ThostFtdcMdApi.h"
%feature("director") CThostFtdcTraderSpi;
%include "ThostFtdcTraderApi.h"

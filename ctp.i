#if defined(SWIGPYTHON) || defined(SWIGRUBY)
%module(directors="1") ctp
#else
%module(directors="1") Ctp
#endif

%include "typemaps.i"

%{
#ifdef SWIGPYTHON
  #define SWIG_FILE_WITH_INIT
#endif

#include "ThostFtdcUserApiDataType.h"
#include "ThostFtdcUserApiStruct.h"
#include "ThostFtdcTraderApi.h"
#include "ThostFtdcMdApi.h"
%}

/* These symbols are NEVER used in original files */
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
%rename(ThostTeResumeType) THOST_TE_RESUME_TYPE;
%rename("%(lowercamelcase)s", %$isfunction) "";
%include "various.i"
%apply char **STRING_ARRAY { char *ppInstrumentID[] };

%javaconst(1);

#endif

#ifdef SWIGCSHARP
%include "arrays_csharp.i"
%rename(ThostTeResumeType) THOST_TE_RESUME_TYPE;
%csconst(1);
CSHARP_ARRAYS(char *, string)
%typemap(imtype, inattributes="[In, MarshalAs(UnmanagedType.LPArray, SizeParamIndex=0, ArraySubType=UnmanagedType.LPStr)]") char *INPUT[] "string[]"
%apply char *INPUT[] { char *ppInstrumentID[] };
#endif

#ifdef SWIGRUBY
%include "ruby/char_array.i"
%apply (char **ARRAY, int SIZE) { (char *ppInstrumentID[], int nCount) };
#endif

#ifdef SWIGPYTHON
%include "python/char_array.i"
%apply (char **ARRAY, int SIZE) { (char *ppInstrumentID[], int nCount) };
#endif

%include "ThostFtdcUserApiDataType.h"
%include "ThostFtdcUserApiStruct.h"


%feature("director") CThostFtdcMdSpi;
%include "ThostFtdcMdApi.h"


%feature("director") CThostFtdcTraderSpi;
%include "ThostFtdcTraderApi.h"


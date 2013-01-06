#!/usr/bin/env ruby


require 'thread'
require 'ctp'
include Ctp


mutex = Mutex.new
resource = ConditionVariable.new


class MdSpi < CThostFtdcMdSpi
  @@request_id = 0

  def initialize
    super
  end

  def start(front, broke_id, user_id, password)
    @front = front;
    @broke_id = broke_id
    @user_id = user_id
    @password = password
    @api = CThostFtdcMdApi.create_ftdc_md_api()
    @api.register_spi(self)
    @api.register_front(@front)
    @api.init()
  end

  def join
    @api.join()
  end

  def stop
    @api.register_spi(nil)
    @api.release
  end

  def subscribe
    puts "subcribe..."
    @api.subscribe_market_data(["IF1302"]);
  end

  def on_front_connected
    puts "on_front_connected"

    field = CThostFtdcReqUserLoginField.new
    field.BrokerID = @broke_id
    field.UserID = @user_id
    field.Password = @password
    @@request_id += 1
    @api.req_user_login field, @@request_id
  end
  #
  def on_front_disconnected(reason)
    puts "on_front_connected"
  end
  #
  def on_heart_beat_warning(time_lapse)
    puts "on_heart_beat_warning"
  end
  #
  def on_rsp_user_login(field, info, request_id, last)
    puts "on_rsp_user_login"
    #day = @api.get_trading_day()
    #puts day
    #mutex.synchronize {
    #  resource.signal
    #}

    puts "dddd" + Thread.current.to_s
  end
  #
  #def on_rsp_user_logout
  #end
  #
  def on_rsp_error(rsp_info, request_id, last)
  end
  #
  def on_rsp_sub_market_data(field, info, request_id, last)
    puts 'on_rsp_sub_market_data'
  end
  #
  #def on_rsp_un_sub_market_data
  #end
  #
  #def on_rtn_depth_market_data
  #end
end

conn = "tcp://asp-sim2-front1.financial-trading-platform.com:26213"
broker = "2030"
user = "352240"
password = "888888"

spi = MdSpi.new
spi.start(conn, broker, user, password)
puts Thread.current
#mutex.synchronize {
#  resource.wait(mutex)
#}

#spi.subscribe
spi.join
spi.stop

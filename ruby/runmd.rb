#!/usr/bin/env ruby

require 'ctp'

include Ctp

class MySpi < CThostFtdcMdSpi
  @@request_id = 0
  def initialize(front, broke_id, user_id, password, api)
    @front = front;
    @broke_id = broke_id
    @user_id = user_id
    @password = password
    @api = api
  end

  def on_front_connected
    puts "on_front_connected"
  end
end

class MdSpi < CThostFtdcMdSpi
  @@request_id = 0
  def initialize(front, broke_id, user_id, password, api)
    @front = front;
    @broke_id = broke_id
    @user_id = user_id
    @password = password
    @api = api
    @api.register_spi(@self)
    @api.register_front(@front)
    @api.init()
    @api.join()
  end

  def finalize
    @api.register_spi(nil)
    @api.release
  end

  #def run
  #  @api.init()
  #  @api.join()
  #end
  #
  #def on_front_connected
  #  puts "on_front_connected"
  #
  #  field = Ctp::CThostFtdcReqUserLoginField.new
  #  field.BrokerID = "2030"
  #  field.UserID = "352240"
  #  filed.Password = "888888"
  #  @@request_id += 1
  #  @api.req_user_login field, @@request_id
  #end
  #
  #def on_front_disconnected
  #  puts "on_front_connected"
  #end
  #
  #def on_heart_beat_warning
  #  puts "on_heart_beat_warning"
  #end
  #
  #def on_rsp_user_login
  #end
  #
  #def on_rsp_user_logout
  #end
  #
  #def on_rsp_error
  #end
  #
  #def on_rsp_sub_market_data
  #end
  #
  #def on_rsp_un_sub_market_data
  #end
  #
  #def on_rtn_depth_market_data
  #end
end

conn = "tcp://asp-sim1-front1.financial-trading-platform.com:41213"
broker = "2030"
user = "0000000624"
password = "asdfgh"

api = CThostFtdcMdApi.create_ftdc_md_api()
spi = MdSpi.new(conn, broker, user, password, api)
spi.finalize
#spi.run

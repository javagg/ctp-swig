#!/usr/bin/env ruby

$:.unshift "/usr/local/lib"

require 'ctp'

class MdSpi < Ctp::CThostFtdcMdSpi
  @@request_id = 0
  def initialize
    @api = Ctp::CThostFtdcMdApi.create_ftdc_md_api()
    @api.register_spi(self)
    @api.register_front("protocal=tcp;host=asp-sim2-front1.financial-trading-platform.com;port=26213;userid=352240;password=888888;brokerid=2030")
  end

  def destroy
    @api.register_spi(nil)
    @api.release
  end

  def run
    @api.init()
    @api.join()
  end

  def on_front_connected
    puts "on_front_connected"

    field = Ctp::CThostFtdcReqUserLoginField.new
    field.BrokerID = "2030"
    field.UserID = "352240"
    filed.Password = "888888"
    @@request_id += 1
    @api.req_user_login field, @@request_id
  end

  def on_front_disconnected
    puts "on_front_connected"
  end

  def on_heart_beat_warning
    puts "on_heart_beat_warning"
  end

  def on_rsp_user_login
  end

  def on_rsp_user_logout
  end

  def on_rsp_error
  end

  def on_rsp_sub_market_data
  end

  def on_rsp_un_sub_market_data
  end

  def on_rtn_depth_market_data
  end
end

spi = MdSpi.new
spi.run

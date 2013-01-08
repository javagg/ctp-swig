require 'thread'
require 'swigmt'

include Swigmt

class DCallback < Callback
	def response
		puts "response from ruby in another thread " + Thread.current.to_s
	end
end

cb = DCallback.new
caller = Caller.new(cb)
puts "request in ruby, in thread " + Thread.current.to_s
caller.request
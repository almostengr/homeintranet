#!/bin/bash 

function main {
	/usr/bin/wget -O /home/pintranet/intranetp/feeds/curweather/KMGM_$(date +%Y%m%d%H%M%S).xml http://w1.weather.gov/xml/current_obs/KMGM.xml

	/usr/bin/wget -O /home/pintranet/intranetp/feeds/curweather/KTOI_$(date +%Y%m%d%H%M%S).xml http://w1.weather.gov/xml/current_obs/KTOI.xml 
}
# end function main

# main > /home/pintranet/log/get_nws_weather.log
main


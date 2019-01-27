#!/bin/bash 

function main {

	FEEDFILE=/var/www/intranet/private/feeds/inetspeed/$(date +%Y%m%d%H%M%S).csv

	# /usr/bin/python /home/pintranet/bin/speedtest-cli/speedtest.py --csv-header --csv-delimiter "|" > ${FEEDFILE}
	/usr/bin/python /home/pintranet/bin/speedtest-cli/speedtest.py --csv --csv-delimiter "|" >> ${FEEDFILE}
}
# end function main 

main



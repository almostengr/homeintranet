#!/bin/bash 

function main {
	# /usr/bin/python /home/aphintranet/bin/speedtest-cli/speedtest.py --csv-header --csv-delimiter "|" > ${FEEDFILE}
	/usr/bin/python $HOME/bin/speedtest-cli/speedtest.py --csv --csv-delimiter "|" >> ${HOME}/intranetp/feeds/inetspeed/$(date +%Y%m%d%H%M%S).csv
}
# end function main 

main $*


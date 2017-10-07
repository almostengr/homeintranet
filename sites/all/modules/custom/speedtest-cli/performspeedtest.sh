#!/bin/bash 

function main {
	echo $(date) | "Running internet test"

	FEEDNAME=$(date +%Y%m%d%H%M%S).csv
	# /usr/bin/python $HOME/bin/speedtest-cli/speedtest.py --csv-header --csv-delimiter "|" > ${HOME}/intranetp/feeds/inetspeed/${FEEDNAME}
	/usr/bin/python $HOME/bin/speedtest-cli/speedtest.py --csv --csv-delimiter "|" >> ${HOME}/intranetp/feeds/inetspeed/${FEEDNAME}

	echo $(date) | "Done running internet test"
}
# end function main 

main $*


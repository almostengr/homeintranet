#!/bin/bash 

function get_status {
	# run the script to get the status
	SSSTATUS=$(perl /var/www/intranet.matrixneo.ddns.net/SimpliSafeStatus/simplisafe_status.pl)

	# update Drupal with the appropriate status
	if [ "${SSSTATUS}" == "Home" ]; then
		curl -H "Content-Type: application/json" -X PUT -d '{"title":"iot_simplisafe:Home","nid":"469"}' http://intranet.matrixneo.ddns.net?q=iot/node/469.json
	elif [ "${SSSTATUS}" == "Away" ]; then
                curl -H "Content-Type: application/json" -X PUT -d '{"title":"iot_simplisafe:Away","nid":"469"}' http://intranet.matrixneo.ddns.net?q=iot/node/469.json
	elif [ "${SSSTATUS}" == "Off" ]; then
                curl -H "Content-Type: application/json" -X PUT -d '{"title":"iot_simplisafe:Off","nid":"469"}' http://intranet.matrixneo.ddns.net?q=iot/node/469.json
	else
                curl -H "Content-Type: application/json" -X PUT -d '{"title":"iot_simplisafe:Away","nid":"469"}' http://intranet.matrixneo.ddns.net?q=iot/node/469.json
		cat "Error occurred when determining Alarm Status. Assuming Away." | mailx -s "IOT Error" 2053835510\@mms.att.net kjrobin04\@yahoo.com

		# generate ticket
		
		# If error occurs, then sleep for 1 hour	
		sleep 3600
	fi
} # end function

function main {
	date
	check_previous_run
	# get_status

	# cleanup after logout 
	rm /tmp/sscookie.txt

	date
} # end function 

function check_previous_run {
	pgrep "dchcustom_simplisafe.sh"
	
	# IF PROCESS IS ALREADY RUNNING, THEN DO NOT START IT.
	if [ $? -eq 0 ]; then
		echo "Already running"
	else
	# IF PROCESS IS NOT ALREADY RUNNING, THEN START IT
		echo "Not running. Starting..."
		get_status
	fi
} # end function

main
p


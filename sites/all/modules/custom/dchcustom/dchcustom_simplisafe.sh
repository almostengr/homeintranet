#!/bin/bash 

function main {
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
                curl -H "Content-Type: application/json" -X PUT -d '{"title":"iot_simplisafe:Home","nid":"469"}' http://intranet.matrixneo.ddns.net?q=iot/node/469.json
		cat "Error occurred when determining Alarm Status" | mailx -s "IOT Error" 2053835510@mms.att.net
		
		# If error occurs, then sleep for 1 hour	
		sleep 3600
	fi

	# wait 5 minutes after completing check
	sleep 300	
}

while true
do 
main
done


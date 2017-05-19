#!/bin/bash 

function log_msg {
# LOG MESSAGES TO THE LOG FILE
	echo $(date)" | "$1
} # end function

function get_status {
	AUTHKEY="EwXPMZR9Df0oS2KkvOFPWA"
	log_msg "Getting the status" 

	# run the script to get the status
	SSSTATUS=$(perl /home/aphintranet/intranetp/SimpliSafeStatus/simplisafe_status.pl)

	JSONSTRING='{"title":"iot_simplisafe:'"${SSSTATUS}"'","nid":"469","api-key":"'"${AUTHKEY}"'"}'

	echo $JSONSTRING

        # curl -H "Content-Type: application/json" -X PUT -d ${JSONSTRING} http://intranet.myhouse.lan/?q=security/node/469.json
	# update Drupal with the appropriate status

	log_msg "Writing feed file"
	echo "469,security "${SSSTATUS} > /home/aphintranet/intranetp/feeds/iotvariable/security.csv
	log_msg "Done writing feed file"

	log_msg "Feed file contents"
	cat /home/aphintranet/intranetp/feeds/iotvariable/security.csv
	log_msg "Done feed file contents"

        log_msg ""
	log_msg "Status is: "${SSSTATUS}
	log_msg "Done getting the status"
} # end function

# Perform cleanup of files after run
function perform_cleanup {
	log_msg "Performing cleanup"

	rm /tmp/cookie.txt
	rm /tmp/sscookie.txt
	
	log_msg "Done performing cleanup"
} # end function

function main {
	log_msg "Running script" 

	check_previous_run
	# get_status

	perform_cleanup

	log_msg "Done running script"
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

# call main function
main $*


#!/bin/bash 

INTRANETDIR=/home/aphintranet/intranet
INTRANETPDIR=/home/aphintranet/intranetp
SCRIPTDIR=${INTRANETPDIR}/speedtest-cli
FEEDDIR=${INTRANETPDIR}/feeds/inetspeed
FEEDFILE=${FEEDDIR}"/"$(date +%Y%m%d%H%M%S)".csv"

# write the messages to the log
function log_msg {
	echo $(date)" | "$1
} # end function

# run the test
function run_test {
	touch ${FEEDFILE}

	log_msg "Writing the header"
	
	# write the header
	${SCRIPTDIR}/speedtest-csv --header >> ${FEEDFILE}
	
	log_msg "Done writing the header"

	log_msg "Running the speed test"

	# run the test and remove the additional text from the numeric fields
	${SCRIPTDIR}/speedtest-csv --sep ";" | sed 's| ms||g' | sed 's| km||g' | sed 's| Mbit/s||g' >> ${FEEDFILE}

	log_msg "Done running the speed test"
} # end function 

# Change the permissions on the feed after generating
function change_permissions {
	log_msg "Changing the permissions on the feed file."

	chown www-data ${FEEDFILE}

	log_msg "Done changing the permissions on the feed file."
} 

# main 
function main {
	log_msg "Script starting"

	log_msg "FEEDFILE="${FEEDFILE}
	log_msg $(env)

	run_test
	
	change_permissions
	
	log_msg "Script completed"
} # end function

# call the main program
main



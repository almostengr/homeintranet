#!/bin/bash 

function run_cron {
	cd /var/www/intranet.matrixneo.ddns.net/drupal
        drush cron
}

function main {
	date
	check_previous_run
	date
} # end function 

function check_previous_run {
	pgrep "dchcustom_cron.sh"
	
	# IF PROCESS IS ALREADY RUNNING, THEN DO NOT START IT.
	if [ $? -eq 0 ]; then
		echo "Already running... exiting."
	else
	# IF PROCESS IS NOT ALREADY RUNNING, THEN START IT
		echo "Not running. Starting..."
		run_cron
	fi
} # end function

main


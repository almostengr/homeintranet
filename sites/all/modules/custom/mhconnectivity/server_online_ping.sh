#/bin/bash

#################
# Name: check_servers.sh
# Author: Kenny Robinson
# Date: 2016/02/05
# Description: Check to see if local servers are online. If they are not, 
# script will create ticket and send email notification.
# Usage: check_servers.sh matrix.myhouse.lan
#
# Version History (date - description)
# 2016/02/05 - Initial version.
####################

# SCRIPT START
date

# SCRIPT VARIABLES

# SCRIPT CODE
cd $HOME

# SOURCE CONFIGURATION
source $HOME/.bashrc

## SCRIPT MAIN ##

if [ -z "$1" ]; then
	echo "ERROR: Server name not provided."
	echo ""
	echo "Usage, Internal: check_servers.sh <servername>"
	echo "Usage, External: check_servers.sh internet"
	echo ""
	echo "Exiting..."
else
	# ping the server

        url=$1

        if [ "$url" == "internet" ]; then
                url="google.com"
        fi

        echo "Testing URL $url"

        ping -c 3 $url > /dev/null 2>&1
        if [ $? -ne 0 ]
        then
                echo "Unable to reach server $1. Sending notifications."

                if [ "$1" != "internet" ]; then
                        # Send email notification if the server down is internal.
                        mailx -s "Server $url is down" -t "$NOTIFYEMAIL" < /dev/null
                fi

                # create ticket
                # curl --request POST 'http://localhost/Service' --data "path=/xyz/pqr/test/" --data "fileName=1.doc"
        else
                echo "Server $url is online and responding."
        fi

fi
# end if string not empty


# SCRIPT END
date


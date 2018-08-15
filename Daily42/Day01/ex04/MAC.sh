ifconfig -a | grep 'ether ' | tr -d ' ' | tr -d '\t' | sed 's/ether//g'

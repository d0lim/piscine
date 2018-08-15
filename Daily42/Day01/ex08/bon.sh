ldapsearch -Q -LLL -H ldap://ldap-master.42.us.org 'sn=*bon*' | sed -n '/sn:/p' | sort -f | cut -c5- | wc -l | tr -d ' '

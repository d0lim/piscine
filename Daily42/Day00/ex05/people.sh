ldapsearch -LLL -H ldap://ldap-master.42.us.org 'uid=z*' cn | sed -n '/cn:/p' | sort -f -r | cut -c5-

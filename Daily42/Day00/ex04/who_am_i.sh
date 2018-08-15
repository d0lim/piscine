ldapsearch -LLL -H ldap://ldap-master.42.us.org 'uid=dolim' dn | sed -n 's/^[\t]*dn:[\t]*\(.*\)/\1/p'

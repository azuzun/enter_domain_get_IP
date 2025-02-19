# enter_domain_get_IP
enter a domain - get IP
DNS NOTES
arpa/inet.h
inet_ntoa
convert numeric IP their		binary <-> text forms.

inet_ntoa
IPv4	binary -> string
in the standard dot notation (192.168.1.1).

netdb.h	
define the structures, macros, functions
used for domain name resolution.

include definition for gethostbyname, gethostbyaddr, hostent.

gethostbyname
retrieve info about a host based on its domain name.
It returns a pointer to a hostent structure
that contains info about the host such as its IP addresses.


 
perform a DNS lookup for a given domain name,
converting it into one or more IP addresses


struct hostent iceririk
 

char  *h_name;       		host name.
char **h_aliases;     		alternate names array.
int    h_addrtype;    		Address type (AF_INET for IPv4).
int    h_length;      		address Length.
char **h_addr_list;  		network addresses array.





*host_entry
pointer to a struct hostent
used to store info about a given host (such as a domain name or IP address).

gethostbyname()
When the function gethostbyname() is called with a domain name,
it performs a DNS lookup and returns a pointer to a struct hostent
that contains info about the host.
This info includes
the host's name, aliases, address type, length of the address,
a list of addresses associated with the host.



struct hostent *host_entry;
declare a pointer to a struct hostent.

struct hostent is a structure defined in the <netdb.h> header,
which stores info about a given host (such as its IP addresses).

The host_entry pointer
will later point to the data returned by the gethostbyname function.

host_entry = gethostbyname( domain.c_str() );
gethostbyname funct
perform  DNS lookup.
It takes a domain name as an argument
and returns a pointer to a struct hostent containing information about the host.

domain.c_str()
domain string -> C-style string (const char*)
gethostbyname expects a C-style string.


 

Initialization: char *ip_address;
declares a pointer to a character array
that will store the IP address in a human-readable format.
h_addr_list[i]
part of the hostent structure,
store host info (such as a domain name) obtained via DNS lookup.


struct hostent
{
    char **h_addr_list;  	// Null-terminated network addresses array for the host.
};



Loop through IP addresses: for (int i = 0; host_entry -> h_addr_list[i] != NULL; i++)
This for loop iterates through the list of IP addresses associated with the domain name.

char **h_addr_list
vector of addresses for the host.
host might be connected to multiple networks and have different addresses on each one.

host_entry -> h_addr_list
array of pointers to network addresses for the given host (domain).

host_entry->h_addr_list[i] != NULL
checks that the current address pointer is not null,
ensuring that the loop continues until all addresses have been processed.

 

Convert network address to readable format:
ip_address = inet_ntoa( * (struct in_addr *) host_entry -> h_addr_list[i] );

host_entry -> h_addr_list[i]
gives a pointer to a network address.

(struct in_addr *) host_entry -> h_addr_list[i]
casts this pointer to a pointer of type struct in_addr.
inet_ntoa expects an argument of type struct in_addr.

* dereferences the pointer,
giving the actual struct in_addr object.

inet_ntoa converts this struct in_addr object
to a string in dotted-decimal format		(e.g., "192.168.1.1").




----

in_addr
in_addr structure
represents an IPv4 address in the binary format.

defined in the <netinet/in.h> header file.

structure contains a single member,
which is an unsigned 32-bit integer that holds the IPv4 address.

Here is the typical definition of the in_addr structure:

 

 

In the code you provided,
the inet_ntoa function is used to convert an in_addr structure
to a human-readable string representing the IPv4 address in the dotted-decimal format.

----

-> gecerli olmasi icin
Degisken class - structure  icinde veya 
Pointer olmalı
 

 








![image](https://github.com/user-attachments/assets/13417725-5eb7-42a3-bc12-bcdd92ffad39)

// enter a domain name and get the IP

#include <iostream>
#include <string>

#include <arpa/inet.h>
#include <netdb.h>       // For gethostbyname and hostent

using namespace std;

int main()
{
  string domain;
  cout << "Enter a domain: ";
  getline(cin, domain);

  // Allocate memory for DNS response
  struct hostent *host_entry;                     // store info given host / IP
  host_entry = gethostbyname(domain.c_str());    // gethostbyname funct: perform DNS lookup.

  // domain.c_str()   domain string -> C-style string (const char*)
  // gethostbyname expects a C-style string.


  if (host_entry == nullptr)
  {
    cerr << "Error: Could not resolve domain." << endl;
    return 1;
  }

  // Iterate through IP addresses and print them
  for (int i = 0; host_entry -> h_addr_list[i] != nullptr; i++)
  {
    struct in_addr *address = (struct in_addr *) host_entry -> h_addr_list[i];
    char *ip_address = inet_ntoa(*address);
    cout << "IP address: " << ip_address << endl;
  }

  // inet_ntoa    convert numeric IP their		binary <-> text forms.

  return 0;
}


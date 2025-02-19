#include <iostream>
#include <string>
#include <arpa/inet.h>
#include <netdb.h>       // For gethostbyname and hostent

using namespace std;

int main()
{
    string domain;
    cout << "Enter a domain name: ";
    getline(cin, domain);

    // Perform DNS lookup
    struct hostent *host_entry = gethostbyname(domain.c_str());

    // Check for DNS lookup errors
    if (host_entry == NULL)
    {
        cerr << "Error: Unable to resolve domain." << endl;
        return 1;
    }

    // Print IP addresses
    for (int i = 0; host_entry->h_addr_list[i] != NULL; i++)
    {
        cout << "IP address: " << inet_ntoa(*(struct in_addr *)host_entry->h_addr_list[i]) << endl;
    }

    return 0;
}

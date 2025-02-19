using namespace std;

#include <iostream>
#include <string>
#include <arpa/inet.h>
#include <netdb.h>

#define DNS_SERVER "8.8.8.8" // Google Public DNS

int main() {
  string domain;
  cout << "Enter a domain name: ";
  getline(cin, domain);

  // Perform DNS lookup
  struct addrinfo hints, *result;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET; // IPv4

  int err = getaddrinfo(domain.c_str(), nullptr, &hints, &result);
  if (err != 0) {
    cerr << "Error: " << gai_strerror(err) << endl;
    return 1;
  }

  // Check for successful lookup
  if (result == nullptr) {
    cerr << "DNS lookup failed for " << domain << endl;
    freeaddrinfo(result);
    return 1;
  }

  // Print IP address
  for (struct addrinfo* rp = result; rp != nullptr; rp = rp->ai_next) {
    struct sockaddr_in* addr = reinterpret_cast<struct sockaddr_in*>(rp->ai_addr);
    char ip_str[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(addr->sin_addr), ip_str, sizeof(ip_str));
    cout << "IP address: " << ip_str << endl;
  }

  freeaddrinfo(result);
  return 0;
}

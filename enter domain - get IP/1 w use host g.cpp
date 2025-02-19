using namespace std;

#include <iostream>
#include <string>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

void handle_error(const string& message) {
  cerr << "Error: " << message << endl;
  exit(1);
}

string resolve_dns(const string& domain) {
  struct addrinfo hints, *res;

  // Set up hints for IPv4 address
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;

  // Perform DNS lookup
  int status = getaddrinfo(domain.c_str(), nullptr, &hints, &res);
  if (status != 0) {
    handle_error(gai_strerror(status));
  }

  // Extract IP address from the first result
  if (res == nullptr) {
    handle_error("No DNS records found for " + domain);
  }
  char ip_address[INET_ADDRSTRLEN];
  inet_ntop(AF_INET, &((struct sockaddr_in*)res->ai_addr)->sin_addr, ip_address, sizeof(ip_address));

  freeaddrinfo(res);
  return string(ip_address);
}

int main() {
  while (true) {
    string domain;
    cout << "Enter a domain: ";
    getline(cin, domain);

    if (domain.empty() || domain == "q") {
      break;
    }

    try {
      string ip_address = resolve_dns(domain);
      cout << "IP address for " << domain << ": " << ip_address << endl;
    } catch (const exception& e) {
      cerr << "Error resolving DNS: " << e.what() << endl;
    }
  }

  return 0;
}

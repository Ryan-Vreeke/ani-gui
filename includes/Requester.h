#include <curl/curl.h>
#include <string>
#include <iostream>

#pragma once

class Requester {
public:
  Requester();
  ~Requester();

  std::string Request(std::string request);
private:
  CURL *curl;
  CURLcode res;
  std::string readBuffer;

  static size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *userp);

};

#include "../includes/Requester.h"

Requester::Requester() {
  curl_global_init(CURL_GLOBAL_DEFAULT);
  curl = curl_easy_init();
}

Requester::~Requester() {
  curl_easy_cleanup(curl);
  curl_global_cleanup();
}

std::string Requester::Request(std::string url) {
  if (!curl) {
    return "";
  }

  curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

  res = curl_easy_perform(curl);

  if (res != CURLE_OK) {
    return "";
  }

  std::string response = readBuffer;
  readBuffer.clear();
  return response;
}

size_t Requester::WriteCallback(void *contents, size_t size, size_t nmemb, std::string *userp) {
  size_t totalSize = size * nmemb;
  userp->append((char *)contents, totalSize);
  return totalSize;
}

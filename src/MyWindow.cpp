#include "../includes/MyWindow.h"
#include "sigc++/functors/mem_fun.h"

MyWindow::MyWindow() : m_button("click") {
  set_border_width(10);

  m_button.signal_clicked().connect(
      sigc::mem_fun(*this, &MyWindow::on_button_clicked));

  add(m_button);

  m_button.show();
}

size_t WriteCallback(void *contents, size_t size, size_t nmemb,
                     std::string *userp) {
  size_t totalSize = size * nmemb;
  userp->append((char *)contents, totalSize);
  return totalSize;
}

void MyWindow::on_button_clicked() {
  CURL *curl;
  CURLcode res;
  std::string readBuffer;

  curl_global_init(CURL_GLOBAL_DEFAULT);
  curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "http://www.example.com");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

    res = curl_easy_perform(curl);

    if (res == CURLE_OK) {
      std::cout << readBuffer << std::endl;
    }

    curl_easy_cleanup(curl);
  }
  curl_global_cleanup();
}

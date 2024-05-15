#include "../includes/MyWindow.h"
#include "sigc++/functors/mem_fun.h"

MyWindow::MyWindow() : m_button("click") {
  set_border_width(10);

  m_button.signal_clicked().connect(
      sigc::mem_fun(*this, &MyWindow::on_button_clicked));

  add(m_button);

  m_button.show();
}


void MyWindow::on_button_clicked() {

}

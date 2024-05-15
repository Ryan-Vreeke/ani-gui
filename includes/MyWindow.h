#include <gtkmm-3.0/gtkmm.h>
#include <gtkmm/button.h>
#include <iostream>

#pragma once

class MyWindow : public Gtk::Window {
public:
  MyWindow();

protected:
  void on_button_clicked();

  Gtk::Button m_button;
};

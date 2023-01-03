#include "base.h"

int main(int argc, char* argv[])
{
  auto app = Gtk::Application::create("PAlg.hbnms");

  return app->make_window_and_run<MyWindow>(argc, argv);
}
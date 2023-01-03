#include "base.h"
#include "Conversions.h"
#include "Calculator.h"

int N1I = 1, N2I = 1;

MyWindow::MyWindow() 
: m_button("Calculate!"), 
m_label1("Huge Binary Numbers Multiplication System"), 
m_label2("="),
m_label3("X"),
m_label4("="),
label_res("RESULT:"),
label_n("Normal\nMultiplication"),
label_k("Karatsuba\nMultiplication"),
Vbox(Gtk::Orientation::VERTICAL),
Vbox2(Gtk::Orientation::VERTICAL),
Vbox_n(Gtk::Orientation::VERTICAL),
Vbox_k(Gtk::Orientation::VERTICAL),
h_box1(Gtk::Orientation::HORIZONTAL),
h_box2(Gtk::Orientation::HORIZONTAL),
h_box3(Gtk::Orientation::HORIZONTAL)
{
  set_title("Huge Binary Numbers Multiplication System");
  set_default_size(800, 500);
  set_visible(true);

  set_child(Vbox);
  Vbox.set_valign(Gtk::Align::CENTER);

  Vbox.append(m_label1);
  m_label1.set_margin(25);
  m_label1.set_can_focus(false);

  Vbox.append(h_box1);
  h_box1.set_margin(10);
  h_box1.set_halign(Gtk::Align::CENTER);


  h_box1.append(b_entry1);
  b_entry1.set_width_chars(100);
  b_entry1.set_can_focus(true);
  b_entry1.signal_activate().connect(sigc::mem_fun(*this, &MyWindow::on_b1_changed));
  h_box1.append(m_label2);
  m_label2.set_can_focus(false);
  m_label2.set_margin_start(10);
  m_label2.set_margin_end(10);
  h_box1.append(d_entry1);
  d_entry1.set_width_chars(25);
  d_entry1.set_can_focus(true);
  d_entry1.set_focus_on_click(true);
  d_entry1.signal_activate().connect(sigc::mem_fun(*this, &MyWindow::on_d1_changed));

  Vbox.append(m_label3);
  m_label3.set_can_focus(false);

  Vbox.append(h_box2);
  h_box2.set_margin(10);
  h_box2.set_halign(Gtk::Align::CENTER);
  
  h_box2.append(b_entry2);
  b_entry2.set_width_chars(100);
  b_entry2.signal_activate().connect(sigc::mem_fun(*this, &MyWindow::on_b2_changed));
  h_box2.append(m_label4);
  m_label4.set_margin_start(10);
  m_label4.set_margin_end(10);
  h_box2.append(d_entry2);
  d_entry2.set_width_chars(25);
  d_entry2.signal_activate().connect(sigc::mem_fun(*this, &MyWindow::on_d2_changed));

  Vbox.append(m_button);
  m_button.set_margin(10);
  m_button.set_halign(Gtk::Align::CENTER);
  m_button.set_expand(false);
  m_button.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::on_button_clicked));

  Vbox.append(Vbox2);
  Vbox2.set_visible(false);

  Vbox2.append(label_res);
  label_res.set_margin(20);

  Vbox2.append(label_res_v);
  label_res_v.set_margin(20);
  label_res_v.set_wrap();
  label_res_v.set_selectable();

  Vbox2.append(h_box3);
  h_box3.set_margin(10);
  h_box3.set_halign(Gtk::Align::CENTER);

  h_box3.append(Vbox_n);
  Vbox_n.set_valign(Gtk::Align::CENTER);
  Vbox_n.set_margin_end(200);

  Vbox_n.append(label_n_time);
  label_n_time.set_margin(10);
  Vbox_n.append(label_n);

  h_box3.append(Vbox_k);
  Vbox_k.set_valign(Gtk::Align::CENTER);
  Vbox_k.set_margin_start(200);

  Vbox_k.append(label_k_time);
  label_k_time.set_margin(10);
  Vbox_k.append(label_k);
}

void MyWindow::on_button_clicked(){
  std::cout << "clicou" << std::endl;
  std::string b_num1 = b_entry1.get_text().c_str();
  std::string b_num2 = b_entry2.get_text().c_str();

  double duration_n, duration_k;

  std::string res_k = karatsuba_mutliplication_ini(b_num1, b_num2, &duration_k);
  std::string res_n = normal_mutliplication(b_num1, b_num2, &duration_n);
  std::string res_k_d = btod(res_k);
  std::string res_n_d = btod(res_n);

  if(res_k == res_n && res_k_d == res_n_d){
    label_res_v.set_text(res_k + " = " + res_n_d);
  }else {
    label_res_v.set_text("Erro! ;(");  
    std::cout << "Dk:" << res_k_d << " Dn:" << res_n_d << std::endl;
    std::cout << "Bk:" << res_k << " Bn:" << res_n << std::endl;
  }

  label_n_time.set_text(std::to_string(duration_n) + " Seconds");
  label_k_time.set_text(std::to_string(duration_k) + " Seconds");
  Vbox2.set_visible(true);
}

void MyWindow::on_b1_changed(){
  std::string num = btod(b_entry1.get_text().c_str());
  d_entry1.set_text(num);
}

void MyWindow::on_b2_changed(){
  std::string num = btod(b_entry2.get_text().c_str());
  d_entry2.set_text(num);
}

void MyWindow::on_d1_changed(){
  std::string num = dtob(d_entry1.get_text().c_str());
  b_entry1.set_text(num);
}

void MyWindow::on_d2_changed(){
  std::string num = dtob(d_entry2.get_text().c_str());
  b_entry2.set_text(num);
}
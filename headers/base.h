#pragma once    

#include <gtkmm.h>
#include <iostream>

class MyWindow : public Gtk::Window {
private:
    Gtk::Box Vbox, Vbox2, Vbox_n, Vbox_k, h_box1, h_box2, h_box3;
    Gtk::Entry b_entry1, b_entry2, d_entry1, d_entry2;
    Gtk::Label m_label1, m_label2, m_label3, m_label4, label_res, label_res_v, label_n, label_k, label_n_time, label_k_time;

public:
    MyWindow();

protected:
    Gtk:: Button m_button;

    void on_button_clicked();
    void on_b1_changed();
    void on_b2_changed();
    void on_d1_changed();
    void on_d2_changed();
};
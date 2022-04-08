// generated by Fast Light User Interface Designer (fluid) version 1.0305

#ifndef fskioUI_h
#define fskioUI_h
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include "status.h"
#include "fsk.h"
#include "ValueSlider.h"
extern Fl_Input2 *FSK_txt_to_send;
#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
extern Fl_Button *btn_fskio_config;
extern Fl_Button *btn_fskio_clear;
#include <FL/Fl_Light_Button.H>
extern Fl_Light_Button *btn_fskioSEND;
extern Fl_Button *FSK_btn_msg[12];
Fl_Double_Window* fskio_window();
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Box.H>
#include "flinput2.h"
extern Fl_Input2 *FSK_edit_label[12];
extern Fl_Input2 *FSK_edit_msg[12];
extern Fl_Button *FSK_btn_cancel_edit;
extern Fl_Button *FSK_btn_apply_edit;
extern Fl_Button *FSK_btn_FSK_done_edit;
Fl_Double_Window* FSK_make_message_editor();
#include "combo.h"
extern Fl_ComboBox *select_fskioPORT;
extern Fl_Light_Button *btn_fskioCONNECT;
#include <FL/Fl_Check_Button.H>
extern Fl_Check_Button *btn_fskioCAT;
extern Fl_Check_Button *btn_fskioAUX;
extern Fl_Check_Button *btn_fskioSEP;
extern Fl_Check_Button *btn_fskioSHARED;
extern Fl_Check_Button *btn_fskioINVERTED;
extern Fl_Check_Button *btn_fskioSTOPBITS;
extern Fl_ListBox *listbox_fskioKEYLINE;
#include <FL/Fl_Spinner.H>
extern Fl_Spinner *cntr_fskioPTT;
Fl_Double_Window* fskio_config_dialog();
#endif

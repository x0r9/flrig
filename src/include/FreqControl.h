// ----------------------------------------------------------------------------
//
// Frequency Control Widget for the Fast Light Tool Kit
//
// Copyright (C) 2014
//              David Freese, W1HKJ
//
// This file is part of flrig.
//
// flrig is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
//
// flrig is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// ----------------------------------------------------------------------------
//
// Usage:
//	Create a multi-digit receiver / transceiver frequency control widget
//
// label used to pass # digits & decimal position to control
// the widget can be used in Fluid & initialized with the
// number of digits as the label string
// default is 7; min number is 1, max number is 9 as in
//
// cFreqControl myFreqConrol(x0, y0, w0, h0, "N");  where N is # digits
// cFreqControl *pMyFreqControl = new cFreqControl(x0,y0,w0,h0,"N");

#ifndef _FREQCONTROL_H_
#define _FREQCONTROL_H_

#include <FL/Fl.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Repeat_Button.H>
#include <FL/Fl_Group.H>
#include <FL/Enumerations.H>

#ifdef MAX_DIGITS
#undef MAX_DIGITS
#endif
#define MAX_DIGITS 10

#ifdef MIN_DIGITS
#undef MIN_DIGITS
#endif
#define MIN_DIGITS 4

class Fl_Box;
class Fl_Float_Input;

class cFreqControl : public Fl_Group {
friend void cbSelectDigit (Fl_Widget *btn, void * nbr);
public:
	cFreqControl(int x, int y, int w, int h, const char *lbl = "7");
	~cFreqControl();
	void updatevalue();
	void value(unsigned long int lv);
	unsigned long int value(){return val;};
	void font(Fl_Font fnt);
	void SetONCOLOR (uchar r, uchar g, uchar b);
	void SetOFFCOLOR (uchar r, uchar g, uchar b);
	void GetONCOLOR (uchar &r, uchar &g, uchar &b) {
			Fl::get_color(ONCOLOR, r, g, b);
	};
	void GetOFFCOLOR (uchar &r, uchar &g, uchar &b) {
			Fl::get_color(OFFCOLOR, r, g, b);
	};
	void SetONOFFCOLOR( Fl_Color, Fl_Color);
	void setCallBack (int (*cbf)() ){ cbFunc = cbf;};
	void do_callback() { if (cbFunc) cbFunc(); }
	int  handle(int event);
	void visual_beep();
	void set_hrd(bool b) {hrd_buttons = b;}

	void reverse_colors();
	void restore_colors();
	bool  is_reversed_colors() { return colors_reversed; }

	void resize (int X, int Y, int W, int H);

	void set_precision(int val) {
		switch (val) {
			case 100:
				dpoint = 1; precision = 100; break;
			case 10:
				dpoint = 2; precision = 10; break;
			default:
				dpoint = 3; precision = 1; break;
		}
		set_ndigits(nD);
	}

	void set_ndigits(int val);

	void activate() { active = true; }
	void deactivate() { active = false; }
	bool isactive() { return active; }

private:
	Fl_Repeat_Button	*Digit[MAX_DIGITS];
	Fl_Float_Input		*finp;
	static const char	*Label[];
	int					mult[MAX_DIGITS];
	Fl_Box				*decbx;
	Fl_Box				*hfill;
	Fl_Font				font_number;
	int					font_size;
	Fl_Color			OFFCOLOR;
	Fl_Color			ONCOLOR;
	Fl_Color			SELCOLOR;
	Fl_Color			ILLUMCOLOR;
	Fl_Color			REVONCOLOR;
	Fl_Color			REVOFFCOLOR;
	int					nD;
	int					active;
	unsigned long int	maxVal;
	unsigned long int	minVal;

	int pw; // decimal width
	int wfill;
	int bdr;
	int fcWidth;
	int fcTop;
	int fcHeight;
	int W;

	void DecFreq(size_t n);
	void IncFreq(size_t n);
	int (*cbFunc)();
	static void freq_input_cb(Fl_Widget* input, void* arg);
protected:
	unsigned long int val, oldval;
	unsigned long fcval;
	int  precision;
	int  dpoint;
	bool hrd_buttons;
	bool colors_reversed;
};

#endif 

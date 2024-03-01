// The MIT License (MIT)
//
// Copyright (c) <2024> chromabox <chromarockjp@gmail.com>
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
#pragma once

#include "wxbasedef.h"

enum
{
	wxID_FMENU_FOPEN = 1000,
	wxID_FMENU_TEST,
	wxID_FMENU_EXIT
};

class mainApp: public wxApp
{
public:
	mainApp() { }

	virtual bool OnInit() override;

	wxDECLARE_NO_COPY_CLASS(mainApp);
};

// メインウィンドウを表すクラス
class appFrame : public wxFrame
{
protected:
	wxStatusBar* m_statusBar;

public:
	appFrame();
	virtual ~appFrame();

	void OnClose(wxCloseEvent& event);

	// file menu
	void OnFileMenu_FileOpen( wxCommandEvent& event );
	void OnFileMenu_Test( wxCommandEvent& event );
	void OnFileMenu_Exit( wxCommandEvent& event );
};


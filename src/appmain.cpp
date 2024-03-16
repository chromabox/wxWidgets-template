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
#include "appmain.h"
#include "appmain.xpm"

#define LOCALE_SETJP_UTF8 1

// ---------------------------------------------------------------------------------

wxDECLARE_APP(mainApp);

wxIMPLEMENT_APP(mainApp);

bool mainApp::OnInit()
{
#ifdef LOCALE_SETJP_UTF8	
	// windows 10.0.17134.0 after or ubuntu
	 setlocale(LC_ALL, "ja_JP.UTF-8");		// これをしないとコンソールで日本語出力がうまくいかないです
#endif

	// コマンドライン引数を処理する
	if(!wxApp::OnInit()){
		// 止める
		return false;
	}
	// ロガー作成
	auto *logger=new wxLogStream(&std::cout);
	wxLog::SetActiveTarget(logger);

	// wxImageを扱うときは必ず必要
	wxInitAllImageHandlers();

	appFrame* frame = new appFrame;
	frame->Show();
	// メッセージループ実行
	return true;
}


// ----------------------------------------------------------------------------------

appFrame::appFrame()
	: wxFrame(nullptr, wxID_ANY, "wxSample")
{
	// アプリアイコンの設定
	SetIcon(wxICON(appmain));
	// メインメニューの作成
	auto menuFile = new wxMenu;
	menuFile->Append(new wxMenuItem( menuFile, wxID_FMENU_FOPEN, wxString( L"open..." ) , wxEmptyString, wxITEM_NORMAL ));
	menuFile->Append(new wxMenuItem( menuFile, wxID_FMENU_TEST, wxString( L"test" ) , wxEmptyString, wxITEM_NORMAL ));
	menuFile->AppendSeparator();
	menuFile->Append(new wxMenuItem( menuFile, wxID_FMENU_EXIT, wxString( L"Quit" ) , wxEmptyString, wxITEM_NORMAL ));

	auto menuBar = new wxMenuBar;

	menuBar->Append(menuFile, L"File");

	SetMenuBar(menuBar);

	m_statusBar = this->CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );

	// イベントハンドラーの登録
	Bind(wxEVT_MENU,&appFrame::OnFileMenu_FileOpen, this, wxID_FMENU_FOPEN);
	Bind(wxEVT_MENU,&appFrame::OnFileMenu_Test, this, wxID_FMENU_TEST);
	Bind(wxEVT_MENU,&appFrame::OnFileMenu_Exit, this, wxID_FMENU_EXIT);

	Bind(wxEVT_CLOSE_WINDOW, &appFrame::OnClose, this);
}

appFrame::~appFrame()
{
}

// wxEVT_CLOSE_WINDOW はウィンドウが閉じられようとしていた場合に呼ばれる
void appFrame::OnClose(wxCloseEvent& event)
{
	Destroy();
}

void appFrame::OnFileMenu_FileOpen( wxCommandEvent& event )
{
	wxLogMessage(L"select open");
	wxString filename = wxLoadFileSelector(L"load file", wxEmptyString);
	if ( filename.empty() ){
		wxLogMessage(L"select cancel");
	}
	wxLogMessage(L"ok %ls" ,filename);
	wxMessageBox(filename);
}

void appFrame::OnFileMenu_Test( wxCommandEvent& event )
{
	wxMessageBox(L"テストが押されました！！");
	wxLogMessage(L"テストが押されました");
}    

void appFrame::OnFileMenu_Exit( wxCommandEvent& event )
{
	Close(true);
}


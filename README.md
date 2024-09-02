# wxWidgets-template
これは`wxWidgets`(C++用クロスプラットフォームGUIライブラリ)の基本的なテンプレートサンプルです  
`cmake`で`wxWidgets`をビルドする時のサンプルにもなっています   
github画面の右端にある`use this template`ボタンを押すだけでwxWidgetsのプロジェクトの雛形から起こすことが出来ます  
  
ubuntu 24.04.1の環境で動作確認済  
(gcc 13.2.0, wxWidgets 3.2.4)  
  
wxWidgetsについてはこちら  
https://www.wxwidgets.org/  
https://github.com/wxWidgets/wxWidgets  



## ビルド方法(ubuntu/linux):

cmake とか wxWidgetsの開発用ライブラリ(〜dev)は必要なのでインストールします。
```
$ sudo apt install build-essential cmake
$ sudo apt install libwxbase3.0-dev libwxgtk3.0-gtk3-dev libwxgtk-webview3.0-gtk3-dev libwxgtk-media3.0-gtk3-dev libwxsmithlib-dev libwxsvg-dev
```

次に、github画面の右端にある`use this template`ボタンを押してプロジェクトを作ります。  
その後cloneしてから  
```bash
$ ./build.sh
```
でとりあえずビルド出来ます。  
  
これに必須ではありませんが、wxFormBuilderを使用するとダイアログやフォームがGUIで作りやすいです  
ubuntuではFlatpak版を使ったほうがいいと思います  
Flatpak版のインストール方法は以下のようになります  
```
$ wget https://github.com/wxFormBuilder/wxFormBuilder/releases/download/v4.0.0/wxFormBuilder-4.0.0-x86_64.flatpak
$ flatpak install ./wxFormBuilder-4.0.0-x86_64.flatpak
```

## TODO:
- Windowsでの例を入れる
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
$ sudo apt install wx3.2-i18n libwxgtk3.2-dev libwxgtk-webview3.2-dev libwxgtk-media3.2-dev libwxsmithlib-dev libwxsvg-dev
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
$ wget https://github.com/wxFormBuilder/wxFormBuilder/releases/download/v4.2.1/wxFormBuilder-4.2.1-x86_64.flatpak
$ sudo flatpak install ./wxFormBuilder-4.2.1-x86_64.flatpak
```

## TODO:
- Windowsでの例を入れる
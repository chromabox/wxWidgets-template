# wx-template-project
これはwxWidgetの基本的なテンプレートサンプルです  
github画面の右端にある`use this template`ボタンを押すだけでwxWidgetのプロジェクトの雛形から起こすことが出来ます  

ubuntu 22.04の環境で動作確認済  

## ビルド方法:

cmake とか wxWidgetのライブラリは必要なのでインストールします。
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
  
なお、これに必須ではありませんが、FormBuilderのインストールをするとダイアログやフォームがGUIで作りやすいです  
Flatpak版を使ったほうがいいと思います  
```
$ wget https://github.com/wxFormBuilder/wxFormBuilder/releases/download/v4.0.0/wxFormBuilder-4.0.0-x86_64.flatpak
$ flatpak install ./wxFormBuilder-4.0.0-x86_64.flatpak
```

# Docker (Windows)

## コンピューターの設定の確認
- 「タスクマネージャー」を起動し、［パフォーマンス］→［CPU］から［仮想化：有効］となっていることを確認する。
  - 有効にする方法はコンピューターのメーカーや機種によって異なるので、自分で調べる。
- 「コントロールパネル」を起動し、［プログラム］→［Windowsの機能の有効化または無効化］を開き、［Hyper-V］と［Linux用Windowsサブシステム（Windows Subsystem for Linux）］にチェックが入っていることを確認する。

## ソフトウェアのインストール
- DockerのアカウントでDocker Hubにアクセスする。
  - https://hub.docker.com/
- Docker Desktop for Windowsをインストールする。
  - https://docs.docker.com/get-docker/
- Docker Desktop.exeを起動し、IDとPasswordを入力する。
- コマンドプロンプトを起動し、コマンドdockerが実行できることを確認する。
  ```
  > docker version
  ```

## GUIの設定
- GUIを使用するためにVcXsrvをインストールする。
  - https://sourceforge.net/projects/vcxsrv/
- ホストのIPアドレスを確認する。Wi-FiなどのIPv4アドレスを確認する。
  ```
  > ipconfig
  ```
- ホストの設定を変更する。Xmingのインストール先（/Program Files (x86)/Xming）にあるX0.hostsファイルに、X Window Systemの転送を許可するホストのIPアドレスを記入する。
  ```
  localhost
  ホストのIPアドレス（←追記！）
  ```
- コンピューターを再起動する。
- VcXsrvをソフトウェア「XLanuch」で起動する。
  - 「Native opengl」のチェックを外す。
  - 「Disable access control」にチェックを入れる。

## イメージのダウンロード
- Ubuntu 18.04のイメージをダウンロードする。
  ```
  > docker pull ubuntu:18.04
  ```
- Ubuntu 18.04のイメージが存在することを確認する。
  ```
  > docker images
  ```

## コンテナーの作成→テスト
- ホストのIPアドレスを指定しつつ、イメージを用いてコンテナーを作成し、起動する。オプションnameでコンテナーに対して名前（例：ubuntu）を付けておく。
  ```
  《記法》
  > docker run -itd -e DISPLAY=IPアドレス:0.0 -v ~/.Xauthority:/root/.Xauthority --name コンテナー名 イメージ名 /bin/bash
  《実例》
  > docker run -itd -e DISPLAY=172.31.2.23:0.0 -v ~/.Xauthority:/root/.Xauthority --name ubuntu ubuntu:18.04 /bin/bash
  ```
- コンテナー「ubuntu」が存在することを確認する。
  ```
  > docker ps -a
  ```
- コンテナー「ubuntu」に入る。
  ```
  > docker exec -it ubuntu /bin/bash
  ```
- コマンドsudoをインストールする。
  ```
  # su
  # apt update
  # apt -y install sudo
  ```
- geditをインストールし、実行してみる。
  ```
  # sudo apt -y install gedit
  # gedit
  ```
  - libGLに関するエラーが発生する場合は、下記のコマンドを実行する。
    ```
    # export LIBGL_ALWAYS_INDIRECT=1
    ```
- x11-appsをインストールし、実行してみる。
  ```
  # sudo apt -y install x11-apps
  # xeyes
  ```
  - マウスカーソルを見続ける目が表示される。

## コンテナーの操作（今後のために）

### コンテナーの起動
- コンテナーを起動する。
  ```
  《記法》
  > docker start コンテナー名
  《実例》
  > docker start ubuntu
  ```

### コンテナーの停止
- コンテナーをコマンドexitで抜けてから、コンテナーを停止する。
  ```
  # exit
  ```
  ```
  《記法》
  > docker stop コンテナー名
  《実例》
  > docker stop ubuntu
  ```

### コンテナーの削除
- コンテナーを作り直す場合は、まず、コマンドpsでコンテナーIDを確認する。そして、コマンドrmで削除する。コンテナーを停止してから行う。
  ```
  > docker ps -a
  ```
  ```
  《記法》
  > docker rm コンテナーID
  《実例》
  > docker rm 81ae65b0ac4296538f66d4037b18d36a2cc530b926eb0c9d3bce4a5a622ef003
  ```

[このページのトップへ](#)

[Dockerページへ](https://stl-apu.github.io/advanced_experiment_2022/docker)

[応用実験用サイトのトップへ](https://stl-apu.github.io/advanced_experiment_2022/)

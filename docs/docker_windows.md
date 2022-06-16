# Docker (Windows)

## コンピューターの設定確認
- 「タスクマネージャー」を起動し、［パフォーマンス］→［CPU］から「仮想化：有効」となっていることを確認する。
  - 有効にする方法はコンピューターのメーカーや機種によって異なるので、自分で調べる。
- 「コントロールパネル」を起動し、［プログラム］→［Windowsの機能の有効化または無効化］から［Hyper-V］にチェックが入っていることを確認する。
- 「コントロールパネル」を起動し、［プログラム］→［Windowsの機能の有効化または無効化］から［Linux用Windowsサブシステム（Windows Subsystem for Linux）］にチェックが入っていることを確認する。

## ソフトウェアのインストール
- Dockerのアカウントを作成し、Docker Hubにアクセスする。
  - https://hub.docker.com/
- Docker Desktop for Windowsをインストールする。
  - https://docs.docker.com/get-docker/
- Docker.appを起動し、IDとPasswordを入力する。
- コマンドプロンプトを起動し、Dockerコマンドが使用できるか（Dockerが起動しているか）を確認する。
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
- イメージが存在することを確認する。
  ```
  > docker images
  ```

## コンテナーの作成
- ホストのIPアドレスを指定しつつ、イメージを用いてコンテナーを作成（起動）する。nameオプションでコンテナーに対して名前（例：ubuntu）を付けておく。
  ```
  《記法》
  > docker run -itd -e DISPLAY=IPアドレス:0.0 -v ~/.Xauthority:/root/.Xauthority --name コンテナー名 イメージ名 /bin/bash
  《実例》
  > docker run -itd -e DISPLAY=172.31.2.23:0.0 -v ~/.Xauthority:/root/.Xauthority --name ubuntu ubuntu:18.04 /bin/bash
  ```
- コンテナーに入る。
  ```
  > docker exec -it ubuntu /bin/bash
  ```
- sudoコマンドをインストールする。
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
- x11-appsをインストールし、実行してみる。
  ```
  # sudo apt -y install x11-apps
  # xeyes
  ```

## コンテナーの停止
- コンテナーを抜ける。
  ```
  # exit
  ```
- コンテナーを停止する。
  ```
  > docker stop ubuntu
  ```

## コンテナーの起動
- コンテナーを起動する。
  ```
  > docker start ubuntu
  ```

## コンテナーの削除
- コンテナーを作り直す場合は、psコマンドでコンテナーIDを確認し、rmコマンドで削除する。コンテナーを停止してから行う。
  ```
  > docker ps -a
  > docker rm コンテナーID
  ```

[このページのトップへ](#)

[Dockerページへ](https://stl-apu.github.io/advanced_experiment_2022/docker)

[応用実験用サイトのトップへ](https://stl-apu.github.io/advanced_experiment_2022/)

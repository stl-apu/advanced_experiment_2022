# Docker（Mac）

## ソフトウェアのインストール
- Dockerのアカウントを作成し、Docker Hubにアクセスする。
  - https://hub.docker.com/
- Docker Desktop for Macをインストールする。
  - https://docs.docker.com/get-docker/
- Docker.appを起動し、IDとPasswordを入力する。
- ターミナルを起動し、Dockerコマンドが使用できるか（Dockerが起動しているか）を確認する。
  ```
  % docker version
  ```

## GUIの設定
- XQuartzをインストールする。
  - https://www.xquartz.org/
- XQuartzを起動し、［環境設定］→［セキュリティ］から［ネットワーク・クライアントからの接続を許可］にチェックを入れる。
- コンピューターを再起動する。
- 再度、XQuartzを起動する。

## イメージのダウンロード
- Ubuntu 18.04のイメージをダウンロードする。
  ```
  % docker pull ubuntu:18.04
  ```
- イメージが存在するかを確認する。
  ```
  % docker images
  ```

## コンテナーの作成
- イメージを用いてコンテナーを作成（起動）する。nameオプションでコンテナーに対して名前（例：ubuntu）を付けておくと良い。
  ```
  % docker run -itd -e DISPLAY=$(hostname):0 -v ~/.Xauthority:/root/.Xauthority --name ubuntu ubuntu:18.04 /bin/bash
  ```
- コンテナーが存在することを確認する。
  ```
  % docker ps -a
  ```
- コンテナーに入る。
  ```
  % docker exec -it ubuntu /bin/bash
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
  % docker stop ubuntu
  ```    

## コンテナーの起動
- コンテナーを起動する。
  ```
  % docker start ubuntu
  ```

## コンテナーの削除
- コンテナーを作り直す場合は、psコマンドでコンテナーIDを確認し、rmコマンドで削除する。コンテナーを停止してから行う。
  ```
  % docker ps -a
  % docker rm コンテナーID
  ```

[このページのトップへ](#)

[Dockerページへ](https://stl-apu.github.io/advanced_experiment_2022/docker)

[応用実験用サイトのトップへ](https://stl-apu.github.io/advanced_experiment_2022/)

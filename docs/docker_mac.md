# Docker（Mac）

## ソフトウェアのインストール
- DockerのアカウントでDocker Hubにアクセスする。
  - https://hub.docker.com/
- Docker Desktop for Macをインストールする。
  - https://docs.docker.com/get-docker/
- Docker.appを起動し、IDとPasswordを入力する。
- ターミナルを起動し、コマンドdockerが実行できることを確認する。
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
- Ubuntu 18.04のイメージが存在することを確認する。
  ```
  % docker images
  ```

## コンテナーの作成→テスト
- イメージを用いてコンテナーを作成し、起動する。オプションnameでコンテナーに対して名前（例：ubuntu）を付けておく。
  ```
  % docker run -itd -e DISPLAY=$(hostname):0 -v ~/.Xauthority:/root/.Xauthority --name ubuntu ubuntu:18.04 /bin/bash
  ```
- コンテナー「ubuntu」が存在することを確認する。
  ```
  % docker ps -a
  ```
- コンテナー「ubuntu」に入る。
  ```
  % docker exec -it ubuntu /bin/bash
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
  % docker start コンテナー名
  《実例》
  % docker start ubuntu
  ```

### コンテナーの停止
- コンテナーをコマンドexitで抜けてから、コンテナーを停止する。
  ```
  # exit
  ```
  ```
  《記法》
  % docker stop コンテナー名
  《実例》
  % docker stop ubuntu
  ```

### コンテナーの削除
- コンテナーを作り直す場合は、まず、コマンドpsでコンテナーIDを確認する。そして、コマンドrmで削除する。コンテナーを停止してから行う。
  ```
  % docker ps -a
  ```
  ```
  《記法》
  % docker rm コンテナーID
  《実例》
  % docker rm コンテナーID
  ```


[このページのトップへ](#)

[Dockerページへ](https://stl-apu.github.io/advanced_experiment_2022/docker)

[応用実験用サイトのトップへ](https://stl-apu.github.io/advanced_experiment_2022/)

# Docker（Ubuntu）

## ソフトウェアのインストール
- Dockerをインストールする。
  ```
  $ sudo apt update
  $ sudo apt -y install docker.io
  ```
- Dockerが実行できることを確認する。
  ```
  $ docker version
  ```

## ソケット通信の設定
- dockerグループにユーザーを追加する。
  ```
  $ sudo gpasswd -a $USER docker
  ```
- ソケット通信に関するファイルの所有者を変更する。
  ```
  $ sudo chgrp docker /var/run/docker.sock
  ```
- dockerサービスを再起動する。
  ```
  $ sudo service docker restart
  ```
- コンピューターを再起動する。
  ```
  $ sudo reboot
  ```
- 接続が許可されているクライアント（Docker Container）として『LOCAL:』があることを確認する。
  ```
  $ xhost
  access control enabled, only authorized clients can connect
  LOCAL:
  SI:localuser:ユーザー名
  ```
  - 『LOCAL:』が無い場合は追加する。
    ```
    $ xhost +local:
    ```
- dockerサービスを起動する。
  ```
  $ sudo service docker start
  ```

## イメージのダウンロード
- Ubuntu 18.04のイメージをダウンロードする。
  ```
  $ docker pull ubuntu:18.04
  ```
- イメージが存在することを確認する。
  ```
  $ docker images
  ```

## コンテナーの作成
- イメージを用いてコンテナーを作成（起動）する。nameオプションでコンテナーに対して名前（例：ubuntu）を付けておく。
  ```
  $ docker run -itd --env="DISPLAY" --env="QT_X11_NO_MITSHM=1" --volume="/tmp/.X11-unix:/tmp/.X11-unix:rw" --name ubuntu ubuntu:18.04 /bin/bash
  ```
- コンテナーが存在することを確認する。
  ```
  $ docker ps -a
  ```
- コンテナーに入る。
  ```
  $ docker exec -it ubuntu /bin/bash
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
  - libGLに関するエラーへの対処
    ```
    # export LIBGL_ALWAYS_INDIRECT=1
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
  $ docker stop ubuntu
  ```

## コンテナーの起動
- コンテナーを起動する。
  ```
  $ docker start ubuntu
  ```

## コンテナーの削除
- コンテナーを作り直す場合は、psコマンドでコンテナーIDを確認し、rmコマンドで削除する。コンテナーを停止してから行う。
  ```
  $ docker ps -a
  $ docker rm コンテナーID
  ```

[このページのトップへ](#)

[Dockerページへ](https://stl-apu.github.io/advanced_experiment_2022/docker)

[応用実験用サイトのトップへ](https://stl-apu.github.io/advanced_experiment_2022/)
